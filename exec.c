#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    int ret = 1;
    int status;
    char *argv[] = {"/bin/ls", "-l", NULL}; // command to execute

    pid = fork();
    if (pid == -1)
    {
        perror("can't fork");
        exit(1);
    }
    else if (pid == 0) // child process
    {
        ret = execv(argv[0], argv); // execute command
        if (ret == -1)
        {
            perror("execv failed");
            exit(127);
        }
    }
    else // parent process
    {
        if (waitpid(pid, &status, 0) > 0)
        {
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
                printf("program execution successful\n");
            else if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            {
                printf("program terminated normally but returned a non-zero status\n");
            }
            else
            {
                printf("program didn't terminate normally\n");
            }
        }
        else
        {
            perror("waitpid failed");
        }
    }

    return 0;
}
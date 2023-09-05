#include <unistd.h>

int main(void)
{
    char *cmd = "ls";
    char *arg = "-al";
    char *arg2 = "/home/";
    execlp(cmd,arg, arg2, NULL);
    return(0);
}
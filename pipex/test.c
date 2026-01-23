#include <unistd.h>

int main(int ac, char **av, char **envp)
{
    (void) ac;
	(void) av;
    const char *filename = "/usr/bin/ls";
    char *const argv[] = {"/usr/bin/ls", "", NULL};
    
    execve(filename, argv, envp);
}

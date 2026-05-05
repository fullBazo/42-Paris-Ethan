#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int cd(char **av, int i)
{
	if (i != 2)
		return err("cd :vbad"), 1;
	if (chdir(av[1]) == -1)
		return err("cd : cannot "), err(av[1]), err("\n");
}

void set_pipe(int has_pipe, int *fd, int end) {
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[1]) == -1 || -1 ))
		return (err("error: fatal\n")), exit (1);
}

int exec(char **av, int i, char **envp)
{
	int has_pipe, pid, status, fd[2];
	has_pipe = av[i] && !strcmp(av[i], "|");
	if (!has_pipe && !strcmp(*av, "cd"))
		return cd(av,i);
	if (has_pipe && pipe(fd) == -1)
		fatal err
	if ((pid = fork()) == -1)
		err
	if (!pid) {
		av[i] = 0;
		set_pipe(has_pipe, fd, 1);
		if (!strcmp(*av, "cd"))
			exit(cd(av,i));
		execve(*av, av, envp);
		err(cannot execute)
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return (WIFEXITED(status) && WEXITSTATUS(status))
}

int main(int, char **av, char **envp)
{
	int i = 0, status = 0, saved_stdin = dup(0);
	while (av[i])
	{
		av += i + 1;
		i = 0;
		while (av[i] && strcmp(av[i]))
			i++;
		if (i)
			status = exec(av, i, envp);
		if (!str)
	}
}

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	putstr(char *s1, char *s2)
{
	while(*s1)
		write(2, s1++, 1);
	if (s2)
		while(*s2)
			write(2, s2++, 1);
	write(2, "\n", 1);
	return 1;
}

int	exc(char **av, int i, int tmp_fd, char **ev)
{
	av[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(av[0], av, ev);
	return (putstr("error:: cannot execute ", av[0]));
}

int main(int ac, char **av, char **ev)
{
	(void)ac;

	int	fd[2];
	int	tmpFd = dup(STDIN_FILENO);

	int	i = 0;
	while(av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;

		while(av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;

		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				putstr("error.", NULL);
			else if (chdir(av[1]) != 0)
				putstr("error in chrdir ", av[1]);
		}

		else if ((i != 0 && av[i] == NULL) || ( i != 0 && strcmp(av[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (exc(av, i, tmpFd, ev))
					return 1;
			}
			else
			{
				close(tmpFd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmpFd = dup(STDIN_FILENO);
			}
		}

		else if (i != 0 && strcmp(av[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (exc(av, i, tmpFd, ev))
					return 1;
			}
			else
			{
				close(tmpFd);
				close(fd[1]);
				tmpFd = fd[0];
			}
		}
	}



	close(tmpFd);
	return 0;
}


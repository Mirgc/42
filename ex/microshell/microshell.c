#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void ft_putchar(char c)
{
	write(STDERR_FILENO, &c, 1);
}

int error(char *str)
{
	while (*str)
		ft_putchar(*str++);
	return (1);
}

int fatal(char **free_ptr)
{
	free(free_ptr);
	exit(error("error: fatal\n"));
}

int size_cmd(char **cmd)
{
	int i;

	if (!cmd)
		return (0);
	i = -1;
	while (cmd[++i]);
	return (i);
}

int	size_cmd_char(char **cmd, char *str)
{
	int i;

	if (!cmd)
		return (0);
	i = -1;
	while(cmd[++i])
		if (!strcmp(cmd[i], str))
			return (i);
	return (i);
}

char **next_pipe(char **cmd)
{
	int i;

	if (!cmd)
		return (0);
	i = -1;
	while (cmd[++i])
		if (!strcmp(cmd[i], "|"))
			return (&cmd[i + 1]);
	return (NULL);
}

char **add_cmd(char **argv, int *i)
{
	int size;
	int j;
	char **tmp;

	size = size_cmd_char(&argv[*i], ";");
	if (!size)
		return (NULL);
	tmp = malloc(sizeof(*tmp) * (size + 1));
	if (!tmp)
		fatal(NULL);
	j = -1;
	while(++j < size)
		tmp[j] = argv[j + *i];
	tmp[j] = NULL;
	*i += size;
	return (tmp);
}

int ft_cd(char **cmd)
{
	if (size_cmd(cmd) != 2)
		return(error("error: cd: bad arguments\n"));
	if (chdir(cmd[1]) < 0)
	{
		error("error: cd: cannot change directory ");
		error(cmd[1]);
		error("\n");
	}
	return (0);
}

int exec_cmd(char **cmd, char **env, char **free_ptr)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
		fatal(free_ptr);
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
		{
			error("error: cannot execute ");
			error(cmd[0]);
			error("\n");
		}
	}
	waitpid(0, NULL, 0);
	return (0);
}

int exec_child(char **cmd, char **env, char **tmp, int fd_in, int fd_pipe[2])
{
	if (dup2(fd_in, STDIN_FILENO) < 0)
		fatal(cmd);
	if (next_pipe(tmp) && dup2(fd_pipe[1], STDOUT_FILENO) < 0)
		fatal(cmd);
	close(fd_in);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	tmp[size_cmd_char(tmp, "|")] = NULL;
	exec_cmd(tmp, env, cmd);
	free(cmd);
	exit(0);
}

int execute(char **cmd, char **env)
{
	if (!next_pipe(cmd))
		return(exec_cmd(cmd, env, cmd));

	int fd_in;
	int fd_pipe[2];
	char **tmp;
	int nb_wait;
	pid_t pid;

	tmp = cmd;
	nb_wait = 0;

	fd_in = dup(STDIN_FILENO);
	if(fd_in < 0)
		return(fatal(cmd));
	while(tmp)
	{
		if (pipe(fd_pipe) < 0 || (pid = fork()) < 0)
			fatal(cmd);
		if (pid == 0)
			exec_child(cmd, env, tmp, fd_in, fd_pipe);
		else
		{
			if (dup2(fd_pipe[0], fd_in) < 0)
				fatal(cmd);
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			++nb_wait;
			tmp = next_pipe(tmp);
		}
	}
	close(fd_in);
	while(nb_wait-- >= 0)
		waitpid(0, NULL, 0);
	return (0);
}

int main(int argc, char **argv, char **env)
{
	char **cmd = NULL;
	int i = 0;

	while (++i < argc)
	{
		cmd = add_cmd(argv, &i);
		if (cmd && !strcmp(cmd[0], "cd"))
			ft_cd(cmd);
		else if (cmd)
			execute(cmd, env);
		free(cmd);
		cmd = NULL;
	}
	return (0);
}


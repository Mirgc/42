#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int fd_in;
int fd_pipe[2];
pid_t pid;

int error(char *str)
{
	while(*str)
		write(STDERR_FILENO, str++, 1);
	return(1);
}

int fatal(char **cmd)
{
	free(cmd);
	exit(error("error: fatal\n"));
}

int len_cmd(char **cmd)
{
	int i = -1;

	if(!cmd)
		return(0);
	while(cmd[i])
		++i;
	return (i);
}

int len_to_char(char **cmd, char *c)
{
	int i = -1;

	if(!cmd)
		return(0);
	while(cmd[++i])
		if(!strcmp(cmd[i], c))
			break ;
	return(i);
}

char **ft_pipe(char **cmd)
{
	int i = -1;
	
	if (!cmd)
		return (0);
	while(cmd[++i])
		if(!strcmp(cmd[i], "|"))
			return(&cmd[i + 1]);
	return(NULL);
}

char **split_cmd(char **argv, int *i)
{
	char **tmp;
	int len, j;

	len = len_to_char(&argv[*i], ";");
	if (!len)
		return(NULL);
	tmp = malloc(sizeof(*tmp) * (len + 1));
	if (!tmp)
		fatal(NULL);
	j = -1;
	while(++j < len)
		tmp[j] = argv[j + *i];
	tmp[j] = NULL;
	*i += len;
	return (tmp);
}

int exec_cmd(char **cmd, char **env, char **tmp)
{
	pid = fork();
	if (pid < 0)
		fatal(tmp);
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

int child(char **cmd, char **env, char **tmp)
{
	if (dup2(fd_in, STDIN_FILENO) < 0)
		fatal(cmd);
	if (ft_pipe(tmp) && dup2(fd_pipe[1], STDOUT_FILENO) < 0)
		fatal(cmd);
	close(fd_in);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	tmp[len_to_char(tmp, "|")] = NULL;
	exec_cmd(tmp, env, cmd);
	free(cmd);
	exit(0);
}

int exec(char **cmd, char **env)
{

	char **tmp;
	int nwait = 0;

	if (!ft_pipe(cmd))
		return(exec_cmd(cmd, env, cmd));
	tmp = cmd;
	fd_in = dup(STDIN_FILENO);
	if (fd_in < 0)
		return(fatal(cmd));
	while(tmp)
	{
		if (pipe(fd_pipe) < 0 || (pid = fork()) < 0)
			fatal(cmd);
		if (pid == 0)
			child(cmd, env, tmp);
		else
		{
			if (dup2(fd_pipe[0], fd_in) < 0)
				fatal(cmd);
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			++nwait;
			tmp = ft_pipe(tmp);
		}
	}
	close(fd_in);
	while(nwait-- >= 0)
		waitpid(0, NULL, 0);
	return (0);
}

int main(int argc, char **argv, char **env)
{
	char **cmd = NULL;
	int i = 0;

	while (++i < argc)
	{
		cmd = split_cmd(argv, &i);
		if (cmd && !strcmp(cmd[0], "cd"))
		{
			if (len_cmd(cmd) != 2)
				return(error("error: cd: bad arguments\n"));
			if (chdir(cmd[1]) < 0)
			{
				error("error: cd: cannot change directory to ");
				error(cmd[1]);
				error("\n");
			}
		}
		else if (cmd)
			exec(cmd, env);
		free(cmd);
		cmd = NULL;
	}
	return (0);
}

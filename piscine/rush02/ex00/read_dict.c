/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 09:00:42 by hmartin-          #+#    #+#             */
/*   Updated: 2021/05/02 21:45:50 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h" 

void	ft_strcat(char *dictionary, char *read_buff)
{
	while (*read_buff)
	{
		*dictionary = *read_buff;
		dictionary++;
		read_buff++;
	}
}

unsigned	int	ft_get_fsize(char *dict_name)
{
	int				fd;
	unsigned int	size;
	char			read_buff[BUFFSIZE + 1];
	int				count_reads ;

	count_reads =1;
	fd = open(dict_name, 'r');
	if (fd == -1)
		return (-1);
	while ((read(fd, read_buff, BUFFSIZE)))
		size =BUFFSIZE * count_reads++;
	close(fd);
	return (size);
}

int	ft_close_file(int fd)
{
	int	ret_val;

	ret_val =0;
	if (close(fd) == -1)
		ret_val = 3;
	return (ret_val);
}

void	ft_read_file(int fd, char *dict_ptr)
{
	unsigned int	size;
	char			read_buff[BUFFSIZE + 1];
	char			*tmp_ptr;

	tmp_ptr = dict_ptr;
	size = read(fd, read_buff, BUFFSIZE);
	while (size > 0)
	{
		read_buff[size] = '\0';
		ft_strcat(tmp_ptr, read_buff);
		size = read(fd, read_buff, BUFFSIZE);
		tmp_ptr = tmp_ptr + BUFFSIZE;
	}
}

struct	s_list	*ft_read_dict_file(char	*dict_name)
{
	int				fd;
	unsigned int	size;
	char			*dict_ptr;
	t_list			*tab;

	size = ft_get_fsize(dict_name);
	if (size <= 0)
		return (NULL);
	dict_ptr = malloc(sizeof(char) * (size * 3));
	fd = open(dict_name, 'r');
	if (dict_ptr == NULL || fd == -1)
		return (NULL);
	ft_read_file(fd, dict_ptr);
	tab = ft_parse(dict_ptr);
	free(dict_ptr);
	return (tab);
}

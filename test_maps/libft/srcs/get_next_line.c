/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:39:48 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/14 13:49:44 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Add_buff() is basically a ft_lstnew() call that creates a t_buff inside it.
*/

static t_list	*add_buff(int fd)
{
	t_list	*node;

	node = ft_lstnew(NULL, 0);
	if (!node)
		return (NULL);
	node->content = ft_memalloc(sizeof(t_buff));
	if (!node->content)
	{
		free(node);
		return (NULL);
	}
	node->content_size = sizeof(t_buff);
	((t_buff *)(node->content))->buff_i = BUFF_SIZE;
	((t_buff *)(node->content))->fd = fd;
	return (node);
}

/*
 * Setup_buffer() checks if the buffer list has a head, and depending on that
 * it either creates a new one or searches for a t_buff that matches the file
 * descriptor that was called for get_next_line(). If one is found it fetches 
 * the t_buff to be used for this line, or creates a new node if one isn't
 * present.
*/

static int	setup_buffer(t_list **buffs, t_buff **buff_cur, int fd,
		t_list **node_cur)
{
	t_list	*node;

	if (!*buffs)
	{
		*buffs = add_buff(-1);
		if (!*buffs)
			return (0);
	}
	{
		node = *buffs;
		while ((node->next && ((t_buff *)(node->content))->fd != fd))
			node = node->next;
		if (((t_buff *)(node->content))->fd != fd)
		{
			node->next = add_buff(fd);
			if (!(node->next))
				return (0);
			node = node->next;
		}
		*node_cur = node;
		*buff_cur = (t_buff *)(node->content);
	}
	return (1);
}

/*
 * Read_fd() is responsible for actually reading the file into the buffer char *
 * inside t_buff. If read() is called, the buffers index is also reset.
*/

static ssize_t	read_fd(t_buff **buff_cur)
{
	if ((*buff_cur)->buff_i >= BUFF_SIZE)
	{
		(*buff_cur)->read_result = read((*buff_cur)->fd, \
			(void *)((*buff_cur)->buff), BUFF_SIZE);
		if ((*buff_cur)->read_result == -1)
			return (-1);
		(*buff_cur)->buff_i = 0;
	}
	return ((*buff_cur)->read_result);
}

/*
 * Read_line() is the main workhorse of this implementation. It runs a while
 * loop for as long as there is still something to be read (Newline or EOF is
 * encountered) and writes the buffer to the line variable along the way.
*/

static ssize_t	read_line(char **line, t_buff *buff_cur, size_t line_len)
{
	char	*temp;
	ssize_t	line_i;

	line_i = 0;
	while (1)
	{
		if (read_fd(&buff_cur) < 0)
			return (-1);
		if (line_i >= (ssize_t)line_len)
		{
			temp = (char *)ft_memalloc((line_len *= 2));
			if (!temp)
				return (-1);
			ft_memcpy(temp, *line, line_len / 2);
			free(*line);
			*line = temp;
		}
		if (buff_cur->buff[buff_cur->buff_i] == '\n' \
		|| buff_cur->buff_i >= (size_t)buff_cur->read_result)
		{
			line[0][line_i] = '\0';
			return (line_i);
		}
		line[0][line_i++] = buff_cur->buff[buff_cur->buff_i++];
	}
}

/*
 * "Main()" of this implementation, mostly deals with handling proper return
 * values for the function.
*/

int	get_next_line(const int fd, char **line)
{
	static t_list	*buffs = NULL;
	t_buff			*buff_cur;
	t_list			*node_cur;
	ssize_t			linelen;

	if (fd < 0 || !line)
		return (-1);
	*line = (char *)ft_memalloc(BUFF_SIZE);
	if (!*line)
		return (-1);
	if (!setup_buffer(&buffs, &buff_cur, fd, &node_cur))
		return (-1);
	linelen = read_line(line, buff_cur, BUFF_SIZE);
	if (buff_cur->read_result == -1)
	{
		buff_cur->buff_i = BUFF_SIZE;
		return (-1);
	}
	if (buff_cur->read_result < (ssize_t)++buff_cur->buff_i && linelen == 0)
	{
		ft_lstpopref(buffs, &node_cur);
		return (0);
	}
	else
		return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:44:38 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/14 16:31:49 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# include "./libft/libft.h"

int						get_next_line(const int fd, char **line);
int						check_nl(char *str);
int						check_eof(int fd, char *buff_end);
char					*read_till_nl(int fd, char *buff, char **line);

typedef struct			s_fd_list
{
	int					fd;
	char				*buff_end;
	struct t_fd_list	*next;
}						t_fd_list;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:44:38 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/20 15:56:30 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# include "./libft/libft.h"

int		get_next_line(const int fd, char **line);
int		gnl(char *buff, char **line, const int fd, int ret);
int		fill_buffer(int fd, char *buff_end);
char	*str_memcat(char *mem1, char *mem2, size_t size);
int		check_nl(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:02:00 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/12 15:20:38 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

int     main(int ac, char **av, char **env);
int     no_file(char **av);
char    *ft_getenv(char **env);
void    exit_error(int n);

char *get_path(char *cmd, char *path);

char    *ft_getenv_function(char *cmd, char **path);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	*free_array(char **array);
char	*if_null(char **array, int a);
char	*save_words(const char *s, char c);
int	count_words(char const *str, char c);
void    ft_free(char **delete);
#endif
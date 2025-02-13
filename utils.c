/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:04:20 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/13 11:39:50 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    exit_error(int n)
{
    if (n == 1)
        ft_putstr_fd("./pipe infile cmd cmd outfile\n", 2);
    exit (0);
}
char    *ft_getenv(char **env)
{
    int     i;
    char *path;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
        {
            path = env[i] + 5;
            return (path);
        }
        i++;
    }
    return (NULL);
}
char *get_path(char *cmd, char *path)
{
    int i = 0;
    char **paths;
    char *full_path;

    paths = ft_split(path, '/');

    i = 0;
    while (paths[i])
    {
        full_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
        full_path = ft_strjoin(path, cmd);
        //ft_putstr_fd(full_path, 2);
        //ft_putstr_fd("\n", 2);
        if (access("/bin", R_OK) == 0)
        {
            ft_free(paths);
            ft_putstr_fd(full_path, 2);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    ft_free(paths);
    return (NULL);
}
int     no_file(char **av)
{
    if (open(av[1], O_RDONLY) == -1)
        return (1);
    if (open(av[4], O_RDONLY) == -1)
        return (1);
    return (0);
}
void    ft_free(char **delete)
{
    size_t i;
    
    i = 0;
    while (delete[i])
    {
        free(delete[i]);
        i++;
    }
    free(delete);
}


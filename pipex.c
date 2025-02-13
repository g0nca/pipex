/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:07:24 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/13 13:50:21 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    exec(char *cmd, char **env)
{
    char **command;
    char *path;
    char *test;

    command = ft_split(cmd, ' ');
    path = ft_getenv(env);
    test = get_path(command[0], path);
    ft_putstr_fd(test, 2);
    ft_printf("test");
    if (execve(test, command, env) == -1)
    {
        ft_putstr_fd("\npipex:command not found:\n", 2);
        ft_free(command);
        exit(0);
    }
}

void    child(char **av, int *p_fd, char **env)
{
    int     fd;
    fd = open(av[1], 0);
    dup2(fd, 0);
    dup2(p_fd[1], 1);
    close(p_fd[0]);
    exec(av[2], env);
}

int     main(int ac, char **av, char **env)
{
    int p_fd[2];
    pid_t   pid;
    
    if (no_file(av) == 1 || ac != 5)
        exit(1);
    if (pipe(p_fd) == -1) //The function pipe create 2 file descriptors, one for read and one for write
        exit(1);
    pid = fork();
    if (pid == -1)
        exit(-1);
    if (pid == 0)
    {
        printf("Child\n");
        child(av, p_fd, env);
    }
    else
    {
        wait(NULL);
        printf("Parent\n");
    }
    return (0);
}

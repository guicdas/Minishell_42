/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:25:40 by gcatarin          #+#    #+#             */
/*   Updated: 2024/02/26 13:56:53 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp_env(char *key, char *str)
{
	int	i;

	i = 0;
	while (str[i] == key[i])
	{
		if (str[i] == key[i] && !key[i + 1] && \
		(str[i + 1] == '\0' || str[i + 1] == '='))
			return (i + 1 + (str[i + 1] == '='));
		i++;
	}
	return (0);
}

char	*get_env(t_shell *s, char *key)
{
	int		i;
	size_t	key_len;

	i = 0;
	while (s->env[i])
	{
		key_len = ft_strlen(key);
		if (ft_strncmp(s->env[i], key, key_len) == 0 && \
		s->env[i][key_len] == '=')
			return (s->env[i] + key_len + 1);
		i++;
	}
	return ("");
}

void	set_env(char **env, char *key, char *value)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = ft_strncmp_env(key, env[i]);
		if (j)
		{
			free(env[i]);
			if (value)
			{
				key = ft_strjoin(key, "=");
				env[i] = ft_strjoin(key, value);
				free(key);
			}
			else
				env[i] = ft_strdup(key);
			break ;
		}
		i++;
	}
}

int	env_cmd(t_cmd *cmd, t_shell *s, int in, int out)
{
	int		i;

	i = 0;
	(void) in;
	(void) cmd;
	if (cmd->args[1])
	{
		ft_putstr_fd("env: \'", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd("\': No such file or directory\n", 2);
		return (32512);
	}
	while (s->env[i])
	{
		ft_putstr_fd(s->env[i++], out);
		ft_putstr_fd("\n", out);
	}
	return (0);
}

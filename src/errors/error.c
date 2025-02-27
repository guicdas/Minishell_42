/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:13:26 by gcatarin          #+#    #+#             */
/*   Updated: 2024/02/24 18:58:17 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	invalid_name_error(t_shell *shell, char *s)
{
	shell->status = 1;
	ft_putstr_fd("Minishell: export: \'", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
}

void	cmd_not_found_error(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": command not found\n", 2);
}

int	invalid_file_error(char *s1, char *s2)
{
	if (s2[0] == '$')
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(s2, 2);
		ft_putstr_ln(": ambiguous redirect", 2);
		return (0);
	}
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_ln(s1, 2);
	return (1);
}

void	ctrl_d_error(char *s)
{
	ft_putstr_fd("Minishell: warning: here-document ", 2);
	ft_putstr_fd("delimited by end-of-file (wanted \"", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\")", 2);
	ft_putstr_fd("\n", 2);
}

void	cd_error(char *s)
{
	ft_putstr_fd("Minishell: cd: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_ln(strerror(errno), 2);
}

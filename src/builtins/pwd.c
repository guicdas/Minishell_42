/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:36 by gcatarin          #+#    #+#             */
/*   Updated: 2024/02/25 16:09:39 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_cmd(t_cmd *cmd, t_shell *s, int in, int out)
{
	(void) in;
	(void) cmd;
	ft_putstr_fd(get_env(s, "PWD"), out);
	ft_putstr_fd("\n", out);
	return (0);
}

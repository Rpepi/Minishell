/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:38:33 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/06 22:17:17 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*prompt(t_env *env)
{
	char	*input;

	setup_shell_signals();
	while (1)
	{
		input = readline("\033[1;32mminishell $ \033[0m");
		if (!input)
		{
			ft_putstr_fd("exit\n", 1);
			reset_signals();
			return (NULL);
		}
		if (input[0] != '\0' && check_input(env, input))
		{
			execute_line(env, input);
			add_history(input);
			free(input);
		}
		else
			free(input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	**env_tmp;

	(void)argc;
	(void)argv;
	if (argc != 1)
		return (1);
	env_tmp = ft_malloc_strcpy_array(envp);
	if (!env_tmp)
		return (EXIT_FAILURE);
	env = init_env(env_tmp);
	setup_shell_signals();
	prompt(env);
	reset_signals();
	free_env(env);
	return (0);
}

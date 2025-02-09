/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:44:48 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/06 22:30:34 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

///# include "debug/malloc_debug.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define TOKEN_NULL 0
# define TOKEN_BLANK 1
# define TOKEN_WORD 2
# define TOKEN_SINGLE_QUOTE 3
# define TOKEN_DOUBLE_QUOTE 4
# define TOKEN_PARANTHESIS 5
# define TOKEN_COMMAND 6
# define TOKEN_BUILT_IN 7
# define TOKEN_BINARY 8
# define TOKEN_FLAGS 9
# define TOKEN_ARGUMENT 10
# define TOKEN_VARIABLE 11
# define TOKEN_FILE 12
# define TOKEN_REDIRECTION 16
# define TOKEN_PIPE 17
# define TOKEN_INPUT_CHEVRON 18
# define TOKEN_OUTPUT_CHEVRON 19
# define TOKEN_APPEND_CHEVRON 20
# define TOKEN_HERE_DOC 21
# define TOKEN_BOOLEAN 22
# define TOKEN_LIMITER 23

typedef struct s_token
{
	void			*class;
	int				id;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_arg
{
	char			*content;
	int				id;
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_arg;

typedef struct s_cmd
{
	int				id;
	char			*content;
	char			**args;
	char			*bin;
	char			*arg;
	int				fd_in;
	int				fd_out;
	t_arg			*first_arg;
	int				pid;

}					t_cmd;

typedef struct s_var
{
	int				index;
	int				id;
	char			*name;
	char			*value;
	struct s_var	*next;
	struct s_var	*prev;

}					t_var;

typedef struct s_env
{
	char			**env_variable;
	t_token			*first_token;
	t_var			*first_var;
	char			*bin;
	int				nb_cmd;
	int				error_in_parsing;
	int				**pipes;
	int				return_value;
	int				last_exit_status;

}					t_env;

typedef struct s_file
{
	char			*name;

}					t_file;

typedef struct s_word
{
	int				id;
	char			*content;

}					t_word;

typedef struct s_redir
{
	int				fd_in;
	int				fd_out;
	int				type;
	char			*limiter;
	char			*file_name;
	char			*content;

}					t_redir;

/* main */
void				*prompt(t_env *env);
int					check_input(t_env *env, char *input);
int					check_open_quotes(char *input);
void				execute_line(t_env *env, char *input);
int					check_parsing(t_env *env);
int					check_word_without_cmd(t_env *env);
int					check_token_cmd_next_pipe(t_env *env);

/* signal*/
void				setup_signals(void);
void				reset_signals(void);
void				handle_sigint(int sig);
void				setup_child_signals(void);
void				setup_shell_signals(void);
void				ignore_sigint(void);

/*libft utils*/
void				ft_free_dtab(char **tab);
char				*ft_malloc_substrcpy(char *origin, int start, int end);
char				*ft_malloc_strcpy(char *origin);
char				**ft_malloc_strcpy_array(char **origin);
char				*ft_strjoin_inter(char *s1, char *s2, char c);
char				*ft_strjoin_inter_str(char *s1, char *s2, char *content);
int					ft_ismaj(int c);
int					is_letter(char c);
int					ft_strlen_int(char *str);
int					ft_same(char *s1, char *s2);
char				*cmd_list_to_string(t_cmd *cmd);

/*init env*/
t_env				*init_env(char **env_tab);
t_var				*init_variable(char *name, char *value, int id);
void				connect_var(t_var *curr_var, t_var *next_var);
void				connect_token(t_token *curr_token, t_token *next_token);
void				connect_arg(t_arg *curr_arg, t_arg *next_arg);
void				connect_new_var(t_var *prev_var, t_var *curr_var,
						t_var *next_var);
void				add_var(t_env *env, char **env_variable);
void				add_variables_list(t_env *env, t_var *var);
char				*get_variable_name(char *variable);
char				*get_variable_value(char *variable);
t_var				*get_first_env_var(t_env *env);

/*parsing*/
t_token				*init_token(void);
t_cmd				*init_cmd(char *content, int id);
t_arg				*init_arg(char *content, int id);
void				extract_new_content(char *content, char *new_content,
						int start, int end);
void				string_detection(char *line, int *i);
int					find_dollar_word(t_env *env, char *content, int end);
int					find_type_arg(char *content);
t_var				*get_first_env_var(t_env *env);
char				*get_env_var_value(t_env *env, char *name);
t_var				*get_env_var_name(t_env *env, char *name);
t_token				*get_first_token(t_env *env);
t_cmd				*get_first_cmd(t_env *env);
t_token				*init_token(void);
t_cmd				*init_cmd(char *content, int id);
t_file				*init_file(char *name);
t_word				*init_word(char *content, int id);
int					replace_var(t_env *env, char *content, int start, int end);
char				*echange_variable(t_env *env, char *content);
char				*replace_var_basic(t_env *env, char *content);
char				*delete_content(char *content, int start, int end);
char				*replace_value(char *content, int start, int end,
						char *value);
int					find_dollar_variable(char *content);
char				*variable_dollar_check(t_env *env, char *content);
int					check_is_output(char *content, int start, int end);

/* tokenize */
void				tokenize_line(t_env *env, char *line);
void				class_string(t_env *env, char *line, int *index);
void				class_redir(t_env *env, char *line, int *index);
t_token				*create_token_redir(char *line, int index, int *new_index);
void				redirection_detection(char *line, int *index);
void				tokenize_cmd(t_env *env, char *content, char *line,
						int *index);
void				tokenize_arg(t_env *env, t_cmd *cmd, char *line,
						int *index);
void				add_token_list(t_env *env, t_token *token);
t_token				*create_token_file(char *name, int id);
t_token				*file_tokenizer(t_env *env, char *name, int id);
void				file_extraction(t_env *env, t_token *token, char *line,
						int *index);
int					find_file_index(char *line, int index, int new_index);
int					file_end_detection(char *line, int index, int new_index);
void				file_detection(t_env *env, char *line, int *i);
void				next_file_tokenizer(t_env *env, char *line, int *index);
int					check_only_spaces_or_tabs(char *input);
int					arg_redirect_extraction(t_env *env, t_token *token,
						char *line, int index);
void				connect_token(t_token *curr_token, t_token *next_token);
void				connect_var(t_var *curr_var, t_var *next_var);
int					type_of_redirect(char *content);
t_redir				*init_redirection(int type, char *content);
void				add_arg_list(t_cmd *cmd, t_arg *arg);
void				*get_class(t_token *token);
void				extract_new_content(char *content, char *new_content,
						int start, int end);
void				find_start_end_indices(char *content, int *start, int *end);
void				handle_heredoc(t_redir *redir, char *line, int *index);
void				handle_append(t_redir *redir, char *line, int *index);
void				handle_input_chevrons(t_redir *redir, char *line,
						int *index);
void				handle_output_chevrons(t_redir *redir, char *line,
						int *index);
void				handle_redir_arg(t_redir *redir, char *content, char *line,
						int *index);
char				*handle_double_quote(t_env *env, char *content);
char				*echange_variable_next(t_env *env, char *content,
						int start);
int					content_have_still_variable(char *new_content, int start);
int					find_end_variable(char *content, int start);
void				find_next_file(t_env *env, t_redir *redir, char *line,
						int *index);
char				*remove_quote_from_content(char *content);
int					find_end_dollar_word(char *content, int index, int *flag);
int					is_different_type(char *content, int index, int *flag);
char				*check_arg(t_env *env, char *content);
int					find_end_arg(char *line, int index);
int					find_end_quote(char *content, int start);
char				*handle_dollar_word(t_env *env, char *content);
char				*get_name_without_dollar(char *content);
int					find_end_dollar_word(char *content, int index, int *flag);
int					is_different_type_quote(char *content, int index);
int					is_different_type(char *content, int index, int *flag);
int					check_consecutive_redir(char *input);
void				check_inversion_redir(t_env *env);
int					check_redir_error(char *input);
void				check_token_word(t_env *env);
int					handle_output_redirection_ofile(int new_fd);
char				*handle_dollar_var(t_env *env, char *content,
						int *i, int len);

/* is */
char				**get_env_bins(t_env *env);
t_token				*get_last_token(t_env *env);
int					test_bin_access(char **bins, char *word);
int					test_absolute_bin_access(char *path);
int					is_built_in(char *content);
int					is_bin(t_env *env, char *word);
int					is_not_finish(char c);
int					is_finish(char c);
int					is_cmd(t_env *env, char *word);
int					is_dollar_word(char *line, int i);
int					contain_dollar_word(t_env *env, char *content);
int					is_file(char *line, int i);
int					is_flag_arg(char *line, int i);
int					is_flag(char *str);
int					is_in_double_quote(char *content);
int					is_in_single_quote(char *content);
int					is_in_quotes(char *content);
int					is_token_cmd(t_token *token);
int					is_metachar(char c);
int					is_token_file(t_token *token);
int					is_token_word(t_token *token);
int					is_token_redirection(t_token *token);
int					is_token_input_chevron(t_token *token);
int					is_metachar(char c);
int					is_in_double_quote(char *content);
int					is_in_quotes(char *content);
int					is_in_single_quote(char *content);
int					is_pipe(char *line, int i);
int					is_redir(char *line, int i);
int					is_file_redir(char *line, int i);
int					is_argument_separator(t_env *env, char *line, int index);
int					is_token_basic_redirection(t_token *token);
int					is_basic_redirection_token(int token_id);
int					is_token_append_chevron(t_token *token);
int					is_double_quote(char c);
int					is_single_quote(char c);
int					is_quote(char c);
int					is_after_redirect(char *line, int index);
int					is_output_chevrons(char *line, int i);
int					is_input_chevrons(char *line, int i);
int					is_append_chevrons(char *line, int i);
int					is_heredoc(char *line, int i);
int					is_separator(char *line, int i);
int					is_delimiter(char *line, int index);
int					is_variable_delimiter(char *line, int index);
int					is_blank(char c);
int					is_blank_before_finish(char *line, int index);
int					*blank_escape(char *line, int *index);
int					is_variable_word(char *line, int i);
int					variable_exist(t_env *env, char *name);
char				*variable_name_extraction(char *line, int index);
int					is_variable(t_env *env, char *line, int i);
int					is_string(char *line, int i);
int					is_echo(t_cmd *cmd);
int					is_cd(t_cmd *cmd);
int					is_pwd(t_cmd *cmd);
int					is_env(t_cmd *cmd);
int					is_export(t_cmd *cmd);
int					is_unset(t_cmd *cmd);
int					is_exit(t_cmd *cmd);
int					contain_dollar_word(t_env *env, char *content);
int					is_path(const char *path);
int					is_absolute_path(const char *path);
int					is_relative_path(const char *path);
int					cmd_have_args(t_cmd *cmd);

/* free */
void				free_tokens(t_env *env);
void				free_env(t_env *env);
void				free_var(t_var *var);
void				ft_free(char *input, t_env *env, t_token *token);
void				free_file(t_file *file);
void				free_redir(t_redir *redir);
void				free_cmd(t_cmd *cmd);
void				free_word(t_word *word);
void				free_token_class(t_token *token);
void				free_env_var(t_var *var);
void				free_env(t_env *env);
void				free_arg(t_arg *arg);

char				*convert_relative_path(t_env *env, char *relative_path);
void				execution(t_env *env);
char				**get_next_args_in_array(t_cmd *cmd);
char				*get_bin(t_cmd *cmd, t_env *env);
char				**get_env_vars(t_var *var);
void				free_string_array(char **array);
int					is_word(char *word);
t_var				*update_var_value_with_name(t_env *env, char *name,
						char *new_value);
int					is_accessible_directory(char *path);
void				free_get_env_vars(char **array);
void				print_args(char **strings);
int					is_standard_cmd_fd(t_cmd *cmd);
int					is_standard_fd(int fd);
t_token				*get_next_cmd(t_token *token);
t_token				*get_first_cmd_token(t_token *token);
int					get_nb_cmds(t_token *token);
int					**init_pipes(t_env *env, int nb_cmds);
void				quit_program(t_env *env);
int					change_fd_pipes(t_env *env, t_token *token, int index);
void				close_pipes(t_env *env);
void				collect_children(t_env *env, t_token *last_cmd_token);
void				close_unused_pipes(t_env *env, int index);
int					has_redir(t_token *token, char *content);
int					open_files(t_token *token, t_env *env);
void				free_all_tokens(t_token *token);

/* built in and exec */
int					exec_pwd(void);
int					exec_cd(t_env *env, t_cmd *cmd);
int					exec_echo(t_cmd *cmd);
int					exec_export(t_env *env, t_cmd *cmd);
char				*cmd_list_to_string(t_cmd *cmd);
void				print_all_env_export_var_fd(t_env *env, int fd);
char				*get_export_variable_name(char *variable);
void				change_or_create_var(t_env *env, char *name, char *value,
						int flag);
int					assign_env_var_flag(char *value);
t_var				*get_last_env_var(t_env *env);
void				add_new_env_variable(t_env *env, t_var *new);
int					variable_exist(t_env *env, char *name);
void				change_env_var_value_with_name(t_env *env, char *name,
						char *value);
void				rl_replace_line(const char *text, int clear_undo);
int					exec_env(t_env *env, t_cmd *cmd);
int					exec_exit(t_env *env, t_cmd *cmd);
void				print_exported_vars(t_env *env);
int					exec_unset(t_env *env, t_cmd *cmd);
char				*get_value_arg(t_arg *arg, int *index);
int					check_is_value(char *str);
char				*get_name_arg(t_arg *arg, int *index);
int					str_compare(const char *a, const char *b);
int					here_doc(t_redir *redir, t_env *env);
void				wait_for_process(t_env *env, int pid);
void				wait_all_children(t_env *env);
int					is_part_of_pipeline(t_token *token);
void				cleanup_pipes(int **pipes, int count);
int					open_file(t_redir *redir, int prev_fd, int flags,
						mode_t permissions);
int					open_here_doc(t_redir *redir, t_env *env);
int					handle_input_redirection(t_env *env, t_token *token,
						int index);
t_token				*get_next_redir_token(t_token *token);
int					handle_redirection(t_redir *redir, int *fd_in,
						int *fd_out, t_env *env);
char				*ft_strjoin_free(char *s1, char const *s2);
int					handle_only_redir(t_token *token, t_env *env);
int					exec_built_in(t_env *env, t_cmd *cmd);
void				exec_bin_cmd(t_env *env, t_cmd *cmd, int index);
void				execute_builtin(t_env *env, t_cmd *cmd, int is_pipeline,
						int index);
char				*expand_heredoc_line(char *line, t_env *env);

#endif
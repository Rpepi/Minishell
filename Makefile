# Nom de l'exécutable
NAME = minishell

# Compilateur et options
CC = gcc -Wall -Wextra -Werror -g
INCLUDES = -I/opt/homebrew/opt/readline/include -I./libft
LDFLAGS = -L/opt/homebrew/opt/readline/lib -lreadline -g -fsanitize=address
#LDFLAGS = -L/usr/local/opt/readline/lib -lreadline -fsanitize=address
#LDFLAGS = -L/usr/local/opt/readline/lib -lreadline #-fsanitize=address
#INCLUDES = -I/Users/$(USER)/.brew/opt/readline/include -I./libft
#LDFLAGS = -L/Users/$(USER)/.brew/opt/readline/lib -lreadline #-fsanitize=address

# Couleurs pour l'affichage
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

# Sources
SRC_DIR = src
TOKENIZER_DIR = $(SRC_DIR)/tokenizer
ARGS_DIR = $(TOKENIZER_DIR)/args
IS_DIR = $(SRC_DIR)/is
ENV_DIR = env
GET_DIR = $(SRC_DIR)/get
EXECUTION_DIR = $(SRC_DIR)/execution
BUILT_IN_DIR = $(EXECUTION_DIR)/built_in
LIBFT_UTILS_DIR = libft_utils

SRCS = $(SRC_DIR)/main.c \
    $(SRC_DIR)/init_class.c \
    $(SRC_DIR)/free/free_class.c \
    $(SRC_DIR)/signals.c \
    $(SRC_DIR)/free/free.c \
    $(SRC_DIR)/execute_line.c \
    $(SRC_DIR)/check_parsing.c \
    $(SRC_DIR)/check_token_cmd_next_pipe.c \
    $(SRC_DIR)/detection.c \
    $(SRC_DIR)/class_string.c \
    $(SRC_DIR)/class_redir.c \
    $(SRC_DIR)/handle_heredoc.c \
    $(SRC_DIR)/check_input.c \
    $(SRC_DIR)/chaine.c \
    $(SRC_DIR)/casting.c \
    $(SRC_DIR)/connect.c \
    $(SRC_DIR)/add_token_word.c \
    $(SRC_DIR)/check_input_utils.c \
    $(SRC_DIR)/check_redir_error.c \
    $(SRC_DIR)/check_word_cmd.c \
    $(SRC_DIR)/utils/convert_relative_path.c \
	$(SRC_DIR)/quit_program.c \
	$(SRC_DIR)/get/get_cmd.c \
	$(SRC_DIR)/execution/here_doc.c \
	$(SRC_DIR)/inversion_redir.c \
	$(SRC_DIR)/is/is_token_pipe.c \
    $(TOKENIZER_DIR)/cmd_tokenizer.c \
    $(TOKENIZER_DIR)/create_token.c \
    $(TOKENIZER_DIR)/file_tokenizer.c \
    $(ARGS_DIR)/add_args_list.c \
    $(ARGS_DIR)/find_type_arg.c \
    $(ARGS_DIR)/tokenize_args.c \
    $(IS_DIR)/is_arg.c \
    $(IS_DIR)/is_basic_redirection.c \
    $(IS_DIR)/is_bins.c \
    $(IS_DIR)/is_blank.c \
    $(IS_DIR)/is_in.c \
    $(IS_DIR)/is_built_in.c \
    $(IS_DIR)/is_cmd_arg.c \
    $(IS_DIR)/is_cmd.c \
    $(IS_DIR)/is_fd.c \
    $(IS_DIR)/is_file.c \
    $(IS_DIR)/is_line.c \
    $(IS_DIR)/is_finish.c \
    $(IS_DIR)/is_quote.c \
    $(IS_DIR)/is_redirection.c \
    $(IS_DIR)/get_first.c \
    $(IS_DIR)/is_same.c \
    $(IS_DIR)/is_separator.c \
    $(IS_DIR)/is_token_cmd.c \
    $(IS_DIR)/is_token_redirection.c \
    $(IS_DIR)/is_token.c \
    $(IS_DIR)/is_variable.c \
    $(IS_DIR)/is_dollar_word.c \
    $(IS_DIR)/is.c \
    $(IS_DIR)/is_metachar.c \
    $(IS_DIR)/cmd_have.c \
    $(IS_DIR)/have.c \
    $(IS_DIR)/is_path.c \
    $(IS_DIR)/is_word.c \
    $(ENV_DIR)/create_chained_env.c \
    $(ENV_DIR)/get_env.c \
    $(ENV_DIR)/init_env.c \
    $(GET_DIR)/get_env.c \
    $(GET_DIR)/get_arg.c \
    $(GET_DIR)/get_last_token.c \
    $(EXECUTION_DIR)/execution.c \
    $(GET_DIR)/get_bin.c \
    $(SRC_DIR)/free/free_array.c \
    $(BUILT_IN_DIR)/pwd.c \
    $(BUILT_IN_DIR)/cd.c \
    $(ENV_DIR)/utils/add_var.c \
    $(IS_DIR)/is_accessible_directory.c \
    $(BUILT_IN_DIR)/echo.c \
    $(BUILT_IN_DIR)/export.c \
    $(BUILT_IN_DIR)/export_2.c \
    $(BUILT_IN_DIR)/export_utils.c \
    $(BUILT_IN_DIR)/unset.c \
    $(BUILT_IN_DIR)/env.c \
    $(BUILT_IN_DIR)/exit.c \
    $(IS_DIR)/is_standard_fd.c \
    $(LIBFT_UTILS_DIR)/free_utils.c \
    $(LIBFT_UTILS_DIR)/malloc_utils.c \
    $(LIBFT_UTILS_DIR)/utils.c \
    $(LIBFT_UTILS_DIR)/utils_2.c \
    $(LIBFT_UTILS_DIR)/utils_3.c \
    $(EXECUTION_DIR)/pipe.c \
	$(EXECUTION_DIR)/process.c \
	$(EXECUTION_DIR)/clean_pipes.c \
	$(EXECUTION_DIR)/open_files.c \
	$(EXECUTION_DIR)/handle_only_redir.c \
	$(EXECUTION_DIR)/exec_cmd.c \
	$(EXECUTION_DIR)/hereroc_dollar_var.c \
	$(TOKENIZER_DIR)/args/variable_utils.c \
	$(TOKENIZER_DIR)/args/check_arg.c \
	$(TOKENIZER_DIR)/args/check_arg_utils.c \
	$(EXECUTION_DIR)/redirection.c \
	$(EXECUTION_DIR)/exec_builtin.c \
	$(SRC_DIR)/free/free_executed_cmd.c \
	$(LIBFT_UTILS_DIR)/ft_strjoin_free.c

OBJS = $(SRCS:.c=.o)

# Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Règles
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(YELLOW)Compilation de $@...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $@ > /dev/null
	@echo "$(GREEN)$@ compilé avec succès !$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ > /dev/null

$(LIBFT):
	@echo "$(YELLOW)Compilation de libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null

clean:
	@echo "$(YELLOW)Nettoyage des fichiers objets...$(RESET)"
	@rm -f $(OBJS) > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "$(YELLOW)Suppression de $(NAME)...$(RESET)"
	@rm -f $(NAME) > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re

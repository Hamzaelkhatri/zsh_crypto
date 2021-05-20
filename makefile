NAME_CRYPTO= crypto
SRC_PATH= .
HDR_PATH= .
OBJ_PATH= obj
LIB_PATH= libft

SRC_NAME=crypto.c ftoa.c
HDR_NAME=crypto.h 

OBJ_NAME= $(SRC_NAME:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIB= libft.a
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a
H_FLAG= -I $(HDR_PATH)

COMP= gcc

# FLAGS = -Wall -Wextra -Werror

all: lib $(NAME_CHECKER) $(NAME_CRYPTO) 

$(NAME_CRYPTO) : $(LIB_PATH)/$(LIB) $(OBJ)
	@rm -rf crypto
	@$(COMP) -g $(H_FLAG) $(OBJ) $(LLIB_FLAG) -lm -o $@
	@echo "						Compilation of $(NAME_CRYPTO):  \033[1;32mOK\033[m"

lib:
	@make -sC $(LIB_PATH)

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH)
	@$(COMP) -g $(FLAGS) $(H_FLAG) -lm -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m" 

fclean: clean
	@rm -rf $(NAME_CRYPTO)
	@make fclean -C $(LIB_PATH)
	@echo "\033[0;31m>> $(NAME_CRYPTO) && all objects are deleted.\033[0m" 

re : fclean all
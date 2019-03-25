# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkettani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:15:50 by jkettani          #+#    #+#              #
#    Updated: 2019/03/25 16:55:33 by jkettani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- VARIABLES -----

NC =               \x1b[0m
OK_COLOR =         \x1b[32;01m
ERR_COLOR =        \x1b[31;01m
WARN_COLOR =       \x1b[34;01m
QUIET :=           @
ECHO :=            @echo
ifneq ($(QUIET),   @)
ECHO :=            @true
endif
SHELL =            /bin/sh
MAKEFLAGS +=       --warn-undefined-variables
NAME =             test
SRC_PATH =         .
INC_PATH =         .
OBJ_PATH =         .obj
TEST_PATH =        .
TEST_SRC =         $(TEST_PATH)/main.c
LFT_PATH =         libft
LFT_INC_PATH =     $(LFT_PATH)/includes
LFT_NAME =         libft.a
LFT =              $(LFT_PATH)/$(LFT_NAME)
RM =               rm -f
RMDIR =            rmdir
AR =               ar
ARFLAGS =          -rcs
CC =               gcc
LEAK_TYPE :=       summary
ifeq ($(LEAK_TYPE), full)
LEAK_TYPE :=        full
else
LEAK_TYPE :=		summary
endif
VALFLAGS =         --leak-check=$(LEAK_TYPE)
CERRFLAGS =        -Wall -Wextra
CFLAGS =           -g3 -Werror -Wall -Wextra
CPPFLAGS =         -I$(LFT_INC_PATH) -I$(INC_PATH)
DEPFLAGS =         -MT $@ -MMD -MP -MF $(OBJ_PATH)/$*.d
LIBFLAGS =         -L$(LFT_PATH) -lft
COMPILE.c =        $(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c
POSTCOMPILE =      touch $@
SRC_NAME =     	   main get_next_line
SRC =              $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(SRC_NAME)))
OBJ =              $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))
DEP =              $(addprefix $(OBJ_PATH)/, $(SRC:.c=.d))
OBJ_TREE =         $(shell find $(OBJ_PATH) -type d -print | sort -r \
				   2> /dev/null)

.SUFFIXES:
.SUFFIXES: .c .o .h

# ----- RULES -----

.PHONY: all
all: $(NAME)

.PRECIOUS: $(OBJ_PATH)%/. $(OBJ_PATH)/. 
$(OBJ_PATH)/. $(OBJ_PATH)%/.: 
	$(ECHO) "Making directory $(WARN_COLOR)$@$(NC)..."
	$(QUIET) mkdir -p $@

$(OBJ_PATH)/%.d: ;

.SECONDEXPANSION:

$(OBJ): $(OBJ_PATH)/%.o: %.c $(OBJ_PATH)/%.d | $$(@D)/.
	$(ECHO) "Compiling $(WARN_COLOR)$<$(NC)..."
	$(QUIET) $(COMPILE.c) $< -o $@
	$(QUIET) $(POSTCOMPILE)

$(NAME): $(OBJ) $(LFT)
	$(ECHO) "Compiling $(WARN_COLOR)$@$(NC)..."
	$(QUIET) $(CC) $(CFLAGS) $(CPPFLAGS) $(LIBFLAGS) $(OBJ) -o $@

$(LFT): force_rule
	$(ECHO) "Compiling $(WARN_COLOR)$(LFT)$(NC) if necessary..."
	$(QUIET) make -C $(LFT_PATH)

force_rule:

.PHONY: norminette
norminette: 
	norminette $(SRC_PATH)
	norminette $(INC_PATH)

.PHONY: clean
clean:
	$(ECHO) "Cleaning object files..."
	$(QUIET) $(RM) $(OBJ)
	$(ECHO) "Cleaning dependency files..."
	$(QUIET) $(RM) $(DEP)
	$(ECHO) "Cleaning obj tree..."
	$(QUIET) echo $(OBJ_TREE) | xargs $(RMDIR) 2> /dev/null || true
	@if [ -d $(OBJ_PATH) ]; \
		then echo "$(ERR_COLOR)-> Could not clean obj directory.$(NC)"; \
		else echo "$(OK_COLOR)-> Obj directory succesfully cleaned.$(NC)"; fi

.PHONY: fclean
fclean: clean
	$(ECHO) "Cleaning $(NAME)..."
	$(QUIET) $(RM) $(NAME)
	@if [ -f $(NAME) ]; \
		then echo "$(ERR_COLOR)-> Could not clean $(NAME).$(NC)"; \
		else echo "$(OK_COLOR)-> $(NAME) succesfully cleaned.$(NC)"; fi

.PHONY: re
re: fclean all

# ----- INCLUDES -----

-include $(DEP)

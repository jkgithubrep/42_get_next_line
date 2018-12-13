# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkettani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:15:50 by jkettani          #+#    #+#              #
#    Updated: 2018/12/09 16:42:46 by jkettani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := libft.a
FT := ft_
SRC_PATH := .
INCLUDE_PATH := .
OBJ_PATH := obj
DEP_PATH := .deps
RM := rm -rf
AR := ar
ARFLAGS := -rcs
CC := gcc
CFLAGS := -Werror -Wall -Wextra
CPPFLAGS = -I$(INCLUDE_PATH)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_PATH)/$*.Td
POSTCOMPILE = @mv -f $(DEP_PATH)/$*.Td $(DEP_PATH)/$*.d && touch $@
SRC_NAME :=	atoi bzero count_words_c isalnum isalpha isascii \
			isblank iscntrl isdigit isgraph islower isprint \
			isspace isupper isxdigit itoa itoa_base lstadd \
			lstdel lstdelone lstiter lstmap lstnew memalloc \
			memccpy memchr memcmp memcpy memdel memmove \
			memset print_bytes putchar putchar_fd putendl putendl_fd \
			putnbr putnbr_base putnbr_fd putstr putstr_fd strcat \
			strchr strclr strcmp strcpy strdel strdup \
			strdup_c strequ striter striteri strjoin strlcat \
			strlen strmap strmapi strncat strncmp strncpy \
			strnequ strnew strnstr strrchr strsplit strstr \
			strsub strtrim tolower toupper 
SRC = $(addprefix $(SRC_PATH)/$(FT),$(addsuffix .c, $(SRC_NAME)))
OBJ = $(addprefix $(OBJ_PATH)/$(FT),$(addsuffix .o, $(SRC_NAME)))
DEP = $(addprefix $(DEP_PATH)/$(FT),$(addsuffix .d, $(SRC_NAME)))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $?

$(OBJ): | $(OBJ_PATH) $(DEP_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEP_PATH)/%.d
	$(COMPILE.c) $< -o $@ 
	$(POSTCOMPILE)

$(DEP_PATH)/%.d: ;

$(OBJ_PATH):
	mkdir $@

$(DEP_PATH):
	mkdir $@

.PHONY: clean
clean:
	$(RM) $(OBJ_PATH)
	$(RM) $(DEP_PATH)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PRECIOUS: $(DEP_PATH)/%.d

include $(wildcard $(DEP))

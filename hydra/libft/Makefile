# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/06 21:20:54 by timfuzea     #+#   ##    ##    #+#        #
#    Updated: 2018/02/16 16:09:37 by timfuzea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

DEBUG		=no

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

#		IN

PWD			:= $(shell pwd)

CONF_PATH	:= $(PWD)/.conf.mk/

INC_PATH	:= $(PWD)/includes/
SRC_PATH	:= $(PWD)/srcs/
OBJ_PATH	:= $(PWD)/obj/

#		EXT

TEMPALT		:= $(ROOT)/.template/lib.mk

# **************************************************************************** #
#									NAME LST                                   #
# **************************************************************************** #

INC_LST	:= libft.h colors.h

SRC_LST	:= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c \
				\
				ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c  ft_strcat.c \
				ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
				ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
				\
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c \
				\
				ft_memalloc.c ft_memdel.c \
				\
				ft_strnew.c ft_strdel.c ft_strclr.c \
				ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
				\
				ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
				ft_strtrim.c ft_strsplit.c ft_itoa.c \
				\
				ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
				\
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				\
				ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
				ft_lstiter.c ft_lstmap.c \
				\
				ft_strndup.c ft_sizeint.c ft_isalspace.c ft_swap.c ft_vswap.c \
				ft_valide_base.c \
				ft_strnew_2d.c ft_strnew_2d.c  ft_putstr_2d.c ft_putendl_2d.c\
				ft_strdel_2d.c ft_strdup_2d.c ft_strequ_2d.c ft_strlen_2d.c \
				ft_putstr_2dfd.c \
				\
				ft_str_isalpha.c ft_str_isdigit.c ft_str_isin.c \
				\
				ft_strjoin_free.c ft_strsplit_free.c ft_strnclr.c ft_memdup.c \
				ft_putnbr_base.c \
				get_next_line.c

# **************************************************************************** #
#									SHELL                                      #
# **************************************************************************** #

$(shell touch $(CONF_PATH)var.mk)
include $(CONF_PATH)var.mk

#				COMPILATION

ifndef CC
	CC		:= /usr/bin/clang 
endif

#			LINK

ifndef LN
	LN			:= /bin/ln 
endif

#			REMOVE

ifndef RM
	RM			:= /bin/rm
endif

ifndef AR
	AR			:= ar
endif

# **************************************************************************** #
#									FLAG                                       #
# **************************************************************************** #

#				DEFAULTS VALUE

ifndef CC_FLAG
ifeq ($(DEBUG),yes)
	CC_FLAG		= -Wall -Werror -Wextra -g3 -ferror-limit=-1 -fsanitize=address
else
	CC_FLAG		= -Wall -Werror -Wextra
endif
endif

ifndef LN_FLAGS
	LN_FLAGS	= -sf
endif

ifndef RM_FLAG
	RM_FLAG		= -rf
endif

ifndef AR_FLAG
	AR_FLAG		= rcs
endif

#				ADD VALUE

ifdef CC_CUS_FLAG
	CC_CUS_FLAG	+= $(CC_CUS_FLAG)
endif

ifdef LN_CUS_FLAGS
	LN_FLAGS	+= $(LN_CUS_FLAG)
endif

ifdef RM_CUS_FLAG
	RM_FLAG		+= $(RM_CUS_FLAG)
endif

ifdef AR_CUS_FLAGS
	AR_FLAG		+= $(AR_CUS_FLAGS)
endif

# **************************************************************************** #
#									VAR                                        #
# **************************************************************************** #

#			IN

NAME			:= $(shell cat $(CONF_PATH)name.mk)
#INC_LST		:= $(shell cat $(CONF_PATH)includes.mk)
#SRC_LST		:= $(shell cat $(CONF_PATH)sources.mk)
OBJ_LST			:= $(SRC_LST:.c=.o)

INC				:= $(addprefix $(INC_PATH),$(INC_LST))
SRC				:= $(addprefix $(SRC_PATH),$(SRC_LST))
OBJ				:= $(addprefix $(OBJ_PATH),$(OBJ_LST))

# **************************************************************************** #
#									STR IN COLOR                               #
# **************************************************************************** #

START			:="\033[0;32mStart\033[0m\n"
END				:="\033[0;32mEnd\033[0;0m\n\n"
OK				:="\033[0;33mOK\033[0;0m\n"

# **************************************************************************** #
#									REGLES                                     #
# **************************************************************************** #

all: $(NAME)

#				RULE INC

ifdef R_INC_PATH
inc_link:
	@printf "link Header $(NAME): "
	@$(LN) $(LN_FLAGS) $(INC) $(R_INC_PATH)
	@printf $(END)
endif

#				RULE LIB

$(NAME): $(OBJ_PATH) $(OBJ)
	@printf "Creation de $(NAME):"
	@$(AR) $(AR_FLAG) $(NAME) $(OBJ)
	@printf $(OK)

#				RULE OBJ

$(OBJ_PATH):
	@printf "Creation de $(OBJ_PATH):"
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@printf $(OK)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)
	@printf "Creation de $(shell basename $@):"
	@$(CC) $(CC_FLAG) -I $(INC_PATH) -o $@ -c $<
	@printf " done\n"

#				RULE CLEAN

clean:
	@printf "Clean des obj:"
	@$(RM) -f $(OBJ)
	@$(RM) -rf $(OBJ_PATH)
	@printf " done\n"

fclean: clean
	@printf "Clean $(NAME):"
	@$(RM) -f $(NAME)
	@printf " done\n"

re: fclean all

#				RULE UPDATE

update: update_clean
	@printf "Update $(NAME): "
	@printf "$(SRC_LST)" > sources.mknew
	@mv Makefile Makefile.mkback
	@cp $(TEMPALT) Makefile
	@printf "done\n"

update_back:
	@printf "Back $(NAME): "
	@if [[ -e ./Makefile.mkback ]] ; then \
		$(RM) $(RM_FLAGS) Makefile ; \
		mv Makefile.mkback Makefile ; \
		printf "done\n" ; \
	else \
		echo -n "no .mkback found in $(NAME)" ; \
	fi

update_clean:
		@$(RM) $(RM_FLAGS) Makefile.mkback
		@$(RM) $(RM_FLAG) sources.mknew

#				RULE OTHER

norme:
	@printf "\tNorme de $(SRC_LST)\n"
	@norminette $(SRC)
	@printf "\tNorme de $(INC_LST)\n"
	@norminette $(INC)

# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    mod.mk                                           .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/12 18:10:57 by timfuzea     #+#   ##    ##    #+#        #
#    Updated: 2018/03/07 14:58:31 by timfuzea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

#		IN

PWD			:= $(shell pwd)

INC_PATH	:= $(PWD)/includes/
OBJ_PATH	:= $(PWD)/obj/
SRC_PATH	:= $(PWD)/srcs/
CONF_PATH	:= $(PWD)/.conf.mk/

TMP			= ""

# **************************************************************************** #
#									NAME LST                                   #
# **************************************************************************** #

INC_LST		:= hydra.h

SRC_LST		:= deflaut_flag.c ft_flagdel.c ft_flagnew.c ft_readsock_del.c \
			   ft_readsock_new.c ft_usage.c init_addrinfo.c main_serveur.c \
			   open_socket.c read_socket.c serveur_parseur.c write_socket.c \
			   daemonize.c reseau.c print_info.c

# **************************************************************************** #
#									SHELL                                      #
# **************************************************************************** #

$(shell touch $(CONF_PATH)var.mk)
include $(CONF_PATH)var.mk

#						DEFAULTS VALUE

#			Compilation
ifndef CC
	ifeq ($(ARCH),Linux)
		CC	:= /bin/gcc
	else
		CC	:= /usr/bin/clang
	endif
endif

#			Link
ifndef LN
	LN		:= /bin/ln 
endif

#			Remove
ifndef RM
	RM		:= /bin/rm 
endif

# **************************************************************************** #
#									FLAGS                                      #
# **************************************************************************** #

#						DEFAULTS VALUE

#			Compilation
ifndef CC_FLAGS
	CC_FLAGS	= -Wall -Werror -Wextra
	ifeq ($(DEBUG),yes)
		CC_FLAGS	+= -g3
		ifeq ($(ARCH),Linux)
			CC_FLAGS	+=
		else
			CC_FLAGS	+= -ferror-limit=-1
		endif
	else
		CC_FLAGS	+= -Ofast
	endif
endif

#			Link
ifndef LN_FLAGS
	LN_FLAGS	= -sf
endif

#			Remove
ifndef RM_FLAGS
	RM_FLAGS	= -rf
endif

#						ADD VALUE

#			Compilationn
ifdef CC_CUS_FLAGS
	CC_FLAGS	+= $(CC_CUS_FLAGS)
endif

#			Link
ifdef LN_CUS_FLAGS
	LN_FLAGS	+= $(LN_CUS_FLAGS)
endif

#				Remove
ifdef RM_CUS_FLAGS
	RM_FLAGS	+= $(RM_CUS_FLAGS)
endif

# **************************************************************************** #
#									VAR                                        #
# **************************************************************************** #

NAME		:= $(shell cat $(CONF_PATH)name.mk)
#INC_LST		:= $(shell cat $(CONF_PATH)includes.mk)
#SRC_LST		:= $(shell cat $(CONF_PATH)sources.mk)
OBJ_LST		:= $(SRC_LST:.c=.o)

INC			:= -I $(INC_PATH) -I $(LIB_INC)
SRC			:= $(addprefix $(SRC_PATH),$(SRC_LST))
OBJ			:= $(addprefix $(OBJ_PATH),$(OBJ_LST))

# **************************************************************************** #
#									RULES                                      #
# **************************************************************************** #


all: $(NAME) copy_root

$(NAME): $(OBJ_PATH) $(OBJ)
	@printf "Creation de $(NAME):"
	@$(CC) $(LIB_SRC) $(OBJ) -o $@
	@printf " OK\n"

copy_root:
	@cp $(NAME) $(ROOT)

#			RULE OBJ

obj: $(OBJ_PATH) $(OBJ)

$(OBJ_PATH):
	@printf "\nCreation de $(NAME)/obj: "
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@printf "OK\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@printf "$(NAME) => $(notdir $@): "
	@$(CC) $(INC) $(CC_FLAGS) -o $@ -c $<
	@printf "done\n"


#			RULE UPDATE

#			RULE CLEAN

clean:
	@printf "Clean $(NAME): "
	@$(RM) $(RM_FLAGS) $(OBJ_PATH)
	@printf "done\n"

fclean: clean
	@printf "Fclean $(NAME)"
	@$(RM) $(RM_FLAGS) $(NAME)
	@printf "done\n"

re: clean all

#			RULE NORME

norme:
	@printf "\t\t NORME $(NAME)\n\n"
	@norminette $(INC)
	@norminette $(SRC)

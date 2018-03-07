# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/16 17:23:50 by timfuzea     #+#   ##    ##    #+#        #
#    Updated: 2018/02/16 18:22:11 by timfuzea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/12 16:20:49 by timfuzea     #+#   ##    ##    #+#        #
#    Updated: 2018/02/16 17:22:27 by timfuzea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

DEBUG		:= no

# **************************************************************************** #
#								PATH                                           #
# **************************************************************************** #

#			IN

PWD			:= $(shell pwd)
ROOT		:= $(PWD)
NO_ERROR	:= 2> /dev/null

#			PATH

CONF_PATH	:= $(PWD)/.conf.mk/
LIB_PATH	:= $(ROOT)/libft/

CLIENT_PATH	:= $(PWD)/client/
SERVEUR_PATH:= $(PWD)/serveur/

#			EXT

ARCH		:= $(shell uname)
ROOT		:= $(PWD)



#			EXPORT

export		ROOT
export		ARCH

# **************************************************************************** #
#								NAME LST                                       #
# **************************************************************************** #

LIB_NAME	:= libft

CLIENT		:= $(shell cat $(CLIENT_PATH).conf.mk/name.mk)
SERVEUR		:= $(shell cat $(SERVEUR_PATH).conf.mk/name.mk)

# **************************************************************************** #
#								VAR                                            #
# **************************************************************************** #

LIB_SRC		:= $(addprefix $(LIB_PATH),libft.a)
LIB_INC		:= $(addprefix $(LIB_PATH),includes)

#			EXPORT

export		LIB_SRC
export		LIB_INC

# **************************************************************************** #
#								SHELL                                          #
# **************************************************************************** #

$(shell touch $(CONF_PATH)var.mk)
include $(CONF_PATH)var.mk

#			Compilation
ifndef CC
	ifeq ($(ARCH),Linux)
		CC	= /bin/gcc
	else
		CC	= /usr/bin/clang
	endif
endif

#			Link
ifndef LN
	LN		= /bin/ln
endif

#			Remove
ifndef RM
	RM		= /bin/rm
endif

#			EXPORT

export		CC
export		LN
export		RM

# **************************************************************************** #
#								FLAGS                                          #
# **************************************************************************** #

#						DEFAULTS VALUE

#			Compilation
ifndef CC_FLAGS
	CC_FLAGS		= -Wall -Werror -Wextra
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
	LN_FLAGS	= -f
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

#			Remove
ifdef RM_CUS_FLAGS
		RM_FLAGS	+= $(RM_CUS_FLAGS)
	endif


#			EXPORT

export		CC_FLAGS
export		LN_FLAGS
export		RM_FLAGS

# **************************************************************************** #
#								COLOR                                          #
# **************************************************************************** #

START		:=\033[0;32mStart\033[0m\n
END			:=\033[0;32mEnd\033[0;0m\n\n
OK			:=\033[0;33mOK\033[0;0m\n\n

# **************************************************************************** #
#								RULES                                          #
# **************************************************************************** #

.PHONY: all client serveur

all: lib client serveur

client: $(LIB_SRC)
	@$(MAKE) -C $(CLIENT_PATH) all

serveur: $(LIB_SRC)
	@$(MAKE) -C $(SERVEUR_PATH) all



#			RULES FOR LIB

.PHONY: lib clean_lib fclean_lib

lib:
	@printf "Creation de $(LIB_NAME).a: $(START)"
	@$(MAKE) -C $(LIB_PATH) all
	@printf "Creation de $(LIB_NAME).a: $(END)"

#		RULES CLEAN

.PHONY: clean_lib clean_client clean_serveur clean

#	clean

clean_lib:
	@$(MAKE) -C $(LIB_PATH) clean

clean_client:
	@$(MAKE) -C $(CLIENT_PATH) clean

clean_serveur:
	@$(MAKE) -C $(SERVEUR_PATH) clean

clean: clean_lib clean_client clean_serveur

#	fclean

.PHONY: fclean_lib fclean_client fc fclean

fclean_lib:
	@$(MAKE) -C $(LIB_PATH) fclean

fclean_client:
	@$(MAKE) -C $(CLIENT_PATH) fclean

fclean_serveur:
	@$(MAKE) -C $(SERVEUR_PATH) fclean

fclean: clean fclean_lib fclean_client fclean_serveur
	@$(RM) $(RM_FLAGS) $(SERVEUR) $(CLIENT)

re: fclean all


#		RULES OTHER

push_clean: fclean
	@printf "\n\t\tLes sources sont ok tu peux git\n"

norme:
	@$(MAKE) $(CLIENT_PATH) RULE=norme
	@$(MAKE) $(SERVEUR_PATH) RULE=norme

# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    mod.mk                                           .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/12 18:10:57 by timfuzea     #+#   ##    ##    #+#        #
#    Updated: 2018/03/13 16:13:41 by timfuzea    ###    #+. /#+    ###.fr      #
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

#		EXT

TEMPALT		:= $(ROOT)/.template/mod.mk

# **************************************************************************** #
#									NAME LST                                   #
# **************************************************************************** #

INC_LST		:=

SRC_LST		:=

LIB_LST		:=

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

INC			:= -I $(R_INC_PATH)
SRC			:= $(addprefix $(SRC_PATH),$(SRC_LST))
OBJ			:= $(addprefix $(OBJ_PATH),$(OBJ_LST))

INC_LINK	:= $(addprefix $(INC_PATH),$(INC_LST))
# **************************************************************************** #
#									RULES                                      #
# **************************************************************************** #


all: obj


#			RULE INC

inc_link:
	@printf "link Header $(NAME): "
	@$(LN) $(LN_FLAGS) $(INC_LINK) $(R_INC_PATH)
	@printf "done\n"


#			RULE OBJ

obj: $(OBJ_PATH) $(OBJ)

$(OBJ_PATH):
	@printf "\nCreation de $(NAME)/obj: "
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@printf "OK\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_LINK)
	@printf "$(NAME) => $(notdir $@): "
	@$(CC) $(INC) $(CC_FLAGS) -o $@ -c $<
	@if [[ "$(findstring $@,$(R_OBJ_LST))" = "" ]] ; then \
		echo "$@" >> "$(R_OBJ_PATH)" ; \
	fi
	@rm -rf $(R_LOCK_LINK) $(NO_ERROR)
	@printf "done\n"


#			RULE UPDATE

update:
	@printf "Update $(NAME): "
	@printf "INC_LST\t\t:=$(INC_LST)\n\nSRC_LST\t\t:=$(SRC_LST)\n" >> sources.mknew
	@$(RM) $(RM_FLAGS) Makefile.mkback $(NO_ERROR)
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
	@$(RM) $(RM_FLAGS) sources.mknew


#			RULE CLEAN

clean:
	@printf "Clean $(NAME): "
	@$(RM) $(RM_FLAGS) $(OBJ_PATH)
	@printf "done\n"

re: clean obj

#			RULE NORME

norme:
	@printf "\t\t NORME $(NAME)\n\n"
	@norminette $(INC)
	@norminette $(SRC)

# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/12 16:20:49 by timfuzea     #+#   ##    ##    #+#        #
#    Updated: 2018/03/13 16:12:35 by timfuzea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

DEBUG		= yes

# **************************************************************************** #
#								PATH                                           #
# **************************************************************************** #

#			IN

PWD			:= $(shell pwd)
ROOT		:= $(PWD)
NO_ERROR	:= 2> /dev/null

#			PATH

CONF_PATH	:= $(PWD)/.conf.mk/

INC_PATH	:= $(PWD)/includes/
LIB_PATH	:= $(ROOT)/libft/

R_INC_PATH	:= $(ROOT)/incs.mk/
R_OBJ_PATH	:= $(ROOT)/objlst.mk

#			EXT

ARCH		:= $(shell uname)
ROOT		:= $(PWD)


#			LOCK

LOCK_UPDATE_PATH	:= $(CONF_PATH).lock_update
R_LOCK_LINK			:= $(CONF_PATH).lock_re_link

#			EXPORT

export		ROOT
export		ARCH
export		R_INC_PATH
export		R_OBJ_PATH
export		R_OBJ_LST
export		R_LOCK_LINK



# **************************************************************************** #
#								NAME LST                                       #
# **************************************************************************** #

SUBDIRS		:= srcs

LIB_NAME	:= libft

INC_LST		:= sh21.h

R_OBJ_LST	:= $(shell cat $(R_OBJ_PATH) $(NO_ERROR))

# **************************************************************************** #
#								VAR                                            #
# **************************************************************************** #

#			IN

NAME		:= $(shell cat $(CONF_PATH)name.mk)
#SUBDIRS		:= $(shell cat $(CONF_PATH)subdirs.mk)
#INC_LST		:= $(shell cat $(CONF_PATH)includes.mk)

#			EXT

INC			:= -I $(R_INC_PATH)
LIB_INC		:= $(addprefix -I,$(LIB_PATH)includes/)
LIB_SRC		:= $(addprefix $(LIB_PATH),libft.a)

#			EXPORT

export		INC
export		LIB_INC
export		LIB_SRC


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

.PHONY: all rm_lock

all: install_lock $(NAME)

install_lock:
	@touch $(R_LOCK_LINK)

$(NAME): lib inc obj $(LIB_SRC)
	@if [[ -e "$(R_LOCK_LINK)" && -e "$(NAME)" ]] ; then \
		echo "Nothing to do" ; \
		exit 0 ; \
	else \
	printf "Creation de $(NAME): " ; \
	$(CC) $(CC_FLAGS) $(INC) $(shell cat $(R_OBJ_PATH)) -o $(NAME) $(LIB_SRC) ; \
	printf "$(OK)" ; \
	fi
	@$(RM) $(RM_FLAGS) $(R_LOCK_LINK)

#			RULES FOR LIB

.PHONY: lib clean_lib fclean_lib

lib:
	@printf "Creation de $(LIB_NAME).a: $(START)"
	@$(MAKE) -C $(LIB_PATH) all
	@printf "Creation de $(LIB_NAME).a: $(END)"

clean_lib:
	@$(MAKE) -C $(LIB_PATH) clean

fclean_lib:
	@$(MAKE) -C $(LIB_PATH) fclean


#			RULES FOR INC

.PHONY: inc clean_inc

inc: $(R_INC_PATH)
	@printf "link Header : $(START)"
	@$(LN) $(LN_FLAGS) $(addprefix $(INC_PATH),$(INC_LST)) $(R_INC_PATH)
	@$(MAKE) -C $(LIB_PATH) inc_link
	@$(MAKE) $(SUBDIRS) RULE=inc_link
	@printf "link Header : $(END)"

$(R_INC_PATH):
	@printf "Creation de $(R_INC_PATH): "
	@mkdir -p $(R_INC_PATH) 2> /dev/null
	@printf "done\n"

clean_inc:
	@printf "Clean $(R_INC_PATH): "
	@$(RM) $(RM_FLAGS) $(R_INC_PATH)
	@printf "$(OK)"


#			RULES FOR OBJ

.PHONY: obj clean_obj

obj:
	@printf "Creation des obj: $(START)"
	@$(MAKE) $(SUBDIRS) RULE=obj
	@printf "Creation des obj: $(END)"

clean_obj:
	@printf "Clean de $(basename $(R_OBJ_PATH)): \n"
	@$(RM) $(RM_FLAGS) $(R_OBJ_PATH)
	@printf "$(OK)"


#			RULES UPDATE

.PHONY: update update_back update_clean update_lock_install update_lock_uninstall

update_lock_install:
	@touch $(LOCK_UPDATE_PATH)
	@printf "update is now locked\n"

update_lock_uninstall:
	@$(RM) $(RM_FLAGS) $(LOCK_UPDATE_PATH)
	@printf "update are now unlock\n"

ifeq ($(shell if [ -f $(LOCK_UPDATE_PATH) ]; then echo "yes" ; fi),yes)

update:
	@printf "For update please use first update_lock_uninstall.\n"

update_back:
	@printf "For update please use first update_lock_remove.\n"

else

update:
	@$(MAKE) $(SUBDIRS) RULE=update

update_back:
	@$(MAKE) $(SUBDIRS) RULE=update_back
	@printf "Please check and correct your bug before you don\'t remember\n"

endif

update_clean:
	@$(MAKE) $(SUBDIRS) RULE=update_clean


#		RULES CLEAN

.PHONY: clean fclean re

clean: clean_inc clean_obj clean_lib
	@$(MAKE) $(SUBDIRS) RULE=clean

fclean: clean fclean_lib
	@$(RM) -f $(NAME)

re: fclean all

push_clean: fclean update_lock_install
	@printf "\n\t\tLes sources sont ok tu peux git\n"

#		RULES OTHER

.PHONY: $(SUBDIRS) norme doc

$(SUBDIRS):
	@$(MAKE) -C $@ $(RULE)

norme:
	@$(MAKE) $(SUBDIRS) RULE=norme

doc:
	@less ./.template/doc.txt

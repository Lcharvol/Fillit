# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 10:00:05 by piquerue          #+#    #+#              #
#    Updated: 2016/11/25 15:01:39 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

file = $(shell (find . -type f | grep "\.c" | sed "s/.\///"))

obj = $(file:.c=.o)

EOC = \033[37m

MAG = \033[35m

RED = \033[31m

BLUE = \033[34m

GREEN = \033[32m

YELLOW = \033[33m

NAME = fillit

all: $(NAME)	

files:
	@clear
	@printf "\t    $(MAG)Le projet contient les fichiers suivants : $(EOC)\n"
	@printf "$(YELLOW)\t\t\t%s $(EOC)\n"  $(file)

clean:
	@rm -rf $(obj)

fclean: clean
	@rm -rf ./$(NAME)

re: fclean all

info:
	@clear
	@printf "$(YELLOW) Il existe differente regle afin de faciliter les corrections & co : $(EOC)\n"
	@printf "\t* $(MAG)make norminette$(EOC) ($(GREEN)permet d'effectuer la norminette sur l'ensemble des .c et .h $(RED)[norminette *.[ch]]$(EOC))\n"
	@printf "\t* $(MAG)make author$(EOC) ($(GREEN)permet d'afficher le contenu du fichier auteur $(RED)[cat -e]$(EOC))\n"
	@printf "\t* $(MAG)make files$(EOC) ($(GREEN)permet d'afficher la liste des fichiers .c$(EOC))\n"
	@printf "\t* $(MAG)make push$(EOC) ($(GREEN)permet d'envoyer une modification sur le repo git$(EOC))\n"
	@printf "\t* $(MAG)make pull$(EOC) ($(GREEN)permet de recuperer les modifications effectuer sur le repo git$(EOC))\n"
	@printf "\t* $(MAG)make check$(EOC) ($(GREEN)permet de lancer le test de fillit checker$(EOC))\n"
	@printf "\t* $(MAG)make clean$(EOC) ($(GREEN)Cette regle supprimme les .o$(EOC))\n"
	@printf "\t* $(MAG)make fclean$(EOC) ($(GREEN)Cette regle lance make clean puis supprime  l'executable$(EOC))\n"
	@printf "\t* $(MAG)make re$(EOC) ($(GREEN)Cette regle execture make fclean puis lance make all$(EOC))\n"
	@printf "\t* $(MAG)make all$(EOC) ($(GREEN)Cette regle permet lance la compilation du projet$(EOC))\n"

check:
	@clear
	@sh ~/Desktop/skript/libft/42FileChecker/fillit_checker/test.sh .

push:
	@clear
	@git add -A
	@git commit -m "Commit provenant du makefile"
	@clear
	@git push
	@clear

pull:
	@clear
	@git pull
	@clear

norminette:
	@norminette *.[ch]

author:
	@clear
	@cat -e auteur

$(NAME): 
	@clear
	@printf "\t\t\t$(MAG) Projet Fillit $(EOC)\n"
	@printf "\t\t     $(MAG)By $(GREEN)piquerue$(MAG) && $(GREEN)lcharvol$(EOC)\n"
	@clang -Wall -Werror -Wextra -c $(file)
	@clang -o $(NAME) $(file)

.PHONY : all clean fclean re norminette author pull push check info files

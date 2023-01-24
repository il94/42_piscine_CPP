#==============================================================================#
#                                   TARGETS                                    #
#==============================================================================#

NAME = interface

#==============================================================================#
#                                   COMMANDS                                   #
#==============================================================================#

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS = -MMD
MKDIR = mkdir -p
RM = rm -f
MAKE_SILENT = make --no-print-directory

#==============================================================================#
#                                    COLORS                                    #
#==============================================================================#

PURPLE = \033[35m
GREEN = \033[32m
YELLOW = \033[33m
END = \033[0m

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_DIR = src/
HEADER_DIR = include/
OBJ_DIR = obj/

#==============================================================================#
#                                   SOURCES                                    #
#==============================================================================#

SRC = main.cpp A_Materia.cpp MateriaCure.cpp MateriaIce.cpp Character.cpp I_Character.cpp I_MateriaSource.cpp MateriaSource.cpp \

#==============================================================================#
#                                   HEADERS                                    #
#==============================================================================#

HEAD = $(addprefix $(HEADER_DIR), A_Materia.hpp MateriaCure.hpp MateriaIce.hpp Character.hpp I_Character.hpp I_MateriaSource.hpp MateriaSource.hpp) \

#==============================================================================#
#                                   OBJECTS                                    #
#==============================================================================#

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

#==============================================================================#
#                                   MAKEFILE                                   #
#==============================================================================#

all : $(OBJ_DIR) $(NAME)

$(NAME) : $(OBJ)
	echo "$(YELLOW)Making CPP Exercise$(END)"
	$(CXX) $(OBJ) -o $(NAME)
	echo "$(GREEN)Done$(END)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp $(HEAD) Makefile
	$(CC) $(CXXFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR) :
	$(MKDIR) $(OBJ_DIR)

clean :
	echo "$(PURPLE)Cleaning CPP Exercise's objects...$(END)"
	$(RM)r $(OBJ_DIR)
	echo "$(GREEN)Done$(END)"

fclean : clean
	echo "$(PURPLE)Cleaning CPP Exercise...$(END)"
	$(RM) $(NAME)
	echo "$(GREEN)Done$(END)"

re : fclean
	$(MAKE_SILENT) all

.PHONY : all clean fclean re
.SILENT :
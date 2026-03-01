NAME = push_swap
BONUS = checker
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = 	algorithm_utils.c algorithm.c exec.c ft_atoi.c ft_push_swap.c\
		ft_split.c linked_list_functions.c op_pa_pb.c op_ra_rb_rr.c\
		op_rra_rrb_rrr.c op_sa_sb_ss.c push_swap.c utils.c

SRC_BONUS = algorithm_bonus.c algorithm_utils_bonus.c exec_bonus.c ft_atoi_bonus.c ft_push_swap_bonus.c\
			ft_split_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c linked_list_functions_bonus.c op_pa_pb_bonus.c\
			op_ra_rb_rr_bonus.c op_rra_rrb_rrr_bonus.c op_sa_sb_ss_bonus.c push_swap_bonus.c utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)


# bonus: $(BONUS)

# $(BONUS): $(OBJ_BONUS)
# 	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(BONUS)

%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: clean
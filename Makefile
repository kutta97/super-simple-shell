SRCS_DIR = srcs/

SRCS_LST = util.cpp \
			command.cpp \
			match.cpp \
			ls.cpp \
			rm.cpp \
			touch.cpp \
			error.cpp

SRCS	 = simple_shell.cpp $(addprefix $(SRCS_DIR), $(SRCS_LST))

OBJS	 = $(SRCS:%.c=%.o)
GCC		 = g++
RM		 = rm -rf
INCLUEDS = -I./includes

NAME	 = simple_shell

%.o: %.c
	$(GCC) $(INCLUEDS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)

clean:
	$(RM) $(NAME)

re: clean all
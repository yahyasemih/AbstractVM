NAME = avm
CXX = g++
CPPFLAGS = -std=c++14 -Wall -Wextra -Werror

SRC = main.cpp\
    Token.cpp\
    Parser.cpp\
    InstructionType.cpp\
    exceptions/ArithmeticException.cpp\
    exceptions/AssertionErrorException.cpp\
    exceptions/InvalidInstructionException.cpp\
    exceptions/InvalidNumberException.cpp\
    exceptions/InvalidStackStateException.cpp\
    exceptions/OutOfRangeException.cpp\
    exceptions/SyntaxErrorException.cpp\
    operands/BaseOperand.cpp\
    operands/Int8.cpp\
    operands/Int16.cpp\
    operands/Int32.cpp\
    operands/Float.cpp\
    operands/Double.cpp\
    operands/OperandFactory.cpp
OBJ := $(patsubst %.cpp,%.o,$(SRC))
DEPENDS := $(patsubst %.cpp,%.d,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $^ -o $@

clean:
	/bin/rm -f $(OBJ) $(DEPENDS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

-include $(DEPENDS)

%.o: %.cpp Makefile
	$(CXX) $(CPPFLAGS) -c $< -o $@
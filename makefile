INC= -I ./include
CPPSRC= src/*.cpp

ifeq ($(OS) ,Windows_NT)
	NAME=calculator.exe
else
	NAME=calculator
endif

calc:
	g++ $(INC) $(CPPSRC) -o $(NAME)

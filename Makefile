CC = g++

FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations \
		-Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual        \
		-Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op                 \
		-Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192         \
		-Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE


all: do

clean:
	rm obj/*.o do.exe
	
quadratic_equation: quadratic_equation.cpp
	$(CC) $(FLAGS) -c quadratic_equation.cpp -o obj/quadratic_equation.o

test_mode: tests/test_mode.cpp
	$(CC) $(FLAGS) -c tests/test_mode.cpp -o obj/test_mode.o

io: src/io.cpp
	$(CC) $(FLAGS) -c src/io.cpp -o obj/io.o

solve_equation: src/solve_equation.cpp
	$(CC) $(FLAGS) -c src/solve_equation.cpp -o obj/solve_equation.o

solver: src/solver.cpp
	$(CC) $(FLAGS) -c src/solver.cpp -o obj/solver.o

utils: src/utils.cpp
	$(CC) $(FLAGS) -c src/utils.cpp -o obj/utils.o

do: quadratic_equation test_mode io solve_equation solver utils
	$(CC) $(FLAGS) obj/quadratic_equation.o obj/test_mode.o obj/io.o obj/solve_equation.o obj/solver.o obj/utils.o -o do.exe
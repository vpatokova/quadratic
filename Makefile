CC = g++

FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations \
		-Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual        \
		-Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op                 \
		-Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192         \
		-Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE


SOURCES = quadratic_equation.cpp src/io.cpp src/solve_equation.cpp src/solver.cpp src/utils.cpp tests/test_mode.cpp

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = hello

all: $(SOURCES) $(EXECUTABLE)

.SUFFIXES: .cpp .o

.cpp.o:
	$(CC) $(FLAGS) -c -o $@ $<

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(FLAGS) $(OBJECTS) -o $@

clean:
	-rm obj/*.o src/*.o *.o hello.exe
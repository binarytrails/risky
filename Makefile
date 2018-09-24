#! @file
#! @author Vsevolod (Seva) Ivanov

CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -Wfatal-errors -pedantic \
		 -I./src -I./src/drivers

root="src"
build="build"
drivers="src/drivers"

all:
	mkdir -p build

game: all
	${CXX} ${CXXFLAGS} -lSDL2 \
	${drivers}/Game.cpp ${root}/Window.cpp \
	-o ${build}/game.out

clean:
	rm -rf ${build}/

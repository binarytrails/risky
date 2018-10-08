#! @file
#! @author Vsevolod (Seva) Ivanov

CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -Wfatal-errors -pedantic \
		 -I./src

root=src
build=build

all:
	mkdir -p build

game: all
	${CXX} ${CXXFLAGS} -lSDL2 \
	${root}/Map.cpp ${root}/Country.cpp ${root}/Player.cpp \
	${root}/Dice.cpp ${root}/Card.cpp \
	${root}/Window.cpp ${root}/Game.cpp ${root}/GameDriver.cpp \
	-o ${build}/game.out

player: all
	${CXX} ${CXXFLAGS} -lSDL2 \
	${root}/Country.cpp ${root}/Player.cpp \
	${root}/Dice.cpp ${root}/Card.cpp \
	${root}/Window.cpp ${root}/Game.cpp ${root}/PlayerDriver.cpp \
	-o ${build}/player.out

clean:
	rm -rf ${build}/

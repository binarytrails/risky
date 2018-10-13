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
	${root}/Card.cpp ${root}/PlayerDice.cpp \
	${root}/Window.cpp ${root}/Game.cpp ${root}/GameDriver.cpp \
	-o ${build}/game.out

player: all
	${CXX} ${CXXFLAGS} \
	${root}/Country.cpp ${root}/Player.cpp \
	${root}/Card.cpp ${root}/PlayerDice.cpp \
	${root}/PlayerDriver.cpp \
	-o ${build}/player.out

map: all
	${CXX} ${CXXFLAGS} \
	${root}/Country.cpp ${root}/Player.cpp \
	${root}/Card.cpp ${root}/PlayerDice.cpp \
	${root}/Map.cpp ${root}/MapDriver.cpp \
	-o ${build}/map.out

clean:
	rm -rf ${build}/

CXX = g++
CXXFLAGS = -std=c++0x -Wall -g

TARGET = game
OBJS = Character.o main.o utilityFunctions.o Die.o Barbarian.o BlueMen.o Game.o HarryPotter.o Vampire.o Medusa.o
SRCS = Character.cpp main.cpp utilityFunctions.cpp Die.cpp Barbarian.cpp BlueMen.cpp Game.cpp HarryPotter.cpp Vampire.cpp Medusa.cpp
HEADERS = Character.hpp utilityFunctions.hpp globalConstants.hpp Die.hpp Barbarian.hpp BlueMen.hpp Game.hpp HarryPotter.hpp Vampire.hpp Medusa.hpp

${TARGET}: ${OBJS} ${HEADERS}
	${CXX} ${SRCS} -o ${TARGET}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm ${OBJS}
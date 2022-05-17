PROG = space
CC = g++
CFLAGS = -g -Wall
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
OBJS = game.o main.o world.o spritenode.o scenenode.o aircraft.o entity.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LIBS)
main.o :
	$(CC) $(CFLAGS) -c main.cpp
game.o :
	$(CC) $(CFLAGS) -c game.cpp
world.o :
	$(CC) $(CFLAGS) -c world.cpp
spritenode.o : 
	$(CC) $(CFLAGS) -c spritenode.cpp
scenenode.o :
	$(CC) $(CFLAGS) -c scenenode.cpp
aircraft.o :
	$(CC) $(CFLAGS) -c aircraft.cpp
entity.o :
	$(CC) $(CFLAGS) -c entity.cpp
clean:
	$(RM) $(PROG) $(OBJS)

install:
	cp space /usr/bin

uninstall:
	$(RM) /usr/bin/space

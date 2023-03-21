CC=g++

ODIR = objects
DDIR = dependencies

CFLAGS=-std=c++11 -MMD -MP
SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

debug: CFLAGS+=-g -Wall

$(ODIR)/%.o: &.cpp | $(ODIR) $(DDIR)
	$(CC) -c $< -0 $@ $(CFLAGS) -MF $(DDIR)/$(patsubst %.o,%.d,$(@F))

04_Input: Game.o
	$(CC) $< -o $@ $(SFMLFLAGS)

$(ODIR) $(DDIR):
	mkdir -p $@

run: 04_Input
	./04_Input

debug: clean 04_Input
	gdb 04_Input

clean:
	rm -f sfml-app # deprecated
	rm -f *.app
	rm -f *.o
	rm -f *.d
	rm -f -r objects/
	rm -f -r dependencies/
	
-include $(DDIR)/*.d

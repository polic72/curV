PROG = curV
OBJS = obj/$(PROG).o obj/xyz.o obj/line.o obj/base_curve.o
# obj/base_curve.o

DOC = doc/html

CC = gcc
CFLAGS = -Wall -lm
# -std=gnu11
LIBS = 
DEBUGFLAGS = 


#all : $(PROG) $(DOC)
all : bin/$(PROG)


debug : CFLAGS += -DDEBUG -g -O
debug : all


bin/$(PROG) : $(OBJS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(OBJS) -o bin/$(PROG) $(LIBS)
	ln -s bin/$(PROG) $(PROG)

$(DOC) : Doxyfile *.c
	doxygen

obj/%.o : src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o "$@" $(DEBUGFLAGS) $(LIBS)


clean:
	rm -f $(OBJS) $(PROG)
	rm -rf $(DOC)
	rm -rf bin
	rm -rf obj

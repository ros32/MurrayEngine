SRCS = ExtendedCollisionAction.cpp ObjectFactory.cpp WitchAI.cpp MainProgram.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = test
CC = g++
DEBUG = -g -Wall
CFLAGS = -std=c++11 $(DEBUG)
LFLAGS = -L. -L../lib
INCLUDES = -I. -I../MurrayEngine
LIBS = -lmurray -lSDL2 -lSDL2_ttf -lSDL2_image

all:	$(MAIN)
	@echo Simple compiler named test has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

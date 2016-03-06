SCRCS = *.cpp
OBJS = $(SCRCS:.cpp=.o)
CC = g++
DEBUG = -g
CFLAGS = -c -std=c++11 $(DEBUG)
LFLAGS = -c -std=c++11 $(DEBUG)
OUT=../lib/libmurray.a

default: all $(OUT)

all:
	$(CC) $(LFLAGS) $(SCRCS)

$(OUT) :
	ar rcs $(OUT) $(OBJS)

clean:
	rm -f *.o $(OUT)



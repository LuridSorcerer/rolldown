CC=g++
cflags=-I/usr/include/alsa
ldflags=-lasound
src=rolldown.cpp
obj=rolldown.o
exe=rolldown

all: rolldown.o
	$(CC) -o $(exe) $(src) $(ldflags) -no-pie

rolldown.o: rolldown.cpp
	$(CC) -c $(cflags) rolldown.cpp

clean:
	rm -rf $(exe) $(obj)
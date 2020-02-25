CC = g++ -g
exe_file = wumpus
$(exe_file): driver.o game.o room.o event.o wumpus.o bats.o pit.o gold.o rope.o player.o
	$(CC) driver.o game.o room.o event.o wumpus.o bats.o pit.o gold.o rope.o player.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
game.o: game.cpp
	$(CC) -c game.cpp
room.o: room.cpp
	$(CC) -c room.cpp
event.o: event.cpp
	$(CC) -c event.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
bats.o: bats.cpp
	$(CC) -c bats.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
rope.o: rope.cpp
	$(CC) -c rope.cpp
player.o: player.cpp
	$(CC) -c player.cpp
clean:
	rm -f *.out *.o $(exe_file)

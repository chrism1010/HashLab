all: hash
	mkdir build
	mkdir build/objects
	mkdir build/bin
	mv *.o build/objects
	mv hashlab build/bin

hash: main.o linked_list.o hashset.o
	g++ main.o linked_list.o hashset.o -o hashlab

main.o: src/main.cpp
	g++ -c -Wall -I lib src/main.cpp

linked_list.o: lib/linked_list.cpp
	g++ -c -Wall -I lib lib/linked_list.cpp

hashset.o: lib/hashset.cpp
	g++ -c -Wall -I lib lib/hashset.cpp

clean:
	rm -r build



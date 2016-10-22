run: main.o
	g++ main.o -o run

	main.o: main.cpp
		g++ -c main.cpp

# message.o: message.cpp message.h
# 		g++ -c message.cpp

clean:
	rm *.o run



# target: dependecies
# 	action



# run: main.o allheaders.o
# 	g++ main.o allheaders.o -o run

# run: main.o allheaders.o
# 	g++ main.o allheaders.o -o Executible



# clean:
# 	rm *.o run

# clean:
# 	remove anythingthatendsin.o run

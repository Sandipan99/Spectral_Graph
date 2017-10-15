CC = g++ -std=gnu++11
objects = graph.o common.o

main : $(objects)
		 $(CC) main.cpp -o main $(objects) -O1 -larmadillo 
graph.o : graph.h graph.cpp 
	$(CC) -c graph.cpp

common.o: common.h common.cpp
	$(CC) -c common.cpp

clean : 
	rm $(objects) 

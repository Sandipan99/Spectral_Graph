CC = g++ -std=gnu++11
objects = graph.o common.o graph_models.o

main : $(objects)
		 $(CC) main.cpp -o main $(objects) -O1 -larmadillo 
graph.o : graph.h graph.cpp 
	$(CC) -c graph.cpp

common.o: common.h common.cpp
	$(CC) -c common.cpp

graph_models.o: graph_models.h graph_models.cpp
	      $(CC) -c graph_models.cpp	

clean : 
	rm $(objects) 

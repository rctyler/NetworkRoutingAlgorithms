CC = gcc
CFLAGS = -lstdc++

DEPS = main.h MinimumSpanningTreeAlgorithm.h Edge.h EdgeHeap.h VertexHeap.h AdjacencyList.h KruskalsAlgorithm.h PrimsAlgorithm.h DijkstrasAlgorithm.h BellmanFordsAlgorithm.h Vertex.h DisjointSet.h

OBJ = Edge.o MinimumSpanningTreeAlgorithm.o Vertex.o DisjointSet.o EdgeHeap.o VertexHeap.o AdjacencyList.o KruskalsAlgorithm.o PrimsAlgorithm.o DijkstrasAlgorithm.o BellmanFordsAlgorithm.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

NetworkRoutingAlgorithms: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -rf ./NetworkRoutingAlgorithms;
	rm -rf *.o;

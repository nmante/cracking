#ifndef __EDGE_HPP__
#define __EDGE_HPP__

class Vertex;

class Edge{

public:
	Vertex *start;
	Vertex *end;
	double weight;
	bool visited = false;

	Edge(Vertex *start, Vertex *end) : 
		start(start),
		end(end)
	{}

	Edge(Vertex *start, Vertex *end, double weight) :
		start(start),
		end(end),
		weight(weight)
	{}

};

#endif // __EDGE_HPP__

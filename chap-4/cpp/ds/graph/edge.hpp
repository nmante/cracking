#ifndef __EDGE_HPP__
#define __EDGE_HPP__
#include <memory>

#include "vertex.hpp"
//class Vertex;

class Edge{
	friend class Vertex;

public:
	std::shared_ptr<Vertex> start; // The beginning vertex of the edge
	std::shared_ptr<Vertex> end; // The end vertex of the edge
	double weight = 0; // The edge weight
	bool visited = false; // Has this edge been visited
	
	// Construct an edge with two vertices and no cost
	Edge(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end) : 
		start(start),
		end(end)
	{}

	// Construct an edge with two vertices and a cost
	Edge(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end, double weight) :
		start(start),
		end(end),
		weight(weight)
	{}

	// Destroy the edge
	~Edge(){
		start = nullptr;
		end = nullptr;
		weight = 0;
		visited = false;
	}

	// Need this less than operator overload for 'Set' insertion in the Graph
	bool operator<(const Edge &other) const{
		// Names
		if(start->name < other.start->name) return true;
		if(start->name > other.start->name) return false;
		if(end->name < other.end->name) return true;
		if(end->name > other.end->name) return false;

		// Weights
		if(weight < other.weight) return true;
		if(weight > other.weight) return false;

		return false;
	}

	// A convenient way to print our edge
	friend std::ostream & operator<<(std::ostream & out, const Edge &e){
		out << e.start->name << " -> " << e.end->name << " : {" << std::endl;
		out << '\t' << "cost : " << e.weight << "," << std::endl;
		out << '\t' << "visited : " << e.visited<< "," << std::endl;
		out << "}" << std::endl;
		return out;
	}
};

#endif // __EDGE_HPP__

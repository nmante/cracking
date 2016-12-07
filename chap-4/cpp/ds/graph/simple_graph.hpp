#ifndef __SIMPLEGRAPH_HPP__
#define __SIMPLEGRAPH_HPP__
#include "vertex.hpp"
#include "edge.hpp"
#include "graph.hpp"

class SimpleGraph : public Graph<Vertex, Edge>{

private:
	std::string name;

public:
	SimpleGraph(std::string name) : 
		Graph(),
		name(name)
	{}
	
};	

#endif // __SIMPLEGRAPH_HPP__

#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__
/*
 * Nii Mante 2016
 * Vertex Class for Graphs
 *
 * Vertex can have names and edges that connect them to other vertices.
 *
 */

#include <string>
#include <set>
#include <iostream>
#include <memory>
//#include "edge.hpp"

class Edge;

class Vertex {
	friend class Edge;
private:
	std::string name;
public:

	double cost = 0; // cost to reach this node. Useful for path cost algos
	bool visited = false; // has this node been visited. Useful for path cost algos
	std::set<std::shared_ptr<Edge> > edges; // Edges leading out of this graph
	std::shared_ptr<Vertex> previous; // Our previous vertex 
	Vertex(std::string name) : name(name){}
	~Vertex(){
		previous = nullptr;
	}

	std::string getName() const{
		return name;
	}

	bool operator<(const Vertex &other) const{
		return name < other.name;
	}
	friend std::ostream & operator<<(std::ostream & out, const Vertex &v);
};

#endif // __VERTEX_HPP__

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

class Edge;

class Vertex {

public:
	std::string name;
	double cost = 0;
	bool visited = false;
	std::set<Edge*> edges;
	Vertex *previous = NULL;
	Vertex(std::string name) : name(name){}
};

#endif // __VERTEX_HPP__

#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__
//#include "vertex.hpp"
//#include "edge.hpp"
#include <set>
#include <map>
#include <string>
#include <iostream>

template <class VertexType, class EdgeType>
class Graph{

public:
	std::set<VertexType*> vertexSet;
	std::set<EdgeType*> edgeSet;
	std::map<std::string, VertexType*> vertexMap; 

public:
	Graph(){}

	// Edge Operations
	EdgeType* addEdge(VertexType *v1, VertexType *v2);
	EdgeType* addEdge(std::string name1, std::string name2);
	EdgeType* addEdge(EdgeType *edge);

	bool removeEdge(VertexType *v1, VertexType *v2);
	bool removeEdge(std::string name1, std::string name2);
	bool removeEdge(EdgeType *edge);

	bool containsEdge(VertexType *v1, VertexType *v2) const;
	bool containsEdge(std::string name1, std::string name2) const;
	bool containsEdge(EdgeType *edge) const;

	EdgeType* getEdge(VertexType *v1, VertexType *v2) const;
	EdgeType* getEdge(std::string v1, std::string v2) const;

	const std::set<EdgeType*> & getEdgeSet() const;
	const std::set<EdgeType*> & getEdgeSet(Vertex *v) const;
	const std::set<EdgeType*> & getEdgeSet(std::string vertexName) const;

	// Vertex Operations
	VertexType* addVertex(VertexType *v);
	VertexType* addVertex(std::string name);

	bool containsVertex(VertexType *v);
	bool containsVertex(std::string name);

	const std::set<VertexType*> getNeighbors(VertexType *v) const;
	const std::set<VertexType*> getNeighbors(std::string name) const;

	bool removeVertex(VertexType *v);
	bool removeVertex(std::string name);

	VertexType* getVertex(std::string name) const;
	const std::set<VertexType*> & getVertexSet() const;

	// Utility Operations
	bool isEmpty();
	int size();

	friend std::ostream & operator<<(std::ostream &out, const Graph<VertexType, EdgeType> &g);

};

#include "graph.cpp"
#endif // __GRAPH_HPP__

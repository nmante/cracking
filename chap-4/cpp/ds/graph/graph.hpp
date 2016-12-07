#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__
//#include "vertex.hpp"
//#include "edge.hpp"
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <memory>

/*
 * Graph implementation
 * Nii Mante
 * December 2016
 * API based off of http://stanford.edu/~stepp/cppdoc/BasicGraph-class.html
 * Huge difference between my implementation and Stanford's is my use of 
 * shared_ptr instead of normal raw pointers.
 *
 * This Graph API is template based. It allows you to create custom node/vertex
 * types and edge/arc types. It gives you all the operations necessary to 
 * do graph operations.
 *
 * A single header file implementation was chosen because it was the simplest way
 * to use shared_ptr's with template arguments.
 * (see the 'using VertexPtr...' statements at top of Graph class).
 */



template <class VertexType, class EdgeType>
class Graph{
	using VertexPtr = std::shared_ptr<VertexType>;
	using EdgePtr = std::shared_ptr<EdgeType>;
public:
	std::set<VertexPtr> vertexSet;
	std::set<EdgePtr> edgeSet;
	std::map<std::string, VertexPtr> vertexMap; 

public:
	Graph(){}

	// Edge Operations
	EdgePtr addEdge(VertexPtr v1, VertexPtr v2){
		// Create the edge using these two nodes
		// and add it to the edge set
		EdgePtr edge(new EdgeType(v1, v2));
		this->edgeSet.insert(edge);
		
		// Add these vertices to the graph. The addVertex instance method will take 
		// care of pre-existing vertices 
		this->addVertex(v1);
		this->addVertex(v2);
		/*
		if(this->vertexSet.count(v2) == 0){
			this->vertexSet.insert(v2);
		}
		*/
		return edge;
	}
	EdgePtr addEdge(std::string name1, std::string name2){
		EdgePtr edge(new EdgeType(name1, name2));
		this->edgeSet.insert(edge);
		this->addVertex(edge->start);
		this->addVertex(edge->end);
		return edge;
	}
	EdgePtr addEdge(EdgePtr edge){
		this->edgeSet.insert(edge);
		this->addVertex(edge->start);
		this->addVertex(edge->end);
		return edge;
	}
	EdgePtr addEdge(std::string name1, std::string name2, double cost);
	

	bool removeEdge(VertexPtr v1, VertexPtr v2){
		if(this->containsEdge(v1, v2)){
			this->edgeSet.erase(this->edgeSet.find(EdgeType(v1,v2)));
			return true;
		}
		return false;
	}
	bool removeEdge(std::string name1, std::string name2){
		if(this->containsEdge(name1, name2)){
			this->edgeSet.erase(this->edgeSet.find(EdgeType(name1,name2)));
			return true;
		}
		return false;
	}
	bool removeEdge(EdgePtr edge){
		if(this->containsEdge(edge)){
			this->edgeSet.erase(this->edgeSet.find(EdgeType(edge)));
			return true;
		}
		return false;
	}

	bool containsEdge(VertexPtr v1, VertexPtr v2) const{
		return this->edgeSet.count(EdgeType(v1, v2)) == 1;
	}

	bool containsEdge(std::string name1, std::string name2) const;
	bool containsEdge(EdgePtr edge) const;

	EdgePtr getEdge(VertexPtr v1, VertexPtr v2) const;
	EdgePtr getEdge(std::string name1, std::string name2) const;

	const std::set<EdgePtr> & getEdgeSet() const;
	const std::set<EdgePtr> & getEdgeSet(VertexPtr v) const;
	const std::set<EdgePtr> & getEdgeSet(std::string vertexName) const;

	// Vertex Operations
	VertexPtr addVertex(VertexPtr v){
		this->vertexSet.insert(v);
		return v;
	}
	VertexPtr addVertex(std::string name);

	bool containsVertex(VertexPtr v);
	bool containsVertex(std::string name);

	const std::set<VertexPtr> getNeighbors(VertexPtr v) const;
	const std::set<VertexPtr> getNeighbors(std::string name) const;

	bool removeVertex(VertexPtr v);
	bool removeVertex(std::string name);

	VertexPtr getVertex(std::string name) const;
	const std::set<VertexPtr> & getVertexSet() const;

	// Utility Operations
	bool isEmpty();
	int size();
	friend std::ostream & operator<<(std::ostream &out, const Graph<VertexType, EdgeType> &g);

};

#endif // __GRAPH_HPP__

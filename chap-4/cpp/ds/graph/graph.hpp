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
	struct VertexPtrNameCmp {
		bool operator()(const VertexPtr lhs, const VertexPtr rhs) const {
			if(lhs->name < rhs->name)
				return true;
			return false;
		}	
	};

	struct EdgePtrNameCmp {
		bool operator()(const EdgePtr lhs, const EdgePtr rhs) const {
			if(lhs->start->getName() < rhs->start->getName()) return true;
			if(lhs->start->getName() > rhs->start->getName()) return false;
			if(lhs->end->getName() < rhs->end->getName()) return true;
			if(lhs->end->getName() > rhs->end->getName()) return false;

			return false;
		}
	};
	std::set<VertexPtr> vertexSet;
	std::set<VertexPtr, VertexPtrNameCmp> vertexNameSet;
	std::set<EdgePtr, EdgePtrNameCmp> edgeSet;
	std::map<std::string, VertexPtr> vertexMap; 

public:
	Graph(){}

	// Edge Operations
	EdgePtr addEdge(VertexPtr v1, VertexPtr v2){
		EdgePtr edge(new EdgeType(v1, v2));
		this->edgeSet.insert(edge);
		this->addVertex(v1);
		this->addVertex(v2);
		edge->start->edges.insert(edge);
		//edge->end->edges.insert(edge);
		return edge;
	}
	EdgePtr addEdge(std::string name1, std::string name2){
		VertexPtr v1(new VertexType(name1));
		VertexPtr v2(new VertexType(name2));
		EdgePtr edge(new EdgeType(v1, v2));
		this->edgeSet.insert(edge);
		this->addVertex(edge->start);
		this->addVertex(edge->end);
		edge->start->edges.insert(edge);
		return edge;
	}
	EdgePtr addEdge(EdgePtr edge){
		this->edgeSet.insert(edge);
		this->addVertex(edge->start);
		this->addVertex(edge->end);

		edge->start->edges.insert(edge);
		//edge->end->edges.insert(edge);
		return edge;
	}
	EdgePtr addEdge(std::string name1, std::string name2, double cost){
		// Add the edge and vertices to this Graph
		VertexPtr v1(new VertexType(name1));
		VertexPtr v2(new VertexType(name2));
		EdgePtr edge(new EdgeType(v1, v2, cost));
		this->edgeSet.insert(edge);
		this->addVertex(edge->start);
		this->addVertex(edge->end);

		// Add the edge to 'edges' set of each vertex
		edge->start->edges.insert(edge);
		//edge->end->edges.insert(edge);
		return edge;
	}
	
	bool removeEdge(VertexPtr v1, VertexPtr v2){
		if(this->containsEdge(v1, v2)){
			EdgePtr e(new EdgeType(v1, v2));
			this->edgeSet.erase(this->edgeSet.find(e));
			return true;
		}
		return false;
	}

	bool removeEdge(std::string name1, std::string name2){
		if(this->containsEdge(name1, name2)){
			VertexPtr v1(new VertexType(name1));
			VertexPtr v2(new VertexType(name2));
			EdgePtr e(new EdgeType(v1, v2));
			this->edgeSet.erase(this->edgeSet.find(e));
			return true;
		}
		return false;
	}

	bool removeEdge(EdgePtr edge){
		if(this->containsEdge(edge)){
			this->edgeSet.erase(this->edgeSet.find(edge));
			return true;
		}
		return false;
	}

	bool containsEdge(VertexPtr v1, VertexPtr v2) const{
		// If the vertices are not in the graph then the edge isn't there either 

		// Create an edge pointer
		EdgePtr e(new EdgeType(v1, v2));

		// Search the edgeSet. Our set consists of POINTERS to edges
		// Luckily we created our edgeSet with a custom comparator that 
		// compares the fields of an edge (start->name, end->name, etc.)
		auto eResult = this->edgeSet.find(e);
		if(eResult == this->edgeSet.end())
			return false;

		return true;
	}

	bool containsEdge(std::string name1, std::string name2) const{
		VertexPtr v1(new VertexType(name1));
		VertexPtr v2(new VertexType(name2));
		EdgePtr edge(new EdgeType(v1, v2));
		if(this->edgeSet.find(edge) == this->edgeSet.end())
			return false;

		return true;
	}

	bool containsEdge(EdgePtr edge) const{
		return this->edgeSet.count(edge) == 1;
	}

	EdgePtr getEdge(VertexPtr v1, VertexPtr v2) const{
		EdgePtr e(new EdgeType(v1, v2));
		auto eResult = this->edgeSet.find(e);
		if(eResult != this->edgeSet.end()){
			return *eResult; 
		}
		return nullptr;
	}
	EdgePtr getEdge(std::string name1, std::string name2) const{
		VertexPtr v1(new VertexType(name1));
		VertexPtr v2(new VertexType(name2));
		EdgePtr edge(new EdgeType(v1, v2));
		//EdgePtr e(new EdgeType(name1, name2));
		auto eResult = this->edgeSet.find(edge);
		if(eResult != this->edgeSet.end()){
			return *eResult; 
		}
		return nullptr;
	}

	const std::set<EdgePtr, EdgePtrNameCmp> & getEdgeSet() const{
		return this->edgeSet;
	}

	const std::set<EdgePtr> getEdgeSet(VertexPtr v) const{
		auto vRet = this->vertexSet.find(v);
		if(vRet != this->vertexSet.end())
			return (*vRet)->edges;
		std::set<EdgePtr> s;
		return s;
	}
	const std::set<EdgePtr> getEdgeSet(std::string vertexName) const{
		auto v = this->vertexMap.at(vertexName);
		if(v)
			return v->edges;
		std::set<EdgePtr> s;
		return s; 
	}

	// Vertex Operations
	VertexPtr addVertex(VertexPtr v){
		this->vertexSet.insert(v);
		this->vertexMap[v->getName()] = v;
		return v;
	}

	VertexPtr addVertex(std::string name){
		VertexPtr v(new VertexType(name));
		this->vertexSet.insert(v);
		this->vertexMap[name] = v;
		return v;
	}

	VertexPtr getVertex(std::string name){
		return this->vertexMap.at(name);
	}

	bool containsVertex(VertexPtr v){
		if(this->vertexSet.find(v) == this->vertexSet.end())
			return false;
		return true;
	}
	bool containsVertex(std::string name){
		if(this->vertexMap[name] == nullptr)
			return false;
		return true;
	}

	const std::set<VertexPtr> getNeighbors(VertexPtr v) const{
		auto res = this->vertexSet.find(v);
		if(res != this->vertexSet.end()){
			std::set<VertexPtr> neighbors;
			auto vRes = *res;
			for(auto e : vRes->edges){
				neighbors.insert(e->end);
			}
			return neighbors;
		}
		return std::set<VertexPtr>();
		
	}
	const std::set<VertexPtr> getNeighbors(std::string name) const{
		auto v = this->vertexMap.at(name);
		if(v){
			std::set<VertexPtr> neighbors;
			for(auto e : v->edges){
				neighbors.insert(e->end);
			}
			return neighbors;
		}
		return std::set<VertexPtr>();
	}

	bool removeVertex(VertexPtr v){
		if(this->containsVertex(v)){
			this->vertexSet.erase(v);
			this->vertexMap.erase(v->getName());
			return true;
		}
		return false;
	}
	bool removeVertex(std::string name){
		if(this->containsVertex(name)){
			this->vertexSet.erase(this->vertexMap[name]);
			this->vertexMap.erase(name);
			return true;
		}
		return false;
	}

	VertexPtr getVertex(std::string name) const {
		return this->vertexMap.at(name);
	}
	const std::set<VertexPtr> & getVertexSet() const {
		return this->vertexSet;
	}

	// Utility Operations
	bool isEmpty(){
		return this->edgeSet.size() == 0;
	}
	int size(){
		return this->edgeSet.size();
	}
	std::string toString() const {
		std::string out = "{";
		for(auto v : this->vertexSet){
			out += v->getName() + ", "; 
		}
		
		int count = 0;
		for(auto it = this->edgeSet.begin(); it != this->edgeSet.end(); ++it){
			out += (*it)->toString(); 
			if(count != this->edgeSet.size() - 1){
				out += ", ";
			}
			count++;
		}
	
		out += "}";
		return out;
	}

	friend std::ostream & operator<<(std::ostream &out, const Graph<VertexType, EdgeType> &g){
		out << g.toString() << std::endl;
		return out;
	}

};

#endif // __GRAPH_HPP__

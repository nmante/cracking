#include <iostream>
#include "ds/graph/simple_graph.hpp"
#include <string>
#include <queue>
#include <set>

/*
 * Problem: Determine if a path exists between two nodes
 *
 * start: 1030pm
 * end: 1045pm
 */

bool pathExists(const SimpleGraph & g, std::shared_ptr<Vertex> & start, std::shared_ptr<Vertex> &end){
	// Get a reference to our start node
	//auto start = g.getVertex(startName);
	//auto end = g.getVertex(endName);
	if(!start || !end){
		return false;
	}

	std::queue<std::shared_ptr<Vertex> > q;
	std::set<std::shared_ptr<Vertex> > s;
	q.push(start);
	s.insert(start);
	// Now we need to look through the neighbors of each node, starting
	// with 'start' and see if we encounter 'end' at all.
	// As we move through, keep track of 
	while(!q.empty()){
		auto v = q.front();
		q.pop();
		s.erase(v);
		for(auto neighbor : g.getNeighbors(v)){
			if(neighbor == end){
				return true;
			}
			auto ret = s.insert(neighbor);
			if(ret.second){
				q.push(neighbor);
			}
		}
	}	
	
	return false;
}

std::string test(SimpleGraph &g, std::shared_ptr<Vertex> &v, std::shared_ptr<Vertex> &v2){
	bool result = pathExists(g, v, v2); 	
	std::cout << g << std::endl;
	std::string out = result ? "Path Exists" : "Path doesn't exist";
	return out + " between " +  v->getName() + " and " + v2->getName();
}

int main(){
	SimpleGraph g("awesome");
	auto v1 = std::make_shared<Vertex>("hello");
	auto v2 = std::make_shared<Vertex>("world");
	auto v3 = std::make_shared<Vertex>("A");
	auto v4 = std::make_shared<Vertex>("B");
	auto v5 = std::make_shared<Vertex>("C");
	auto v6 = std::make_shared<Vertex>("D");
	auto v7 = std::make_shared<Vertex>("E");

	auto e = g.addEdge(v1, v2);
	auto e2 = g.addEdge(v1, v3);
	auto e3 = g.addEdge(v1, v4);
	auto e4 = g.addEdge(v2, v5);
	auto e5 = g.addEdge(v5, v6);
	auto e6 = g.addEdge(v6, v7);
	std::cout << test(g, v1, v2) << std::endl;
	std::cout << test(g, v2, v3) << std::endl;
	std::cout << test(g, v1, v7) << std::endl;
	
	return 0;
}

/*
 * Solution:
 * 	- We're only interested in determining if a path exists.
 * 	- We can do a simple search along the graph
 * 	- That means we can do a BFS or DFS
 *
 */

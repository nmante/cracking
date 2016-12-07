#include <iostream>
#include "ds/graph/simple_graph.hpp"

int main(){
	SimpleGraph g("awesome");
	auto v1 = std::make_shared<Vertex>("hello");
	auto v2 = std::make_shared<Vertex>("world");
	auto e = g.addEdge(v1, v2);
	std::cout << *e << std::endl;
	std::cout << *(e->start) << std::endl;

	return 0;
}

#include "vertex.hpp"
#include "edge.hpp"

std::ostream & operator<<(std::ostream & out, const Vertex &v){
	out << v.name << " : {" << std::endl; 
	out << '\t' << "cost : " << v.cost << "," << std::endl;
	out << '\t' << "visited : " << v.visited<< "," << std::endl;
	if(v.previous){
		out << '\t' << "previous : " << v.previous->name << "," << std::endl;
	}
	out << '\t' << "edges : {" << std::endl;
	for(auto e : v.edges){
		out << '\t' << '\t' << "previous : " << e->start->name << " -> " << e->end->name << "," << std::endl;
	}
	out << '\t' << "}" << std::endl;
	out << "}" << std::endl;

	return out;
}

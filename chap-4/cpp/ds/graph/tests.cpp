#include "tests.hpp"
#include <iostream>
#include "colors.hpp"
#include "simple_graph.hpp"
#include <set>

void TestSuite::testFeatures(){
	for(unsigned int i = 0; i < this->features.size(); i++){
		Feature f = this->features[i];
		std::cout << colors::fblu("FEATURE [") << colors::fwht(std::to_string(i+1)) << colors::fblu("|") << colors::fblu(std::to_string(this->features.size()));
		std::cout << colors::fblu("]: ") << std::endl;
		std::cout << '\t' << colors::fmag("NAME: ") << colors::bold(colors::fcyn(f.name)) << std::endl;
		std::cout << '\t' << colors::fmag("DESCRIPTION: ") << colors::fyel(f.description) << std::endl;
		bool result = f.test();
		this->numTestsPassed += result ? 1 : 0;
		std::string resultString = result ? colors::fgrn("PASSED") : colors::fred("FAILED");
		std::cout << '\t' << colors::fmag("RESULT: ") << resultString << std::endl; 
	}

	std::cout << colors::bold(colors::fgrn(std::to_string(this->numTestsPassed))) << colors::bold(colors::fgrn("/")) << colors::bold(colors::fgrn(std::to_string(this->features.size()))); 
	std::cout << colors::fgrn(" TESTS PASSED.") << std::endl;
}

// Setup all the tests

GraphTestSuite::GraphTestSuite()
	: TestSuite()
{
	Feature f("Add Edge - Vertices", 
		"Given two vertices, add a new edge to our graph",
		Tests::testAddEdge_Vertices);
	features.push_back(f);

	Feature f1("Add Edge - Names", 
		"Given two vertex names, add a new edge to our graph",
		Tests::testAddEdge_Names);
	features.push_back(f1);

	Feature f2("Add Edge - Edge", 
		"Given an edge, add a new edge to our graph",
		Tests::testAddEdge_Edge);
	features.push_back(f2);

	Feature f3("Remove Edge - Names", 
		"Given two vertex names, remove the matching edge from our graph",
		Tests::testRemoveEdge_Names);
	features.push_back(f3);

	Feature f4("Remove Edge - Vertex", 
		"Given two vertices, remove the matching edge from our graph",
		Tests::testRemoveEdge_Vertices);
	features.push_back(f4);

	Feature f5("Remove Edge - Edge",
		"Given an edge reference, remove the matching edge from our graph",
	       Tests::testRemoveEdge_Edge);	
	features.push_back(f5);

	Feature f6("Contains Edge - Edge",
		"Given an edge reference, check to see if this edge is in the graph",
		Tests::testContainsEdge_Edge);
	features.push_back(f6);

	Feature f7("Contains Edge - Names",
		"Given two vertex names, check to see if an edge with those two vertices is in the graph",
		Tests::testContainsEdge_Names);
	features.push_back(f7);

	Feature f8("Contains Edge - Vertex",
		"Given two vertex references, check to see if a matching edge is in the graph",
		Tests::testContainsVertex_Vertex);
	features.push_back(f8);

	Feature f9("Get Edge - Vertex",
		"Given two vertices, return a matching edge within this graph",
		Tests::testGetEdge_Vertex);
	features.push_back(f9);

	Feature f10("Get Edge - Names",
		"Given two vertex names, return a matching edge within this graph",
		Tests::testGetEdge_Names);
	features.push_back(f10);

	Feature f11("Get Edge Set",
		"Return the set of edges in this graph",
		Tests::testGetEdgeSet);
	features.push_back(f11);

	Feature f12("Get Edge Set - Vertex",
		"Return the set of edges connected to this node",
		Tests::testGetEdgeSet_Vertex);
	features.push_back(f12);

	Feature f13("Get Edge Set - Name",
		"Return the set of edges connected a node with this name",
		Tests::testGetEdgeSet_Name);
	features.push_back(f13);

	Feature f14("Add Vertex - Name",
		"Create a new vertex given a name, and add it to the graph",
		Tests::testAddVertex_Name);
	Feature f15("Add Vertex - Vertex",
		"Add this vertex pointer to the graph",
		Tests::testAddVertex_Vertex);
	features.push_back(f15);

	Feature f16("Contains Vertex - Vertex",
		"Check if this vertex is present in our graph",
		Tests::testContainsVertex_Vertex);
	features.push_back(f16);

	Feature f17("Contains Vertex - Name",
		"Check if a vertex by this name is present in our graph",
		Tests::testContainsVertex_Name);
	features.push_back(f17);

	Feature f18("Get Neighbors - Vertex",
		"Given a vertex, return its neighbors",
		Tests::testGetNeighbors_Vertex);
	features.push_back(f18);

	Feature f19("Get Vertex Set",
		"Return the vertex set of this graph",
		Tests::testGetVertexSet);
	features.push_back(f19);

	Feature f20("Is Empty",
		"Given a graph, determine if the graph is empty",
		Tests::testIsEmpty);
	features.push_back(f20);

	Feature f21("Size",
		"Given a graph, determine the size of the graph",
		Tests::testSize);
	features.push_back(f21);

}

bool Tests::testAddEdge_Vertices(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B");
	auto e = g.addEdge(v1, v2);
	auto ret = g.addEdge(e);
	if(ret == e && g.size() == 1)
		return true;
	return false;
}

bool Tests::testAddEdge_Names(){
	SimpleGraph g("test");
	auto e = g.addEdge("A", "B");
	if(g.size() == 1)
		return true;
	return false;
}

bool Tests::testAddEdge_Edge(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B");
	auto edge = std::make_shared<Edge>(v1, v2);
	auto ret = g.addEdge(edge);
	if(g.size() == 1 && ret == edge)
		return true;
	return false;
}

bool Tests::testAddEdge_Cost(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B");
	auto edge = std::make_shared<Edge>(v1, v2, 1.0);
	auto ret = g.addEdge(edge);
	if(g.size() == 1 && ret == edge)
		return true;
	return false;
}

bool Tests::testRemoveEdge_Edge(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B");
	auto edge = std::make_shared<Edge>(v1, v2, 1.0);

	auto ret = g.addEdge(edge);
	if(g.removeEdge(edge))
		return true;
	return false;
}

bool Tests::testRemoveEdge_Vertices(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B");
	auto e = g.addEdge(v1, v2);
	g.addEdge(e);
	if(g.removeEdge(v1, v2))
		return true;
	return false;
}

bool Tests::testRemoveEdge_Names(){
	SimpleGraph g("test");
	auto e = g.addEdge("A", "B");
	if(g.removeEdge("A", "B"))
		return true;
	return false;
}

bool Tests::testContainsEdge_Names(){
	SimpleGraph g("test");
	auto e = g.addEdge("A", "B");
	if(g.containsEdge("A", "B"))
		return true;
	return false;
}

bool Tests::testContainsEdge_Edge(){
	SimpleGraph g("test");
	auto e = g.addEdge("A", "B");
	if(g.containsEdge(e))
		return true;
	return false;
}

bool Tests::testGetEdge_Names(){
	SimpleGraph g("test");
	auto e = g.addEdge("A", "B");
	if(e == g.getEdge("A", "B"))
		return true;
	return false;
}

bool Tests::testGetEdge_Vertex(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B");
	auto e = g.addEdge(v1, v2);
	if(e == g.getEdge(v1, v2))
		return true;
	return false;
}

bool Tests::testGetEdgeSet(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B");
	auto v3 = std::make_shared<Vertex>("C");
	auto v4 = std::make_shared<Vertex>("D");
	auto v5 = std::make_shared<Vertex>("E");
	auto v6 = std::make_shared<Vertex>("F");

	auto edge1 = std::make_shared<Edge>(v1, v2);
	auto edge2 = std::make_shared<Edge>(v3, v4);
	auto edge3 = std::make_shared<Edge>(v5, v6);
	auto v = std::make_shared<Vertex>("G");
	g.addVertex(v);
	g.addEdge(edge1);
	g.addEdge(edge2);
	g.addEdge(edge3);
	if(g.getEdgeSet().size() == 3)
		return true;

	return false;
}

bool Tests::testGetEdgeSet_Name(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B");
	auto v3 = std::make_shared<Vertex>("C");
	auto v4 = std::make_shared<Vertex>("D");

	auto edge1 = std::make_shared<Edge>(v1, v2);
	auto edge2 = std::make_shared<Edge>(v1, v3);
	auto edge3 = std::make_shared<Edge>(v1, v4);
	g.addEdge(edge1);
	g.addEdge(edge2);
	g.addEdge(edge3);

	auto edgeSet = g.getEdgeSet("A");
	for(auto e : edgeSet){
		std::cout << *e << std::endl;
	}
	//std::set<std::shared_ptr<Edge> , Graph<Vertex, Edge >::EdgePtrNameCmp>  s;
	std::set<std::shared_ptr<Edge> >  s;
	s.insert(edge1);
	s.insert(edge2);
	s.insert(edge3);
	for(auto e : s){
		std::cout << *e << std::endl;
	}
	if(edgeSet == s)
		return true;
	
	return false;
}

bool Tests::testGetEdgeSet_Vertex(){
	SimpleGraph g("test");
	auto v = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B");
	auto v3 = std::make_shared<Vertex>("C");
	auto edge1 = g.addEdge(v, v2);
	auto edge2 = g.addEdge(v, v3);
	std::set<std::shared_ptr<Edge> > s;
	auto edgeSet = g.getEdgeSet(v);
	s.insert(edge1);
	s.insert(edge2);
	if(s == edgeSet){
	       return true;
	}	       
	

	return false;
}

bool Tests::testAddVertex_Name(){
	SimpleGraph g("test");
	g.addVertex("A");
	if(g.containsVertex("A"))
		return true;
	return false;
}

bool Tests::testAddVertex_Vertex(){
	SimpleGraph g("test");
	auto vertex = std::make_shared<Vertex>("A");
	g.addVertex(vertex);
	if(g.containsVertex(vertex))
		return true;
	return false;
}

bool Tests::testContainsVertex_Name(){
	SimpleGraph g("test");
	auto vertex = std::make_shared<Vertex>("A");
	g.addVertex(vertex);
	if(g.containsVertex("A"))
		return true;
	return false;
}

bool Tests::testContainsVertex_Vertex(){
	SimpleGraph g("test");
	auto vertex = std::make_shared<Vertex>("A");
	g.addVertex(vertex);
	if(g.containsVertex(vertex))
		return true;
	return false;
}

bool Tests::testGetNeighbors_Name(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B"); 
	auto v3 = std::make_shared<Vertex>("C"); 
	auto v4 = std::make_shared<Vertex>("D"); 

	auto edge1 = std::make_shared<Edge>(v1, v2); 
	auto edge2 = std::make_shared<Edge>(v1, v3);
	auto edge3 = std::make_shared<Edge>(v1, v4);
	g.addEdge(edge1);
	g.addEdge(edge2);
	g.addEdge(edge3);

	auto neighbors = g.getNeighbors("A");
	std::set<std::shared_ptr<Vertex> > s;
	s.insert(edge1->end);
	s.insert(edge2->end);
	s.insert(edge3->end);
	
	if(neighbors == s)
		return true;
	return false;
}

bool Tests::testGetNeighbors_Vertex(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B"); 
	auto v3 = std::make_shared<Vertex>("C"); 
	auto v4 = std::make_shared<Vertex>("D"); 

	auto edge1 = std::make_shared<Edge>(v1, v2); 
	auto edge2 = std::make_shared<Edge>(v1, v3);
	auto edge3 = std::make_shared<Edge>(v1, v4);

	g.addEdge(edge1);
	g.addEdge(edge2);
	g.addEdge(edge3);

	auto neighbors = g.getNeighbors(v1);
	std::set<std::shared_ptr<Vertex> > s;
	s.insert(v2);
	s.insert(v3);
	s.insert(v4);

	if(neighbors == s)
		return true;

	return false;
}

bool Tests::testRemoveVertex_Vertex(){
	SimpleGraph g("test");
	auto vert = std::make_shared<Vertex>("A");
	g.addVertex(vert);
	auto isRemoved = g.removeVertex(vert);
	if(isRemoved && g.getVertex("A") == nullptr)
		return true;

	return false;
}

bool Tests::testRemoveVertex_Name(){
	SimpleGraph g("test");
	auto vert = std::make_shared<Vertex>("A");
	g.addVertex(vert);
	auto isRemoved = g.removeVertex("A");
	if(isRemoved && g.getVertex("A") == nullptr)
		return true;

	return false;
}

bool Tests::testGetVertex_Name(){
	SimpleGraph g("test");
	g.addVertex(std::make_shared<Vertex>("A"));
	auto vert = g.getVertex("A");
	if(vert->getName() == "A")
		return true;
	return false;
}

bool Tests::testGetVertexSet(){
	SimpleGraph g("test");
	g.addVertex(std::make_shared<Vertex>("A"));
	g.addVertex(std::make_shared<Vertex>("B"));
	g.addVertex(std::make_shared<Vertex>("C"));
	auto vertexSet = g.getVertexSet();
	if(vertexSet.size() == 3)
		return true;

	return false;
}
bool Tests::testIsEmpty(){
	SimpleGraph g("test");
	if(g.isEmpty())
		return true;
	
	return false;
}

bool Tests::testSize(){
	SimpleGraph g("test");
	auto v1 = std::make_shared<Vertex>("A");
	auto v2 = std::make_shared<Vertex>("B");
	auto edge = std::make_shared<Edge>(v1, v2);
	g.addEdge(edge);
	g.addVertex(std::make_shared<Vertex>("C"));
	if(g.size() == 1)
		return true;

	return false;
}



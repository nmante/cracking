#include "tests.hpp"
#include <iostream>
#include "colors.hpp"

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
		"Given a vertex, return it's neighbors",
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
	return false;
}

bool Tests::testAddEdge_Names(){
	return false;
}

bool Tests::testAddEdge_Edge(){
	return false;
}

bool Tests::testAddEdge_Cost(){
	return false;
}

bool Tests::testRemoveEdge_Edge(){
	return false;
}

bool Tests::testRemoveEdge_Vertices(){
	return false;
}

bool Tests::testRemoveEdge_Names(){
	return false;
}

bool Tests::testContainsEdge_Names(){
	return false;
}

bool Tests::testContainsEdge_Edge(){
	return false;
}

bool Tests::testGetEdge_Names(){
	return false;
}

bool Tests::testGetEdge_Vertex(){
	return false;
}

bool Tests::testGetEdgeSet(){
	return false;
}

bool Tests::testGetEdgeSet_Name(){
	return false;
}

bool Tests::testGetEdgeSet_Vertex(){
	return false;
}

bool Tests::testAddVertex_Name(){
	return false;
}

bool Tests::testAddVertex_Vertex(){
	return false;
}

bool Tests::testContainsVertex_Name(){
	return false;
}

bool Tests::testContainsVertex_Vertex(){
	return false;
}

bool Tests::testGetNeighbors_Name(){
	return false;
}

bool Tests::testGetNeighbors_Vertex(){
	return false;
}

bool Tests::testRemoveVertex_Vertex(){
	return false;
}

bool Tests::testRemoveVertex_Name(){
	return false;
}

bool Tests::testGetVertex_Name(){
	return false;
}

bool Tests::testGetVertexSet(){
	return false;
}

bool Tests::testIsEmpty(){
	return false;
}

bool Tests::testSize(){
	return false;
}



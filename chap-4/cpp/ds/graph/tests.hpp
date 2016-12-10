#ifndef __TESTS_HPP__
#define __TESTS_HPP__

#include <string>
#include <functional>
#include <vector>

class Feature{
public:
	std::string name;
	std::string description;
	std::function<bool()> test;
	Feature(std::string name, std::string description, std::function<bool()> test) :
		name(name),
		description(description),
		test(test)
	{}
	~Feature(){}

};

class TestSuite {
	int numTestsPassed = 0;
	
public:
	std::vector<Feature> features;
	TestSuite(){}
	void testFeatures();
};

class GraphTestSuite : public TestSuite{
public:
	GraphTestSuite(); 
	~GraphTestSuite(){}
};

namespace Tests{
	bool testAddEdge_Edge();
	bool testAddEdge_Vertices();
	bool testAddEdge_Names();
	bool testAddEdge_Cost();

	bool testRemoveEdge_Vertices();
	bool testRemoveEdge_Edge();
	bool testRemoveEdge_Names();

	bool testContainsEdge_Names();
	bool testContainsEdge_Edge();

	bool testGetEdge_Vertex();
	bool testGetEdge_Names();

	bool testGetEdgeSet();
	bool testGetEdgeSet_Vertex();
	bool testGetEdgeSet_Name();

	bool testAddVertex_Vertex();
	bool testAddVertex_Name();

	bool testContainsVertex_Vertex();
	bool testContainsVertex_Name();

	bool testGetNeighbors_Vertex();
	bool testGetNeighbors_Name();

	bool testRemoveVertex_Vertex();
	bool testRemoveVertex_Name();

	bool testGetVertex_Name();
	bool testGetVertexSet();

	bool testIsEmpty();
	bool testSize();
}



#endif // __TESTS_HPP__

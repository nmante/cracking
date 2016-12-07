#include "tests.hpp"
#include <iostream>
#include "colors.hpp"

void GraphTestSuite::runTests(){
	for(unsigned int i = 0; i < this->features.size(); i++){
		Feature f = this->features[i];
		std::cout << colors::fblu("FEATURE [") << colors::fblu(std::to_string(i+1)) << colors::fblu("|") << colors::fblu(std::to_string(this->features.size()));
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

GraphTestSuite::GraphTestSuite(){
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

	/*
	Feature f3("Add Edge - Edge", 
		"Given an edge, add a new edge to our graph",
		Tests::testAddEdge_Names);
	features.push_back(f3);
	*/

}
bool Tests::testAddEdge_Vertices(){
	return true;
}

bool Tests::testAddEdge_Names(){
	return true;
}

bool Tests::testAddEdge_Edge(){
	return true;
}




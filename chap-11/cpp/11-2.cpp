#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <time.h>
#include <set>
#include <queue>

/*
 * Problem 11-2
 * How would you design the data structures for a very large social network
 * (Facebook, LinkedIn, etc.)?
 *
 * Describe how you would design an algorithm to show the connections, or 
 * path, between two people (e.g., Me -> Bob -> Susan -> Nii -> You).
 */

/*
 * Solution
 * 	- Each person is a node
 * 	- Each person has list of people references, aka friends
 * 	- could have convenience methods for 'isFriend'
 * 	- Ultimately, the entire network of people would be 
 * 	a graph or several graphs, since not all people are friends
 * 	- one machine stores all people
 * 	- For finding if people are friends, just do a Breadth First 
 * 	Search (BFS) 
 *
 * Follow Up (one machine runs out of space)
 * 	- if one person's friend list can't be contained on one machine two options
 * 		- move entire person to new machine with friend list
 * 		- create a new ref on new machine, with rest of friend list there
 *	- Store diff people on different machines 
 * 		- Could be locality based (most people are friends with people 
 * 		geographically near them)
 * 	- Could have proxy that routes requests for persons 
 * 		- sharding essentially
 *
 * Full Fledged
 * 	- Could use a graph database like Neo4j, GraphDB to store users
 *
 */

class Person {
	int mID;
	std::string mName;
	std::map<int, Person*> friendsMap;

public:
	Person(std::string name, int id) : mID(id), mName(name) {}
	int getID() const { return mID; }
	std::string getName() const { return mName; }
	std::map<int, Person*> getFriends() const { return friendsMap; }

	Person *addFriend(Person *p){
		int pID = p->getID();
		// Add if this is a new friend, and if it's not us
		if(this->getID() != pID && friendsMap.count(pID) == 0){
			friendsMap[pID] = p;
		}
		return p;
	}

	bool removeFriend(int pID){
		if(friendsMap.count(pID) == 0){
			return false;
		}
		friendsMap.erase(pID);
		return true;
	}

	bool removeFriend(Person *p){
		return removeFriend(p->getID());
	}
	void print(){
		std::cout << "ID: " << mID;
		std::cout << " NAME: " << mName << std::endl;
		std::cout << "-------" << std::endl;
		std::cout << "FRIENDS" << std::endl;
		for(auto &pair : this->friendsMap){
			std::string name = pair.second->getName();
			std::cout << name << ", "; 
		}
		std::cout << std::endl;
		std::cout << "-------" << std::endl;
	}
};

class Machine {
	int mID;
	int mNumPeoplePerMachine;
	std::map<int, Person*> peopleMap;

public:
	Machine(int id, int numPeople) : mID(id), mNumPeoplePerMachine(numPeople) {} 
	~Machine(){
		for(auto &p : peopleMap){
			this->removePerson(p.first);
		}
	}
	bool addPerson(Person *p){
		if(!p || size() == mNumPeoplePerMachine){
			return false;
		}
		peopleMap[p->getID()] = p;
		return true;
	}
	Person *getPerson(int personID){
		if(peopleMap.count(personID) == 0){
			return nullptr;
		}
		return peopleMap[personID];
	}

	bool removePerson(int personID){
		bool res = false;
		for(auto &pair : this->peopleMap){
			int pID = pair.first; 
			Person *fr = pair.second;
			Person *pToRemove = getPerson(personID);
			if(fr == pToRemove){
				// this is the person we need to remove
				delete pToRemove;
				this->peopleMap.erase(pID);
				res = true;
			}else{
				res = fr->removeFriend(pToRemove);
			}
		}
		return false || res;
	}
	int size() const { return peopleMap.size(); }
	void print(){
		std::cout << "========" << std::endl;
		std::cout << "MACHINE: " << mID << std::endl;
		for(auto &pair : peopleMap){
			Person *p = pair.second;
			p->print();
		}
		std::cout << "========" << std::endl;
	}
};

class Server {
	static int sPeopleIDs;
	static int sMachineIDs;
	int mNumPeoplePerMachine = 10;
	std::vector<Machine*> machines;

public:
	Server(int numPeoplePerMachine) : mNumPeoplePerMachine(numPeoplePerMachine) {
		// Make first machine
		this->createMachine();
	}	

	int machineIDForPersonID(int personID){
		/*
		 * - Three options
		 * 	- Hash method 
		 * 		- O(n) space, O(1) access
		 * 		- could have a hash that has person ids as keys,
		 * 		list of machine ids as value
		 * 	- Calculate method (USING THIS)
		 * 		- Constant time and no extra space 
		 * 	- Store machine id in person data structure
		 * 		- O(1) space, each id is 32bit, could make it 64 bit
		 * 		- add 8 bytes to each person
		 */
		return personID / mNumPeoplePerMachine;
	}

	int numberMachines() const { return machines.size(); }

	Machine *createMachine(){
		Machine *m = new Machine(sMachineIDs++, mNumPeoplePerMachine);
		machines.push_back(m);
		return m;
	}

	Person *createPerson(std::string name){
		// Get machine id
		int machineID = machineIDForPersonID(sPeopleIDs);
		Machine *m = nullptr;

		// Create machine if necessary
		if(numberMachines() == machineID){
			m = createMachine();
		}else{
			m = machines[machineID];
		}

		// Add person to machine 
		Person *p = new Person(name, sPeopleIDs++);
		m->addPerson(p);
		
		return p;
	}
	
	Person *getPerson(int personID){
		int machineID = this->machineIDForPersonID(personID);
		if(machineID >= this->numberMachines()){
			return nullptr;
		}
		return machines[machineID]->getPerson(personID);
	}

	bool makeFriends(Person *p1, Person *p2){
		if(!p1 || !p2){
			return false;
		}

		p1->addFriend(p2);
		p2->addFriend(p1);
		return true;
	}

	bool makeFriends(int id1, int id2){
		Person *p1 = this->getPerson(id1);
		Person *p2 = this->getPerson(id2);
		return this->makeFriends(p1, p2);
	}

	bool removePerson(Person *p){
		// The person will exist one one machine
		// But there may be pointers to the person on 
		// every machine (due to friendships)
		bool deleted = false;
		
		// For each machine, remove friend connections, AND the friend
		for(auto &m : this->machines){
			// if any machine deleted, we were successful
			deleted |= m->removePerson(p->getID());
		}
		return deleted;
	}

	void print(){
		std::cout << "SERVER" << std::endl;
		for(auto &m : this->machines){
			m->print();
		}
	}

	std::vector<Person*> BFS(int p1ID, int p2ID){

		Person *source = this->getPerson(p1ID), *end = this->getPerson(p2ID);
		if(!source || !end){
			return {};
		}

		std::set<Person*> visited;
		std::queue<std::vector<Person*>> Q;
		Q.push({source});
		std::vector<Person*> finalPath;

		while(!Q.empty()){
			auto path = Q.front(); Q.pop();
			Person *curr = path.back();
			if(curr == end){
				finalPath = path;
				break;
			}else if(visited.count(curr) == 0){
				for(auto &pair: curr->getFriends()){
					Person *neighbor = pair.second;
					std::vector<Person*> newPath(path);
					newPath.push_back(neighbor);
					
					Q.push(newPath);
				}
				visited.insert(curr);
			}
		}
		
		return finalPath;
	}
};

int Server::sPeopleIDs = 0;
int Server::sMachineIDs = 0;

template <class T>
class Node{
public:
	Node *parent;
	T *val;
	Node(T *val, Node *parent) : val(val), parent(parent) {}
};

void printPath(std::vector<Person*> &path){
	for(auto &p : path){
		std::cout << p->getName() << " -> ";
	}
	std::cout << "NULL" << std::endl;

}

void test(){
	// Init a server
	Server s(4);

	// Create some people
	std::vector<std::string> names({
		"James", "Nii", "Zach", "Kendyl", "Zain",
		"Chima", "Joey", "David", "Fred", "Charles",
		"Naa Adei", "Zenaida", "Nii Kojo", "Florence",
		"Jon", "Jay", "Jesper", "Ruchi", "Andrew"
	});
	for(auto &n : names){
		s.createPerson(n);
	}

	// Make some friends
	s.makeFriends(0, 1);
	s.makeFriends(1, 2);
	s.makeFriends(2, 3);
	s.makeFriends(3, 4);
	s.makeFriends(4, 5);
	s.makeFriends(5, 6);
	s.makeFriends(6, 7);
	s.makeFriends(7, 8);

	// Find path for James, Fred 
	auto path = s.BFS(0, 8);
	printPath(path);
	
	// Find path for Zach, Chima
	path = s.BFS(2, 5);
	printPath(path);

	// Find path for Nii, Kendyl
	path = s.BFS(1, 3);
	printPath(path);
}

int main(){
	std::srand(time(NULL));
	test();
	return 0;
}

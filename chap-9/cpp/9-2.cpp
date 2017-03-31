#include <iostream>
#include <vector>

/*
 * Problem 9-2
 * Write a method to sort an array of strings so that all
 * the anagrams are next to each other.
 *
 * iceman, cinema, abc, bca, cba, are, ear
 *
 * abc, are, bca, cba, cinema, ear, iceman
 *
 * abc, bca, cba, are, cinema, ear, iceman
 *
 * abc, bca, cba, are, ear, cinema, iceman
 *
 * choose element, store as min
 * if we see another min, update
 * once we reach end, insert min
 * now iterate again, search for min and anagram
 *
 * abc, bca, cba, 
 */

typedef std::vector<std::string> StringList;

void printList(StringList & arr){
	for(auto el : arr){
		std::cout << el << ", ";
	}
	std::cout << std::endl;
}

bool isAnagram(std::string str, std::string str2){
	if(str.length() != str2.length()){
		return false;
	}
	std::vector<int> hit(256, 0);
	std::vector<int> hit2(256, 0);
	for(int i = 0; i < (int)str.length(); i++){
		hit[(int)str[i]] += 1;
		hit2[(int)str2[i]] += 1;
	}
	return hit2 == hit;
}

void sortArrayOfStrings(StringList &arr){
	for(int i = 0; i < (int)arr.size(); i++){
		std::string min = arr[i];
		int minIndex = i;
		for(int j = i + 1; j < (int)arr.size(); j++){
			if(arr[j] < min){
				min = arr[j];
				minIndex = j;
			}
		}
		std::string temp = arr[i];
		arr[i] = min;
		arr[minIndex] = temp;
	}
	printList(arr);

	// now do anagram sort
	for(int i = 0; i < (int)arr.size() - 1; i++){
		for(int j = i + 1; j < (int)arr.size(); j++){
			if(isAnagram(arr[i], arr[j])){
				std::string temp = arr[i+1];
				arr[i+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printList(arr);

}

int main(int argc, char *argv[]){
	StringList a = {"iceman", "cinema", "abc", "bca", "cba", "are", "ear"};
	sortArrayOfStrings(a);
	return 0;
}

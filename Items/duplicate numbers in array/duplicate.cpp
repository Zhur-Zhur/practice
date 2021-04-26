#include <iostream>
#include <vector>

//return a vector of all duplicate numbers in the num array in range [0...size-1]. O(n) time, O(n) space
std::vector<int> find_duplicate(int* num, int size){
	int flags[size] = {0};
	for(int i = 0; i < size; i++) flags[num[i]] += 1; //sum all occurrences, O(n) time
	
	std::vector<int> duplicate;
	for(int i = 0; i < size; i++) if (flags[i] > 1) duplicate.push_back(i); //Make list of duplicate numbers, O(n) time
	return duplicate;
}

int main(){
	int test_0[8] = {1,2,3,5,0,3,0,7};
	for (int num : find_duplicate(test_0, 8)) std::cout << num << std::endl;
	return 0;
}
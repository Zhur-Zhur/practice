#include <iostream>
#include <vector>

//return a vector of all missing numbers in the num array in range [0...size-1]. O(n) time, O(n) space
std::vector<int> find_missing(int* num, int size){
	bool flags[size] = {0};
	for(int i = 0; i < size; i++) flags[num[i]] = 1; //Flag all occurrences, O(n) time
	
	std::vector<int> missing;
	for(int i = 0; i < size; i++) if (!flags[i]) missing.push_back(i); //Make list of missing numbers, O(n) time
	return missing;
}

int main(){
	int test_0[6] = {1,2,3,5,0,3};
	for (int num : find_missing(test_0, 6)) std::cout << num << std::endl;
	return 0;
}
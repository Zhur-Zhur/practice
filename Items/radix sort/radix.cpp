#include <iostream>
#include <list>

//helper function to find the maximum value in the array
//Time: O(n)
int max_value(int* arr, int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max) 
			max = arr[i];
	return max;
}

//sort performed on array for a given digit
//Time: O(n)
//Space: O(n), buckets will not take more space then n
void _sort(int* arr, int size, int place) {
	std::list<int> buckets[10];  //storage buckets
	int i;
	for (i = 0; i < size; i++)
		buckets[(arr[i]/place)%10].push_back(arr[i]); //place into buckets
	
	i = 0;
	for(auto bucket: buckets)
		for (int num: bucket)
			arr[i++] = num;

}

//LSD radix sort
//Time: O(n*k), k is number of digits in max.
//	If k is large time complexity can be worse then O(n^2), k >= n
//Space: O(n)
void radix_sort(int* arr, int size) {
	int max = max_value(arr, size);
	for (int i = 1; 1 > (i / max); i *= 10)
		_sort(arr, size, i);

}

int main() {
	int arr[] = {259, 9, 803, 64, 79, 849, 5, 429, 32, 3, 112, 85};
	int n = sizeof(arr) / sizeof(arr[0]);
	radix_sort(arr, n);
	for (int n : arr)
		std::cout << n << std::endl;

	return 0;
}
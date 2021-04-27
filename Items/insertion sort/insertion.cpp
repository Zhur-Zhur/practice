#include <iostream>

//Insertion sort O(n^2) time.
void insertion_sort(int* arr, int size){
	int temp, j;
	for(int i = 1; i < size; i++){
		temp = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > temp){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

int main(){
	int arr[] = {12, 6, 123, 72, 235, 93, 134, 12};
	int size = sizeof(arr)/sizeof(arr[0]); 
	insertion_sort(arr, size);
	for(int num : arr){
		std::cout << num << std::endl;
	}
	return 0;
}
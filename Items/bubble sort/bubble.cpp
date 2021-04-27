#include <iostream>

//Bubble sort O(n^2) time.
void bubble_sort(int* arr, int size){
	int temp;
	for(int n = 0; n < size-1; n++){
		for(int m = 0; m < size-n-1; m++){
			if(arr[m] > arr[m+1]){
				temp = arr[m+1];
				arr[m+1] = arr[m];
				arr[m] = temp;
			}
		}
	}
}

int main(){
	int arr[] = {12, 6, 123, 72, 235, 93, 134, 12};
	int size = sizeof(arr)/sizeof(arr[0]); 
	bubble_sort(arr, size);
	for(int num : arr){
		std::cout << num << std::endl;
	}
	return 0;
}
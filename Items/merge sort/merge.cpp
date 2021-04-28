#include <iostream>
#include <string.h>

/* Merge sort O(nLogn) time.
 * By moving the array pointer in the recersive calls and passing the size of 
 * the sub array merge_sort does not need the right bounds for the right block
 * or the right bound for the left block.
 * No more then O(n) space is used for the temp array.
 */
void merge_sort(int* arr, int size){
	if (size <= 1) return; //Base case
	int pivot = size/2; //Rounds down
	merge_sort(arr, size-pivot); //Left
	merge_sort(arr+pivot, size-(size-pivot)); //Right
	
	int k = 0, i = 0, j = size-pivot;
	int temp[size]; //Temp storage for sorted array
	
	//Merge
	while (i < size-pivot && j < size)
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];

	//Leftovers in left
	while (i < size-pivot) temp[k++] = arr[i++];

	//Leftovers in right
	while (j < size) temp[k++] = arr[j++];

	memcpy(arr, temp, size*sizeof(int)); //write sorted array to memory
}

int main(){
	int arr[] = {12, 6, 123, 72, 235, 93, 134, 12};
	int size = sizeof(arr)/sizeof(arr[0]); 
	merge_sort(arr, size);
	for(int num : arr){
		std::cout << num << std::endl;
	}
	return 0;
}
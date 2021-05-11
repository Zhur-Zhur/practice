#include <iostream>
#include <string.h>

/* Quick sort
 * Worst case time: O(n^2), pivot selected is always largest or smallest value in partition
 * Best case time: O(nLog(n)), pivot is middle value of array and recursion only requires Log(n) depth to sort everything.
 * Space: O(n)
 */
void quick_sort(int* arr, int size){
	if (size < 2) return; //Array already sorted
	
	int pivot = arr[size-1];  //Last element pivot
	int temp, i = 0;
		
	//Move all values equal or less then to the left of the pivot
	for (int j = 0; j < size-1; j++)
		if (arr[j] <= pivot){
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
		}

	//Swap the pivot with the leftmost value that is greater then it.
	arr[size-1] = arr[i];
	arr[i] = pivot;
		
	quick_sort(arr, i); //Quick sort everything to the left of the pivot
	quick_sort(arr+i, size-(i)); //Quick sort everything to the right of the pivot
}

int main() {
	int arr[] = { 12, 6, 123, 9, 72, 235, 93, 134, 12, 12 };
	int size = sizeof(arr) / sizeof(arr[0]);
	quick_sort(arr, size);
	for (int num : arr) {
		std::cout << num << std::endl;
	}
	return 0;
}
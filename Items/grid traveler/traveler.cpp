#include <iostream>
#include <chrono>

//Calculate how many ways you can travel to the bottom right corner of a x by y grid. O(xy) time, and O(xy) space (storing memo)
//Technically memo is never deleted so memory leak can happen but this implementation doesn't care.
int travel_r(int x, int y, int* memo = NULL, int y_max = 0){
	if (memo == NULL){
		y_max = y; // C++ requires passing one of the side lengths for 2D arrays.
		memo = new int[x*y]();	
	}
	if (x <= 0 || y <= 0) return 0;
	if (x == 1 || y == 1) return 1;
	if (memo[(x-1)*y_max + (y-1)] != 0) return memo[(x-1)*y_max + (y-1)];
	memo[(x-1)*y_max + (y-1)] = travel_r(x-1, y, memo, y_max) + travel_r(x, y-1, memo, y_max);
	return memo[(x-1)*y_max + (y-1)];
}

//Calculate how many ways you can travel to the bottom right corner of a x by y grid. O(xy) time, and O(xy) space
int travel_i(int x, int y){
	if (x <= 0 || y <= 0) return 0;
	int grid[x][y] = {};
	grid[0][0] = 1;
	for(int n = 0; n < x; n++) for(int m = 0; m < y; m++){
			if (n < x-1) grid[n+1][m] += grid[n][m];
			if (m < y-1) grid[n][m+1] += grid[n][m];
		}
	return grid[x-1][y-1];
}


int main(){
	auto begin = std::chrono::high_resolution_clock::now();

	//Recursive Grid Travel O(nm) time, O(nm) space.
	std::cout << "Recursive Grid Travel";
	for (int x = 0; x < 10; x++) for (int y = 0; y < 10; y++) {
		begin = std::chrono::high_resolution_clock::now();
		std::cout << "travel_r(" << x << "," << y << ") = " << travel_r(x,y) << " ";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - begin).count() << std::endl;
	}
	
	//Iterative Grid Travel O(nm) time, O(nm) space.
	std::cout << "\nIterative Grid Travel";
	for (int x = 0; x < 10; x++) for (int y = 0; y < 10; y++) {
		begin = std::chrono::high_resolution_clock::now();
		std::cout << "travel_i(" << x << "," << y << ") = " << travel_i(x,y) << " ";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - begin).count() << std::endl;
	}

	return 0;
}
#include <iostream>
#include <ctime>
/*
int fib_r(int n){
	
}
*/
long long fib_i(int n){
	long long sum_0 = 0,
		sum_1 = 1,
		sum_f = 0;
	if(n < 1) return 0;
	if(n == 1) return 1;
	for(int i = 2; i <= n; i++){
		sum_f = sum_0 + sum_1;
		sum_0 = sum_1;
		sum_1 = sum_f;
	}
	return sum_f;
}

int main(){
	std::clock_t begin;
	
	//Iterative fibonacci O(n) time, O(1) space.
	std::cout << "Iterative fibonacci" << std::endl;
	//fib(0) = 0
	begin = clock();
	std::cout << "fib_i(0) = " << fib_i(0) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(1) = 1
	begin = clock();
	std::cout << "fib_i(1) = " << fib_i(1) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(2) = 1
	begin = clock();
	std::cout << "fib_i(2) = " << fib_i(2) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(3) = 2
	begin = clock();
	std::cout << "fib_i(3) = " << fib_i(3) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(5) = 5
	begin = clock();
	std::cout << "fib_i(5) = " << fib_i(5) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(10) = 55
	begin = clock();
	std::cout << "fib_i(10) = " << fib_i(10) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(20) = 6765
	begin = clock();
	std::cout << "fib_i(20) = " << fib_i(20) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(50) = 12586269025
	begin = clock();
	std::cout << "fib_i(50) = " << fib_i(50) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	
	return 0;
}

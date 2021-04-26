#include <iostream>
#include <ctime>

/* Calculate fibonacci numbers recursively using a memo to speed up calculations
 * The attempt to use recursive lambda functions because I wasn't feeling like 
 * passing a refrence to a array to act as a memo has reminded me not to bodge
 * a midnight, it doesn't end well.
 */
/*
#include <functional>

long fib_r(int n){
	if (n < 1) return 0L;
	if (n == 1) return 1L;
	 long memo[n];
	for(int i = 0; i < n; i++) memo[i] = -1L;
	
	std::function< long(int)> calc_fib = [&](int m){
		std::cout << m << std::endl;
		if (memo[m] != -1L){
			std::cout <<"e1 "<< m << std::endl;
			std::cout <<"e1 "<< memo[m] << std::endl;
			return memo[m];
		}
		if (m == 0){
			std::cout <<"e2 "<< m << std::endl;
			return 0L;
		}
		if (m == 1){
			std::cout <<"e3 "<< m << std::endl;
			return 1L;
		}
		memo[m] = calc_fib(m-1) + calc_fib(m-2);
		return memo[m];
	};
	
	long long calc_fib(int n){
		if (memo[n] != -1) return memo[n];
		if (n == 0) return 0;
		if (n == 1) return 1;
		memo[n] = calc_fib(n-1) + calc_fib(n-2);
		return memo[n];
	}
	long v = calc_fib(n);
	std::cout << "-----" << std::endl;
	for( long num: memo){
		std::cout << num << " ";
	}
	std::cout<<std::endl;
	return v;
}
*/

//Calculate fibonacci numbers recursively using a memo to speed up calculations, dictionaries (maps) are nice.
#include <unordered_map>
long long fib_r(int n, std::unordered_map<int, long long> *memo = new std::unordered_map<int, long long>){
	if (memo->find(n) != memo->end()) return (*memo)[n];
	if (n == 0) return 0ll;
	if (n == 1) return 1ll;
	(*memo)[n] = fib_r(n-1, memo) + fib_r(n-2, memo);
	return (*memo)[n];
}

//Calculate fibonacci numbers iteratively
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
	
	//Recursive fibonacci .
	std::cout << "Recursive  fibonacci" << std::endl;
	//fib(0) = 0
	begin = clock();
	std::cout << "fib_r(0) = " << fib_r(0) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(1) = 1
	begin = clock();
	std::cout << "fib_r(1) = " << fib_r(1) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(2) = 1
	begin = clock();
	std::cout << "fib_r(2) = " << fib_r(2) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(3) = 2
	begin = clock();
	std::cout << "fib_r(3) = " << fib_r(3) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(5) = 5
	begin = clock();
	std::cout << "fib_r(5) = " << fib_r(5) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(10) = 55
	begin = clock();
	std::cout << "fib_r(10) = " << fib_r(10) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(20) = 6765
	begin = clock();
	std::cout << "fib_r(20) = " << fib_r(20) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;
	//fib(50) = 12586269025
	begin = clock();
	std::cout << "fib_r(50) = " << fib_r(50) << " ";
	std::cout << double(clock() - begin) / CLOCKS_PER_SEC << std::endl;

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

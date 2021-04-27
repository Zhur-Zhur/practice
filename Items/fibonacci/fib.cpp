#include <iostream>
#include <chrono>

//Calculate fibonacci numbers recusively without a memo.
long long fib_terrible(int n){
	if (n == 0) return 0ll;
	if (n == 1) return 1ll;
	return fib_terrible(n-1) + fib_terrible(n-2);
}

//Calculate fibonacci numbers recursively using a memo to speed up calculations, using lamda functions.
#include <functional>
long long fib_r_lamda(int n){
	//Create memo array in a higher scope.
	long long memo[n+1];
	for(int i = 0; i <= n; i++) memo[i] = 0ll;
	
	//Lamda function to calculate fibonacci numbers recusively
	std::function<long long(int)> calc_fib = [&](int m){
		if (memo[m] != 0ll)	return memo[m];
		if (m == 0) return 0ll;
		if (m == 1) return 1ll;
		memo[m] = calc_fib(m-1) + calc_fib(m-2);
		return memo[m];
	};

	return calc_fib(n);
}

//Calculate fibonacci numbers recursively using a memo to speed up calculations, array instead of dictionary (map).
//Technically memo is never deleted so memory leak can happen but this implementation doesn't care.
long long fib_r_alt(int n, long long *memo = NULL){
	//Allocate array initialy
	if (memo == NULL){
		memo = new long long[n+1];
		for(int i = 0; i <= n; i++) memo[i] = 0ll;
	}
	if (memo[n] != 0ll) return memo[n];
	if (n == 0) return 0ll;
	if (n == 1) return 1ll;
	memo[n] = fib_r_alt(n-1, memo) + fib_r_alt(n-2, memo);
	return memo[n];
}

//Calculate fibonacci numbers recursively using a memo to speed up calculations, dictionaries (maps) are nice.
//Technically memo is never deleted so memory leak can happen but this implementation doesn't care.
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
	if (n < 1) return 0;
	if (n == 1) return 1;
	for (int i = 2; i <= n; i++){
		sum_f = sum_0 + sum_1;
		sum_0 = sum_1;
		sum_1 = sum_f;
	}
	return sum_f;
}

int main(){
	//fib(0) = 0
	//fib(1) = 1
	//fib(2) = 1
	//fib(3) = 2
	//fib(5) = 5
	//fib(10) = 55
	//fib(20) = 6765
	//fib(30) = 832040
	//fib(40) = 102334155
	//fib(50) = 12586269025

	std::array<int, 10> test_items =  {0, 1, 2, 3, 5, 10, 20, 30, 40, 50};
	auto begin = std::chrono::high_resolution_clock::now();
	//Recursive fibonacci O(n) time, O(n) space. Map memo
	std::cout << "Recursive  fibonacci (Map Memo)" << std::endl;
	for(int i : test_items){
		begin = std::chrono::high_resolution_clock::now();
		std::cout << "fib_r(" << i << ") = " << fib_r(i) << " ";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - begin).count() << std::endl;
	}

	//Recursive fibonacci O(n) time, O(n) space. Lamda Recursion, Array Memo
	std::cout << "\nRecursive  fibonacci (Lamda, Array Memo)" << std::endl;
	for(int i : test_items){
		begin = std::chrono::high_resolution_clock::now();
		std::cout << "fib_r_lamda(" << i << ") = " << fib_r_lamda(i) << " ";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - begin).count() << std::endl;
	}
	
	//Recursive fibonacci O(n) time, O(n) space. Array Memo
	std::cout << "\nRecursive  fibonacci (Array Memo)" << std::endl;
	for(int i : test_items){
		begin = std::chrono::high_resolution_clock::now();
		std::cout << "fib_r_alt(" << i << ") = " << fib_r_alt(i) << " ";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - begin).count() << std::endl;
	}
	
	//Recursive fibonacci O(2^n) time, O(n) space.
	std::cout << "\nRecursive  fibonacci (No Memo)" << std::endl;
	for(int i = 0; i < test_items.size()-1; i++){
		begin = std::chrono::high_resolution_clock::now();
		std::cout << "fib_terrible(" << test_items[i] << ") = " << fib_terrible(test_items[i]) << " ";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - begin).count() << std::endl;
	}
	std::cout << "fib_terrible(50) takes far too long" << std::endl;
	
	//Iterative fibonacci O(n) time, O(1) space.
	std::cout << "\nIterative fibonacci" << std::endl;
	for(int i : test_items){
		begin = std::chrono::high_resolution_clock::now();
		std::cout << "fib_i(" << i << ") = " << fib_i(i) << " ";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - begin).count() << std::endl;
	}
	
	return 0;
}

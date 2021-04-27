#include<iostream>

int main(){
	int a = 10;
	int b = 87;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	a = a + b;
	b = a - b;
	a = a - b;
	std::cout << "Addition/Subtraction swap." << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	std::cout << "XOR swap" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	return 0;
}
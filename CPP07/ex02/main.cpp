#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750
int main(int, char**)
{
	{
		Array<int> numbers(MAX_VAL);
		int *mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++) {
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "didn't save the same value!!" << std::endl;
				delete[] mirror;
				return 1;
			}
		}
		try {
			numbers[-2] = 0;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
		try {
			numbers[MAX_VAL] = 0;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
			numbers[i] = rand();
		delete[] mirror;
	}
	{
		std::cout << "out of bounds test: " << std::endl;
		Array<int>	empty;
		try {
			std::cout << empty[5] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << empty[-5] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "---------------------------------" << std::endl;
		std::cout << "int array test: " << std::endl;
		Array<int>	arr(5);
		srand(time(NULL));
		for (int i = 0; i < 5; i++) {
			arr[i] = rand() % 10;
		}
		std::cout << "array: ";
		for (int i = 0; i < 5; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	{
		std::cout << "---------------------------------" << std::endl;
		std::cout << "double array test: " << std::endl;
		Array<double>	arr(5);
		srand(time(NULL));
		for (int i = 0; i < 5; i++) {
			arr[i] = rand() % 10 + 0.5;
		}
		std::cout << "array: ";
		for (int i = 0; i < 5; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
}

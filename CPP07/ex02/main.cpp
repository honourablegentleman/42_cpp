#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"
#include "Array.tpp"

int main()
{
	{
		std::cout << "out of bounds test:" << std::endl;
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
		std::cout << "int array test:" << std::endl;
		Array<int>	arr(5);
		srand(time(NULL));
		for (int i = 0; i < 5; i++)
			arr[i] = rand() % 10;
		std::cout << "array: ";
		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "---------------------------------" << std::endl;
		std::cout << "double array test:" << std::endl;
		Array<double>	arr(5);
		srand(time(NULL));
		for (int i = 0; i < 5; i++)
			arr[i] = rand() % 10 + 0.5;
		std::cout << "array: ";
		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "---------------------------------" << std::endl;
		std::cout << "string array test:" << std::endl;
		Array<std::string>	arr(5);
		arr[0] = "this";
		arr[1] = "is";
		arr[2] = "very";
		arr[3] = "true";
		arr[4] = "yes";
		std::cout << "array: ";
		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << ", ";
		std::cout << std::endl;
	}
}

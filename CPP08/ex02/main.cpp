/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:36:09 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/05 13:36:12 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
	{
		std::cout << "subject test:" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "--------------------------------" << std::endl;
		std::cout << "float test:" << std::endl;
		MutantStack<float>	mstack;

		mstack.push(1.123f);
		mstack.push(4.432f);
		mstack.push(6.543f);
		mstack.push(3.546f);

		for (MutantStack<float>::iterator it = mstack.begin(); it != mstack.end(); it++)
			std::cout << *it << std::endl;
	}
	{
		std::cout << "--------------------------------" << std::endl;
		std::cout << "string test:" << std::endl;

		MutantStack<std::string>	mstack;

		mstack.push("this");
		mstack.push("is");
		mstack.push("very");
		mstack.push("true");

		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); it++)
			std::cout << *it << std::endl;
	}
	return 0;
}

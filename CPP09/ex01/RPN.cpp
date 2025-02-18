/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:05:52 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/17 13:05:55 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN &cpy)
{
	*this = cpy;
}

RPN	&RPN::operator=(const RPN &cpy)
{
	(void)cpy;
	return (*this);
}

RPN::~RPN()
{

}

void	RPN::calculate(char sign)
{
	if (this->stack != 2)
		throw ErrorMsg();

	int	a = this->stack.top();
	this->stack.pop();

	int b = this->stack.top();
	this->stack.pop();

	switch (sign) {
		case '+':
			a += b;
			break ;
		case '-':
			a = b - a;
			break ;
		case '*':
			a *= b;
			break ;
		case '/':
			if (a == 0)
				throw ErrorMsg();
			a = b / a;
			break ;
	}
	this->stack.push(a);
}

void	RPN::execute(char **argv)
{
	char	*str = argv[1];

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			continue ;
		if (str[i] >= '0' && str[i] <= '9' && (!str[i + 1] || str[i + 1] == ' '))
			this->stack.push(str[i] - '0');
		else if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && (!str[i + 1] || str[i + 1] == ' '))
			calculate(str[i]);
		else
			throw ErrorMsg();
	}
	std::cout << this->stack.top() << std::endl;
}

const char	*RPN::ErrorMsg::what() const throw()
{
	return "Error";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:06:03 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/17 13:06:17 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>

class RPN {
private:
	std::stack<int>	stack;
public:
	RPN();
	RPN(const RPN &cpy);
	RPN	&operator=(const RPN &cpy);
	~RPN();
	void	execute(char **argv);
	void	calculate(char sign);
	class ErrorMsg : public std::exception {
		const char	*what() const throw();
	};
};


#endif

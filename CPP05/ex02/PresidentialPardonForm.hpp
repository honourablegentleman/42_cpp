/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:53:17 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/13 11:53:18 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const &presidentialPardonForm);
	virtual void	execute(Bureaucrat const &executor) const;
};

#endif

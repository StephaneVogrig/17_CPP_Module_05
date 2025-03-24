/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:51:59 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/24 23:11:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
	: AForm("Shrubbery creation", 145, 137), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & toCopy)
{
	*this = toCopy;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm & toAssign)
{
	if (this == &toAssign)
		return *this;
	this->AForm::operator=(toAssign);
	return *this;
}

void	RobotomyRequestForm::execute(void) const
{
	std::cout << "Make a drilling noise : \a" << std::endl;
	srand (time(NULL));
	int r = rand() % 2;
	if (r)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;

}

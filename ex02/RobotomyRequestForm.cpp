/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:51:59 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/02 11:08:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
	: AForm("Robotomy request", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & toCopy)
	: AForm(toCopy), _target(toCopy._target)
{}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm & toAssign)
{
	if (this == &toAssign)
		return *this;
	this->AForm::operator=(toAssign);
	_target = toAssign._target;
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

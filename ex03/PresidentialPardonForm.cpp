/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:09:51 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/25 13:24:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
	: AForm(PRESIDENTIALPARDONFORM_NAME, 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & toCopy)
{
	*this = toCopy;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm & toAssign)
{
	if (this == &toAssign)
		return *this;
	this->AForm::operator=(toAssign);
	return *this;
}

void	PresidentialPardonForm::execute(void) const
{
	std::cout	<< _target << " has been pardoned by Zaphod Beeblebrox"
				<< std::endl;
}


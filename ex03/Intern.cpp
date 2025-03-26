/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:58:33 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/26 04:30:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern & toCopy)
{
	*this = toCopy;
}

Intern & Intern::operator = (const Intern & toAssign)
{
	if (this == &toAssign)
		return *this;
	return *this;
}

Intern::~Intern()
{}

AForm * Intern::newShrubberyCreationForm(const std::string & target)
{
	return new ShrubberyCreationForm(target);
}

AForm * Intern::newRobotomyRequestForm(const std::string & target)
{
	return new RobotomyRequestForm(target);
}

AForm * Intern::newPresidentialPardonForm(const std::string & target)
{
	return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm(const std::string & formName, const std::string & target)
{
	static const std::string _formName[] = {SHRUBBERYCREATIONFORM_NAME,
											ROBOTOMYREQUESTFORM_NAME,
											PRESIDENTIALPARDONFORM_NAME};

	static t_formptr newForm[] = {	Intern::newShrubberyCreationForm,
									Intern::newRobotomyRequestForm,
									Intern::newPresidentialPardonForm};

	for (size_t i = 0; i < sizeof(newForm) / sizeof(t_formptr); ++i)
	{
		if (_formName[i] == formName)
		{
			AForm * form = newForm[i](target);
			std::cerr << YELLOW "Intern create: " RESET << *form << std::endl;
			return form;
		}
	}
	std::cerr << "Error: " << formName << " doesn't exist" << std::endl;
	return NULL;
}

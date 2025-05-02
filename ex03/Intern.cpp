/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:58:33 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/02 17:01:44 by svogrig          ###   ########.fr       */
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

AForm * Intern::newShrubberyCreationForm(const std::string & target) const
{
	return new ShrubberyCreationForm(target);
}

AForm * Intern::newRobotomyRequestForm(const std::string & target) const
{
	return new RobotomyRequestForm(target);
}

AForm * Intern::newPresidentialPardonForm(const std::string & target) const
{
	return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm(const std::string & formName, const std::string & target) const
{

	static const std::string formNames[] = {SHRUBBERYCREATIONFORM_NAME,
											ROBOTOMYREQUESTFORM_NAME,
											PRESIDENTIALPARDONFORM_NAME};

	typedef AForm * (Intern::*t_formptr)(const std::string &) const;

	static const t_formptr formTypes[] = {	&Intern::newShrubberyCreationForm,
											&Intern::newRobotomyRequestForm,
											&Intern::newPresidentialPardonForm};

	for (size_t i = 0; i < sizeof(formTypes) / sizeof(t_formptr); ++i)
	{
		if (formNames[i] == formName)
		{
			AForm * form = (this->*formTypes[i])(target);
			std::cout << YELLOW "Intern create: " RESET << *form << std::endl;
			return form;
		}
	}
	throw FormNotFound();
}

const char * Intern::FormNotFound::what() const throw()
{
	return "Intern: form not found";
}

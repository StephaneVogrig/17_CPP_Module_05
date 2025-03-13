/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:47:50 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/13 01:31:34 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* constructor ---------------------------------------------------------------*/

Bureaucrat::Bureaucrat(const std::string & name, int grade)
			: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat & toCopy)
			: _name(toCopy._name), _grade(toCopy._grade)
{
}

/* destructor ----------------------------------------------------------------*/

Bureaucrat::~Bureaucrat(void)
{
}

/* operator ------------------------------------------------------------------*/

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & toAssign)
{
	if (this == &toAssign)
		return (*this);
	_grade = toAssign._grade;
	return (*this);
}

std::ostream & operator << (std::ostream & os, const Bureaucrat & bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

/* getter --------------------------------------------------------------------*/

const std::string & Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

/* utilities -----------------------------------------------------------------*/

void Bureaucrat::incrementGrade(void)
{
	if (_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade++;
}

/* exceptions ----------------------------------------------------------------*/

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:47:50 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/17 12:51:14 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "utils.hpp"

/* constructor ---------------------------------------------------------------*/

Bureaucrat::Bureaucrat(const std::string & name, int grade)
			: _name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat & toCopy)
			: _name(toCopy._name), _grade(toCopy._grade)
{}

/* destructor ----------------------------------------------------------------*/

Bureaucrat::~Bureaucrat(void)
{}

/* operator ------------------------------------------------------------------*/

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & toAssign)
{
	if (this == &toAssign)
		return *this;
	_grade = toAssign._grade;
	return *this;
}

std::ostream & operator << (std::ostream & os, const Bureaucrat & bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

/* accessor ------------------------------------------------------------------*/

const std::string & Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
}

/* utilities -----------------------------------------------------------------*/

void Bureaucrat::incrementGrade(void)
{
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	setGrade(_grade + 1);
}

void Bureaucrat::signForm(Form & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout	<< getName() << YELLOW " signed " RESET
					<< form.getName() << std::endl;
	}
	catch(const std::range_error& e)
	{
		std::cerr	<< getName() << YELLOW " couldn’t sign " RESET
					<< form.getName() << YELLOW " because " RESET
					<< e.what() << '\n';
	}
}

/* exceptions ----------------------------------------------------------------*/

Bureaucrat::GradeTooHighException::GradeTooHighException()
			: range_error(RED "grade is too high" RESET)
{}

Bureaucrat::GradeTooLowException::GradeTooLowException()
			: range_error(RED "grade is too low" RESET)
{}

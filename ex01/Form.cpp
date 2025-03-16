/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:17:31 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/16 23:48:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "utils.hpp"

/* constructor ---------------------------------------------------------------*/

Form::Form(const std::string & name, int gradeToSign, int gradeToExecute)
			: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

Form::Form(const Form & toCopy) : _name(toCopy._name), _isSigned(toCopy._isSigned), _gradeToSign(toCopy._gradeToSign), _gradeToExecute(toCopy._gradeToExecute)
{}

/* destructor ----------------------------------------------------------------*/

Form::~Form(void)
{}

/* operator ------------------------------------------------------------------*/

Form & Form::operator = (const Form & toAssign)
{
	if (this == &toAssign)
		return (*this);
	_isSigned = toAssign._isSigned;
	return *this;
}

std::ostream & operator << (std::ostream & os, const Form & form)
{
	os	<< form.getName() << ", " << (form.getIsSigned() ? "" : "not ")
		<< "signed, grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToSign();
	return os;
}

/* accessor ------------------------------------------------------------------*/

const std::string & Form::getName(void) const
{
	return _name;
}

bool Form::getIsSigned(void) const
{
	return _isSigned;
}

int Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

/* utilities -----------------------------------------------------------------*/

void Form::beSigned(const Bureaucrat & bureaucrat)
{
	if (_gradeToSign < bureaucrat.getGrade())
		throw (GradeTooLowException());
	_isSigned = true;
}

void Form::checkGrade(int grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
}

/* exceptions ----------------------------------------------------------------*/

Form::GradeTooHighException::GradeTooHighException()
			: range_error(RED "grade is too high" RESET)
{}

Form::GradeTooLowException::GradeTooLowException()
			: range_error(RED "grade is too low" RESET)
{}

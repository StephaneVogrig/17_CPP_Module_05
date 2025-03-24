/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:17:31 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/16 23:48:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "utils.hpp"

/* constructor ---------------------------------------------------------------*/

AForm::AForm(const std::string & name, int gradeToSign, int gradeToExecute)
			: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

AForm::AForm(const AForm & toCopy) : _name(toCopy._name), _isSigned(toCopy._isSigned), _gradeToSign(toCopy._gradeToSign), _gradeToExecute(toCopy._gradeToExecute)
{}

/* destructor ----------------------------------------------------------------*/

AForm::~AForm(void)
{}

/* operator ------------------------------------------------------------------*/

AForm & AForm::operator = (const AForm & toAssign)
{
	if (this == &toAssign)
		return (*this);
	_isSigned = toAssign._isSigned;
	return *this;
}

std::ostream & operator << (std::ostream & os, const AForm & Aform)
{
	os	<< Aform.getName() << ", " << (Aform.getIsSigned() ? "" : "not ")
		<< "signed, grade to sign: " << Aform.getGradeToSign()
		<< ", grade to execute: " << Aform.getGradeToSign();
	return os;
}

/* accessor ------------------------------------------------------------------*/

const std::string & AForm::getName(void) const
{
	return _name;
}

bool AForm::getIsSigned(void) const
{
	return _isSigned;
}

int AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

/* utilities -----------------------------------------------------------------*/

void AForm::beSigned(const Bureaucrat & bureaucrat)
{
	if (_gradeToSign < bureaucrat.getGrade())
		throw (GradeTooLowException());
	_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw FormNotSigned();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

void AForm::checkGrade(int grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
}

/* exceptions ----------------------------------------------------------------*/

AForm::GradeTooHighException::GradeTooHighException()
			: range_error(RED "grade is too high" RESET)
{}

AForm::GradeTooLowException::GradeTooLowException()
			: range_error(RED "grade is too low" RESET)
{}

AForm::FormNotSigned::FormNotSigned()
			: runtime_error(RED "form not" RESET)
{}
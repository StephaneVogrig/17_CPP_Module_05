/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:53:25 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/02 11:10:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "utils.hpp"

void test_constructor_bureaucrat(int grade)
{
	std::ostringstream ss;
	ss << "constructor with grade ";
	ss << grade;
	displaySubtest(ss.str());
	try
	{
		Bureaucrat junior = Bureaucrat("crat", grade);
		std::cout << junior << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_bureaucrat(void)
{
	displaySection("test Bureaucrat");
	test_constructor_bureaucrat(75);
	test_constructor_bureaucrat(-10);
	test_constructor_bureaucrat(160);

	displaySubtest("decrementGrade");
	try
	{
		Bureaucrat junior = Bureaucrat("crat", 149);
		std::cout << junior << std::endl;
		junior.decrementGrade();
		std::cout << junior << std::endl;
		junior.decrementGrade();
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	displaySubtest("incrementGrade");
	try
	{
		Bureaucrat junior = Bureaucrat("crat", 2);
		std::cout << junior << std::endl;
		junior.incrementGrade();
		std::cout << junior << std::endl;
		junior.incrementGrade();
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_sign(const std::string & name, int grade, AForm * form)
{
	displaySubtest("sign form by " + name);
	try
	{
		Bureaucrat bureaucrat = Bureaucrat(name, grade);
		std::cout	<< PURPLE "create bureaucrat " RESET
					<< bureaucrat << std::endl;
		bureaucrat.signForm(*form);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_execute(const std::string & name, int grade, AForm * form)
{
	displaySubtest("excute form by " + name);
	try
	{
		Bureaucrat bureaucrat = Bureaucrat(name, grade);
		std::cout	<< PURPLE "create bureaucrat " RESET
					<< bureaucrat << std::endl;
		bureaucrat.executeForm(*form);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	test_bureaucrat();
	test_form_derived<ShrubberyCreationForm>("Shrubbery Creation");
	test_form_derived<RobotomyRequestForm>("Robotomy Request");
	test_form_derived<PresidentialPardonForm>("Presidential Pardon");
	return (EXIT_SUCCESS);
}

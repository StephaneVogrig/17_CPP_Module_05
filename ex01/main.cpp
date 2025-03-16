/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:53:25 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/17 00:14:40 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
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

void test_constructor_form(int gradeToSign, int gradeToExecute)
{
	std::ostringstream ss;
	ss << "constructor with gradeToSign: ";
	ss << gradeToSign;
	ss << " and gradeToExecute: ";
	ss << gradeToExecute;
	displaySubtest(ss.str());
	try
	{
		Form test = Form("cerfa 2076", gradeToSign, gradeToExecute);
		std::cout << test << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_form(void)
{
	displaySection("test Form");
	test_constructor_form(-1, -1);
	test_constructor_form(-1, 75);
	test_constructor_form(75, 75);
	test_constructor_form(75, -1);
	test_constructor_form(75, 160);
	test_constructor_form(160, 160);
	test_constructor_form(160, 80);
}

void test_signForm(void)
{
	displaySubtest("test signForm");
	{
		Bureaucrat bur150("newbie", 150);
		std::cout << PURPLE "create bureaucrat " RESET << bur150 << std::endl;
		Form form150("cerfa150", 150, 150);
		std::cout << PURPLE "create form " RESET << form150 << std::endl;
		Form form1("cerfa1", 1, 150);
		std::cout << PURPLE "create form " RESET << form1 << std::endl;
		std::cout << std::endl;

		bur150.signForm(form150);
		std::cout << form150 << std::endl;
		std::cout << std::endl;

		bur150.signForm(form1);
		std::cout << form1 << std::endl;
		std::cout << std::endl;
	}
	Bureaucrat bur1("senior", 1);
	std::cout << PURPLE "create bureaucrat " RESET << bur1 << std::endl;
	Form form150("cerfa150", 150, 150);
	std::cout << PURPLE "create form " RESET << form150 << std::endl;
	Form form1("cerfa1", 1, 150);
	std::cout << PURPLE "create form " RESET << form1 << std::endl;
	std::cout << std::endl;

	bur1.signForm(form150);
	std::cout << form150 << std::endl;
	std::cout << std::endl;

	bur1.signForm(form1);
	std::cout << form1 << std::endl;
}

int main()
{
	test_bureaucrat();
	test_form();
	test_signForm();
	return (EXIT_SUCCESS);
}

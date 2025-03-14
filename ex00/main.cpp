/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:53:25 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/14 23:22:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Bureaucrat.hpp"
#include "utils.hpp"

void test_constructor(int grade)
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

int main()
{
	displaySection("test Bureaucrat");
	test_constructor(75);
	test_constructor(-10);
	test_constructor(160);

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

	return (EXIT_SUCCESS);
}

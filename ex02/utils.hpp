/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:29:35 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/25 00:39:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define GREY "\033[37m"
#define RESET "\033[0m"

void displaySection(const std::string & title);
void displaySubtest(const std::string & title);
void test_sign(const std::string & name, int grade, AForm * form);
void test_execute(const std::string & name, int grade, AForm * form);

template<typename Form>
void test_form_derived(const std::string & name)
{
	displaySection("test " + name);
	AForm * form = new Form("home");
	std::cout	<< PURPLE "create form: " RESET
				<< *form << std::endl;
	test_execute("junior", 150, form);
	test_execute("senior", 1, form);
	test_sign("junior", 150, form);
	test_sign("senior", 1, form);
	test_execute("junior", 150, form);
	test_execute("senior", 1, form);
	delete form;
}

#endif

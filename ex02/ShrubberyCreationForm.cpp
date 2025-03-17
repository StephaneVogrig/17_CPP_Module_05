/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:28:31 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/17 03:28:44 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target = "noTarget")
						: AForm("Shrubbery creation", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & toCopy)
{
	*this = toCopy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm & toAssign)
{
	if (this == &toAssign)
		return ;
	this->AForm::operator=(toAssign);
}

void	ShrubberyCreationForm::execution(void) const
{

	std::ofstream ofs (	(_target + "shruberry") , std::ofstream::out);

	// https://asciiart.website/index.php?art=plants/trees

	ofs << "           # #### ####               " << std::endl;
	ofs << "         ### \/#|### |/####          " << std::endl;
	ofs << "        ##\/#/ \||/##/_/##/_#        " << std::endl;
	ofs << "      ###  \/###|/ \/ # ###          " << std::endl;
	ofs << "     ##_\_#\_\## | #/###_/_####      " << std::endl;
	ofs << "     ## #### # \ #| /  #### ##/##    " << std::endl;
	ofs << "     __#_--###`  |{,###---###-~      " << std::endl;
	ofs << "               \ }{                  " << std::endl;
	ofs << "                }}{                  " << std::endl;
	ofs << "                }}{                  " << std::endl;
	ofs << "           ejm  {{}                  " << std::endl;
	ofs << "          , -=-~{ .-^- _             " << std::endl;
	ofs << "                `}                   " << std::endl;
	ofs << "                 {                   " << std::endl;

	ofs.close();

}

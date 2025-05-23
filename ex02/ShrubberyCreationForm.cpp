/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:28:31 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/02 11:15:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
	: AForm("Shrubbery creation", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & toCopy)
	: AForm(toCopy), _target(toCopy._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm & toAssign)
{
	if (this == &toAssign)
		return *this;
	this->AForm::operator=(toAssign);
	_target = toAssign._target;
	return *this;
}

void	ShrubberyCreationForm::execute(void) const
{
	std::ofstream ofs((_target + "_shruberry").c_str());

	// https://asciiart.website/index.php?art=plants/trees
	ofs << "" << std::endl;

	ofs << "           # #### ####               " << std::endl;
	ofs << "         ### \\/#|### |/####          " << std::endl;
	ofs << "        ##\\/#/ \\||/##/_/##/_#        " << std::endl;
	ofs << "      ###  \\/###|/ \\/ # ###          " << std::endl;
	ofs << "     ##_\\_#\\_\\## | #/###_/_####      " << std::endl;
	ofs << "     ## #### # \\ #| /  #### ##/##    " << std::endl;
	ofs << "     __#_--###`  |{,###---###-~      " << std::endl;
	ofs << "               \\ }{                  " << std::endl;
	ofs << "                }}{                  " << std::endl;
	ofs << "                }}{                  " << std::endl;
	ofs << "           ejm  {{}                  " << std::endl;
	ofs << "          , -=-~{ .-^- _             " << std::endl;
	ofs << "                `}                   " << std::endl;
	ofs << "                 {                   " << std::endl;

	ofs << "" << std::endl;

	ofs << "       	%%%,%%%%%%%             " << std::endl;
	ofs << "       	,'%% \\\\-*%%%%%%%        " << std::endl;
	ofs << "       ;%%%%%*%   _%%%%\"           " << std::endl;
	ofs << "       ,%%%       \\(_.*%%%%.       " << std::endl;
	ofs << "       % *%%, ,%%%%*(    '         " << std::endl;
	ofs << "       %^     ,*%%% )\\|,%%*%,_     " << std::endl;
	ofs << "         *%    \\/ #).-\"*%%*        " << std::endl;
	ofs << "       	  _.) ,/ *%,            " << std::endl;
	ofs << "       _________/)#(_____________  " << std::endl;
	ofs << "       b'ger                       " << std::endl;

	ofs << "" << std::endl;

	ofs.close();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:48:32 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/26 03:08:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "utils.hpp"

typedef AForm * (*t_formptr)(const std::string &);

class Intern
{
	static std::string	_form_lst[3];
	static t_formptr	_form_ptr[3];

	public:

		Intern();
		Intern(const Intern & toCopy);

		Intern & operator = (const Intern & toAssign);

		~Intern();

		AForm * makeForm(const std::string & formName, const std::string & target);

};

#endif

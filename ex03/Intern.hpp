/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:48:32 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/26 04:38:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "utils.hpp"

class Intern
{

	public:

		Intern();
		Intern(const Intern & toCopy);

		Intern & operator = (const Intern & toAssign);

		~Intern();

		AForm * makeForm(const std::string & formName, const std::string & target);

	private:

		typedef AForm * (*t_formptr)(const std::string &);

		static AForm * newShrubberyCreationForm(const std::string & target);
		static AForm * newRobotomyRequestForm(const std::string & target);
		static AForm * newPresidentialPardonForm(const std::string & target);

};

#endif

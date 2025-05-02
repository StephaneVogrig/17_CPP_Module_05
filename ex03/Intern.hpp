/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:48:32 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/02 17:37:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <exception>
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

		~Intern();

		Intern & operator = (const Intern & toAssign);

		class FormNotFound : public std::exception{
			public:
				const char * what() const throw();
		};

		AForm * makeForm(const std::string & formName, const std::string & target) const;

	private:

		AForm * newShrubberyCreationForm(const std::string & target) const;
		AForm * newRobotomyRequestForm(const std::string & target) const;
		AForm * newPresidentialPardonForm(const std::string & target) const;

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:59:18 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/16 14:26:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:

		Bureaucrat(const std::string & name = "noName", int grade = 150);
		Bureaucrat(const Bureaucrat & toCopy);

		~Bureaucrat(void);

		Bureaucrat & operator = (const Bureaucrat & toAssign);

		const std::string &	getName(void) const;
		int					getGrade(void) const;

		void				setGrade(int grade);

		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(Form & form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};

	private:
		const std::string	_name;
		unsigned int		_grade;

};

std::ostream & operator << (std::ostream & os, const Bureaucrat & bureaucrat);

#endif

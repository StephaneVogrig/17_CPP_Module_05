/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:05:46 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/16 17:15:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

		Form(const std::string & name = "noName",
				int gradeToSign = 150, int GradeToExecute = 150);
		Form(const Form & toCopy);

		~Form(void);

		Form & operator = (const Form & toAssign);

		const std::string &	getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		int					setGradeToSign(int gradeToSign) const;
		int					setGradeToExecute(int gradeToExecute) const;

		void				beSigned(const Bureaucrat & bureaucrat);

		class GradeTooHighException : public std::range_error
		{
			public:
				GradeTooHighException();
		};

		class GradeTooLowException : public std::range_error
		{
			public:
				GradeTooLowException();
		};

	private:

		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		void checkGrade(int grade);

};

std::ostream & operator << (std::ostream & os, const Form & form);

#endif

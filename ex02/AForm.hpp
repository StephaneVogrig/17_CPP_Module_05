/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:05:46 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/17 00:26:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:

		AForm(const std::string & name = "noName",
				int gradeToSign = 150, int GradeToExecute = 150);
		AForm(const AForm & toCopy);

		virtual ~AForm(void);

		AForm & operator = (const AForm & toAssign);

		const std::string &	getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		int					setGradeToSign(int gradeToSign) const;
		int					setGradeToExecute(int gradeToExecute) const;

		void				beSigned(const Bureaucrat & bureaucrat);

		void				execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::range_error
		{
			public:
				GradeTooHighException(void);
		};

		class GradeTooLowException : public std::range_error
		{
			public:
				GradeTooLowException(void);
		};

		class FormNotSigned : public std::runtime_error
		{
			public:
				FormNotSigned(void);
		};

	private:

		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		void checkGrade(int grade);

		virtual void execute(void) const = 0;

};

std::ostream & operator << (std::ostream & os, const AForm & AForm);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:59:18 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/05 18:47:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	public:

		Bureaucrat(void);
		Bureaucrat(const std::string & name, int grade);
		Bureaucrat(const Bureaucrat & toCopy);

		~Bureaucrat(void);

		Bureaucrat & operator = (const Bureaucrat & toAssign);

		std::string &	getName(void);
		int				getGrade(void);
		
		void incrementGrade(void);
		void decrementGrade(void);

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
		int					_grade;

};

#endif
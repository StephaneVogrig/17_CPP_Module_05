/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:28:34 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/17 03:23:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public :

		ShrubberyCreationForm(const std::string & target = "noTarget");
		ShrubberyCreationForm(const ShrubberyCreationForm & toCopy);

		~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator = (const ShrubberyCreationForm & toAssign);

	private:

		const std::string _target;

		void execution(void) const;

};
#endif
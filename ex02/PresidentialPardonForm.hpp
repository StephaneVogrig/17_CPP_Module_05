/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:09:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/24 23:10:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public :

		PresidentialPardonForm(const std::string & target = "noTarget");
		PresidentialPardonForm(const PresidentialPardonForm & toCopy);

		~PresidentialPardonForm(void);

		PresidentialPardonForm & operator = (const PresidentialPardonForm & toAssign);

	private:

		const std::string _target;

		void execute(void) const;

};

#endif

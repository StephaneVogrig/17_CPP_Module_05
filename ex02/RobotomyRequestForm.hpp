/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:47:49 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/24 23:10:49 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public :

		RobotomyRequestForm(const std::string & target = "noTarget");
		RobotomyRequestForm(const RobotomyRequestForm & toCopy);

		~RobotomyRequestForm(void);

		RobotomyRequestForm & operator = (const RobotomyRequestForm & toAssign);

	private:

		const std::string _target;

		void execute(void) const;

};

#endif

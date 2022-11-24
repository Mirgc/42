/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:39:24 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/21 14:24:45 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
# include "Form.hpp"

class RobotomyRequestForm: public Form {
	private:
		const std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);
		std::string		getTarget() const;
		void			execute(const Bureaucrat& executor) const;
};

#endif

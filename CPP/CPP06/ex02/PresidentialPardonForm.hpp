/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:39:24 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/21 11:19:13 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <fstream>
# include "Form.hpp"

class PresidentialPardonForm: public Form {
	private:
		const std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &obj);
		std::string		getTarget() const;
		void			execute(const Bureaucrat& executor) const;
};

#endif

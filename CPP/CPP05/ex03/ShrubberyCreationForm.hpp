/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:39:24 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/21 14:24:22 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form {
	private:
		const std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);
		std::string		getTarget() const;
		void			execute(const Bureaucrat& executor) const;
};

#endif

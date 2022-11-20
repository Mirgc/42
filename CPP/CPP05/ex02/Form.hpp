/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/20 18:39:38 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_H 
# define FORM_H
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string	_name;
		const int		_gradeSign;
		const int		_gradeExec;
		bool			_signed;
	
	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		Form(const Form &copy);
		virtual ~Form();

		Form			&operator=(const Form &obj);
		const std::string	getName(void) const;
		bool			getSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
		void			checkGrade(void);
		void			beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(const Bureaucrat& executor) const = 0;
		void			checkExecute(const Bureaucrat &bureaucrat) const;

		//https://www.youtube.com/watch?v=jmgp576_ndo min(24:29) 
		class gradeTooHighException: public std::exception {
			public:
				const char * what() const throw();
		};
		class gradeTooLowException: public std::exception {
			public:
				const char * what() const throw();
		};
		class isNotSigned: public std::exception {
			public:
				const char * what() const throw();
		};
		class openFile: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Form &bureaucrat);

#endif

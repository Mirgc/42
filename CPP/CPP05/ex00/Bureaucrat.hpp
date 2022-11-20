/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/20 12:31:56 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <string>
# include <iostream>

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat		&operator=(const Bureaucrat &obj);
		const std::string	getName(void) const;
		int			getGrade(void) const;
		void			checkGrade(void);
		void			incrementGrade(void);
		void			decrementGrade(void);

		//https://www.youtube.com/watch?v=jmgp576_ndo min(24:29) 
		class gradeTooHighException: public std::exception {
			public:
				const char * what() const throw();
		};
		class gradeTooLowException: public std::exception {
			public:
				const char * what()const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/22 15:19:15 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <string>
# include <iostream>

class Cast{
	private:
		std::string _str;
		int _grade;
	
	public:
		Cast();
		Cast(std::string name, int grade);
		Cast(const Cast &copy);
		~Cast();

		Cast		&operator=(const Cast &obj);
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

std::ostream &operator<<(std::ostream &o, const Cast &bureaucrat);

#endif

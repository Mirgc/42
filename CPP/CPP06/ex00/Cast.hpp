/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   Cast.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/29 14:26:00 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_H
# define CAST_H
# include <string>
# include <iostream>
# include <iomanip>

# define CHAR 1
# define FLOAT 2
# define DOUBLE 3
# define INT 4
# define INVALID 5

class Cast{
	private:
		char _char;
		int _int; 
		float _float;
	   	double _double;
		std::string _str;
		int _type;
		bool _isWrong;
	
	public:
		Cast();
		Cast(const char *argv);
		Cast(const Cast &copy);
		~Cast();

		Cast		&operator=(const Cast &obj);

		int		getType() const;
		void	setType(int type);
		void	checkType(const char *val);

		void	print();
		void	printChar() const;
		void	printInt() const;
		void	printFloat() const;
		void	printDouble() const;
		
		void	castChar(const char *argv);
		void	castInt(const char *argv);
		void	castFloat(const char *argv);
		void	castDouble(const char *argv);
};

std::ostream &operator<<(std::ostream &o, const Cast &bureaucrat);

#endif

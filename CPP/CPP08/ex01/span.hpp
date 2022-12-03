/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/02 19:14:26 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_H
# define CAST_H
# include <iostream>
# include <vector>

class Span{
	private:
		std::vector<unsigned int> 	_vec;
		unsigned int 				_size;
	
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		~Span();

		Span		&operator=(const Span &obj);

		void	addNumber(unsigned int n);
		int 	shortestSpan() const;
		int 	longestSpan() const;
		void	Print();

		class noSizeException: public std::exception{
			public:
				const char *what() const throw();
		};

		class emptyVectorException: public std::exception{
			public:
				const char *what() const throw();
		};
};

#endif

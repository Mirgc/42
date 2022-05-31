/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:07:26 by migarcia          #+#    #+#             */
/*   Updated: 2022/05/19 16:30:57 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Karen{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		Karen();
		~Karen();	
		void complain( std::string level );
		typedef void (Karen::*Cb)(void);
};

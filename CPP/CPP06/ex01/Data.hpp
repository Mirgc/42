/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/01 09:28:37 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include <string>

class Data{
	private:
		std::string _name;
	
	public:
		Data();
		Data(std::string name);
		Data(const Data &copy);
		~Data();

		Data				&operator=(const Data &obj);
		const std::string	getName(void);
		void				setName(std::string name);
};

#endif

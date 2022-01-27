/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:51:34 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/27 12:53:22 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>
#include <string>

class Contact{
	private://Atributos privados
		std::string first;
		std::string last;
		std::string nickname;
		std::string phone;
		std::string secret;

	public://Metodos publicos
		Contact(void); //Constructor
		~Contact(); //Destructor
		void set_first(std::string str);	
		void set_last(std::string str);	
		void set_nickname(std::string str);	
		void set_phone(std::string str);	
		void set_secret(std::string str);	
		std::string get_first();	
		std::string get_last();	
		std::string get_nickname();	
		std::string get_phone();	
		std::string get_secret();	
};
#endif

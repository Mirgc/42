/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:51:02 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/27 12:53:53 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <iomanip>
# include <string>
# include "contact.hpp" 

class Phonebook{
	private:
		int 	pos;
		int	contacts;
		Contact list[8];
	public:
		Phonebook(void);
		~Phonebook();
		void get_action(std::string &str);
		void add();
		void print_in_col(std::string str);
		void print_table();
		void print_contact(int num);
		void search();
};
#endif

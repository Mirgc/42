/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/07 08:16:55 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &copy);
		virtual ~WrongCat();
		WrongCat &operator=(const WrongCat &obj);
		void makeSound(void) const;
};

#endif

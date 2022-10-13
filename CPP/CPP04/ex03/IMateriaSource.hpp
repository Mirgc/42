/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:07:03 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/12 13:02:55 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H
#include "AMateria.hpp"

class AMateria;

class IMateriaSource
{
	public:
		virtual		~IMateriaSource() {}
		virtual void	learnMateria(AMateria *m) = 0;
		virtual AMateria *createMateria(const std::string &type) = 0;
};

#endif

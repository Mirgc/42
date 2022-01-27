/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:51:21 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/27 12:56:49 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//Constructor, nos sirve para inicializar los atributos
Contact::Contact(void)
{
	return ;
}

//Destructor
Contact::~Contact()
{
	return ;
}

std::string Contact::get_first(){
	return(this->first); 
}

std::string Contact::get_last(){
	return(this->last); 
}

std::string Contact::get_nickname(){
	return(this->nickname); 
}

std::string Contact::get_phone(){
	return(this->phone); 
}

std::string Contact::get_secret(){
	return(this->secret); 
}

void Contact::set_first(std::string str){
	this->first = str; 
}

void Contact::set_last(std::string str){
	this->last = str;
}

void Contact::set_nickname(std::string str){
	this->nickname = str;
}

void Contact::set_phone(std::string str){
	this->phone = str; 
}

void Contact::set_secret(std::string str){
	this->secret = str; 
}

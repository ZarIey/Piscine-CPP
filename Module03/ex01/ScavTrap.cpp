/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:10:13 by ctardy            #+#    #+#             */
/*   Updated: 2023/05/09 13:58:50 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	type_text("Constructorz daughter by default : ", 1);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20), _nameDaughter(_name) {
	type_text("Constructorz daughter with stats : ", 0);
	type_text(_nameDaughter, 1);
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
	this->_name = other._name;
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	return (*this);
}

ScavTrap::~ScavTrap() {
	type_text("Destructorz daughter : ", 0);
	type_text(_nameDaughter, 1);
}

void ScavTrap::guardGate(){
	type_text("\033[33;1mGate Keeper mode activated\033[0m ⛩  (i have no idea what it is)", 1);	
}



void ScavTrap::colorNameDaughter(const std::string &color) {
    int length = _nameDaughter.length();
	int pos = 0;
    _nameDaughter.insert(0, color);
    pos = length + color.length();
    _nameDaughter.insert(pos, reset);
}
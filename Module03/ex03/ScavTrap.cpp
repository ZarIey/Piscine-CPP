/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:10:13 by ctardy            #+#    #+#             */
/*   Updated: 2023/05/09 16:40:15 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	type_text("Constructorz Scav by default : ", 1);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20), _nameDaughter(name) {
	type_text("Constructorz Scav with stats : ", 0);
	type_text(_nameDaughter, 1);
}

ScavTrap::~ScavTrap() {
	type_text("Destructorz Scav : ", 0);
	type_text(_nameDaughter, 1);
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	this->_name = other._name;
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	return (*this);
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

void ScavTrap::attack(const std::string &target) {
	std::ostringstream oss;
	if (EP == 0) {
		oss << _name << " has no more EP, he can't attack anymore 🤖";
		type_text(oss.str(), 1);
		return;
	}
	else if (HP == 0) { 
		oss << _name << " died, he can't attack anymore 🎚";
		type_text(oss.str(), 1);
		return;
	}
	oss << "ClapTrap " <<_name << " ScrapTrap attacks " << target;
    std::string result = oss.str();
    type_text(result, 0);
	oss.str("");
	oss << ", causing " << red << AD << reset << " point(s) of damage ! 🔪" << std::endl;
    result.assign(oss.str());
    type_text(result, 0);
	oss.str("");
	setEP();
	oss << _name << "has now " << blue << EP << reset << " EP ! 🌟";
	DMG += AD;
    return ;
}
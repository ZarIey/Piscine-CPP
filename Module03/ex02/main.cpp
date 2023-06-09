/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 04:58:18 by ctardy            #+#    #+#             */
/*   Updated: 2023/05/06 12:47:36 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void getInfo(std::ostringstream &oss, FragTrap &daughter, int stat, int flag) {
	
	switch(flag) {
		case 1 :
			oss << "\033[32;1mHP : \033[37;1m" << stat << "\033[0m";
			break;
		case 2 :
			oss << "\033[34;1mEP : \033[37;1m" << stat <<"\033[0m";
			break;
		case 3 :
			oss << "\033[0;31;1mAD : \033[37;1m" << stat << "\033[0m";
			break;
	}
	type_text(oss.str(), 1);
	oss.str("");
}

int main() {
	FragTrap daughter("Maïté");
	daughter.colorNameDaughter(daughter.getColor("yellow"));
	std::ostringstream oss;
	getInfo(oss, daughter, daughter.getHP(), 1);
	getInfo(oss, daughter, daughter.getEP(), 2);
	getInfo(oss, daughter, daughter.getAD(), 3);
	daughter.highFivesGuys();
	return 0;
}
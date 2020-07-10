#include "Util.hpp"


std::string int_to_money(const int &value){
	std::string money = std::to_string(value);
	
	/* if only has cents */
	while (money.length() < 3){
		money = "0" + money;
	}

	money = money.substr(0, money.length() - 2) + "," + money.substr(money.length() - 2);
	money = "R$ " + money;

	return money;
}

int money_to_int(const std::string &money){
	std::string temp = "0";
	for (int i = 0; i < money.length(); ++i){
		if (isdigit(money[i])){
			temp += money[i];
		}
	}
	int integer = std::stoi(temp);
	return integer;
}
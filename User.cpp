#include "User.hpp"

User::User(string first_name, string last_name, string username, string phone_number, int money, string role_str)
:first_name(first_name),last_name(last_name),username(username),phone_number(phone_number),money(money)
{
	if( role_str == "buyer" )
		role = BUYER;
	else if( role_str == "seller" )
		role = SELLER;

	cout<<"User \""<<username<<"\" created."<<endl;
}

void User::double_role()
{
	role = BUYER_SELLER;

	cout<<"User "<<username<<"'s role changed to buyer_seller."<<endl;
}

string User::get_first_name(){ return first_name; }
string User::get_last_name(){ return last_name; }
string User::get_username(){ return username; }
string User::get_phone_number(){ return phone_number; }
int User::get_money(){ return money; }
int User::get_role(){ return role; }
string User::get_role_str()
{
	if( role == BUYER )
		return "buyer";
	else if( role == SELLER )
		return "seller";
	else if( role == BUYER_SELLER )
		return "buyer_seller";
}

void User::set_money( int value ){ money = value; }

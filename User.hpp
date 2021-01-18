#include <iostream>
#include <string>

#define BUYER 0
#define SELLER 1
#define BUYER_SELLER 2

using namespace std;

class User{

public:
	User(string first_name, string last_name, string username, string phone_number, int money, string role_str);
	void double_role();
	string get_first_name();
	string get_last_name();
	string get_username();
	string get_phone_number();
	int get_money();
	int get_role();
	string get_role_str();
	void set_money( int value );

private:
	string first_name;
	string last_name;
	string username;
	string phone_number;
	int money;
	int role;

};

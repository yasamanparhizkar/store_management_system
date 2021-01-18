#include <iostream>
#include <string>

#define BUYER 0
#define SELLER 1
#define BUYER_SELLER 2

#ifndef _USER_
#define _USER_
#include "User.hpp"
#endif

using namespace std;

class Goods{

public:
	Goods(string goods_name, int goods_price, int goods_count, User* seller, int sold_count = 0, bool off = 0, bool off_til_end = 0);
	Goods( Goods& src );
	string get_goods_name();
	int get_goods_price();
	int get_goods_count();
	User* get_seller();
	int get_sold_count();
	bool get_off();
	bool get_off_til_end();
	void set_off(bool value);
	void set_off_til_end(bool value);
	void set_goods_count(int value);
	void set_sold_count(int value);


private:
	string goods_name;
	int goods_price;
	int goods_count;
	User* seller;
	int sold_count;
	bool off;
	bool off_til_end;

};

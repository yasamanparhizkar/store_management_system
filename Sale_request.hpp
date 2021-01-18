#include <iostream>
#include <string>

#define BUYER 0
#define SELLER 1
#define BUYER_SELLER 2

#ifndef _GOODS_
#define _GOODS_
#include "Goods.hpp"
#endif

using namespace std;

class Sale_request{

public:
	Sale_request(string buyer_username, Goods* sale_requested_goods);
	string get_buyer_username();
	Goods* get_sale_requested_goods();

private:
	string buyer_username;
	Goods* sale_requested_goods;
};

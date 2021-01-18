#include <iostream>
#include <string>
#include <vector>

#define BUYER 0
#define SELLER 1
#define BUYER_SELLER 2

#ifndef _USER_
#define _USER_
#include "User.hpp"
#endif

#ifndef _GOODS_
#define _GOODS_
#include "Goods.hpp"
#endif

using namespace std;

class Request{
public:
	Request( string request_name, User* buyer );
	string get_request_name();
	User* get_buyer();
	Goods* get_requested_goods(int index);
	void add_goods( Goods* added_goods );

private:
	string request_name;
	User* buyer;
	vector<Goods*> requested_goods;
};

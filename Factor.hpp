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

class Factor{
public:
	Factor(User* buyer);
	User* get_buyer();
	Goods* get_bought_goods(int index);
	int get_bought_goods_size();
	void add_goods( Goods* added_goods );

private:
	User* buyer;
	vector<Goods*> bought_goods;
};

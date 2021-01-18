#ifndef _FACTOR_
#define _FACTOR_
#include "Factor.hpp"
#endif

Factor::Factor(User* buyer):buyer(buyer)
{}

User* Factor::get_buyer(){ return buyer; }
Goods* Factor::get_bought_goods(int index){ return bought_goods[index]; }
int Factor::get_bought_goods_size(){ return bought_goods.size(); }

void Factor::add_goods( Goods* added_goods )
{
	bought_goods.push_back(added_goods);
}

#include <iostream>
#include <vector>
#include <string>
#include "online_store_lib.hpp"

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

#ifndef _FACTOR_
#define _FACTOR_
#include "Factor.hpp"
#endif

#ifndef _SALE_REQUEST_
#define _SALE_REQUEST_
#include "Sale_request.hpp"
#endif

#ifndef _REQUEST_
#define _REQUEST_
#include "Request.hpp"
#endif

#ifndef _GOODS_VECTORS_
#define _GOODS_VECTORS_
struct Goods_vectors{
	vector<Goods*> all_goods;
	vector<Goods*> saled_goods;
	vector<Goods*> temporary_saled_goods;
	vector<Goods*> special_goods;
	vector<Goods*> bestseller_goods;
};
#endif

using namespace std;


int main()
{
	vector<User*> users;
	Goods_vectors goods_vectors;
	vector<Factor*> factors;
	vector<Sale_request*> sale_requests;
	vector<Request*> requests;
	int store_account = 0;

	cout<<"Welcome, Enter your commands."<<endl;

	string command;
	while(cin>>command)
	{
		if( command == "add_user" )
			add_user_handler(users);
		else if( command == "add_goods" )
			add_goods_handler(users, goods_vectors, store_account);
		else if( command == "search" )
			search_handler(goods_vectors.all_goods);
		else if( command == "buy" )
			buy_handler(users, goods_vectors, factors, store_account, sale_requests);
		else if( command == "sale" )
			sale_handler( users, goods_vectors, sale_requests, store_account );
		else if( command == "search_sale" )
			search_sale_handler( goods_vectors.all_goods );
		else if( command == "search_bestseller" )
			search_bestseller_handler( goods_vectors.bestseller_goods );
		else if( command == "add_money" )
			add_money_handler( users );
		else if( command == "print_factor" )
			print_factor_handler( users, factors );
		else
			cout<<"Command Failed."<<endl;

	}
	return 0;
}

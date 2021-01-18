#include <iostream>
#include <vector>

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

void add_user_handler(vector<User*>& users);
int search( vector<User*>& users, string username);
int search( vector<Goods*>& all_goods, string goods_name, int goods_count, string seller_username);
int search( vector<Goods*>& goods_vector, Goods* goods );
int search( vector<Sale_request*>& sale_requests, string buyer_username, Goods* sale_requested_goods );
bool same_except_role(vector<User*>& users, int index, string first_name, string last_name, string phone_number, int money, string role_str);
void add_goods_handler(vector<User*>& users, Goods_vectors& goods_vectors, int& store_account);
void make_goods(Goods_vectors& goods_vectors, User* seller, string goods_name, int goods_price, int goods_count, int& store_account);
void adjust_off(Goods* goods, vector<Goods*>& temporary_saled_goods );
bool same_goods_name(vector<Goods*>& all_goods,string seller_username, string goods_name );
void search_handler(vector<Goods*>& all_goods);
void sort_goods(vector<Goods*>& all_goods);
void swap_goods(vector<Goods*>& all_goods, int index1, int index2);
void sort_goods_by_name(vector<Goods*>& all_goods);
void sort_goods_by_count(vector<Goods*>& all_goods);
void sort_goods_by_price(vector<Goods*>& all_goods);
void sort_goods_by_seller_username(vector<Goods*>& all_goods);
void buy_handler(vector<User*>& users, Goods_vectors& goods_vectors, vector<Factor*>& factors, int& store_account, vector<Sale_request*>& sale_requests);
bool fix_seller_username( string& seller_username );
void buy_goods(vector<User*>& users, Goods_vectors& goods_vectors, vector<Factor*>& factors, User* buyer,
			   int& store_account, vector<Sale_request*>& sale_requests);
void eject_goods( Goods_vectors& goods_vectors, Goods* goods, int goods_count, int& store_account );
bool cash( Goods* goods, User* buyer, int goods_count, int& store_account, Goods_vectors& goods_vectors, vector<Sale_request*> sale_requests );
void add_to_factor( Factor* factor, Goods* bought_goods, int bought_count );
void print_factor( vector<Factor*>& factors, int index, int edition );
void empty( Goods_vectors& goods_vectors, Goods* goods );
void add_money_handler( vector<User*>& users );
void check_sale( int& store_account, Goods_vectors& goods_vectors, vector<Sale_request*>& sale_requests );
void check_bestseller( vector<Goods*>& bestseller_goods, Goods* goods );
bool is_enough(int& store_account, Goods* case_goods );
void check_goods_counts(int store_account, Goods_vectors& goods_vectors);
void check_sale_requests(int store_account, vector<Goods*>& saled_goods, vector<Sale_request*>& sale_requests );
void sale_handler( vector<User*>& users, Goods_vectors& goods_vectors, vector<Sale_request*>& sale_requests, int& store_account );
void handle_sale( User* buyer, Goods_vectors& goods_vectors, vector<Sale_request*>& sale_requests, int& store_account );
void make_sale(User* buyer, Goods* goods, Goods_vectors& goods_vectors, vector<Sale_request*>& sale_requests, int& store_account);
void search_sale_handler( vector<Goods*>& all_goods );
void search_bestseller_handler( vector<Goods*>& bestseller_goods );
void print_factor_handler(vector<User*>& users,vector<Factor*>& factors );
void print_buyer_factors(string buyer_username,vector<Factor*>& factors );

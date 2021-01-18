#ifndef _SALE_REQUEST_
#define _SALE_REQUEST_
#include "Sale_request.hpp"
#endif

Sale_request::Sale_request(string buyer_username, Goods* sale_requested_goods)
:buyer_username(buyer_username), sale_requested_goods(sale_requested_goods)
{}

string Sale_request::get_buyer_username(){ return buyer_username; }
Goods* Sale_request::get_sale_requested_goods(){ return sale_requested_goods; }

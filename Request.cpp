#ifndef _REQUEST_
#define _REQUEST_
#include "Request.hpp"
#endif

Request::Request( string request_name, User* buyer ):request_name(request_name), buyer(buyer)
{}

string Request::get_request_name(){ return request_name; }
User* Request::get_buyer(){ return buyer; }
Goods* Request::get_requested_goods(int index){ return requested_goods[index]; }

void Request::add_goods( Goods* added_goods )
{
	requested_goods.push_back( added_goods );
}

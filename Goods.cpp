#ifndef _GOODS_
#define _GOODS_
#include "Goods.hpp"
#endif

Goods::Goods(string goods_name, int goods_price, int goods_count, User* seller, int sold_count, bool off, bool off_til_end)
:goods_name(goods_name), goods_price(goods_price), goods_count(goods_count),
 seller(seller), sold_count(sold_count), off(off), off_til_end(off_til_end)
{}

Goods::Goods( Goods& src )
{
	goods_name = src.get_goods_name();
	goods_price = src.get_goods_price();
	goods_count = src.get_goods_count();
	seller = src.get_seller();
	sold_count = src.get_sold_count();
	off = src.get_off();
	off_til_end = src.get_off_til_end();	
}

string Goods::get_goods_name(){ return goods_name; }
int Goods::get_goods_price(){ return goods_price; }
int Goods::get_goods_count(){ return goods_count; }
User* Goods::get_seller(){ return seller; }
int Goods::get_sold_count(){ return sold_count; }
bool Goods::get_off(){ return off; }
bool Goods::get_off_til_end(){ return off_til_end; }

void Goods::set_off(bool value){ off = value; }
void Goods::set_off_til_end(bool value){ off_til_end = value; }
void Goods::set_goods_count(int value){ goods_count = value; }
void Goods::set_sold_count(int value){ sold_count = value; }

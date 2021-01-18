#include "online_store_lib.hpp"
#include <string>

#define BUYER 0
#define SELLER 1
#define BUYER_SELLER 2
#define NOT_FOUND -1
#define SALE_THRESHHOLD 29

using namespace std;

void add_user_handler(vector<User*>& users)
{
	string first_name, last_name, username, phone_number, role_str;
	int money;

	cin>>first_name>>last_name>>username>>phone_number>>money>>role_str;

	int index = search(users, username);

	if( index == NOT_FOUND )
	{
		users.push_back( new User( first_name, last_name, username, phone_number, money, role_str ) );
		cout<<"Command OK."<<endl;
	}
	else if( same_except_role(users, index, first_name, last_name, phone_number, money, role_str) )
	{
		users[index]->double_role();
		cout<<"Command OK."<<endl;
	}
	else
		cout<<"Command Failed."<<endl;
}

int search(vector<User*>& users, string username)
{
	for( int i=0; i<users.size(); i++ )
		if( users[i]->get_username() == username )
			return i;

	return NOT_FOUND;
}

int search(vector<Goods*>& all_goods, string goods_name, int goods_count, string seller_username)
{
	for( int i=0; i<all_goods.size(); i++ )
	{
		if( (all_goods[i]->get_goods_name() == goods_name)
	 		&& (all_goods[i]->get_goods_count() >= goods_count)
		 	&& (all_goods[i]->get_seller()->get_username() == seller_username) )
				return i;
	}
	return NOT_FOUND;
}

int search( vector<Goods*>& goods_vector, Goods* goods )
{
	for( int i=0; i<goods_vector.size(); i++ )
		if( goods_vector[i] == goods )
			return i;
	return NOT_FOUND;
}

int search( vector<Sale_request*>& sale_requests, string buyer_username, Goods* sale_requested_goods )
{
	for( int i=0; i<sale_requests.size(); i++ )
	{
		if( (sale_requests[i]->get_buyer_username() == buyer_username)
	 		&& (sale_requests[i]->get_sale_requested_goods() == sale_requested_goods) )
				return i;
	}
	return NOT_FOUND;
}

bool same_except_role(vector<User*>& users, int index, string first_name, string last_name, string phone_number, int money, string role_str)
{
	if( ( users[index]->get_first_name() == first_name )
 		&& ( users[index]->get_last_name() == last_name )
		&& ( users[index]->get_phone_number() == phone_number )
		&& ( users[index]->get_money() == money )
	 	&& ( users[index]->get_role_str() != role_str ) )
			return true;
	else
			return false;
}

void add_goods_handler(vector<User*>& users, Goods_vectors& goods_vectors, int& store_account)
{
	string seller_username;
	string goods_name;
	int goods_price;
	int goods_count;

	cin>>seller_username>>goods_name>>goods_price>>goods_count;

	int index = search(users, seller_username);

	if( index == NOT_FOUND )
		cout<<"Command Failed."<<endl;
	else if( users[index]-> get_role() == BUYER )
		cout<<"Command Failed."<<endl;
	else if( same_goods_name( goods_vectors.all_goods, seller_username, goods_name ) )
		cout<<"Command Failed."<<endl;
	else
	{
		make_goods(goods_vectors, users[index], goods_name, goods_price, goods_count, store_account);
		cout<<"Command OK."<<endl;
	}
}

void make_goods(Goods_vectors& goods_vectors, User* seller, string goods_name, int goods_price, int goods_count, int& store_account)
{
	goods_vectors.all_goods.push_back( new Goods(goods_name, goods_price, goods_count, seller) );
	cout<<"Goods \""<<goods_vectors.all_goods[goods_vectors.all_goods.size()-1]->get_goods_name()<<"\" created."<<endl;
	check_goods_counts( store_account, goods_vectors);
}

bool same_goods_name(vector<Goods*>& all_goods,string seller_username, string goods_name )
{
	for( int i=0; i<all_goods.size(); i++ )
	{
		if( (all_goods[i]->get_seller()->get_username() == seller_username)
			&& (all_goods[i]->get_goods_name() == goods_name) )
				return true;
	}
	return false;
}

void search_handler(vector<Goods*>& all_goods)
{
	string goods_name;
	int goods_count;
	cin>>goods_name>>goods_count;

	sort_goods(all_goods);

	int number = 1;
	for( int i=0; i<all_goods.size(); i++ )
	{
		if( all_goods[i]->get_goods_name() == goods_name
	 		&& all_goods[i]->get_goods_count() >= goods_count )
		  {
			  cout<<number<<". "<<goods_name<<" "
			  <<all_goods[i]->get_goods_count()<<" "
			  <<all_goods[i]->get_goods_price()<<" "
			  <<all_goods[i]->get_seller()->get_username()<<endl;

			  number++;
		  }
	}
}

void sort_goods(vector<Goods*>& all_goods)
{
	sort_goods_by_name(all_goods);
	sort_goods_by_count(all_goods);
	sort_goods_by_price(all_goods);
	sort_goods_by_seller_username(all_goods);
}

void sort_goods_by_name(vector<Goods*>& all_goods)
{
	for( int i=0; i<all_goods.size(); i++ )
		for( int j=i+1; j<all_goods.size(); j++ )
			if( all_goods[j]->get_goods_name() < all_goods[i]->get_goods_name() )
				swap_goods(all_goods, i, j);
}
void sort_goods_by_count(vector<Goods*>& all_goods)
{
	for( int i=0; i<all_goods.size(); i++ )
		for( int j=i+1; ( j<all_goods.size() ) && ( all_goods[i]->get_goods_name() == all_goods[j]->get_goods_name() ) ; j++ )
			if( all_goods[j]->get_goods_count() < all_goods[i]->get_goods_count() )
				swap_goods(all_goods, i, j);
}
void sort_goods_by_price(vector<Goods*>& all_goods)
{
	for( int i=0; i<all_goods.size(); i++ )
		for( int j=i+1; ( j<all_goods.size() ) && ( all_goods[i]->get_goods_count() == all_goods[j]->get_goods_count() ) ; j++ )
			if( all_goods[j]->get_goods_price() < all_goods[i]->get_goods_price() )
				swap_goods(all_goods, i, j);
}
void sort_goods_by_seller_username(vector<Goods*>& all_goods)
{
	for( int i=0; i<all_goods.size(); i++ )
		for( int j=i+1; ( j<all_goods.size() ) && ( all_goods[i]->get_goods_price() == all_goods[j]->get_goods_price() ) ; j++ )
			if( all_goods[j]->get_seller()->get_username() < all_goods[i]->get_seller()->get_username() )
				swap_goods(all_goods, i, j);
}

void swap_goods(vector<Goods*>& all_goods, int index1, int index2)
{
	Goods* temp;
	temp = all_goods[index1];
	all_goods[index1] = all_goods[index2];
	all_goods[index2] = temp;
}

void buy_handler(vector<User*>& users, Goods_vectors& goods_vectors, vector<Factor*>& factors, int& store_account, vector<Sale_request*>& sale_requests)
{
	string buyer_username;

	cin>>buyer_username;
	int index = search( users, buyer_username );

	if( index == NOT_FOUND )
		cout<<"Command Failed."<<endl;
	else if( users[index]->get_role() == SELLER )
		cout<<"Command Failed."<<endl;
	else
		buy_goods(users, goods_vectors, factors, users[index], store_account, sale_requests);
}

bool fix_seller_username( string& seller_username )
{
	char end_of_list = seller_username[seller_username.size()-1];
	seller_username.resize( seller_username.size()-1 );

	if( end_of_list == ',' )
	 	return false;
	else
		return true;
}

void buy_goods(vector<User*>& users, Goods_vectors& goods_vectors, vector<Factor*>& factors, User* buyer,
			   int& store_account, vector<Sale_request*>& sale_requests )
{
	string goods_name, seller_username;
	int goods_count;

	factors.push_back( new Factor( buyer ) );

	bool end_of_list = false;
	while( !end_of_list )
	{
		cin>>goods_name>>goods_count>>seller_username;
		end_of_list = fix_seller_username(seller_username);

		int index = search(goods_vectors.all_goods, goods_name, goods_count, seller_username);

		if( index == NOT_FOUND )
			cout<<"Command Failed."<<endl;
		else if( !cash( goods_vectors.all_goods[index], buyer, goods_count, store_account, goods_vectors, sale_requests ) )
			cout<<"Command Failed."<<endl;
		else
		{
			add_to_factor( factors[factors.size()-1], goods_vectors.all_goods[index], goods_count );
			eject_goods( goods_vectors, goods_vectors.all_goods[index], goods_count, store_account );
			cout<<"Command OK."<<endl;
		}
	}
	print_factor( factors, factors.size()-1, 1 );
}

void eject_goods( Goods_vectors& goods_vectors, Goods* goods, int goods_count,int& store_account )
{
	int remain_goods_count = ( goods->get_goods_count() ) - goods_count;

	goods->set_sold_count( goods->get_sold_count() + 1 );

	check_bestseller( goods_vectors.bestseller_goods, goods );

	if( remain_goods_count < 1 )
		empty( goods_vectors, goods );
	else
	{
		goods->set_goods_count( remain_goods_count );
		check_goods_counts( store_account, goods_vectors);
	}
}

bool cash( Goods* goods, User* buyer, int goods_count, int& store_account, Goods_vectors& goods_vectors, vector<Sale_request*> sale_requests )
{
	int total_price = ( goods->get_goods_price() )*goods_count;
	if( goods->get_off_til_end() || goods->get_off() )
		total_price = total_price*0.9;

	if( buyer->get_money() < (total_price*1.05) )
		return false;

	buyer->set_money( buyer->get_money() - (total_price*1.05) );

	if( search( goods_vectors.special_goods, goods ) )
	{
		goods->get_seller()->set_money( goods->get_seller()->get_money() + total_price );
		store_account += 0.05*total_price;
	}
	else
	{
		goods->get_seller()->set_money( goods->get_seller()->get_money() + ( ( goods->get_goods_price() )*goods_count ) );
		store_account += ( ( total_price*1.05 ) - ( ( goods->get_goods_price() )*goods_count ) );
	}

	check_sale( store_account, goods_vectors, sale_requests );
	return true;
}

void add_to_factor( Factor* factor, Goods* bought_goods, int bought_count )
{
	bought_goods = new Goods( (*bought_goods) );
	bought_goods->set_goods_count( bought_count );
	factor->add_goods( bought_goods );
}

void print_factor( vector<Factor*>& factors, int index, int edition )
{
	if( factors[index]->get_bought_goods_size() == 0 )
		return;

	User* buyer = factors[index]->get_buyer();

	if( edition == 1 )
	{
		cout<<"Factor number "<<index+1<<endl;
		cout<<buyer->get_first_name()<<" "<<buyer->get_last_name()<<" "<<buyer->get_username()<<" "<<buyer->get_phone_number()<<endl;
		cout<<"#. Goods Name | Goods Count | Goods Price | Seller Username | Sum (count * price )"<<endl;
	}
	else if( edition == 2 )
	{
		cout<<"Factor "<<index+1<<" "<<buyer->get_username()<<endl;
	}


	int sum = 0;
	for( int i=0; i < factors[index]->get_bought_goods_size(); i++ )
	{
		Goods* bought_goods = factors[index]->get_bought_goods(i);

		int goods_price = bought_goods->get_goods_price();
		if( bought_goods->get_off_til_end() || bought_goods->get_off() )
			goods_price = goods_price*0.9;

		cout<<i+1<<". "<<bought_goods->get_goods_name()<<" | "
			<<bought_goods->get_goods_count()<<" | "
			<<goods_price<<" | "
			<<bought_goods->get_seller()->get_username()<<" | "
			<<( goods_price*( bought_goods->get_goods_count() ) )<<endl;

		sum += ( goods_price*( bought_goods->get_goods_count() ) );
	}

	cout<<"Goods Sum = "<<sum<<endl;
	cout<<"Total Sum = "<<( sum + 0.05*sum )<<endl;
}

void empty( Goods_vectors& goods_vectors, Goods* goods )
{
	cout<<"Goods \""<<goods->get_goods_name()<<"\" deleted."<<endl;

	delete goods;

	for( int i=0; i<goods_vectors.all_goods.size(); i++ )
		if( goods_vectors.all_goods[i] == goods )
			goods_vectors.all_goods.erase( goods_vectors.all_goods.begin()+i );

	for( int i=0; i<goods_vectors.saled_goods.size(); i++ )
		if( goods_vectors.saled_goods[i] == goods )
			goods_vectors.saled_goods.erase( goods_vectors.all_goods.begin()+i );

	for( int i=0; i<goods_vectors.temporary_saled_goods.size(); i++ )
		if( goods_vectors.temporary_saled_goods[i] == goods )
			goods_vectors.temporary_saled_goods.erase( goods_vectors.all_goods.begin()+i );

	for( int i=0; i<goods_vectors.special_goods.size(); i++ )
		if( goods_vectors.special_goods[i] == goods )
			goods_vectors.special_goods.erase( goods_vectors.all_goods.begin()+i );

	for( int i=0; i<goods_vectors.bestseller_goods.size(); i++ )
		if( goods_vectors.bestseller_goods[i] == goods )
			goods_vectors.bestseller_goods.erase( goods_vectors.all_goods.begin()+i );
}

void add_money_handler( vector<User*>& users )
{
	string username;
	int money;
	cin>>username>>money;

	int index = search( users, username );

	if( index == NOT_FOUND )
		cout<<"Command Failed."<<endl;
	else
	{
		users[index]->set_money( users[index]->get_money() + money );
		cout<<"Command OK."<<endl;
	}
}

void check_sale( int& store_account, Goods_vectors& goods_vectors, vector<Sale_request*>& sale_requests )
{
	check_sale_requests( store_account, goods_vectors.saled_goods, sale_requests );
	check_goods_counts( store_account, goods_vectors);
}

void check_sale_requests(int store_account, vector<Goods*>& saled_goods, vector<Sale_request*>& sale_requests )
{
	for( int i=0; i<sale_requests.size(); i++ )
	{
		Goods* case_goods = sale_requests[i]->get_sale_requested_goods();
		int count = 1;

		for( int j=i+1; j<sale_requests.size(); j++ )
			if( sale_requests[j]->get_sale_requested_goods() == case_goods )
				count++;

		if( count >= 10 && case_goods->get_off_til_end() == false && is_enough( store_account, case_goods ) )
		{
			case_goods->set_off_til_end( true );
			saled_goods.push_back( case_goods );
			cout<<"Goods \""<<case_goods->get_goods_name()<<"\" is Off by user requests."<<endl;
		}
	}
}

void check_goods_counts(int store_account, Goods_vectors& goods_vectors)
{
	for( int i=0; i<goods_vectors.all_goods.size(); i++ )
	{
		int index = search( goods_vectors.temporary_saled_goods, goods_vectors.all_goods[i] );

		if( goods_vectors.all_goods[i]->get_goods_count() > SALE_THRESHHOLD
			&& ( index == NOT_FOUND )
		 	&& is_enough( store_account, goods_vectors.all_goods[i] ) )
		{
			goods_vectors.temporary_saled_goods.push_back( goods_vectors.all_goods[i] );
			goods_vectors.all_goods[i]->set_off( true );
		}
		else if( goods_vectors.all_goods[i]->get_goods_count() <= SALE_THRESHHOLD
			     && ( index != NOT_FOUND ) )
		{
			goods_vectors.temporary_saled_goods.erase( goods_vectors.temporary_saled_goods.begin() + index );

			if( search( goods_vectors.special_goods, goods_vectors.all_goods[i] ) == NOT_FOUND )
				goods_vectors.all_goods[i]->set_off( false );
		}
	}
}

void check_bestseller( vector<Goods*>& bestseller_goods, Goods* goods )
{
	if( goods->get_sold_count() >= 10 )
		bestseller_goods.push_back( goods );
}

bool is_enough(int& store_account, Goods* case_goods )
{
	if( store_account + ( case_goods->get_goods_price() )*( case_goods->get_goods_count() )*( 0.9*1.05 - 1) >= 0 )
		return true;
	return false;
}

void sale_handler( vector<User*>& users, Goods_vectors& goods_vectors, vector<Sale_request*>& sale_requests, int& store_account )
{
	string buyer_username;
	cin>>buyer_username;

	int index = search( users, buyer_username );

	if( index == NOT_FOUND )
		cout<<"Command Failed."<<endl;
	else if( users[index]->get_role() == SELLER )
		cout<<"Command Failed."<<endl;
	else
		handle_sale( users[index], goods_vectors, sale_requests, store_account );
}

void handle_sale( User* buyer, Goods_vectors& goods_vectors, vector<Sale_request*>& sale_requests, int& store_account )
{
	string goods_name, seller_username;
	cin>>goods_name>>seller_username;

	int index = search( goods_vectors.all_goods, goods_name, 0, seller_username );

	if( index == NOT_FOUND )
		cout<<"Command Failed."<<endl;
	else
	{
		make_sale( buyer, goods_vectors.all_goods[index], goods_vectors, sale_requests, store_account );
		cout<<"Command OK."<<endl;
	}
}

void make_sale(User* buyer, Goods* goods, Goods_vectors& goods_vectors, vector<Sale_request*>& sale_requests, int& store_account)
{
	int index = search( sale_requests, buyer->get_username(), goods );

	if( index != NOT_FOUND )
		return;

	sale_requests.push_back( new Sale_request( buyer->get_username() , goods ) );
	check_sale_requests( store_account, goods_vectors.saled_goods, sale_requests );
}

void search_sale_handler( vector<Goods*>& all_goods )
{
	sort_goods( all_goods );

	int number = 1;
	for( int i=0; i<all_goods.size(); i++ )
	{
		if( (all_goods[i]->get_off() == true) || (all_goods[i]->get_off_til_end() == true) )
		{
			cout<<number<<". "<<all_goods[i]->get_goods_name()<<" "
				<<all_goods[i]->get_goods_count()<<" "
				<<all_goods[i]->get_goods_price()<<" "
				<<all_goods[i]->get_seller()->get_username()<<endl;
			number++;
		}
	}
}

void search_bestseller_handler( vector<Goods*>& bestseller_goods )
{
	sort_goods( bestseller_goods );

	int number = 1;
	for( int i=0; i<bestseller_goods.size(); i++ )
	{
			cout<<number<<". "<<bestseller_goods[i]->get_goods_name()<<" "
				<<bestseller_goods[i]->get_goods_count()<<" "
				<<bestseller_goods[i]->get_goods_price()<<" "
				<<bestseller_goods[i]->get_seller()->get_username()<<endl;
			number++;
	}
}

void print_factor_handler(vector<User*>& users,vector<Factor*>& factors )
{
	string buyer_username;
	cin>>buyer_username;

	int index = search( users, buyer_username );

	if( index == NOT_FOUND )
		cout<<"Command Failed."<<endl;
	else if( users[index]->get_role() == SELLER )
		cout<<"Command Failed."<<endl;
	else
		print_buyer_factors( buyer_username, factors );
}

void print_buyer_factors(string buyer_username,vector<Factor*>& factors )
{
	for( int i=0; i<factors.size(); i++ )
	{
		if( factors[i]->get_buyer()->get_username() == buyer_username )
			print_factor( factors, i, 2 );
	}
}

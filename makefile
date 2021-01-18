CC = g++
CFLAGS = -std=c++98 -Wall

all: online_store.cpp online_store_lib user goods factor sale_request request
	$(CC) $(CFLAGS) online_store.cpp online_store_lib.o user.o goods.o factor.o sale_request.o request.o -o a.out && ./a.out <input3.txt

online_store_lib: online_store_lib.hpp online_store_lib.cpp
	$(CC) $(CFLAGS) -c online_store_lib.cpp -o online_store_lib.o

user: User.hpp User.cpp
	$(CC) $(CFLAGS) -c User.cpp -o user.o

goods: Goods.hpp Goods.cpp
	$(CC) $(CFLAGS) -c Goods.cpp -o goods.o

factor: Factor.hpp Factor.cpp
	$(CC) $(CFLAGS) -c Factor.cpp -o factor.o

sale_request: Sale_request.hpp Sale_request.cpp
	$(CC) $(CFLAGS) -c Sale_request.cpp -o sale_request.o

request: Request.hpp Request.cpp
	$(CC) $(CFLAGS) -c Request.cpp -o request.o

clean:
	rm -r *.out; rm -r *.o;

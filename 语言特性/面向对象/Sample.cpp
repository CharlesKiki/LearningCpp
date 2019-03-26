//version 00
//
#include <iostream>
#include "Sample.h"

void Stock::acquire(const std::string & co, long n ,double pr)
{
	company = co;
	if(n < 0)
	{
		std::cout << "Number of shares can't be native;"
				<< company << "shares set to 0. \n";
		shares = 0;
	}
	else 
		shares = n;
	share_val = pr;
	set_tot();
}

void Stock::buy(long num ,double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative."
			<< "Transaction is aborted. \n";
	}
	else 
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if( num < 0 )
	{
		cout<< "Number of shares sold acn't be negative."
			<<" Transaction is aborted.\n "
	}
	else if (num > shares)
	{
		cout << "You can's sell more than you have! "
			<< " Transaction is aborted. \n "
	}
	else 
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::Show()
{
	std::cout <<  "Company :" << company 
		<< " Shares: " << shares << '\n'
		<< " Share Price :" << share_val
		<<" Total Worth: $" << total_val << '\n';
}
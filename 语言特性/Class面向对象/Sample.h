//Here define the class.
//the public funtion is interface 
//The interface is a bridge between programmer and program

#ifndef Sample_H_
#define Sample_H_

#include <string>

class Stock //class declaration
{
	private:
		std::string company;
		long shares_val;
		double share_val;
		double total_val;
		void set_tot() 
		{
			total_val = shares * share_val;
		}
	public:
		void acquire(const std::string & co,long n,double pr);
		void buy(long num,double price);
		void sell(long num,double prive);
		void update(double price);
		void show();
};	//note semicolon at the end

#endif
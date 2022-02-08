#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

class bill
{
	public:
	int xz;
	
	bill()
	{
        xz=0;
    }
	int customerid;
	string name;
	float price,qty,tax,dis;
	void postpaid();
    void prepaid();
    void customer();
}; 

void postpaid()
{

}

void prepaid()
{

}

void customer()
{

}

int main()
{
char ch;cout<<"\n\n\n\tMAIN MENU";
cout<<"\n\n\t01.";
cout<<"\n\n\t02.";
cout<<"\n\n\t03.";
cout<<"\n\n\tPlease Select Your Option (1-3) ";
return 0;
}

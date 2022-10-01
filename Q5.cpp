#include <iostream>

using namespace std;


class ACCOUNT
{
private:
	char name[20];
	double acc_no,bal,Money;
public:
	 int DEPOSIT(double bal,double Money)
	{   cout<<"ENTER THE AMOUNT TO BE DEPOSITED"<<endl;
		cin>>Money;
		bal=bal+Money;
		cout<<"BALANCE"<<bal<<endl;
		return bal;
	}
	int WITHDRAW(double bal,double Money)
	{   cout<<"ENTER THE AMOUNT TO BE WITHDRAW"<<endl;
		cin>>Money;
		bal=bal-Money;
		cout<<"BALANCE"<<bal<<endl;
		return bal;
		
	}
	void INTEREST(double bal)
	
	{
	   float SI;
	  		SI=bal*6*5/100;
		cout<<"THE SIMPLE INTEREST AT 6% Rate for 5 years is :"<<SI;
		cout<<endl;
		
	}
   void display(double bal,char name[],double acc_no)
	{
		cout<<"NAME "<<name<<endl;
		cout<<"ACCOUNT NO "<<acc_no<<endl;
		cout<<"BALCANCE "<<bal<<endl;
	}
	
};
int main()
{
	ACCOUNT A;
	char name[20],h;
	double acc_no,bal,Money;
	int x;
	cout<<"ENTER NAME"<<endl;
	cin>>name;
	cout<<"ENTER ACCOUNT NUMBER"<<endl;
	cin>>acc_no;
	cout<<"ENTER BALANCE"<<endl;
	cin>>bal;
	do{
		cout<<"WHAT DO YOU WWANT TO DO?"<<endl;
		cout<<"1.WITHDRAW"<<endl;
		cout<<"2.DEPOSIT"<<endl;
		cout<<"3.SIMPLE INTEREST"<<endl;
		cout<<"4.DISPLAY"<<endl;
		cout<<"5.EXIT"<<endl;
		cout<<"ENTER CHOICE"<<endl;
		cin>>x;
		switch(x)
		{
			case 1 : A.WITHDRAW(bal,Money); break;
			case 2 : A.DEPOSIT(bal,Money); break;
			case 3 : A.INTEREST(bal); break;
			case 4 : A.display(bal,name,acc_no); break;
			case 5 : exit(0);	
				
				
				
		}
		cout<<"DO YOU WANT TO CONTINUE"<<endl;
		cin>>h;
	}while(h=='y');
}
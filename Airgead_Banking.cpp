//============================================================================
// Name  Janera Dobson      : Airgead_Banking.cpp
//============================================================================

#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>

using namespace std;


// interest calculate by month
double interest(double d,double r){
   return(d*r/(1200));
}

// interest calculate by year
double interestY(double d,double r){
   return(d*r/(100));
}


int main(){

	//Display form to user
	cout << "*************************\n";
	cout << "********Data Input*******\n";
	cout << "Initial Investment Amount: \n";
	cout << "Monthly Deposit: \n";
	cout << "Annual Interest: \n";
	cout << "Number of years: \n";
	//To get press any key to continue line
	system("PAUSE");

   string s;

   // input in string
   cout << endl << endl;
   cout << "*************************\n";
   cout << "********Data Input*******\n";
   cout<<"Initial Investment Amount: ";
   double invst;
   cin>>s;
   stringstream si;

   // remove first character
   si<<s.substr(1);
   si>>invst;

   cout<<"Monthly Deposit: ";
   double md;
   cin>>s;
   stringstream sm;

   // remove first character
   sm<<s.substr(1);
   sm>>md;
   cout<<"Annual Interest: ";
   double ai;
   cin>>s;
   stringstream sa;

   // remove first character
   sa<<s.substr(1);
   sa>>ai;

   cout<<"Number of years: ";
   int ny;
   cin>>s;
   stringstream sn;
   sn<<s;
   sn>>ny;

   system("pause");

   // first report
   cout<<"\n\n Balance and Interest with Additional Monthly Deposits\n";
   cout<<"===================================================================\n";
   cout<<" Year          Year End Balance           Year End Earned Interest \n";
   cout<<"-------------------------------------------------------------------\n";

   double amnt=invst;

   for(int i=0;i<ny;i++){
       cout<<setw(5)<<(i+1);

       // calculate interest
       double itr=interestY(amnt,ai);


       cout<<fixed<<setw(19)<<"$"<<setprecision(2)<<(amnt+itr);
       cout<<setw(23)<<"$"<<setprecision(2)<<itr<<"\n";
       amnt+=itr;
   }


   // 2nd report
   cout << endl << endl;
   cout<<"\n\n Balance and Interest with Additional Monthly Deposits\n";
   cout<<"===================================================================\n";
   cout<<" Year           Year End Balance          Year End Earned Interest \n";
   cout<<"-------------------------------------------------------------------\n";


   amnt=invst;

   for(int i=0;i<ny;i++){
       cout<<setw(5)<<(i+1);
       double tintr=0;

       // calculate total interest and
       // balance after adding interest

       for(int i=0;i<12;i++){
           amnt+=md;

           // interest by month
           double itr=interest(amnt,ai);
           amnt+=itr;

           // total interest
           tintr+=itr;
       }

       stringstream am;
       am<<"$"<<fixed<<setprecision(2)<<(amnt);
       string ams;
       am>>ams;

       cout<<setw(19)<<ams;

       stringstream ai;
       ai<<"$"<<fixed<<setprecision(2)<<tintr;
       string ais;
       ai>>ais;

       cout<<setw(23)<<ais<<"\n";
   }

   // 3rd report
   amnt=invst;

   cout << endl << endl;
   cout<<" Balance and Interest with Additional Monthly Deposits\n";
   cout<<"=============================================================================================\n";
   cout<<" Month     Opening Amount     Deposited Amount     $ Total     $ Interest     Closing Balance\n";
   cout<<"---------------------------------------------------------------------------------------------\n";

   for(int i=0;i<ny*12;i++){
       cout<<setw(5)<<(i+1);

       //oprening amount
       stringstream a;
       a<<"$"<<fixed<<setprecision(2)<<amnt;
       string as;
       a>>as;

       // deposit
       cout<<setw(17)<<as;
       stringstream a1;
       a1<<"$"<<fixed<<setprecision(2)<<md;
       a1>>as;

       cout<<setw(18)<<as;

       // add monthly deposit
       amnt+=md;

       // total amount
       stringstream a2;
       a2<<"$"<<fixed<<setprecision(2)<<amnt;
       a2>>as;


       cout<<setw(15)<<as;


       // interest
       stringstream a3;
       a3<<"$"<<fixed<<setprecision(2)<<interest(amnt,ai);
       a3>>as;


       cout<<setw(14)<<as;

       // add interest
       amnt+=interest(amnt,ai);

       // closing balance
       stringstream a4;
       a4<<"$"<<fixed<<setprecision(2)<<amnt;
       a4>>as;

       cout<<setw(17)<<as<<"\n";
   }

   system("pause");
   return 0;
}

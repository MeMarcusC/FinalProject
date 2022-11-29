#include <iostream>
#include <cstring>

using namespace std;
/*
The Pawn Champs Ltd. needs a program that will manage their transactions at the store. You were hired to develop such a 
program using object oriented programming techniques using C++. A customer can come in and wish to pawn an item. 
The item can be a piece of jewelry or an electronic item. You can consider using a class pawn that will contain all 
the general characteristics (pawn number, balance, monthly payment etc) and methods that a regular pawn transaction 
will possess. Methods can include paypayment, forfeitpawn etc. You can consider derived classes such as jewelrypawn 
and electronicpawn. These classes will be derived from the pawn class.
The program will implement this structure and allow for pawn transactions to be recorded. Also a customer can pay 
monthly installments, forfeit a pawn and all the other methods you consider relevant or
important. The program must use classes and objects. It must have a menu with all the options available. It must 
print all messages or instructions in a professional and user friendly manner.
A user manual must be written with screenshots to describe its functionality to its users.
*/
class Account
{
    private:
        string name;
        int accnum;
        string address;
        int phone;
        bool record;
    public:
        Account(string nm, int acc, string add, int ph, bool rec);
        void makepawn(Account A );
        int getid();
        void CheckRecord();//

        string gettypeE(int T);
        string gettypeJ(int T);
};
class Pawn
{
    private:
        int owner;
        int pawnid;
        double worth;
        double interest;
        double balance;
        double monthlypayment;
        bool status;
    public:
        Pawn();// pawn constructor
        void intdayinc();// Increase of interest of item if data passes 30 days of pawn
        void numdays();//This method will change the date to all items.
        void paypayment() // Pay payment to one item and remove from balance, claudia 
        {
            double pp;
            cout<<"Please Enter How much you are going to pay."<<endl;
            cin>>pp;
            balance=balance-pp;
        }
        void changestatus()//Change the status (paid or in continuation) 
        {
            balance=0;
            status=false;
        }

};
class Jewelry: public Pawn
{
    private:
        string material;
        double weight;
        string design;
    public:
        Jewelry(string m, double w, string d)
        {
            material=m;
            weight=w;
            design=d; 
        }

};
class Electronic: public Pawn
{
    private:
        double timeusage;
        string type;
    public:
        Electronic(double t, string typ)
        {
            timeusage=t;
            type=typ;
        }
};
Account::Account(string nm, int acc, string add, int ph, bool rec)
{
    name= nm;
    accnum=acc;
    address=add;
    phone= ph;
    record= rec;  
}

int Account::getid()
{
    int id;
    id = accnum;
    return id;
}

string Account::gettypeE(int T)
{
    string type;
    if (T == 1)
    {
        type="Mobile Phone";
    }
    else if (T == 2)
    {
        type="Computer";
    }
    else if (T == 3)
    {
        type="Television";
    }
    else if (T == 4)
    {
        type="Kitchen Appliance";
    }
    else if (T == 5)
    {
        type="Security Appliance";
    }
    else if (T == 6)
    {
        type="Sound & Light";
    }
    else if (T == 7)
    {
        type="Entertainment";
    }
    return type;
}

void Account::makepawn(Account A)
{
    int ans;
    int owner;
    int pawnid;
    double worth;
    double interest;
    double balance;
    double monthlypayment;
    bool status;
    owner = A.getid();
    cout<<"\n\nPlease enter the Pawn Item ID: ";
    cin>>pawnid;
    cout<<"Please choose the type of item wished to be pawn (1 or 2).\n";
    cout<<"\n1) Electronic Item\n2) Jewelry\n";
    cout<<"Item: ";
    cin>>ans;
    if (ans == 1)
    {
        double timeusage;
        string type;
        int ty;
        cout<<"Please enter the type of Electronic Item (1,2,3,4,5)...\n";
        cout<<"\n1) Mobile Phone\n2) Computer\n3) Television\n4) Kitchen Appliance\n5) Security Appliance\n6) Network Tool\n7) Entertainment\n";
        cout<<"Type: ";
        cin>>ty;
        type = A.gettypeE(ty);
        cout<<"Please enter the Time Usage of the Item: ";
        cin>>timeusage;
        cout<<"Please enter the worth of the item: ";
        cin>>worth;

    }
    else if (ans == 2)
    {

    }

   
    double interest;
    double balance;
    double monthlypayment;
    bool status;
}
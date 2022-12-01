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
class System
{
    private:
        int na;//number of accounts
        int year;
        int day;
        int month;
    public:;
        System(int y, int d, int m)
        {
            year = y;
            day = d;
            month = m;
        }
        int getacc()
        {
            int num;
            num = na;
            return num;
        }
        void numdays()//This method will change the date to all items.
            {
                int y;
                int d;
                int m;
                cout<<"What day of the month is it? ";
                cin>>d;
                cout<<"What Month of the year is it? ";
                cin>>m;
                cout<<"What year is it? ";
                cin>>y;
                year=y;
                day =d;
                month= m;
            }
        int getY()
        {
            int y;
            y = year;
            return y;
        }
        int getM()
        {
            int m;
            m = month;
            return m;
        }
        int getD()
        {
            int d;
            d = day;
            return d;
        }
        int ShowMenu()
        {
            int choice;
            cout << "\nWelcome to the The Pawn Champs Ltd., Please Enter Your Choice\n"<<endl;
            cout << "1. To Create a Pawn "<<endl; 
            cout << "2. To Foriet a Pawn "<<endl;
            cout << "3. To Make Payment"<<endl;
            cout << "4. To Make New Account"<<endl;
            cout << "5. To Change Account Status"<<endl;
            cout << "6. To Change Current Date"<<endl;
            cout << "7. To Exit"<<endl;
            cin>>choice;
            return choice;
        }
        void Decider(Account A,int choice, Pawn P)
        {
            while (choice !=7)
            {
                switch(choice)
                {
                    case 1:
                        A.makepawn(A);
                        break
                    case 2:
                        P.forfeit();
                        break
                    case 3:
                        P.paypayment();
                        break
                    case 4:

                }
            }
        }
};
class Account
{
    private:
        string name;
        int accnum;
        string address;
        int phone;
        bool record;
    public:
        Account();
        void setAccount(string nm, int acc, string add, int ph, bool rec)
        {
            name= nm;
            accnum=acc;
            address=add;
            phone= ph;
            record= rec;  
        }
        void MakeNewAccount()
        {
            cout<<"\nWelcome to the The Pawn Champs Ltd.,Get Ready to Create an Account With Us"<<endl;
            cout<<"What is Your Name?"<<endl;
            cin>>name;
            cout<<"Please Enter Your Address"<<endl;
            cin>>address;
            cout<<"Please Enter Your Phone Number"<<endl;
            cin>>phone;
            cout<<"Please Enter Record"<<endl;
            cin>>record;
        }
        void makepawn(Account A);
        int getid()
        {       
            int id;
            id = accnum;
            return id;
        }
        void ChangeRecord()//
        {
            string yn;
            cout<<"Does this Account have a good record? (y or n): ";
            cin>>yn;
            if (yn == "y")
            {
                record = true;
            }
            else if ( yn == "n")
            {
                record = false;
            }
        }
        void CheckRecord()//
        {
            if (record == false)
            {
                cout<<"This Account has a Bad Record, and Can Not be Trusted!";
            }
            else if (record == false)
            {
                cout<<"This Account has a Good Record, and Can be Trusted!";
            }
        }
};
class Pawn
{
    private:
        int year;
        int day;
        int month;
        int owner;
        int pawnid;
        
        double worth;
        double interest;
        double balance;
        //double monthlypayment;
        int status;//0= has been paid back(gone), 1= is being paid back, 2 = up for sale
    public:
        void setPawn(int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts)// pawn constructor
        {
            year= yr;
            day = dy;
            month = mh;
            owner= own;
            pawnid= pid;
            worth=wh;
            interest= it;
            balance=bl;
            status = sts;
            
        }
        void intdayinc(System S)// Increase of interest of item if data passes 30 days of pawn
        {
            int Y;
            int M;
            int D;
            int dp;//of
            int md;
            int dd;
            Y= S.getY();
            M = S.getM();
            D = S.getD();
            int Yd= Y-year;

            if (Yd >= 0 )
            {
                M = M + (12 * Yd);
                md = M - month;
                dp = md * 30;
               
            }
            else if (Yd = 0)
            {
                md = M- month;
                dp = md *30;
            }
            dd = D-day;
            dp = dp + dd;
            if ( dp >= 30)
            {
                int nm;
                nm = dp/30;
                balance = balance + (interest * nm);
            }
        }
        void paypayment() // Pay payment to one item and remove from balance, claudia 
        {
            double pp;
            cout<<"Please Enter How much you are going to pay.";
            cin>>pp;
            balance=balance-pp;
        }
        void forfeit()//Change the status (paid or in continuation) 
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
        int design;
    public:
        Jewelry();
        void setjew(int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts,string m, double w, int d)
        {
            Pawn::setPawn(yr,dy,mh,own,pid, wh,it, bl, sts);
            material=m;
            weight=w;
            design=d; 
        }
        string getdes(int T)
        {
            string des;
            if (T == 1)
            {
                des="Necklace";
            }
            else if (T == 2)
            {
                des="Chain";
            }
            else if (T == 3)
            {
                des="Tiara";
            }
            else if (T == 4)
            {
                des="Ring";
            }
            else if (T == 5)
            {
                des="Earring";
            }
            else if (T == 6)
            {
                des="Anklet";
            }
            return des;
        }

};
class Electronic: public Pawn
{
    private:
        double timeusage;
        int type;
    public:
        Electronic();
        void setelc(int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts, double t, int typ)
        {
            Pawn::setPawn(yr,dy,mh,own,pid, wh,it, bl, sts);
            timeusage=t;
            type=typ;
        }
        string gettypeE(int T)
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
                type="Sound & Light";
            }
            else if (T == 6)
            {
                type="Entertainment";
            }
            return type;
        }
};
void Account::makepawn(Account A)
{
    int ans;
    int owner;
    int pawnid;
    string name;
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
        int ty;
        cout<<"Please enter the type of Electronic Item (1,2,3,4,5)...\n";
        cout<<"\n1) Mobile Phone\n2) Computer\n3) Television\n4) Kitchen Appliance\n5) Network Tool\n6) Entertainment\n";
        cout<<"Type: ";
        cin>>ty;
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
int main()
{
  // This is an array of objects having
  // maximum limit of 30 Employees
    Account acc[100];
    acc[0].setAccount("Marcus", 1000, "College Road", 5016072949, true);
    acc[1].setAccount("Marcus", 1000, "College Road", 5016072949, true);
    acc[2].setAccount("Marcus", 1000, "College Road", 5016072949, true);
    acc[3].setAccount("Marcus", 1000, "College Road", 5016072949, true);
    acc[4].setAccount("Marcus", 1000, "College Road", 5016072949, true);
    acc[5].setAccount("Marcus", 1000, "College Road", 5016072949, true);
    acc[6].setAccount("Marcus", 1000, "College Road", 5016072949, true);
    acc[7].setAccount("Marcus", 1000, "College Road", 5016072949, true);
    acc[8].setAccount("Marcus", 1000, "College Road", 5016072949, true);
    acc[9].setAccount("Marcus", 1000, "College Road", 5016072949, true);
    Jewelry jew[100];
    // order int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts,string m, double w, int d)
    jew[0].setjew(2022,20,11,1000,1100,100.00,12.50,100.00,1, "Gold", 2.50, 1);
    jew[0].setjew(2022,20,11,1000,1100,100.00,12.50,100.00,1, "Gold", 2.50, 1);
    jew[0].setjew(2022,20,11,1000,1100,100.00,12.50,100.00,1, "Gold", 2.50, 1);
    jew[0].setjew(2022,20,11,1000,1100,100.00,12.50,100.00,1, "Gold", 2.50, 1);
    jew[0].setjew(2022,20,11,1000,1100,100.00,12.50,100.00,1, "Gold", 2.50, 1);
    jew[0].setjew(2022,20,11,1000,1100,100.00,12.50,100.00,1, "Gold", 2.50, 1);
    jew[0].setjew(2022,20,11,1000,1100,100.00,12.50,100.00,1, "Gold", 2.50, 1);
    jew[0].setjew(2022,20,11,1000,1100,100.00,12.50,100.00,1, "Gold", 2.50, 1);
    jew[0].setjew(2022,20,11,1000,1100,100.00,12.50,100.00,1, "Gold", 2.50, 1);
    jew[0].setjew(2022,20,11,1000,1100,100.00,12.50,100.00,1, "Gold", 2.50, 1);
    Electronic elc[100];
    // order int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts, double t, int typ
    elc[0].setelc(2022,20,11,1000,1100,100.00,12.50,100.00,1, 100.0, 1);
    elc[0].setelc(2022,20,11,1000,1100,100.00,12.50,100.00,1, 100.0, 1);
    elc[0].setelc(2022,20,11,1000,1100,100.00,12.50,100.00,1, 100.0, 1);
    elc[0].setelc(2022,20,11,1000,1100,100.00,12.50,100.00,1, 100.0, 1);
    elc[0].setelc(2022,20,11,1000,1100,100.00,12.50,100.00,1, 100.0, 1);
    elc[0].setelc(2022,20,11,1000,1100,100.00,12.50,100.00,1, 100.0, 1);
    elc[0].setelc(2022,20,11,1000,1100,100.00,12.50,100.00,1, 100.0, 1);
    elc[0].setelc(2022,20,11,1000,1100,100.00,12.50,100.00,1, 100.0, 1);
    elc[0].setelc(2022,20,11,1000,1100,100.00,12.50,100.00,1, 100.0, 1);
    elc[0].setelc(2022,20,11,1000,1100,100.00,12.50,100.00,1, 100.0, 1);
   

}
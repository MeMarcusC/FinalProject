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
    acc[0].setAccount("Marcus", 1000, "College Road", 5016546541, true);
    acc[1].setAccount("Alexis", 1001, "Cotton St.", 5016072949, false);
    acc[2].setAccount("Riley", 1002, "5th Avenue", 5016555213, true);
    acc[3].setAccount("Tamara", 1003, "10th Avenue North", 5016646548, true);
    acc[4].setAccount("Richard", 1004, "Port Saul", 5016026483, false);
    acc[5].setAccount("Evelyn", 1005, "Punta Gorda St.", 5016648922, true);
    acc[6].setAccount("Derek", 1006, "1st Avenue", 5016481789, true);
    acc[7].setAccount("Emma", 1007, "11 St. South", 5016416891, false);
    acc[8].setAccount("Noah", 1008, "Rose St.", 5016789848, true);
    acc[9].setAccount("Logan", 1009, "San Antonio Road", 5016789162, false);
    Jewelry jew[100];
    // order int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts,string m, double w, int d)
    jew[0].setjew(2022,04,10,1001,1101,100.00,12.50,81.00,0, "Stainless Steal", 40.50, 4);
    jew[1].setjew(2022,21,04,1003,1102,250.00,31.25,168.00,2, "Brazilian Gold", 250.00, 6);
    jew[2].setjew(2022,10,09,1005,1103,325.00,40.60,127.00,1, "Silver", 30.50, 2);
    jew[3].setjew(2022,19,12,1004,1104,475.00,59.40,225.00,0, "Gold", 372.00, 3);
    jew[4].setjew(2022,25,07,1009,1105,500.00,62.50,300.00,1, "Diamond", 451.20, 4);
    jew[5].setjew(2022,05,08,1002,1106,550.00,68.75,150.00,2, "Pearl", 3.65, 1);
    jew[6].setjew(2022,12,01,1006,1107,450.00,56.25,185.00,2, "Gold", 350.50, 5);
    jew[7].setjew(2022,27,06,1008,1108,375.00,46.90,132.00,0, "Silver", 27.50, 2);
    jew[8].setjew(2022,30,03,1007,1109,200.00,25.00,90.00,2, "Brazilian Gold", 200.50, 6);
    jew[9].setjew(2022,16,11,1005,1110,150.00,18.75,50.00,1, "Stainless Steal", 42.50, 1);
    Electronic elc[100];
    // order int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts, double t, int typ
    elc[0].setelc(2022,02,05,1005,1111,500.00,62.50,300.00,0, 100.0, 1);
    elc[1].setelc(2022,22,02,1003,1112,450.00,56.25,180.00,1, 100.0, 6);
    elc[2].setelc(2022,15,06,1002,1113,375.00,46.90,130.00,2, 100.0, 2);
    elc[3].setelc(2022,08,10,1009,1114,225.00,28.10,160.00,1, 100.0, 5);
    elc[4].setelc(2022,28,06,1006,1115,100.00,12.50,80.00,2, 100.0, 1);
    elc[5].setelc(2021,31,12,1001,1116,150.00,18.75,55.00,0, 100.0, 4);
    elc[6].setelc(2022,11,09,1004,1117,200.00,25.00,100.00,2, 100.0, 3);
    elc[7].setelc(2022,20,10,1008,1118,325.00,40.60,120.00,0, 100.0, 2);
    elc[8].setelc(2022,17,11,1009,1119,475.00,59.40,250.00,1, 100.0, 6);
    elc[9].setelc(2022,14,01,1006,1120,550.00,68.75,140.00,0, 100.0, 4);

}
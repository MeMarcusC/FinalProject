#include <iostream>
#include <cstring>

using namespace std;
class System
{
    private:
        int noa;//number of accounts
        int noj;
        int noe;
        int year;
        int day;
        int month;
    public:;
        System(int na,int nj,int ne,int yr,int d,int m)
        {
            noa = na;
            noe = ne;
            noj = nj;
            year = yr;
            day = d;
            month = m;
        }
        int getjew()
        {
            int num;
            num = noj + 1;
            noj += 1;
            return num;
        }
        int getelc()
        {
            int num;
            num = noe + 1;
            noe += 1;
            return num;
        }
        int getacc()
        {
            int num;
            num = noa + 1;
            noa += 1;
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
                cout<<"\nThe New date is "<<d<<"/"<<m<<"/"<<y<<endl;
                string ok;
                cout<<"Are you sure you wish to make changes? (y or n): ";
                cin>> ok;
                if ( ok == "y")
                {
                    year=y;
                    day =d;
                    month= m;
                }
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
            cout << "6. To Check Account Status"<<endl;
            cout << "7. To Change Current Date"<<endl;
            cout << "8. To Exit"<<endl;
            cin>>choice;
            return choice;
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
        void makepawn();
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
        int getid()
        {
            int gid;
            gid = pawnid;
            return gid;
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
        void makepawn();
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
        int getid()
        {
            int idd;
            idd = Pawn::getid();
            return idd;
        }

};
class Electronic: public Pawn
{
    private:
        double timeusage;
        int type;
    public:
        void makepawn();
        Electronic();
        int getid()
        {
            int idd;
            idd = Pawn::getid();
            return idd;
        }
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
void Pawn::makepawn()
{
    /*
    int owner;
    int pawnid;
    double worth;
    double interest;
    double balance;
    double monthlypayment;
    bool status;*/
    //owner = id;
    cout<<"\n\nPlease enter the Pawn Item ID: ";
    cin>>pawnid;
    cout<<"Please enter the worth of the item: ";
        cin>>worth;

   
    double interest;
    double balance;
    double monthlypayment;
    bool status;
}
void Jewelry::makepawn()
{
        double timeusage;
        int ty;
        cout<<"Please enter the type of Electronic Item (1,2,3,4,5)...\n";
        cout<<"\n1) Mobile Phone\n2) Computer\n3) Television\n4) Kitchen Appliance\n5) Network Tool\n6) Entertainment\n";
        cout<<"Type: ";
        cin>>ty;
        cout<<"Please enter the Time Usage of the Item: ";
        cin>>timeusage;

}
void Electronic::makepawn()
{

}
int main()
{
  // This is an array of objects having
  // maximum limit of 30 Employees
    System main = System(9,9,9,2022,1,12);
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
    int ans;
    /*cout << "\nWelcome to the The Pawn Champs Ltd., Please Enter Your Choice\n"<<endl;
            cout << "1. To Create a Pawn "<<endl; 
            cout << "2. To Foriet a Pawn "<<endl;
            cout << "3. To Make Payment"<<endl;
            cout << "4. To Make New Account"<<endl;
            cout << "5. To Change Account Status"<<endl;
            cout << "6. To Check Account Status"<<endl;
            cout << "7. To Change Current Date"<<endl;
            cout << "8. To Exit"<<endl;
    */
    ans = main.ShowMenu();
    while (ans !=8)
        {
            if (ans ==1)
            {
                int id;
                cout<<"Please enter the Costumer Account ID: ";
                cin>>id;
                for( int i = 0; i<101;i++)
                {
                    int acid;
                    acid = acc[i].getid();
                    if( acid == id)
                    {
                        acc[i].CheckRecord();
                        string an;
                        cout<<"Do you want to continue? (y or n) : ";
                        cin>>an;
                        if (an == "y")
                        {
                            cout<<"Please choose the type of item wished to be pawn (1 or 2).\n";
                            cout<<"\n1) Electronic Item\n2) Jewelry\n";
                            cout<<"Item: ";
                            cin>>ans;
                            if (ans == 1)
                            {
                                int noid;
                                noid = main.getelc();
                                elc[noid].makepawn();
                            }
                            else if (ans == 1)
                            {
                                int noid;
                                noid = main.getjew();
                                jew[noid].makepawn();
                            }
                        }
                        
                    }
                }
            }
            else if (ans == 2) 
            {
                int id;
                cout<<"Please enter the Costumer Account ID: ";
                cin>>id;
                int pid;
                cout<<"Please enter the Pawn ID: ";
                cin>>pid;
                for( int i = 0; i<101;i++)
                {
                    int acid;
                    acid = acc[i].getid();
                    if( acid == id)
                    {
                        if ( pid >=1100 && pid<1200)
                        {
                            for( int t = 0; t<101;t++)
                            {
                                int paid;
                                paid = jew[t].getid();
                                if( paid == pid)
                                {
                                    jew[t].forfeit();
                                }
                            }
                        }
                        else if ( pid >=1200 && pid<1300)
                        {
                            for( int t = 0; t<101;t++)
                            {
                                int paid;
                                paid = elc[t].getid();
                                if( paid == pid)
                                {
                                    elc[t].forfeit();
                                }
                            }
                        }
                    }
                }
            }
            else if (ans == 3)
            {
                int id;
                cout<<"Please enter the Costumer Account ID: ";
                cin>>id;
                int pid;
                cout<<"Please enter the Pawn ID: ";
                cin>>pid;
                for( int i = 0; i<101;i++)
                {
                    int acid;
                    acid = acc[i].getid();
                    if( acid == id)
                    {
                        if ( pid >=1100 && pid<1200)
                        {
                            for( int t = 0; t<101;t++)
                            {
                                int paid;
                                paid = jew[t].getid();
                                if( paid == pid)
                                {
                                    jew[t].paypayment();
                                }
                            }
                        }
                        else if ( pid >=1200 && pid<1300)
                        {
                            for( int t = 0; t<101;t++)
                            {
                                int paid;
                                paid = elc[t].getid();
                                if( paid == pid)
                                {
                                    elc[t].paypayment();
                                }
                            }
                        }
                    }
                }
            }
            else if (ans == 4)
            {
                int id;
                id = main.getacc();
                acc[id].MakeNewAccount();
            }
            else if (ans == 5)
            {
                int id;
                cout<<"Please enter the Costumer Account ID for status to be changed: ";
                cin>>id;
                for( int i = 0; i<101;i++)
                {
                    int acid;
                    acid = acc[i].getid();
                    if( acid == id)
                    {
                        acc[i].ChangeRecord();
                    }
                }
            }
            else if (ans == 6)
            {
                int id;
                cout<<"Please enter the Costumer Account ID for status to be checked: ";
                cin>>id;
                for( int i = 0; i<101;i++)
                {
                    int acid;
                    acid = acc[i].getid();
                    if( acid == id)
                    {
                        acc[i].CheckRecord();
                    }
                }
            }
            else if (ans == 7)
            {
                main.numdays();
            }
            ans = main.ShowMenu();
        }
        
    
}
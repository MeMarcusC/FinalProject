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
            cout << "7. To View the Information of Pawn Item"<<endl;
            cout << "8. To View the Information of Costumer Account"<<endl;
            cout << "9. To Change Current Date"<<endl;
            cout << "10. To Exit"<<endl;
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
        void ShowUserAccount()
        {
            cout<<"The Users Name is: "<<name<<endl;
            cout<<"The Users Account Number is: "<<accnum<<endl;
            cout<<"The Users Address is: "<<address<<endl;
            cout<<"The Users Phone Number is: "<<phone<<endl;
            cout<<"The Users Record is: "<<record<<endl;
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
        void makepawn(int own);
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
        string getstatus()
        {
            //0= has been paid back(gone), 1= is being paid back, 2 = up for sale
            string st;
            if (status == 0)
            {
                st ="Active";
            }
            else if (status == 0)
            {
                st ="Inactive";
            }
            if (status == 0)
            {
                st ="Up For Sale";
            }
            return st;
        }
        void ShowPawnItem()
        {
            cout<<"The Pawn Item Information is Loading...\n";
            cout<<"The Owner of pawn is: "<<owner<<endl;
            cout<<"The Pawn ID is: "<<pawnid<<endl;
            cout<<"The Date When Item was Pawned is: "<<day<<"/"<<month<<"/"<<year<<endl;
            cout<<"The Worth of the pawn is: "<<worth<<endl;
            cout<<"The Interest accumilated by pawn is: "<<interest<<endl;
            cout<<"The Balance is: "<<balance<<endl;
            cout<<"The Staus of the pawn is: "<<getstatus()<<endl;
        }

};
class Jewelry: public Pawn
{
    private:
        int material;
        double weight;
        int design;
    public:
        void makepawn(int own);
        Jewelry();
        void setjew(int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts,int m, double w, int d)
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
        string getmat(int T)
        {
            string mat;
            if (T == 1)
            {
                mat="Gold";
            }
            else if (T == 2)
            {
                mat="Silver";
            }
            else if (T == 3)
            {
                mat="Pearl";
            }
            else if (T == 4)
            {
                mat="Stainless Steel";
            }
            else if (T == 5)
            {
                mat="Diamond";
            }
            return mat;
        }
        int getid()
        {
            int idd;
            idd = Pawn::getid();
            return idd;
        }
        void ShowPawnItem()
        {
            Pawn::ShowPawnItem();
            cout<<"The Material of the item is: "<<getmat(material)<<endl;
            cout<<"The Weight of the item is: "<<weight<<endl;
            cout<<"The Design of the item is: "<<getdes(design)<<endl;
        }

};
class Electronic: public Pawn
{
    private:
        double timeusage;
        int type;
    public:
        void makepawn(int own);
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
        void ShowPawnItem()
        {
            Pawn::ShowPawnItem();
            cout<<"The Time Usage of the item is: "<<timeusage<<endl;
            cout<<"The type of the item is: "<<gettypeE<<endl;
        }
};
void Pawn::makepawn(int own)
{
    /*
  
    bool status;*/
    //owner = id;
    owner = own;
    cout<<"Lets Get Started Creating A New Pawn Item!\n.....\n";
    cout<<"\nPlease enter the Pawn Item ID: ";
    cin>>pawnid;
    cout<<"Please enter the worth of the item: ";
    cin>>worth;
    int in;
    in = worth *( 12.5/100);
    interest = in;
    balance = worth;
    status = 1;
}
void Jewelry::makepawn(int own)
{
    Pawn::makepawn(own);
    cout<<"Please enter the Material of Jewelry (1,2,3,4,5)...\n";
    cout<<"\n1) Gold\n2) Silver\n3) Pearl\n4) Stainless Steel\n5) Diamond";
    cout<<"Material: ";
    cin>>material;
    cout<<"Please enter the Material of Jewelry (1,2,3,4,5)...\n";
    cout<<"\n1) Necklace\n2) Chain\n3) Tiara\n4) Ring\n5) Earring\n6) Anklet";
    cout<<"Design: ";
    cin>>design;
    cout<<"Please Specify the Weight of the Jewelry: ";
    cin>>weight;  
}
void Electronic::makepawn(int own)
{
    Pawn::makepawn(own);
    cout<<"Please enter the type of Electronic Item (1,2,3,4,5)...\n";
    cout<<"\n1) Mobile Phone\n2) Computer\n3) Television\n4) Kitchen Appliance\n5) Network Tool\n6) Entertainment\n";
    cout<<"Type: ";
    cin>>type;
    cout<<"Please enter the Time Usage of the Item: ";
    cin>>timeusage;
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
    //cout<<"\n1) Gold\n2) Silver\n3) Pearl\n4) Stainless Steel\n5) Combination";
    jew[0].setjew(2022,04,10,1001,1101,100.00,12.50,81.00,0, 4, 40.50, 4);
    jew[1].setjew(2022,21,04,1003,1102,250.00,31.25,168.00,2, 1, 250.00, 6);
    jew[2].setjew(2022,10,9,1005,1103,325.00,40.60,127.00,1, 2, 30.50, 2);
    jew[3].setjew(2022,19,12,1004,1104,475.00,59.40,225.00,0, 1, 372.00, 3);
    jew[4].setjew(2022,25,07,1009,1105,500.00,62.50,300.00,1, 5, 451.20, 4);
    jew[5].setjew(2022,05,8,1002,1106,550.00,68.75,150.00,2, 3, 3.65, 1);
    jew[6].setjew(2022,12,01,1006,1107,450.00,56.25,185.00,2, 1, 350.50, 5);
    jew[7].setjew(2022,27,06,1008,1108,375.00,46.90,132.00,0, 2, 27.50, 2);
    jew[8].setjew(2022,30,03,1007,1109,200.00,25.00,90.00,2,1, 200.50, 6);
    jew[9].setjew(2022,16,11,1005,1110,150.00,18.75,50.00,1, 4, 42.50, 1);
    Electronic elc[100];
    // order int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts, double t, int typ
    elc[0].setelc(2022,02,05,1005,1201,500.00,62.50,300.00,0, 50.0, 1);
    elc[1].setelc(2022,22,02,1003,1202,450.00,56.25,180.00,1, 80.0, 6);
    elc[2].setelc(2022,15,06,1002,1203,375.00,46.90,130.00,2, 100.0, 2);
    elc[3].setelc(2022,8,10,1009,1204,225.00,28.10,160.00,1, 120.0, 5);
    elc[4].setelc(2022,28,06,1006,1205,100.00,12.50,80.00,2, 150.0, 1);
    elc[5].setelc(2021,31,12,1001,1206,150.00,18.75,55.00,0, 180.0, 4);
    elc[6].setelc(2022,11,9,1004,1207,200.00,25.00,100.00,2, 200.0, 3);
    elc[7].setelc(2022,20,10,1008,1208,325.00,40.60,120.00,0, 225.0, 2);
    elc[8].setelc(2022,17,11,1009,1209,475.00,59.40,250.00,1, 250.0, 6);
    elc[9].setelc(2022,14,01,1006,1210,550.00,68.75,140.00,0, 275.0, 4);
    int ans;
    /*cout << "\nWelcome to the The Pawn Champs Ltd., Please Enter Your Choice\n"<<endl;
            cout << "1. To Create a Pawn "<<endl; 
            cout << "2. To Foriet a Pawn "<<endl;
            cout << "3. To Make Payment"<<endl;
            cout << "4. To Make New Account"<<endl;
            cout << "5. To Change Account Status"<<endl;
            cout << "6. To Check Account Status"<<endl;
            cout << "7. To View the Information of Pawn Item"<<endl;
            cout << "8. To View the Information of Costumer Account"<<endl;
            cout << "9. To Change Current Date"<<endl;
            cout << "10. To Exit"<<endl;
    */
    ans = main.ShowMenu();
    while (ans !=10)
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
                                elc[noid].makepawn(id);
                            }
                            else if (ans == 1)
                            {
                                int noid;
                                noid = main.getjew();
                                jew[noid].makepawn(id);
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
            //
            //
            else if (ans == 9)
            {
                main.numdays();
            }
            ans = main.ShowMenu();
        }

}
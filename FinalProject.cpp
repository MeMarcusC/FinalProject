//Program Name : Pawn Shop
//Programmers : Claudia Orellana, Carmita Sosa, Marcus Canul

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
                cout<<"What year is it?(yyyy) ";
                cin>>y;
                cout<<"What Month of the year is it?(1-12) ";
                cin>>m;
                cout<<"What day of the month is it?(1-31) ";
                cin>>d;
                cout<<"\nThe New date (dd/mm/yyyy)is "<<d<<"/"<<m<<"/"<<y<<endl;
                string ok;
                cout<<"\nAre you sure you wish to make changes? (y or n): ";
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
            cout<<"\n***************************************************\n";
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
            cout<<"\n***************************************************\n\n";
            cout<<"Choice: ";
            cin>>choice;
            cout<<"\n***************************************************\n\n";
            return choice;
        }
};
class Account
{
    private:
        string name;
        int accnum;
        string address;
        long int phone;
        bool record;
    public:
        Account()
        {

        }
        void setAccount(string nm, int acc, string add, long int ph, bool rec)
        {
            name= nm;
            accnum=acc;
            address=add;
            phone= ph;
            record= rec;  
        }
        int getid()
        {       
            int id;
            id = accnum;
            return id;
        }
        bool getrec()
        {       
            bool id;
            id = record;
            return id;
        }
        void ChangeRecord()//
        {
            string yn;
            cout<<"\n***************************************************\n\n";
            cout<<"Does this Account have a good record? (y or n): ";
            cin>>yn;
            bool rec;
            if (yn == "y")
            {
                rec = true;
            }
            else if ( yn == "n")
            {
                rec = false;
            }
            record = rec;
        }
        void CheckRecord()//
        {
            cout<<"\n\n***************************************************\n\n";

            if (record == false)
            {
                cout<<"This Account has a Bad Record, and Can Not be Trusted!\n";
            }
            else if (record == true)
            {
                cout<<"This Account has a Good Record, and Can be Trusted!\n";
            }

        }
        void ShowUserAccount()
        {
            cout<<"\n***************************************************\n\n";
            cout<<"The Account Information is Loading...\n";
            cout<<"The Users Name is: "<<name<<endl;
            cout<<"The Users Account Number is: "<<accnum<<endl;
            cout<<"The Users Address is: "<<address<<endl;
            cout<<"The Users Phone Number is: "<<phone<<endl;
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
        Pawn()
        {

        }
        Pawn(int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts)// pawn constructor
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
            int nm;
            int dp;//of
            int md;
            int dd;
            Y= S.getY();
            M = S.getM();
            D = S.getD();


            int Yd= Y-year;
            int sts = status; 
            if (status ==1 )
            {

            if (Yd >= 0 )
            {
                M = M + (12 * Yd);
                md = M - month;
                dp = md * 30;               
            }
            else if (Yd == 0)
            {
                md = M- month;
                dp = md *30;
            }
            dd = D-day;
            dp = dp + dd;
            if ( dp >= 30)
            {
                nm = dp/30;
                balance = balance + (interest * nm);
            }
            if (nm >= 6)
            {
                balance=0;
                interest = 0;
                status=2;
            }
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
            cout<<"Please enter how much is being paid: ";
            cin>>pp;
            balance=balance-pp;
        }
        void forfeit()//Change the status (paid or in continuation) 
        {
            balance=0;
            interest = 0;
            status=2;
        }
        string getstatus()
        {
            //0= has been paid back(gone), 1= is being paid back, 2 = up for sale
            string st;
            int sts;
            sts = status;
            cout<<"status"<<status;
            if (sts == 1)
            {
                st ="Active";
            }
            else if (sts == 0)
            {
                st ="Inactive";
            }
            else if (sts == 2)
            {
                st ="Up For Sale";
            }
            return st;
        }
        void checksts()
        {
            int sts;
            sts = status;
            double bl;
            bl = balance;
            if ( sts == 2)
            {
                balance=0;
                interest = 0;
            }
            if (bl == 0 && sts == 1)
            {
                status = 0;
                interest = 0;
            }
        }
        void ShowPawnItem()
        {
            string st;
            st = getstatus();
            cout<<"\n***************************************************\n\n";
            cout<<"The Pawn Item Information is Loading...\n";
            cout<<"\nThe Owner of pawn is: "<<owner<<endl;
            cout<<"The Pawn ID is: "<<pawnid<<endl;
            cout<<"The Date When Item was Pawned is: "<<day<<"/"<<month<<"/"<<year<<endl;
            cout<<"The Worth of the pawn is: $"<<worth<<endl;
            cout<<"The Set Amount Interest of the pawn is: $"<<interest<<endl;
            cout<<"The Balance is: $"<<balance<<endl;
            cout<<"The Status of the pawn is: "<<st<<endl;
        }

};
class Jewelry: public Pawn
{
    private:
        int material;
        double weight;
        int design;
    public:
        void check()
        {
            Pawn::checksts();
        }
        void interestcheck(System S)
        {
            Pawn::intdayinc(S);
        }
        Jewelry()
        {

        }
        Jewelry(int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts,int m, double w, int d):Pawn(yr,dy,mh,own,pid, wh,it, bl, sts)
        {
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
            string mat;
            mat = getmat(material);
            string des;
            des = getdes(design);
            Pawn::ShowPawnItem();
            cout<<"The Material of the item is: "<<mat<<endl;
            cout<<"The Weight of the item is: "<<weight<<" grams\n";
            cout<<"The Design of the item is: "<<des<<endl;
        }

};
class Electronic: public Pawn
{
    private:
        double timeusage;
        int type;
    public:
        void check()
        {
            Pawn::checksts();
        }
        void interestcheck(System S)
        {
            Pawn::intdayinc(S);
        }
        Electronic()
        {

        }
        int getid()
        {
            int idd;
            idd = Pawn::getid();
            return idd;
        }
        Electronic(int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts, double t, int typ):Pawn(yr,dy,mh,own,pid, wh,it, bl, sts)
        {
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
            string ty = gettypeE(type);
            cout<<"The Time Usage of the item is: "<<timeusage<<endl;
            cout<<"The type of the item is: "<<ty<<endl;
        }
};

int main()
{
  // This is an array of objects having
  // maximum limit of 30 Employees
  //System(int na,int nj,int ne,int yr,int d,int m)
    System main = System(9,9,9,2022,1,12);
    Account acc[20];
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
    Jewelry jew[20];
    // order int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts,string m, double w, int d)
    jew[0] = Jewelry(2022,04,10,1001,1100,100.00,12.50,81.00,0, 4, 40.50, 4);
    jew[1] = Jewelry(2022,21,04,1003,1101,250.00,31.25,168.00,2, 1, 250.00, 6);
    jew[2] = Jewelry(2022,10,9,1005,1102,325.00,40.60,127.00,1, 2, 30.50, 2);
    jew[3] = Jewelry(2022,19,12,1004,1103,475.00,59.40,225.00,0, 1, 372.00, 3);
    jew[4] = Jewelry(2022,25,07,1009,1104,500.00,62.50,300.00,1, 5, 451.20, 4);
    jew[5] = Jewelry(2022,05,8,1002,1105,550.00,68.75,150.00,2, 3, 3.65, 1);
    jew[6] = Jewelry(2022,12,01,1006,1106,450.00,56.25,185.00,2, 1, 350.50, 5);
    jew[7] = Jewelry(2022,27,06,1008,1107,375.00,46.90,132.00,0, 2, 27.50, 2);
    jew[8] = Jewelry(2022,30,03,1007,1108,200.00,25.00,90.00,2,1, 200.50, 6);
    jew[9] = Jewelry(2022,16,11,1000,1119,150.00,18.75,50.00,1, 4, 42.50, 1);
    Electronic elc[20];
    // order int yr,int dy,int mh,int own,int pid,double wh,double it,double bl,int sts, double t, int typ
    elc[0] = Electronic(2022,02,05,1005,1200,500.00,62.50,300.00,0, 50.0, 1);
    elc[1] = Electronic(2022,22,02,1003,1201,450.00,56.25,180.00,1, 80.0, 6);
    elc[2] = Electronic(2022,15,06,1002,1202,375.00,46.90,130.00,2, 100.0, 2);
    elc[3] = Electronic(2022,8,10,1009,1203,225.00,28.10,160.00,1, 120.0, 5);
    elc[4] = Electronic(2022,28,06,1006,1204,100.00,12.50,80.00,2, 150.0, 1);
    elc[5] = Electronic(2021,31,12,1001,1205,150.00,18.75,55.00,0, 180.0, 4);
    elc[6] = Electronic(2022,11,9,1004,1206,200.00,25.00,100.00,2, 200.0, 3);
    elc[7] = Electronic(2022,20,10,1008,1207,325.00,40.60,120.00,0, 225.0, 2);
    elc[8] = Electronic(2022,17,11,1009,1208,475.00,59.40,250.00,1, 250.0, 6);
    elc[9] = Electronic(2022,14,01,1000,1209,550.00,68.75,140.00,0, 275.0, 4);
    for ( int i = 0; i<100;i++)
    {
        elc[i].check();
    }

    int ans;
    ans = main.ShowMenu();
    while (ans !=10)
        {
            if (ans ==1)
            {
                int id;
                cout<<"Please enter the Costumer Account ID: ";
                cin>>id;
                if (id >=1000 && id <=1100)
                {
                for( int i = 0; i<101;i++)
                {
                    int acid;
                    acid = acc[i].getid();
                    if( acid == id)
                    {
                        bool rec;
                        rec == acc[i].getrec();
                        acc[i].CheckRecord();
                        string an;
                        cout<<"Do you want to continue? (y or n) : ";
                        cin>>an;
                        if (an == "y")
                        {
                            int own = id;
                            int pid;
                            double worth;
                            int status;
                            int yr;
                            int d;
                            int m;
                            cout<<"\n***************************************************\n";
                            cout<<"\nLets Get Started Creating A New Pawn Item!\n.....\n";
                            cout<<"\nPlease enter the current year (yyyy): ";
                            cin>>yr;
                            cout<<"Please enter the current month (mm): ";
                            cin>>m;
                            cout<<"Please enter the current day (dd): ";
                            cin>>d;
                            cout<<"\nPlease enter the worth of the item: ";
                            cin>>worth;
                            double inter;
                            inter = worth *( 12.5/100);
                            status = 1;
                            cout<<"\n\n***************************************************\n\n";
                            cout<<"Please choose the type of item wished to be pawn (1 or 2).\n";
                            cout<<"\n1) Electronic Item\n2) Jewelry\n";
                            cout<<"\n***************************************************\n";
                            cout<<"\nItem: ";
                            cin>>ans;
                            cout<<"\n***************************************************\n\n";

                            if (ans == 1)
                            {
                                int noid;
                                double timeusage;
                                int type;
                                noid = main.getelc();
                                int hun = noid + 1200;
                                cout<<"Please enter the type of Electronic Item (1,2,3,4,5)...\n";
                                cout<<"\n1) Mobile Phone\n2) Computer\n3) Television\n4) Kitchen Appliance\n5) Network Tool\n6) Entertainment\n";
                                cout<<"\n***************************************************\n";
                                cout<<"\nType: ";
                                cin>>type;
                                cout<<"\n***************************************************\n\n";
                                cout<<"Please enter the Time Usage of the Item (hours.minutes): ";
                                cin>>timeusage;
                                cout<<"\n***************************************************\n";
                                cout<<"The Pawn Item ID Is : "<<hun;
                                elc[noid] =Electronic(yr,d,m,own,hun,worth,inter,worth,1, timeusage, type);
                                break;
                            }
                            else if (ans == 2)
                            {
                                int noid;
                                noid = main.getjew();
                                int hun = noid + 1100;
                                int material;
                                int design;
                                double weight;
                                cout<<"Please enter the Material of Jewelry (1,2,3,4,5)...\n";
                                cout<<"\n1) Gold\n2) Silver\n3) Pearl\n4) Stainless Steel\n5) Diamond";
                                cout<<"\n***************************************************\n";
                                cout<<"\nMaterial: ";
                                cin>>material;
                                cout<<"\n***************************************************\n\n";
                                cout<<"Please enter the Material of Jewelry (1,2,3,4,5)...\n";
                                cout<<"\n1) Necklace\n2) Chain\n3) Tiara\n4) Ring\n5) Earring\n6) Anklet";
                                cout<<"\n***************************************************\n";
                                cout<<"\nDesign: ";
                                cin>>design;
                                cout<<"\n***************************************************\n\n";
                                cout<<"Please Specify the Weight of the Jewelry (grams): ";
                                cin>>weight; 
                                cout<<"\n***************************************************\n";
                                cout<<"The Pawn Item ID Is : "<<hun;
                                jew[noid] = Jewelry(yr,d,m,own,hun,worth,inter,worth,1,material, weight, design);
                                break;
                            }
                            else
                            {
                                break;
                            }
                            
                        }
                        else
                        {
                            cout<<"Error!\n";
                        }
                        
                    }
                }
                }
                else
                {
                    cout<<"Error!";
                }
            }
            else if (ans == 2) 
            {
                int costumerid;
                cout<<"Please enter the Costumer Account ID: ";
                cin>>costumerid;
                int pawnid;
                cout<<"Please enter the Pawn ID: ";
                cin>>pawnid;
                for( int i = 0; i<101;i++)
                {
                    int acid;
                    acid = acc[i].getid();
                    if( acid == costumerid)
                    {
                        if ( pawnid >=1100 && pawnid<1200)
                        {
                            for( int t = 0; t<101;t++)
                            {
                                int paid;
                                paid = jew[t].getid();
                                if( paid == pawnid)
                                {
                                    jew[t].forfeit();
                                    cout<<"\n\n***************************************************\n\n";
                                    cout<<"The Account Id "<<costumerid<<" Has Succesfully Forfeited The Pawn "<<pawnid<<"\n";
                                    break;
                                }
                            }
                        }
                        else if ( pawnid >=1200 && pawnid<1300)
                        {
                            for( int t = 0; t<101;t++)
                            {
                                int paid;
                                paid = elc[t].getid();
                                if( paid == pawnid)
                                {
                                    elc[t].forfeit();
                                    cout<<"\n\n***************************************************\n\n";
                                    cout<<"The Account Id "<<costumerid<<" Has Succesfully Forfeited The Pawn "<<pawnid<<"\n";
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout<<"Error\n";
                            break;
                        }
                    }
                    else
                    {
                        break;
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
                                    break;
                                }
                            }
                            break;
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
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
            }
            else if (ans == 4)
            {
                string nm;
                string ads;
                long int ph;
                bool rd;
                int id;
                id = main.getacc();
                int l = 1000+ id;
                cout<<"\nWelcome to the The Pawn Champs Ltd.,Get Ready to Create an Account With Us\n";
                cout<<"\nThe Costumer Id is : "<<l;
                cout<<"\nWhat is Account Name: ";
                cin>>nm;
                cout<<"Please Enter Account Address : ";
                cin>>ads;
                cout<<"Please Enter Account Phone Number : ";
                cin>>ph;
                cout<<"Please Enter Account Record (good = 1 or bad = 0) : ";
                cin>>rd;
                bool k=false;
                if( rd == 1)
                {
                    k = true;
                }
                acc[id].setAccount(nm, l, ads, ph, k);

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
                        break;
                    }
                    else
                    {
                        cout<<"Error!\n";
                        break;
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
                        bool rec;
                        rec == acc[i].getrec();
                        acc[i].CheckRecord();
                        break;
                    }
                    else
                    {
                        cout<<"Error!\n";
                        break;
                    }
                }
            }
            else if(ans == 7)
            {
                int pid;
                cout<<"Please enter the Pawn ID: ";
                cin>>pid;
                if ( pid >=1100 && pid<1200)
                {
                    for( int t = 0; t<101;t++)
                    {
                        int paid;
                        paid = jew[t].getid();
                        if( paid == pid)
                        {
                            jew[t].ShowPawnItem();
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
                            elc[t].ShowPawnItem();
                        }
                    }
                }
            }
            else if (ans == 8)
            {
                int accid;
                cout<<"Please enter the Costumer Account ID To Display Information: ";
                cin>>accid;
                for ( int i = 0; i<101;i++)
                {
                    int l = acc[i].getid();
                    if (l == accid)
                    {
                        acc[i].ShowUserAccount();
                        break;
                    }
                }
            }
           
            else if (ans == 9)
            {
                main.numdays();
                for (int i = 0; i<100;i++)
                {
                    jew[i].interestcheck(main);
                }
            }

            ans = main.ShowMenu();
            for ( int p = 0; p<100;p++)
            {
                elc[p].check();
            }
            for ( int z = 0; z<100;z++)
            {
                jew[z].check();
            }
        }
    cout<<"GoodBye! Thank For Using Our Program!\n";
    cout<<"\n***************************************************\n";

}
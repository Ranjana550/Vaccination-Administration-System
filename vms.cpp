#include<stdio.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<iomanip>
using namespace std;
int password();
void menu();
void show();
int no, num_vac;
    int no_vacc;
    int admr;
class vaccine
{
    int age;
    int temperature;
    int blood_pressure;
    char gender;
    string name;
    string aadhar;
    string profession;
    string address;
    string mobile_number;
    int cnt;
public:
    void search_data();
    void add_new();
    void setdata();
    void view_vaccine();
    void showdata();
    void search_by_aadhar();
    void search_by_age();
    void search_by_profession();
    void search_by_gender();
    void show_list();
    void view_vac();
    void add_more();
};
void show()
{
    cout<<setw(20)<<setiosflags(ios::left)<<"Name ";
    cout<<setw(20)<<"Aadhar No.";
    cout<<setw(10)<<"Age";
    cout<<setw(18)<<"Profession";
    cout<<setw(8)<<"B.P.";
    cout<<setw(15)<<"Temperature";
    cout<<setw(7)<<"gender";
    cout<<setw(15)<<"Mobile No.";
    cout<<"Address"<<endl;
}
void vaccine::show_list()
{
    cout<<"\n";
    cout<<setw(20)<<setiosflags(ios::left)<<name;
    cout<<setw(20)<<aadhar;
    cout<<setw(10)<<age;
    cout<<setw(18)<<profession;
    cout<<setw(8)<<blood_pressure;
    cout<<setw(15)<<temperature;
    cout<<setw(7)<<gender;
    cout<<setw(15)<<mobile_number;
    cout<<address<<endl;
}
void vaccine::view_vaccine(){
    cout<<"View Vaccine Statistics "<<endl;
    cout<<"\n1. Add more \t2. View available \t3. Exit"<<endl;
    cout<<"\n\n\t\tEnter your choice : ";
    int ch1;
    cin>>ch1;
    switch(ch1){
        case 1: add_more();
                _getch();
                break;
        case 2: view_vac();
                _getch();
                break;
        case 3:  system("cls");
                 exit(0);
        default:
                system("cls");
                cout<<"ENTER VALID OPTION"<<endl;
                menu();
    }

    }
    void vaccine :: add_more(){
        //int admr;
        cout<<"How many more vaccines do you want to add ?"<<endl;
        cin>>admr;
        ofstream ot;
        cout<<"Updated count of vaccines : ";

        ot.open("F:\\Ranjana\\4th_Sem_SY\\Try\\numvac.txt");
        int no_vacc1;
        no_vacc1 = no_vacc + admr;
        cout<<setw(10)<<no_vacc1;
        ot<<no_vacc1;
        ot.close();

    }
    void vaccine::view_vac(){
    ofstream ot;
    cout<<"No. of vaccines left : ";

    ot.open("F:\\Ranjana\\4th_Sem_SY\\Try\\numvac.txt");
    //int no_vacc;
    no_vacc = num_vac - no;
    cout<<setw(10)<<no_vacc;
    ot<<no_vacc;
    ot.close();

}
void vaccine::search_data()
{
    vaccine item;
    cout<<"From which option you want to perform searching "<<endl;
    cout<<"\n1. By aadhar \t2. By Age "<<endl;
    cout<<"\n3. By profession 4. By gender "<<endl;
    cout<<"\n\n\t\tEnter your choice "<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1:
        search_by_aadhar();
        _getch();
        break;
    case 2:
        search_by_age();
        _getch();
        break;
    case 3:
        search_by_profession();
        _getch();
        break;
    case 4:
        search_by_gender();
        _getch();
        break;
    default:
        system("cls");
        cout<<"ENTER VALID OPTION"<<endl;
        menu();
    }
}
void vaccine::search_by_aadhar()
{
    ifstream in("vaccine.txt");
    int flag =0;
    string adh_num;
    cout<<"enter your aadhar number "<<endl;
    fflush(stdin);
    getline(cin,adh_num);
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(adh_num.compare(aadhar)==0)
        {
            showdata();
            flag=1;
            break;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"Aadhar number not found "<<endl;
    }
    in.close();
}
void vaccine::search_by_age()
{
   ifstream in("vaccine.txt");
    int flag =0;
    int a,p=0;
    cout<<"enter Age by which you want to search "<<endl;
    cin>>a;
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(a==age)
        {
            show_list();
            flag=1;
            p++;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
    cout<<"Age you entered is not found"<<endl;
    }
    cout<<"\n\n\n\nTotal number of user by this age"<<p;
    in.close();

}
void vaccine::search_by_profession()
{
    ifstream in("vaccine.txt");
    int flag =0;
    int p=0;
    string prof;
    cout<<"enter Profession by which you want to search "<<endl;
    fflush(stdin);
    getline(cin,prof);
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(prof.compare(profession)==0)
        {
            show_list();
            flag=1;
            p++;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
    cout<<"The profession you have Enter does not exist"<<endl;
    }
    cout<<"\n\n\n By this profession "<<p<<endl;
    in.close();
}
void vaccine::search_by_gender()
{
    ifstream in("vaccine.txt");
    int flag =0;
    char g;
    int p=0;
    cout<<"enter gender by which you want to search "<<endl;
    cin>>g;
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(toupper(g)==toupper(gender))
        {
            show_list();
            flag=1;
            p++;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
    cout<<"The gender you endered does not exist "<<endl;
    }
    cout<<"\n\n\n by this gender "<<p<<endl;
    in.close();
}
void vaccine::setdata()
{
    fflush(stdin);
        cout<<"enter your name"<<endl;
        getline(cin,name);
        cout<<"enter your aadhar"<<endl;
        getline(cin,aadhar);
        cout<<"enter your gender (M|F)"<<endl;
        cin>>gender;
        cout<<"enter your age"<<endl;
        cin>>age;
        fflush(stdin);
        cout<<"enter your profession"<<endl;
        getline(cin,profession);
        cout<<"enter your B.P."<<endl;
        cin>>blood_pressure;
        cout<<"enter your Body temperature"<<endl;
        cin>>temperature;
        fflush(stdin);
        cout<<"enter your permanent address"<<endl;
        getline(cin,address);
        cout<<"enter your Mobile number "<<endl;
        getline(cin,mobile_number);
}
void vaccine::showdata()
{
   cout<<"Name is: "<<name<<endl;
   cout<<"Aadhar number is: "<<aadhar<<endl;
    cout<<"your age is "<<age<<endl;
    cout<<"Profession is : "<<profession<<endl;
    cout<<"gender is : "<<gender<<endl;
    cout<<"Blood pressure is :"<<blood_pressure<<endl;
    cout<<"BOdy temperature is : "<<temperature<<endl;
    cout<<"Address is "<<address<<endl;
    cout<<"Mobile number is: "<<mobile_number<<endl;
}
void vaccine::add_new()
{
    cout<<"Enter the no. of records you want to enter : ";
    cin>>no;
    fflush(stdin);
    for(int i=0; i<no; i++){
    fstream outin;
    outin.open("vaccine.txt",ios::app|ios::in);
    setdata();
    outin.write((char*)this,sizeof(vaccine));
    cout<<"YOUR DATA HAS BEEN SUCCESSFULLY INSERTED "<<endl;
    _getch();
    outin.close();
    }
}
void menu()
{
    system("cls");
    cout<<"\n*****************************************\n";
    cout<<"\t\tMENU";
    cout<<"\n*****************************************\n";
    cout<<"\n\t\t1: Add NEW Record";
    cout<<"\n\t\t2: View VACCINE DATA";
    cout<<"\n\t\t3: search";
    cout<<"\n\t\t4: exit";
}
int main()
 {
     vaccine obj;
     int k=3;
     //int num_vac;
    cout<<"\n\n\n\n\n\n\t\t\t\t\t"<<(char)(k+175)<<(char)(k+175)<<"VACCINE MANAGEMENT SYSTEM"<<(char)(k+175)<<(char)(k+175);
    cout<<"\n\n\n\n\n\n\n\t\t Press any key to continue....  ";
    _getch();
    B:
    system("cls");
    cout<<"\n\n\t\t\t\t*********************************************";
    cout<<"\n\t\t\t\t\tEnter Username and Password\n";
    cout<<"\t\t\t\t*********************************************\n";
    while(k>=1)
    {
    int c = password();
    if(c==1)
        break;
    else
        cout<<"\n\n\t\t Wrong Password Or Block Name \n\n\t\t You Can try Only "<<k-1<<" times more";
    k--;
    if(k<1)
        {
            for(int i=59; i>=0; i--)
            {
              system("cls");
              cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
              cout<<"\n\n\n\n\n\n\t\t\t\t\tTRY AFTER "<<i<<" SECONDS.....";
              Sleep(1000);
            }
              k=3;
              goto B;
        }
    }
    int ch;
    ofstream out;
    out.open("numvac.txt");
    int ch2;
    system("cls");
    cout<<"1. Number of vaccine government has alloted to you \t\n 2. Skip "<<endl;
    cout<<"enter your option "<<endl;
    cin>>ch2;
    switch(ch2)
 {
     case 1:
    cout<<"Enter number of vaccine "<<endl;
    cin>>num_vac;
    out<<num_vac;
    out.close();
     case 2:
      do{
      menu();
      cout<<"\n\t\n\tWhich One You Want: ";
      cin>>ch;
      vaccine v1;
      switch(ch)
       {
         case 1: system("cls");
                obj.add_new();
                 break;
         case 2: system("cls");
                 obj.view_vaccine();
                 break;
         case 3:system("cls");
                obj.search_data();
                 break;
         case 4:  system("cls");
                    exit(0);
         default: system("cls");
                  cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
                  cout<<"\n\n\t\t\t\t\t****HAVE A NICE DAY*****";
                  Sleep(3000);
                  exit(0);
       }
      }while(ch!=0);
 }
      return 0;
}
int password()
{
    char cname[30],pass[20];
    int ch, i=0;
    cout<<"\n\n\n\n\n\t\t\t\t\tUSERNAME:  ";
    gets(cname);
    cout<<"\n\t\t\t\t\tPASSWORD:    ";
    while((ch=_getch()) != 13)
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }
    pass[i] = '\0';
    if( (strcmp(cname,"vaccine management system")==0) && (strcmp(pass,"sha")==0) )
        return 1;
    else
        return 0;
}

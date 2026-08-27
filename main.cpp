#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
    cout<<"--------------------------------------------------------------------------------------------"<<endl;
    cout<<"=================================BANK MANAGEMENT SYSTEM====================================="<<endl;
    cout<<"--------------------------------------------------------------------------------------------"<<endl;
    cout<<"1--> CREATE ACCOUNT"<<endl;
    cout<<"2--> DISPLAY ACCOUNTS"<<endl;
    cout<<"3--> SEARCHING ACCOUNT"<<endl;
    cout<<"4--> UPDATE ACCOUNT"<<endl;
    cout<<"5--> DELETE ACCOUNT"<<endl;
    cout<<"6--> TRANSACTIONS"<<endl;
    cout<<"7--> SAVE ACCOUNT"<<endl;
    cout<<"0--> EXIT"<<endl; 


    while(1)
    {
    int  choice;
    cout<<"---------------------------------------------------------------------------------------------"<<endl;
    cout<<"ENTER YOUR CHOICE: ";
    cin>>choice;
    switch (choice)
    {

    case 1:
    {
        cout<<"Development under progress";
        break;
    }

    case 2:
    {
       cout<<"Development under progress";
       break;
    }

    case 3:
    {
        cout<<"Development under progress";
        break;
    }

    case 4:
    {
        cout<<"Development under progress";
        break;
    }

    case 5:
    {
        cout<<"Development under progress";
        break;
    }
    
    case 6:
    {
        cout<<"Development under progress";  
        break;
    }

    case 7:
    {
        cout<<"Development under progress";  
        break;
    }

    case 0:
    {
        cout<<"EXITED FROM MANAGMENT"<<endl;
        return 0;
    }
    
    default:
    {
        cout<<"INVALID STATE, PLEASE TRY WHICH ARE IN MENU"<<endl;
        break;
    }
  }

 }
}
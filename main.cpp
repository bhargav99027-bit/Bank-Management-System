#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

string CreatePIN()
{
    string PIN;
    cout<<"CREATE A 5-DIGIT PASSWORD "<<endl;
    getline(cin,PIN);

    if(PIN.size()==5)
    {
        return PIN;
    }

    else
    {
        cout<<"INVALI PIN, TRY AGAIN"<<endl;
        return CreatePIN();
    }
}

class account
{
    public :
    string AccountHolderName;
    string PIN;
    string AccountType;
    string AccountNumber;
    string PhNo;
    string Balance;
    int Age;
   
    public :
    void GetInfo()
    {

      cout<<"ENTER THE ACCOUNT NUMBER "<<endl;
      cin.ignore();
      getline(cin,AccountNumber);

      cout<<"ENTER THE ACCOUNT HOLDER NAME "<<endl;
      getline(cin,AccountHolderName);

      cout<<"ENTER THE ACCOUNT TYPE "<<endl;
      getline(cin,AccountType);

      PIN=CreatePIN();
      Balance="0.00";

      cout<<"ENTER THE AGE OF "<<AccountHolderName<<endl;
      cin>>Age;
      cin.ignore();

      while(true)
      {
        cout<<"ENTER THE VALID PHNO OF "<<AccountHolderName<<endl;
        getline(cin,PhNo);
        if(PhNo.size()==10)
        {
            break;
        }
        else
        {
            cout<<"INVALID NUMBER, TRY AGAIN"<<endl;
        }
      }

    }

    void SaveData()
    {

    }

};

int main()
{
    vector <account> accounts;
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
        account object;
        object.GetInfo();
        accounts.push_back(object);
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
        fstream file;
        file.open("AccountsInfo.txt",ios::app);
        if(file.is_open())
        {
           for(auto ref: accounts)
           {
             file<<ref.AccountNumber<<endl;
             file<<ref.PIN<<endl;
             file<<ref.AccountHolderName<<endl;
             file<<ref.AccountType<<endl;
             file<<ref.Balance<<endl;
             file<<ref.Age<<endl;
             file<<ref.PhNo<<endl;
             file<<endl;
           }
        }

        else
        {
            cout<<"ERROR WHILE OPENING FILE"<<endl;
        }
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
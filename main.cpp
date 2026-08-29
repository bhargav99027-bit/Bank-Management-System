#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

void UpdateAccount()
{
        int choice;
        cout<<"=================================UPDATE OPERATIONS====================================="<<endl;
        cout<<"1--> UPDATE NAME"<<endl;
        cout<<"2--> UPDATE AGE"<<endl;
        cout<<"3--> UPDATE PHNO"<<endl;
        cout<<"4--> UPDATE ACCOUNT NAME"<<endl;
        cout<<"5--> UPDATE PIN"<<endl;
        cout<<"0--> BACK"<<endl;
        int True=1;
        while(True)
        {
        cout<<"ENTER YOUR CHOICE FOR UPDATE OPERATIONS : ";
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
            case 1:
            {
               string AccountHolderName;
               string PIN;
               string AccountType;
               string AccountNumber;
               string PhNo;
               string Balance;
               int Age;
               string EnteredAccNumber;
               string EnteredPIN;
               string NewName;
               bool Found=false;
               ofstream TempFile;
               ifstream AccountsInfoFile;
               TempFile.open("temp.txt",ios::app);
               AccountsInfoFile.open("AccountsInfo.txt");
               if(TempFile.is_open() && AccountsInfoFile.is_open())
               {
                cout<<"ENTER THE ACCOUNT NUMBER TO UPDATE ACCOUNT HOLDER NAME : ";
                getline(cin,EnteredAccNumber);
                while (AccountsInfoFile >> AccountNumber  >> PIN >> AccountHolderName >> AccountType >> Balance >> Age >> PhNo )
                {
                  if(EnteredAccNumber==AccountNumber)
                   {
                      Found=true;
                      cout<<"ENTER THE 5-DIGIT PIN : "<<endl;
                      getline(cin,EnteredPIN);
                      while(EnteredPIN!=PIN)
                      {
                         cout<<"WRONG PIN, TRY AGAIN"<<endl;
                         cout<<"ENTER THE 5-DIGIT PIN : "<<endl;
                         getline(cin,EnteredPIN);
                      }

                      cout<<"ENTER THE NEW NAME TO UPDATE"<<endl;
                      getline(cin,NewName);
                      while(NewName==AccountHolderName)
                      {
                          cout<<"NEW NAME IS SAME AS OLD NAME "<<endl;
                          cout<<"ENTER THE NEW NAME TO UPDATE"<<endl;
                          getline(cin,NewName);

                      }

                      TempFile<<AccountNumber<<"  ";
                      TempFile<<PIN<<"  ";
                      TempFile<<NewName<<"   ";
                      TempFile<<AccountType<<"    ";
                      TempFile<<Balance<<"      ";
                      TempFile<<Age<<"    ";
                      TempFile<<PhNo<<"    ";
                      TempFile<<endl;
                      cout<<"UPDATED NEW NAME SUCCESSFULLY!"<<endl;
                      
                   }
                 else
                   {
                      TempFile<<AccountNumber<<"  ";
                      TempFile<<PIN<<"  ";
                      TempFile<<AccountHolderName<<"   ";
                      TempFile<<AccountType<<"    ";
                      TempFile<<Balance<<"      ";
                      TempFile<<Age<<"    ";
                      TempFile<<PhNo<<"    ";
                      TempFile<<endl;
                   }

                }

                TempFile.close();
                AccountsInfoFile.close();
                remove("AccountsInfo.txt");
                rename("temp.txt","AccountsInfo.txt");
                if(!Found)
                {
                  cout<<"ACCOUNT NUMBER NOT FOUND IN DATA BASE"<<endl;
                }
       
               }
               else
               {
                  cout<<"ERROR IN OPENING FILES"<<endl;
               }
               break;
            }

            case 2:
            {
               string AccountHolderName;
               string PIN;
               string AccountType;
               string AccountNumber;
               string PhNo;
               string Balance;
               int Age;
               string EnteredAccNumber;
               string EnteredPIN;
               int NewAge;
               bool Found=false;
               ofstream TempFile;
               ifstream AccountsInfoFile;
               TempFile.open("temp.txt",ios::app);
               AccountsInfoFile.open("AccountsInfo.txt");
               if(TempFile.is_open() && AccountsInfoFile.is_open())
               {
                cout<<"ENTER THE ACCOUNT NUMBER TO UPDATE ACCOUNT HOLDER AGE : ";
                getline(cin,EnteredAccNumber);
                while (AccountsInfoFile >> AccountNumber  >> PIN >> AccountHolderName >> AccountType >> Balance >> Age >> PhNo )
                {
                  if(EnteredAccNumber==AccountNumber)
                   {
                      Found=true;
                      cout<<"ENTER THE 5-DIGIT PIN : "<<endl;
                      getline(cin,EnteredPIN);
                      while(EnteredPIN!=PIN)
                      {
                         cout<<"WRONG PIN, TRY AGAIN"<<endl;
                         cout<<"ENTER THE 5-DIGIT PIN : "<<endl;
                         getline(cin,EnteredPIN);
                      }

                      cout<<"ENTER THE NEW AGE TO UPDATE"<<endl;
                      cin>>NewAge;
                      while(NewAge==Age)
                      {
                          cout<<"NEW AGE IS SAME AS OLD AGE "<<endl;
                          cout<<"ENTER THE NEW AGE TO UPDATE"<<endl;
                          cin>>NewAge;

                      }

                      TempFile<<AccountNumber<<"  ";
                      TempFile<<PIN<<"  ";
                      TempFile<<AccountHolderName<<"   ";
                      TempFile<<AccountType<<"    ";
                      TempFile<<Balance<<"      ";
                      TempFile<<NewAge<<"    ";
                      TempFile<<PhNo<<"    ";
                      TempFile<<endl;
                      cout<<"UPDATED NEW AGE SUCCESSFULLY!"<<endl;
                      
                   }
                 else
                   {
                      TempFile<<AccountNumber<<"  ";
                      TempFile<<PIN<<"  ";
                      TempFile<<AccountHolderName<<"   ";
                      TempFile<<AccountType<<"    ";
                      TempFile<<Balance<<"      ";
                      TempFile<<Age<<"    ";
                      TempFile<<PhNo<<"    ";
                      TempFile<<endl;
                   }

                }

                TempFile.close();
                AccountsInfoFile.close();
                remove("AccountsInfo.txt");
                rename("temp.txt","AccountsInfo.txt");
                if(!Found)
                {
                  cout<<"ACCOUNT NUMBER NOT FOUND IN DATA BASE"<<endl;
                }
       
               }
               else
               {
                  cout<<"ERROR IN OPENING FILES"<<endl;
               }
                break;
            }

            case 3:
            {
               string AccountHolderName;
               string PIN;
               string AccountType;
               string AccountNumber;
               string PhNo;
               string Balance;
               int Age;
               string EnteredAccNumber;
               string EnteredPIN;
               string NewPhno;
               bool Found=false;
               ofstream TempFile;
               ifstream AccountsInfoFile;
               TempFile.open("temp.txt",ios::app);
               AccountsInfoFile.open("AccountsInfo.txt");
               if(TempFile.is_open() && AccountsInfoFile.is_open())
               {
                cout<<"ENTER THE ACCOUNT NUMBER TO UPDATE ACCOUNT HOLDER PHNO : ";
                //cin.ignore();
                getline(cin,EnteredAccNumber);
                while (AccountsInfoFile >> AccountNumber  >> PIN >> AccountHolderName >> AccountType >> Balance >> Age >> PhNo )
                {
                  if(EnteredAccNumber==AccountNumber)
                   {
                      Found=true;
                      cout<<"ENTER THE 5-DIGIT PIN : "<<endl;
                      getline(cin,EnteredPIN);
                      while(EnteredPIN!=PIN)
                      {
                         cout<<"WRONG PIN, TRY AGAIN"<<endl;
                         cout<<"ENTER THE 5-DIGIT PIN : "<<endl;
                         getline(cin,EnteredPIN);
                      }

                      while(true)
                      {
                           cout<<"ENTER THE NEW PHNO TO UPDATE"<<endl;
                           getline(cin,NewPhno);
                           if(NewPhno.size()==10)
                            {
                               break;
                            }
                            else
                            {
                                cout<<"INVALID NUMBER, TRY AGAIN"<<endl;
                            }
                       }


                      while(NewPhno==PhNo)
                      {
                          cout<<"NEW PHNO IS SAME AS OLD PHNO "<<endl;
                          cout<<"ENTER THE NEW PHNO TO UPDATE"<<endl;
                          getline(cin,NewPhno);

                      }

                      TempFile<<AccountNumber<<"  ";
                      TempFile<<PIN<<"  ";
                      TempFile<<AccountHolderName<<"   ";
                      TempFile<<AccountType<<"    ";
                      TempFile<<Balance<<"      ";
                      TempFile<<Age<<"    ";
                      TempFile<<NewPhno<<"    ";
                      TempFile<<endl;
                      cout<<"UPDATED NEW PHNO SUCCESSFULLY!"<<endl;
                      
                   }
                 else
                   {
                      TempFile<<AccountNumber<<"  ";
                      TempFile<<PIN<<"  ";
                      TempFile<<AccountHolderName<<"   ";
                      TempFile<<AccountType<<"    ";
                      TempFile<<Balance<<"      ";
                      TempFile<<Age<<"    ";
                      TempFile<<PhNo<<"    ";
                      TempFile<<endl;
                   }

                }

                TempFile.close();
                AccountsInfoFile.close();
                remove("AccountsInfo.txt");
                rename("temp.txt","AccountsInfo.txt");
                if(!Found)
                {
                  cout<<"ACCOUNT NUMBER NOT FOUND IN DATA BASE"<<endl;
                }
       
               }
               else
               {
                  cout<<"ERROR IN OPENING FILES"<<endl;
               }
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

            case 0:
            {
                cout<<"EXITED FROM UPDATE OPERATIONS"<<endl;
                True=0;
                break;
            }
        }

    }
}

void DeleteAccount()
{
     
     string AccNumber;
     bool Found=false;
     ofstream TempFile;
     ifstream AccountsInfoFile;
     TempFile.open("temp.txt");
     AccountsInfoFile.open("AccountsInfo.txt");
     if(TempFile.is_open() && AccountsInfoFile.is_open())
     {
       cout<<"ENTER THE ACCOUNT NUMBER TO DELETE : ";
       cin.ignore();
       getline(cin,AccNumber);
       string line;
       while (getline(AccountsInfoFile,line))
       {
         if( (line.find(AccNumber)<line.length()) && !line.empty())
         {
             cout<<"DELETED THE ACCOUNT WITH ACCOUNT NUMBER OF :"<<AccNumber<<endl;
             Found=true;
         }
         else
         {
            TempFile<<line<<endl;
         }

       }
       TempFile.close();
       AccountsInfoFile.close();
       remove("AccountsInfo.txt");
       rename("temp.txt","AccountsInfo.txt");
       if(!Found)
       {
        cout<<"ACCOUNT NUMBER NOT FOUND IN DATA BASE"<<endl;
       }
       
     }
     else
     {
        cout<<"ERROR IN OPENING FILES"<<endl;
     }
}

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
    cout<<"7--> SAVE ACCOUNTS"<<endl;
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
       cout<<"*****************************ACCOUNTS DATABASE*********************************"<<endl;
       cout<<"-------------------------------------------------------------------------------"<<endl;
       cout<<"ACC.NUMBER   PIN    ACC.HOLDER   ACC.TPYE   BALANCE   AGE   PHNO"<<endl;
       cout<<"-------------------------------------------------------------------------------"<<endl;
       string line;
       fstream file;
       file.open("AccountsInfo.txt");
       if(file.is_open())
       {
          while(getline(file,line))
          {
            cout<<line<<endl;
          }
       }
       else
       {
        cout<<"ERROR IN OPENING FILE"<<endl;
       }
       break;
    }

    case 3:
    {
        cout<<"Development under progress";
        break;
    }

    case 4:
    {
        UpdateAccount();
        break;
    }

    case 5:
    {
        DeleteAccount();
        break;
    }
    
    case 6:
    {
        cout<<"Development under progress";  
        break;
    }

    case 7:
    { 
        cout<<"Development under progress"<<endl;
        fstream file;
        file.open("AccountsInfo.txt",ios::app);
        if(file.is_open())
        {
           for(auto ref: accounts)
           {
             file<<ref.AccountNumber<<"  ";
             file<<ref.PIN<<"  ";
             file<<ref.AccountHolderName<<"   ";
             file<<ref.AccountType<<"    ";
             file<<ref.Balance<<"      ";
             file<<ref.Age<<"    ";
             file<<ref.PhNo<<"    ";
             file<<endl;
           }
        }
        else
        {
            cout<<"ERROR WHILE OPENING FILE"<<endl;
        }
        file.close();
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
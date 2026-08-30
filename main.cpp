#include<iostream>
#include<vector>
#include<fstream>
#include<limits>
#include<set>
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

void SearchAccount()
{
       string AccountHolderName;
       string PIN;
       string AccountType;
       string AccountNumber;
       string PhNo;
       string Balance;
       string EnteredAccountNumber;
       bool Found=false;
       int Age;
       fstream file;

       file.open("AccountsInfo.txt");
       cout<<"ENTER THE ACCOUNT NUMBER TO UPDATE ACCOUNT HOLDER NAME : ";
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       getline(cin,EnteredAccountNumber);
       if(file.is_open())
       {
          while(file >> AccountNumber  >> PIN >> AccountHolderName >> AccountType >> Balance >> Age >> PhNo)
          {
                if(EnteredAccountNumber==AccountNumber)
                {
                     Found=true;
                     cout<<"*********************************ACCOUNT INFO**********************************"<<endl;
                     cout<<"-------------------------------------------------------------------------------"<<endl;
                     cout<<"ACC.NUMBER   PIN    ACC.HOLDER   ACC.TPYE   BALANCE   AGE   PHNO"<<endl;
                     cout<<"-------------------------------------------------------------------------------"<<endl;
                     cout<<AccountNumber<<"  ";
                     cout<<"*****"<<"  ";
                     cout<<AccountHolderName<<"   ";
                     cout<<AccountType<<"    ";
                     cout<<Balance<<"      ";
                     cout<<Age<<"    ";
                     cout<<PhNo<<"    ";
                     cout<<endl;
                }
          }
       }
       else
       {
        cout<<"ERROR IN OPENING FILE"<<endl;
       }
       if(!Found)
       {
         cout<<"ACCOUNT NUMBER NOT FOUND IN DATA BASE"<<endl;
       }
       file.close();
}

void DisplayAccounts()
{
       string AccountHolderName;
       string PIN;
       string AccountType;
       string AccountNumber;
       string PhNo;
       string Balance;
       int Age;

       cout<<"*****************************ACCOUNTS DATABASE*********************************"<<endl;
       cout<<"-------------------------------------------------------------------------------"<<endl;
       cout<<"ACC.NUMBER   PIN    ACC.HOLDER   ACC.TPYE   BALANCE   AGE   PHNO"<<endl;
       cout<<"-------------------------------------------------------------------------------"<<endl;

       fstream file;
       file.open("AccountsInfo.txt");
       if(file.is_open())
       {
          while(file >> AccountNumber  >> PIN >> AccountHolderName >> AccountType >> Balance >> Age >> PhNo)
          {
            cout<<AccountNumber<<"  ";
            cout<<"*****"<<"  ";
            cout<<AccountHolderName<<"   ";
            cout<<AccountType<<"    ";
            cout<<Balance<<"      ";
            cout<<Age<<"    ";
            cout<<PhNo<<"    ";
            cout<<endl;
          }
       }
       else
       {
        cout<<"ERROR IN OPENING FILE"<<endl;
       }
       file.close();
}

void UpdateAccount()
{
        int choice;
        cout<<"=================================UPDATE OPERATIONS====================================="<<endl;
        cout<<"1--> UPDATE NAME"<<endl;
        cout<<"2--> UPDATE AGE"<<endl;
        cout<<"3--> UPDATE PHNO"<<endl;
        cout<<"4--> UPDATE ACCOUNT TYPE"<<endl;
        cout<<"5--> UPDATE PIN"<<endl;
        cout<<"0--> BACK"<<endl;
        int True=1;
        while(True)
        {
        cout<<"ENTER YOUR CHOICE FOR UPDATE OPERATIONS : ";
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
               TempFile.open("temp.txt");
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
               string AccountHolderName;
               string PIN;
               string AccountType;
               string AccountNumber;
               string PhNo;
               string Balance;
               int Age;
               string EnteredAccNumber;
               string EnteredPIN;
               string NewAccountType;
               bool Found=false;
               ofstream TempFile;
               ifstream AccountsInfoFile;
               TempFile.open("temp.txt",ios::app);
               AccountsInfoFile.open("AccountsInfo.txt");
               if(TempFile.is_open() && AccountsInfoFile.is_open())
               {
                cout<<"ENTER THE ACCOUNT NUMBER TO UPDATE ACCOUNT TYPE : ";
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

                      cout<<"ENTER THE NEW ACCOUNT TYPE TO UPDATE"<<endl;
                      getline(cin,NewAccountType);


                      while(NewAccountType==AccountType)
                      {
                          cout<<"NEW ACCOUNT TYPE IS SAME AS OLD ACCOUNT TYPE "<<endl;
                          cout<<"ENTER THE NEW ACCOUNT TYPE TO UPDATE"<<endl;
                          getline(cin,NewAccountType);

                      }

                      TempFile<<AccountNumber<<"  ";
                      TempFile<<PIN<<"  ";
                      TempFile<<AccountHolderName<<"   ";
                      TempFile<<NewAccountType<<"    ";
                      TempFile<<Balance<<"      ";
                      TempFile<<Age<<"    ";
                      TempFile<<PhNo<<"    ";
                      TempFile<<endl;
                      cout<<"UPDATED NEW ACCOUNT TYPE SUCCESSFULLY!"<<endl;
                      
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

            case 5:
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
               string NewPIN;
               bool Found=false;
               ofstream TempFile;
               ifstream AccountsInfoFile;
               TempFile.open("temp.txt",ios::app);
               AccountsInfoFile.open("AccountsInfo.txt");
               if(TempFile.is_open() && AccountsInfoFile.is_open())
               {
                cout<<"ENTER THE ACCOUNT NUMBER TO UPDATE ACCOUNT HOLDER PIN : ";
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

                      NewPIN=CreatePIN();

                      while(NewPIN==PIN)
                      {
                          cout<<"NEW PIN IS SAME AS OLD PIN "<<endl;
                          cout<<"ENTER THE NEW PIN TO UPDATE"<<endl;
                          NewPIN=CreatePIN();
                      }

                      TempFile<<AccountNumber<<"  ";
                      TempFile<<NewPIN<<"  ";
                      TempFile<<AccountHolderName<<"   ";
                      TempFile<<AccountType<<"    ";
                      TempFile<<Balance<<"      ";
                      TempFile<<Age<<"    ";
                      TempFile<<PhNo<<"    ";
                      TempFile<<endl;
                      cout<<"UPDATED NEW PIN SUCCESSFULLY!"<<endl;
                      
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

            case 0:
            {
                cout<<"EXITED FROM UPDATE OPERATIONS"<<endl;
                True=0;
                break;
            }

            default:
            {
                cout<<"INVALID STATE, PLEASE TRY WHICH ARE IN MENU"<<endl;
                break;
            }
        }

    }
}

void DeleteAccount()
{
     string AccountHolderName;
     string PIN;
     string AccountType;
     string AccountNumber;
     string PhNo;
     string Balance;
     int Age;
     string EnteredAccNumber;
     bool Found=false;
     ofstream TempFile;
     ifstream AccountsInfoFile;

     TempFile.open("temp.txt");
     AccountsInfoFile.open("AccountsInfo.txt");
     if(TempFile.is_open() && AccountsInfoFile.is_open())
     {
       cout<<"ENTER THE ACCOUNT NUMBER TO DELETE : ";
       cin.ignore(numeric_limits<streamsize>::max(), '\n');

       getline(cin,EnteredAccNumber);
       while (AccountsInfoFile >> AccountNumber  >> PIN >> AccountHolderName >> AccountType >> Balance >> Age >> PhNo)
       {
         if(EnteredAccNumber==AccountNumber)
         {
             cout<<"DELETED THE ACCOUNT WITH ACCOUNT NUMBER OF :"<<EnteredAccNumber<<endl;
             Found=true;
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
            TempFile<<endl;;
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
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      getline(cin,AccountNumber);

      cout<<"ENTER THE ACCOUNT HOLDER NAME "<<endl;
      getline(cin,AccountHolderName);

      cout<<"ENTER THE ACCOUNT TYPE "<<endl;
      getline(cin,AccountType);

      PIN=CreatePIN();
      Balance="0.00";

      cout<<"ENTER THE AGE OF "<<AccountHolderName<<endl;
      cin>>Age;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
    cout<<"3--> SEARCH ACCOUNT"<<endl;
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
    //To Avoid Non Int Value
    if (!(cin >> choice))
    {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "INVALID INPUT. PLEASE ENTER A NUMBER." << endl;
        continue;
    }

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
       DisplayAccounts();
       break;
    }

    case 3:
    {
        SearchAccount();
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
        string AccountHolderName;
        string PIN;
        string AccountType;
        string AccountNumber;
        string PhNo;
        string Balance;;
        fstream file;
        int Age; 
        set <string> AccountNumbers;
        file.open("AccountsInfo.txt",ios::in);
        //Using set TO Insert only Nee Acconts To Data Base
        if(file.is_open())
        {
           while(file >> AccountNumber  >> PIN >> AccountHolderName >> AccountType >> Balance >> Age >> PhNo)
           {
              AccountNumbers.insert(AccountNumber);
           }
        }
        else
        {
         cout<<"ERROR WHILE OPENING FILE"<<endl;
        }
        file.close();

        file.open("AccountsInfo.txt",ios::app);
        if(file.is_open())
        {
           for(auto ref: accounts)
           {
              if(AccountNumbers.find(ref.AccountNumber)==AccountNumbers.end())
              {
                  file<<ref.AccountNumber<<"  ";
                  file<<ref.PIN<<"  ";
                  file<<ref.AccountHolderName<<"   ";
                  file<<ref.AccountType<<"    ";
                  file<<ref.Balance<<"      ";
                  file<<ref.Age<<"    ";
                  file<<ref.PhNo<<"    ";
                  file<<endl;
                  cout << "THE ACCOUNT WITH ACCOUNT NUMBER " << ref.AccountNumber<< "ADDED SUCCESSFULLY!" << endl;
              }
              else
              {
               cout << "THE ACCOUNT WITH ACCOUNT NUMBER " << ref.AccountNumber<< " ALREADY EXISTS IN THE DATABASE" << endl;

              }
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
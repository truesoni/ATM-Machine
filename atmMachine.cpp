#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

// Declaring a Class called atm
class Atm{    
    //Private Variables    
    private: 
        long int account_No;
        string name;
        int PIN;
        double balance;
        string mobileNo;

    // Public Methods    
    public:
        // setData function for setting the data into the private variables
        void setData(long int userAccNo, string userName, int userPIN, double userBalance, string userMobileNo){
            account_No = userAccNo;
            name = userName;
            PIN = userPIN;
            balance = userBalance;
            mobileNo = userMobileNo;
        }

        long int getAccountNo(){ 
            return account_No;
        }

        string getName(){
            return name;
        }

        int getPIN(){
            return PIN;
        }

        double getBalance(){
            return balance;
        }

        string getMobileNo(){
            return mobileNo;
        }

    void setMobile(string mob_prev, string mov_new){
        if(mob_prev == mobileNo){
            cout<<endl<<"Mobile Number Successfully Update.";
            getch();
        }

        else{
            cout<<endl<<"Oops... Incorrect Old Mobile Number";
            getch();  
        }
    }

    void cashWithDraw(int userAmount){
        if(userAmount > 0 && userAmount< balance){
            balance -= userAmount;
            cout<<endl<<"Please Collect Your Cash";
            cout<<endl<<"Available Balance : "<<balance;
            getch();
        }

        else{
            cout<<endl<<"Invalid Input Or Insufficient Balance";
            getch();
        }
    }
};

int main(){
    //Essential Variables
    int choice = 0, enterPIN;
    long int enterAccountNo;
    system("cls");  

    // Creating a user (Object)
    Atm user1;
    // Setting user Details (into Objects)     (Setting Default data)
    user1.setData(7406123,"Tom", 12345, 555743.90, "6536337358");


    // Creating the Login Window
    do{
        system("cls");
        cout<<endl<<"\t\t\t***** Welcome To SoniBank *****"<<endl;
        cout<<endl<<"Enter Your Account Number : ";
        cin>>enterAccountNo;

        cout<<endl<<"Enter PIN : ";
        cin>>enterPIN;

        if((enterAccountNo == user1.getAccountNo()) && enterPIN == user1.getPIN()){
            do{
                int amount = 0;
                string  oldMobileNo, newMobileNo;
                system("cls");

                // UserInterface 
                cout<<endl<<"\t\t\t***** Welcome To SoniBank *****"<<endl;
                cout<<endl<<"Select Options ";
                cout<<endl<<"\t1. Check Balance ";
                cout<<endl<<"\t2. Cash Withdraw";
                cout<<endl<<"\t3. Show User Details";
                cout<<endl<<"\t4. Update Mobile Number";
                cout<<endl<<"\t5. Exit "<<endl;
                cin>>choice;

                switch (choice)
                {
                case 1:
                    cout<<endl<<"Your Bank Balance is : "<<user1.getBalance();
                    getch();
                    break;
                
                case 2:
                    cout<<endl<<"Enter The Amount to Withdraw : ";
                    cin>>amount;
                    user1.cashWithDraw(amount);
                    break;
                
                case 3:
                    cout<<endl<<"Your Bank Details are :  ";
                    cout<<endl<<"\t--> Account Number : "<<user1.getAccountNo();
                    cout<<endl<<"\t--> Name : "<<user1.getName();
                    cout<<endl<<"\t--> Balance : "<<user1.getBalance();
                    cout<<endl<<"\t--> Mobile Number : "<<user1.getMobileNo();
                    getch();
                    break;
                
                case 4:
                    cout<<endl<<"Enter Your Old Mobile Number : ";
                    cin>>oldMobileNo;

                    cout<<endl<<"Enter Your New Mobile Number : ";
                    cin>>newMobileNo;
                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;
                
                
                case 5:
                        exit(0);
                
                default:
                    cout<<endl<<"Enter Valid Data !!!";
                }
            } while(1);   // Main Menu
        }

        else{
            cout<<endl<<"User Doesn't Match With Our Database !!!"; 
            getch();
        }
    } while(1); //Login 

    return 0;
}

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class ATM_MACHINE{
    private:
        int withdraw;
        int deposit;
        int balance;

        public:
            ofstream write;
            ifstream read;
            
            ATM_MACHINE(){
                balance = 0;
            }
            void showChoice(){
                cout<<"1 => Check Balance"<<endl
                    <<"2 => Deposit Money"<<endl
                    <<"3 => Withdraw Money"<<endl
                    <<"4 => Show Transaction History"<<endl
                    <<"5 => Delete Transaction History"<<endl;
            }
            void checkBalance(){
                cout<<"Your Balance is : "<<balance<<"$"<<endl;
            }

            void DepositCash(){
                write.open("history.txt",ios::app);
                cout<<"Enter Amount to Deposit : ";
                cin>>deposit;
                while(deposit<0){
                    cout<<"Plese Enter Correct Value : ";
                    cin>>deposit;
                }
                balance+=deposit;
                cout<<deposit<<"$ Deposited to Your Account"<<endl;
                if(deposit!=0){
                    write<<"You Deposited   : "<<deposit<<"$"<<endl;
                }
                write.close();
            }

            void withdrawCash(){
                write.open("history.txt",ios::app);
                cout<<"Enter Amount to Withdraw : ";
                cin>>withdraw;
                balance-=withdraw;
                cout<<withdraw<<"$ Withdrawn from your Account"<<endl;
                if(withdraw!=0){
                    write<<"You Withdrawn   : "<<withdraw<<"$"<<endl;
                }
                write.close();
            }

            void showHistory(){
                string str;
                read.open("history.txt");
                getline(read,str);
                bool empty = str.empty() != 0;
                if(empty){
                    cout<<"File is Empty!"<<endl;
                }
                else{
                    cout<<"\nTransaction History"<<endl;
                    while(read.eof()==0){
                    getline(read,str);
                    cout<<str<<endl;
                }
                }
                read.close();
            }

            void deleteHistory(){
                write.open("history.txt");
                write<<"";
                write.close();
                cout<<"History Deleted"<<endl;
            }
};

int main(){
    system("clear");
    int choice;
    char ans;
    ATM_MACHINE account;
    
    do{
    account.showChoice();
    cout<<"Enter Your Choice => ";
    cin>>choice;

    switch(choice){
        case 1:
        account.checkBalance();
        break;

        case 2:
        account.DepositCash();
        break;

        case 3:
        account.withdrawCash();
        break;

        case 4:
        account.showHistory();
        break;

        case 5:
        account.deleteHistory();
        break;

        default:
        cout<<"Invalid Choice!"<<endl;
    }

    cout<<"Do You Want to Run Program Again (Y/N) : ";
    cin>>ans;
    if(ans=='N' || ans == 'n'){
        cout<<"Thanks for Using My ATM MACHINE"<<endl;
    }
}while(ans=='Y' || ans=='y');

}
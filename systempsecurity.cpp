#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main(){
    int a ,i=0;
    string text,old, password1,password2,pass,name,password0,age,user,word,word1;
    string creds[2],cp[2];

    cout<<"        Security system     "<<endl<<endl;
    cout<<"_____________________________"<<endl;
    cout<<"        1 Register           "<<endl;
    cout<<"        2 Login               "<<endl;
    cout<<"        3 Change passweord     "<<endl;
    cout<<"________4 End Program___________"<<endl<<endl;
    
    do{
        cout<<endl<<endl;
        cout<<" Enter your choice :-";
        cin>>a;
        switch(a)
        {
            case 1:{
                cout<<"__________________________"<<endl;
                cout<<"|---------Register---------"<<endl;
                cout<<"|___________________________"<<endl;
                cout<<"please enter username:-";
                cin>>name;
                cout<<"please enter the password;--";
                cin>>password0;
                cout<<"Please enter your age :-";
                cin>>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0;
                    of1<<" Registration successfully "<<endl;

                }
                break;

                 }
                 case 2:{
                    i=0;
                    cout<<" ___________________________"<<endl<<endl;
                    cout<<"|-------------Login----------|"<<endl;
                    cout<<"|____________________________|"<<endl<<endl;


                    ifstream of2;
                    of2.open("file.txt");
                    cout<<" Plrasr enter the username:-";
                    cin>>user;
                    cout<<"plese enter the password:-";
                    cin>>pass;

                    if(of2.is_open())
                    {
                        while(!of2.eof()){
                            while(getline(of2,text)){
                                istringstream iss(text);
                                iss>>word;
                                creds[i]=word;
                                i++;

                           
                            }
                            if(user==creds[0] && pass==creds[1]){
                                cout<<"------Log in succesfully----";
                                cout<<endl<<endl;
                                cout<<"  Details:  "<<endl;
                                cout<<" username: "+name <<endl;
                                cout<<"password: "+ pass<<endl;
                                cout<<"age :  "+ age<<endl;


                            }
                            else{
                                cout<<endl<<endl;
                                cout<<" Incorect Credentails "<<endl;
                                cout<<"|      1. press 2 to Login       | "<<endl;
                                cout<< "|     2. Press 3 to change password   | "<<endl;
                                break;
                            }
                        }

                    }
                    break;  
                                   }

                                   case 3:{
                                    i=0;

                                    cout<<"----------------------change password---------"<<endl;
                                    ifstream of0;
                                    of0.open("file.txt");
                                    cout<<" enter the old password:-";
                                    cin>>old;
                                    if(of0.is_open()){
                                        while(of0.eof()){
                                            while(getline(of0, text)){
                                                istringstream iss(text);
                                                iss>>word1;
                                                cp[i]=word1;
                                                i++;


                    
                                            }
                                            if(old==cp[1]){
                                                of0.close();

                                                ofstream of1;
                                                if(of1.is_open()){
                                                    cout<<"enter your new password:-";
                                                    cin>>password1;
                                                    cout<<"enter your password again:-";
                                                    cin>>password2;
                                                    if(password1==password2){
                                                        of1<<cp[0]<<"\n";
                                                        of1<<password1;
                                                        cout<<"password change successfully "<<endl;

                                                        
                                                    }
                                                    else{
                                                        of1<<cp[0]<<"\n";
                                                        of1<<old;
                                                        cout<<"password do not math"<<endl;

                                                    }

                                                }
                                            }
                                            else{
                                                cout<<"please enter a valid password"<<endl;
                                                break;
                                            }
                                        }
                                    }
                                    break;

                                   }
                                   case 4:
                                   {
                                    cout<<"__________________Thankuoy!  _____________";
                                    break;
                                   }
                                   default:
                                   cout<<" enter a valid choiuce ";

                 
        }
    }
    while(a!=4);
    {
        return 0;
    }



}


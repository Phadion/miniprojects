#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
 string username;
 string password;
 string un;
 string pw;

        cout<<"Enter username: ";
 cin>>username;
 
 cout<<"Enter password: ";
 cin>>password;

 ifstream read("/home/jpaterno/development/c++/login_system/"+username+".txt");
 getline(read,un);
 getline(read,pw);

 if (un==username && pw==password)
  return true;
 else
  return false;
}

int main()
{
 int choice;

 cout<<"1: Register\n";
 cout<<"2: Login\n";
 cout<<"Your choice: ";
 cin>>choice;

 if (choice==1)
 {
  string username;
  string password;
  
  cout<<"select a username: ";
  cin>>username;
  cout<<"select a password: ";
  cin>>password;

  ofstream file;
  file.open("/home/jpaterno/development/c++/login_system/"+username+".txt");
  file<<username<<endl<<password;
  file.close();

  main();
 }
 else if (choice==2)
 {
  bool status=IsLoggedIn();

  if (!status)
  {
   cout<<"False Login!"<<endl;
   return 0;
  }
  else
  {
   cout<<"Successfully logged in!"<<endl;
   return 1;
  }
 }
}

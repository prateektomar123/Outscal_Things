#include <iostream>
using namespace std;

class Calculator
{
public:
   Calculator()
   {
     cout<<"Calculator Class Default Constructor"<<endl;
   }
   Calculator(int x)
   {
     cout<<"Calculator Class custom/paramaterized Constructor"<<endl;
   }

   ~Calculator()
   {
     cout<<"Calculator Class Default Destructor"<<endl;
   }
     ~Calculator(int x)
   {
     cout<<"Calculator Class custom/paramaterized Destructor"<<endl;
   }

};

class Add : Calculator
{
public:
   Add()
   {
     cout<<"Add Class Default Constructor"<<endl;
   }

    Add(int x)
   {
     cout<<"Add Class custom/paramaterized Constructor"<<endl;
   }

     ~Add()
   {
     cout<<"Add Class Default Destructor"<<endl;
   }

   ~Add(int x)
   {
     cout<<"Add Class custom/paramaterized Destructor"<<endl;
   }
};
int main()
{
  Add objAdd(10);
  return 0;
}
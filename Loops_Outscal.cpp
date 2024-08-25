#include <iostream>
using namespace std;


void shooting()
{
    cout<< "Player Is Shooting"<<endl;
}
void healing()
{
    cout<< "Player Is Healing"<<endl;
}
void attacking()
{
    cout<< "Player Is Attacking"<<endl;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
       shooting();
       
    }
   cout<<"\n";

    int a = 0;
    while ( a < 5)
    {
        a++;
        healing();
    }
    
    cout<<"\n";
    int b = 0;
    do
    {
        attacking();
        b++;
    } while (b < 7);
    
    
}
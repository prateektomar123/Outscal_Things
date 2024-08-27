#include <iostream>
using namespace std;


class Player
{
    private:
    int health;
    int healingPower;
    int attackingPower;

    public:
    Player()
    {
        cout<<"----Menco - One Last Fight!----"<<endl;
        cout<<"After countless fights and titles. Menco is now going to say bye to UFC and MMA forever" <<endl;
        cout<<"But But... as we say every legend deserves a legendary goodbye so here we have One last Fight "<<endl;
        cout<< "----Menvo vs Draco---"<<endl;
    }

    int gethealth()
    {
        return health;
    }

    int GiveDamage()
    {
        return 0;
    } 

    int TakeDamage(int damage)
    {
        if(health > 0)
        {
            health -= damage;
        }
        else
        {
            cout<< "Menco Lost The Last Match Of his Career"<<endl;
        }
    }
    int heal()
    {

    }

};


int main()
{
 Player playerobj;
  }

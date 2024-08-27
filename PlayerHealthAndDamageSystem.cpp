#include <iostream>
#include <ctime>
using namespace std;


class Player
{
    private:
    int health;
    int healingPower;
    int attackingPower;
    int minDamge = 8;
    int maxDamage = 16;
    int minHeal = 10;
    int maxHeal = 20;
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
        srand(time(0));
        int randomDamage = minDamge + (rand() % (maxDamage - minDamge + 1));
        return randomDamage;
    } 

    void TakeDamage(int damage)
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
    void heal()
    {
        srand(time(0));
        int randomHeal = minHeal + (rand() % (maxHeal - minHeal + 1));
        health += randomHeal; 
    }

};


int main()
{
 Player playerobj;
  }

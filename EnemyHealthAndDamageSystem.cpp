#include <iostream>
#include <ctime>
using namespace std;


class Enemy
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
    Enemy()
    {
        cout<<"----Here is Draco----"<<endl;
        cout<<"After wining two champion trophy consecutively he comes for Meco" <<endl;
        cout<<"so here we have a great vilain for the menco`s mma love story"<<endl;
        cout<< "----Menvo vs Draco---"<<endl;
        cout<<"-------------------------------------------"<<endl;
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
 Enemy enemyObj;
  }

#include <iostream>
using namespace std;

int health, attack, defense, healingPower; 

void TakeDamage(float damageToInflict)
{
    health -= damageToInflict;
    if (health < 0)
    {
        health = 0;
    }
    cout << "Player Health After Taking Damage: " << health <<endl;
    
}

void Heal(float healthToRecover)
{
    health += healthToRecover;
    cout << "Player Health After Healing: " << health <<endl;
}

void DamageMultiplier(float multiplier)
{
    attack *= multiplier;
    cout << "New Attack Value: " << attack << endl;
}

int main()
{
    health = 100;
    attack = 20;
    defense = 10;
    healingPower = 10;

    cout << "Initial Player Health: " << health <<endl; 
    cout << "Initial Attack Value: " << attack <<endl;
    cout << "Initial Defense Value: " << defense <<endl;
    cout << "Initial Healing Power Value: " << healingPower <<endl <<"\n";

    TakeDamage(10);
    Heal(20);
    DamageMultiplier(0.5);
    
}
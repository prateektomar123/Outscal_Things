#include <iostream>
#include <ctime>
using namespace std;

class Player
{
private:
    int health;
    int minDamage;
    int maxDamage;

public:
    Player() : health(100), minDamage(8), maxDamage(16)  // Initialize variables in the constructor
    {
        cout << "-------------------------------Menco - One Last Fight!-------------------------------" << endl;
        cout << "After countless fights and titles, Menco is now going to say goodbye to UFC and MMA forever." << endl;
        cout << "But, as we say, every legend deserves a legendary goodbye, so here we have one last fight!" << endl;
        cout << "----Between????---- any guesses? No? " << endl;
        cout << "----Menco vs Draco---" << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "Menco steps into the ring, the crowd roaring with excitement, every punch he's thrown over the years echoing in their cheers." << endl;
        cout << "Tonight, he faces Draco, the undefeated champion, known for his devastating knockout power and speed." << endl;
        cout << "Can Menco prove that once a legend, always a legend? Let the fight begin!" << endl;
    }

    int getHealth()
    {
        return health;
    }

    int giveDamage()
    {
        int randomDamage = minDamage + (rand() % (maxDamage - minDamage + 1));
        return randomDamage;
    }

    void takeDamage(int damage)
    {
        cout << "Draco unleashes a flurry of punches, landing a series of brutal hooks on Menco!" << endl;
        cout << "Damage taken: " << damage << endl;
        health -= damage;

        if (health <= 0)
        {
            cout << "Menco stumbles and falls! The referee steps in... it's over!" << endl;
            cout << "Menco lost the last match of his career, but he leaves the ring as a true warrior." << endl;
        }
        else
        {
            cout << "Menco's health after receiving damage: " << health << "\n" << endl;
        }
    }
};

class Enemy
{
private:
    int health;
    int minDamage;
    int maxDamage;

public:
    Enemy() : health(100), minDamage(8), maxDamage(16)  // Initialize variables in the constructor
    {
        cout << "----Here is Draco----" << endl;
        cout << "After winning two championship trophies consecutively, Draco steps into the ring to make Menco's last fight memorable." << endl;
        cout << "Draco, known for his fierce and relentless style, aims to cement his legacy by defeating the legend." << endl;
        cout << "Can Draco deliver on his promise, or will Menco prove that his spirit is unbreakable?" << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
    }

    int getHealth()
    {
        return health;
    }

    int giveDamage()
    {
        int randomDamage = minDamage + (rand() % (maxDamage - minDamage + 1));
        return randomDamage;
    }

    void takeDamage(int damage)
    {
        cout << "Menco retaliates with a powerful Jab-Cross-Hook combo that staggers Draco!" << endl;
        cout << "Damage taken: " << damage << endl;
        health -= damage;

        if (health <= 0)
        {
            cout << "Draco is down! The crowd goes wild as Menco raises his fists in victory!" << endl;
            cout << "Menco wins! Once a legend, always a legend. Tonight, he proved it once again." << endl;
        }
        else
        {
            cout << "Draco's health after receiving damage: " << health << "\n" << endl;
        }
    }
};

void gameLoop(Player& player, Enemy& enemy)
{
    char playerInput;
    srand(time(0));  // Seed random number generator once at the start

    do
    {
        cout << "Press A to attack" << endl;
        cin >> playerInput;
        if (playerInput == 'a' || playerInput == 'A')
        {
            cout << "\n";
            int playerDamage = player.giveDamage();
            int enemyDamage = enemy.giveDamage();

            if (playerDamage > enemyDamage)
            {
                cout << "Menco's punches are faster and harder than Draco's!" << endl;
                enemy.takeDamage(playerDamage);
                cout << "The crowd erupts in cheers as Menco takes the lead!" << endl;
            }
            else
            {
                cout << "Draco's power overwhelms Menco in this exchange!" << endl;
                player.takeDamage(enemyDamage);
                cout << "The audience gasps as Menco struggles to stay on his feet!" << endl;
            }
        }
        else
        {
            cout << "Invalid Input! You need to press 'A' to attack!" << endl;
        }
    } while (player.getHealth() > 0 && enemy.getHealth() > 0);
}

int main()
{
    Player playerObj;
    Enemy enemyObj;
    gameLoop(playerObj, enemyObj);  // Start the game loop
    return 0;
}

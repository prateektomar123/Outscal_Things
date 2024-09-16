#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player{
public:
    int health;
    int maxHealth;
    int meleeDamage;
    int rangedDamage;
    int defense;
    int level;
    bool hasSword, hasShield, hasArmor, hasBow;

Player() : maxHealth(100), health(100), meleeDamage(10), rangedDamage(0), defense(5), level(1),
               hasSword(false), hasShield(false), hasArmor(false), hasBow(false) {

               }
void levelUp(){
    level++;
    maxHealth += 10;
    health = maxHealth;
    meleeDamage += 5;
    cout << "Level up! You are now level " << level << "!\n";
    cout << "Max HP: " << maxHealth << ", Melee Damage: " << meleeDamage << ", Defense: " << defense << "\n\n";
}
void receiveItem(string item){
    if (item == "Sword"){
        hasSword = true;
        meleeDamage += 10;
        cout << "You've received the Sword! Melee Damage increased by 10.\n";
    }
    else if(item == "Shield"){
        hasShield = true;
        defense += 10;
        cout << "You've received the Shield! Defense increased by 10.\n";
    }
    else if (item == "Armor") {
        hasArmor = true;
        maxHealth += 20;
        health = maxHealth;
        defense += 5;
        cout << "You've received the Armor! Max HP increased by 20, Defense increased by 5.\n";
    }
    else if (item == "Bow")
    {
        hasBow = true;
        rangedDamage = 15;
        cout << "You've received the Bow! Ranged Attack unlocked (15 damage).\n";
    }
    
    
 
}
bool isAlive(){
    return health > 0;
}

void attackEnemy(bool ranged, int &enemyHealth, int enemyDefense){
    int damage;
    if(ranged && hasBow){
        damage = max(0, rangedDamage - enemyDefense);
        cout << "You shoot a ranged arrow! Dealt " << damage << " damage.\n";
    }
    else{
        damage = max(0, meleeDamage - enemyDefense);
        cout << "You attack with your weapon! Dealt " << damage << " damage.\n";
    }
    enemyHealth -= damage;
}
 void heal(){
    int healAmount = maxHealth/10;
    health = min(maxHealth , health + healAmount);
    cout << "You healed for " << healAmount << " HP. Current HP: " << health << "\n";
 }
};

class Enemy{
public:
    int health;
    int attackPower;
    int defense;

    Enemy(int level){
        health = 20 + rand() % (level * 10);
        attackPower = 5 +  rand() % (level * 5);
        defense = rand() + (level * 5);
    }
    bool isAlive() {
        return health > 0;
    }

    void attackPlayer(Player &player) {
        int damage = max(0, attackPower - player.defense);
        player.health -= damage;
        cout << "Enemy attacks you! You take " << damage << " damage. Your HP: " << player.health << "\n";
    }

};

bool chanceForSpecial() {
    return rand() % 100 < 10;
}


void battle(Player &player, Enemy &enemy){
    while(player.isAlive() && enemy.isAlive()){
        cout << "\nChoose action: (1) Attack (2) Heal: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            player.attackEnemy(false, enemy.health, enemy.defense);

            if (player.level >=2 && chanceForSpecial)
            {
                int criticalDamage = player.meleeDamage * 2;
                enemy.health -= criticalDamage;
                cout << "Critical hit! Dealt extra " << criticalDamage << " damage.\n";
            
            }
            // Check if enemy is defeated
            if (!enemy.isAlive()) {
                cout << "Enemy defeated!\n";
                break;
            }

            // Enemy attacks back
            enemy.attackPlayer(player);
        }
        else if (choice == 2) {
            player.heal();
            enemy.attackPlayer(player);
        }
            
        
        
    }

}

void levelProgress(Player &player, int numEnemies, string rewardItem, string specialAbility){
cout << "\n--- Level " << player.level << " ---\n";
    for (int i = 0; i < numEnemies; ++i) {
        cout << "Enemy " << i + 1 << " approaches!\n";
        Enemy enemy(player.level);
        battle(player, enemy);

        if (!player.isAlive()) {
            cout << "You died! Game over.\n";
            return;
        }
    }

    // Reward player after defeating enemies
    player.receiveItem(rewardItem);
    player.levelUp();
    cout << "Special Ability Unlocked: " << specialAbility << "\n\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generator

    Player player;
    cout << "Welcome to Hero's Quest: Battle Against Murlocs!\n";

    // Level 1
    levelProgress(player, 1, "Map", "None");

    // Level 2
    levelProgress(player, 2, "Sword", "Critical Hits");

    // Level 3
    levelProgress(player, 3, "Shield", "Blocker");

    // Level 4
    levelProgress(player, 4, "Armor", "Life Steal");

    // Level 5
    levelProgress(player, 5, "Bow", "Ranged Attack");

    // Level 6 - Boss Fight
    cout << "--- Level 6: Boss Fight ---\n";
    Enemy murlocBoss(6);
    murlocBoss.health = 150;  // Buffed health for the boss
    while (player.isAlive() && murlocBoss.isAlive()) {
        cout << "\nChoose action: (1) Melee Attack (2) Ranged Attack (3) Heal: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            player.attackEnemy(false, murlocBoss.health, murlocBoss.defense);
        } else if (choice == 2) {
            player.attackEnemy(true, murlocBoss.health, murlocBoss.defense);
        } else if (choice == 3) {
            player.heal();
        }

        // Murloc Boss attacks
        if (murlocBoss.isAlive()) {
            murlocBoss.attackPlayer(player);
        }
    }

    if (player.isAlive()) {
        cout << "You have defeated Murlocs and saved your village!\n";
    } else {
        cout << "You have been defeated by Murlocs. Game over.\n";
    }

    return 0;
}
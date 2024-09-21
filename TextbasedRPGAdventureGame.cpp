#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <functional>
#include <string>

using namespace std;

// Forward declarations
class Enemy;
class Boss;

// Player class
class Player {
private:
    int health;
    int maxHealth;
    int meleeDamage;
    int rangedDamage;
    int defense;
    int level;
    bool hasSword, hasShield, hasArmor, hasBow;

public:
    Player() : health(100), maxHealth(100), meleeDamage(10), rangedDamage(0), defense(5), level(1),
               hasSword(false), hasShield(false), hasArmor(false), hasBow(false) {}

    void attack(Enemy& target);

    void receiveDamage(int damage) {
        int actualDamage = max(0, damage - defense);
        health = max(0, health - actualDamage);
        cout << "You took " << actualDamage << " damage. Current HP: " << health << "\n";
    }

    void levelUp() {
        level++;
        maxHealth += 10;
        health = maxHealth;
        meleeDamage += 5;
        defense += 2;
        cout << "Level up! You are now level " << level << "!\n";
        cout << "Max HP: " << maxHealth << ", Melee Damage: " << meleeDamage << ", Defense: " << defense << "\n\n";
    }

    void receiveItem(const string& item) {
        if (item == "Sword") {
            hasSword = true;
            meleeDamage += 10;
            cout << "You've received the Sword! Melee Damage increased by 10.\n";
        } else if (item == "Shield") {
            hasShield = true;
            defense += 10;
            cout << "You've received the Shield! Defense increased by 10.\n";
        } else if (item == "Armor") {
            hasArmor = true;
            maxHealth += 20;
            health = maxHealth;
            defense += 5;
            cout << "You've received the Armor! Max HP increased by 20, Defense increased by 5.\n";
        } else if (item == "Bow") {
            hasBow = true;
            rangedDamage = 15;
            cout << "You've received the Bow! Ranged Attack unlocked (15 damage).\n";
        }
    }

    void heal(int amount) {
        health = min(maxHealth, health + amount);
        cout << "You healed for " << amount << " HP. Current HP: " << health << "\n";
    }

    bool isAlive() const { return health > 0; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getLevel() const { return level; }
};

// Enemy class
class Enemy {
protected:
    int health;
    int meleeDamage;
    int defense;
    int level;

public:
    Enemy(int level) : level(level) {
        health = 20 + rand() % (level * 10);
        meleeDamage = 5 + rand() % (level * 3);
        defense = rand() % (level * 2);
    }

    virtual ~Enemy() = default;

    virtual void performAction(Player& target) {
        if (rand() % 100 < 80) { // 80% chance to attack
            attack(target);
        } else { // 20% chance to heal
            heal();
        }
    }

    virtual void attack(Player& target) {
        int damage = meleeDamage;
        target.receiveDamage(damage);
        cout << "Enemy attacks! Dealt " << damage << " damage.\n";
    }

    void heal() {
        int healAmount = 5 + rand() % (level * 2);
        health += healAmount;
        cout << "Enemy heals for " << healAmount << " HP. Enemy HP: " << health << "\n";
    }

    void receiveDamage(int damage) {
        int actualDamage = max(0, damage - defense);
        health = max(0, health - actualDamage);
        cout << "Enemy took " << actualDamage << " damage. Enemy HP: " << health << "\n";
    }

    bool isAlive() const { return health > 0; }
    int getHealth() const { return health; }
};

// Boss class inheriting from Enemy
class Boss : public Enemy {
private:
    enum class SpecialMove { GroundSlash, SpeedDash, HealthRegeneration };

public:
    Boss(int level) : Enemy(level) {
        health = 150;  // Buffed health for the boss
        meleeDamage += 10;
        defense += 5;
    }

    void performAction(Player& target) override {
        Enemy::performAction(target);
        
        // 30% chance to use a special move
        if (rand() % 100 < 30) {
            useSpecialMove(target);
        }
    }

private:
    void useSpecialMove(Player& target) {
        SpecialMove move = static_cast<SpecialMove>(rand() % 3);
        switch (move) {
            case SpecialMove::GroundSlash:
                cout << "Boss uses Ground Slash!\n";
                target.receiveDamage(meleeDamage * 1.5);
                break;
            case SpecialMove::SpeedDash:
                cout << "Boss uses Speed Dash! Next attack damage increased.\n";
                meleeDamage += 5;
                break;
            case SpecialMove::HealthRegeneration:
                cout << "Boss uses Health Regeneration!\n";
                health += 15;
                cout << "Boss regenerates 15 HP!\n";
                break;
        }
    }
};

// Player's attack method definition
void Player::attack(Enemy& target) {
    int damage = hasBow && rand() % 2 == 0 ? rangedDamage : meleeDamage;
    cout << (damage == rangedDamage ? "You shoot an arrow! " : "You swing your weapon! ");
    target.receiveDamage(damage);

    // 10% chance to trigger special ability
    if (rand() % 10 == 0) {
        if (hasSword) {
            target.receiveDamage(meleeDamage * 2);
            cout << "Critical hit! Dealt extra damage.\n";
        }
        if (hasShield) {
            defense += 100;  // Temporary boost
            cout << "Blocker activated! Defense greatly increased for this turn.\n";
        }
        if (hasArmor) {
            heal(meleeDamage / 2);
            cout << "Life Steal activated! Recovered some HP.\n";
        }
        if (hasBow) {
            cout << "Ranged Attack special ability activated! You're safe from the next enemy attack.\n";
        }
    }
}

// Level class
class Level {
private:
    
    int numEnemies;
    string rewardItem;
    string specialAbility;
    function<unique_ptr<Enemy>(int)> enemyCreator;

public:
    int number;
    Level(int num, int enemies, string reward, string ability, function<unique_ptr<Enemy>(int)> creator)
        : number(num), numEnemies(enemies), rewardItem(reward), specialAbility(ability), enemyCreator(creator) {}

    bool play(Player& player) {
        cout << "\n--- Level " << number << " ---\n";
        for (int i = 0; i < numEnemies; ++i) {
            cout << "Enemy " << i + 1 << " approaches!\n";
            auto enemy = enemyCreator(player.getLevel());
            if (!battle(player, enemy)) {
                return false;
            }
        }

        if (!rewardItem.empty()) player.receiveItem(rewardItem);
        if (!specialAbility.empty()) cout << "New Special Ability Unlocked: " << specialAbility << "\n";
        player.levelUp();
        return true;
    }

private:
    bool battle(Player& player, unique_ptr<Enemy>& enemy) {
        bool playerTurn = true;
        bool rangedAttackActive = false;

        while (player.isAlive() && enemy->isAlive()) {
            if (playerTurn) {
                cout << "\nYour HP: " << player.getHealth() << "/" << player.getMaxHealth()
                     << " | Enemy HP: " << enemy->getHealth() << "\n";
                cout << "Choose action: (1) Attack (2) Heal: ";
                int choice;
                cin >> choice;

                if (choice == 1) {
                    player.attack(*enemy);
                } else if (choice == 2) {
                    player.heal(player.getMaxHealth() / 10);
                }

                playerTurn = false;
            } else {
                if (!rangedAttackActive) {
                    enemy->performAction(player);
                } else {
                    cout << "Ranged Attack special ability protected you from enemy action!\n";
                    rangedAttackActive = false;
                }
                playerTurn = true;
            }
        }

        if (!player.isAlive()) {
            cout << "You died! Game over.\n";
            return false;
        }
        return true;
    }
};


int main() {
    srand(static_cast<unsigned int>(time(0)));  

    Player player;
    cout << "Welcome to Hero's Quest: Battle Against Murlocs!\n";
    cout << "Your village has been captured by the monstrous Murlocs. ";
    cout << "Defeat them and save your people!\n\n";

    
    Level levels[] = {
        {1, 1, "Map", "None", [](int level) { return make_unique<Enemy>(level); }},
        {2, 2, "Sword", "Critical Hit", [](int level) { return make_unique<Enemy>(level); }},
        {3, 3, "Shield", "Blocker", [](int level) { return make_unique<Enemy>(level); }},
        {4, 4, "Armor", "Life Steal", [](int level) { return make_unique<Enemy>(level); }},
        {5, 5, "Bow", "Ranged Attack", [](int level) { return make_unique<Enemy>(level); }},
        {6, 1, "", "", [](int level) { return make_unique<Boss>(level); }}  // Boss level
    };

    
    for (auto& level : levels) {
        if (level.number == 6) {
            cout << "\n--- Level 6: Boss Fight ---\n";
            cout << "You've reached Murloc's lair. Prepare for the final battle!\n";
        }
        if (!level.play(player)) return 0;
    }

    if (player.isAlive()) {
        cout << "Congratulations! You have defeated the Murlocs and saved your village!\n";
    } else {
        cout << "You have been defeated by the Murloc Boss. Your village remains captive.\n";
    }

    return 0;
}
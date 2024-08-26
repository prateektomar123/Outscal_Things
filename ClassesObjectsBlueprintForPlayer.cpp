#include <iostream>
using namespace std;


void gameStory()
{
    cout<< "----A Lone Warrior----"<<endl;
    cout<< "Once upon a time there lived a warrior"<<endl;
    cout<< "He like to live alone because he thinks that living with someone will make him weak and attached to them"<<endl;
    cout<< "because he lost his both parents in a tsunami"<<endl;
    cout<< "but somehow he didn`t die that day because he wanted to eat chocolate when he grew to be a 19 years old and......"<< "\nwollah !! today is his 19th birthday  "<<endl;
    cout<< "Now he can eat chocolates and live a happy life"<<endl;
}
class Player{

    public:
    int health;
    int attack_power;

    Player(int health_value, int attackPower_value){
        health = health_value;
        attack_power = attackPower_value;

    }
};
int main(){
    gameStory();
    Player player = Player(100,20);
    cout << player.health <<endl << player.attack_power;
}
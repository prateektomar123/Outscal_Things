#include <iostream>

using namespace std;

int main() {
  int playerHealth, enemyHealth;

  cout << "Player Health: " << endl;
  cin >> playerHealth;

  cout << "Enemy Health: " << endl;
  cin >> enemyHealth;


// Checking player health and printing dialogues acc to that 
if (playerHealth == 100)
{
  cout << "Player Health is full" << endl;
}
else if (playerHealth == 50)
{
  cout << "Player Health is half" << endl;
} 
else if (playerHealth == 0) 
{
  cout << "Player Health is zero and Player Died!" << endl;
} 
    
// checking for enemy health acc to player health 

if (playerHealth >= 0)
{
  if (enemyHealth == 100)
  {
    cout << "Enemy Health is full" << endl;
  }
  else if (enemyHealth == 50)
  {
    cout << "Enemy Health is half" << endl;
  } 
  else if (enemyHealth == 0) 
  {
    cout << "Enemy Health is zero" << endl;
  }
}

if(playerHealth == 0 && enemyHealth == 0)
{
  cout << "Game Over! Its Draw" << endl;
}
else if (playerHealth == 0 || enemyHealth == 0)
{
  playerHealth > 0 ? cout << "Game Over! Player Won!" << endl : cout << "Game Over! Player Lost!" << endl;
}


    
  
  return 0;
}

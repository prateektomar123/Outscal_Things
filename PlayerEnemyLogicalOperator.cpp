#include <iostream>
using namespace std;

int main() {
    char input1, input2, input3;
    bool isPlayerInRange, isPlayerAttacking, isPlayerDefending;
    int playerHealth;

    cout << "What`s Player`s Health?" << endl;
    cin >> playerHealth;

    cout << "Is Player In Range? (Y/N): ";
    cin >> input1;
    isPlayerInRange = (input1 == 'y' || input1 == 'Y');

    cout << "Is Player Attacking? (Y/N): ";
    cin >> input2;
    isPlayerAttacking = (input2 == 'y' || input2 == 'Y');

    cout << "Is Player Defending? (Y/N): ";
    cin >> input3;
    isPlayerDefending = (input3 == 'y' || input3 == 'Y');

    // Check the conditions
    if (isPlayerInRange && !isPlayerAttacking) {
        cout << "The enemy should attack" << endl;
    } else if (isPlayerInRange && isPlayerDefending) {
        cout << "The enemy should hold" << endl;
    } else if (isPlayerInRange && playerHealth < 20 && isPlayerAttacking) {
        cout << "Player should deliver a rage attack" << endl;
    } else if (isPlayerInRange && !isPlayerDefending && (playerHealth == 100 || playerHealth < 10)) {
        cout << "Enemy should do a special ability attack." << endl;
    }

    return 0;
}

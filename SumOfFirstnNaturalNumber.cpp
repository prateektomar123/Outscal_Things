#include <iostream>
using namespace std;


int sum;
int value;
int main()
{
    cout << "Enter value n(Natural Number) for the Sum" <<endl;
    cin >> value;

    for (int i = 0; i <= value ; i++)
    {
        
        sum += i;
    }
    cout << sum;

}

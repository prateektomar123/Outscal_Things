#include <iostream>
using namespace std;

template<typename T>
T GenericScoreSum(T a,T b){
return a+b;
}

int main() {
    cout<< "Sum of two integers using generic function: "<<GenericScoreSum<int>(12,12)<<endl;
    cout<< "Sum of two float using generic function: "<<GenericScoreSum<float>(12.5,12.4)<<endl;
    
    return 0;
}
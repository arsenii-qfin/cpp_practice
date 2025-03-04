#include <iostream>
using namespace std;

int main() {
    int inIntNum;
    cout << "Enter an Integer (BIG!): " << endl;
    cin >> inIntNum;
    cout << "Your BIG integer is: " << (inIntNum / 3600) << " hours " << (inIntNum % 3600) / 60 << " minutes and " << (inIntNum % 3600) % 60 << " seconds." << endl;
    return 0;
}
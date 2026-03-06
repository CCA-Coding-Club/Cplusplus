#include <iostream>
//#include <ctime>

//for terminal commands system("etc.")
//#include <cstdlib>

//#include <iomanip>
//relevant functions: std::cin.clear(); fflush(stdin);

//template used
//Functions

//Here are some neat namespaces to consider using consistantly
using std::cout;
using std::string;
using std::cin;
using std::endl;
//etc.

int main() {

    std::cout << "\n";
    int numbers[] = {};
    for(int i = 1; i < 11; i++){
        numbers[i - 1] = i;
        cout << numbers[i - 1] << " ";
    }
    cout << endl;
    
    int size1 = sizeof(numbers)/ sizeof(numbers[0]);
    std::cout << "\n";
    return 0;
}
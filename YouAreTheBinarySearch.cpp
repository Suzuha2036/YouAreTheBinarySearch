#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

int randomNumberGenerator(){
    srand(time(NULL));
    const int randomNumber = rand() % 100;
    return randomNumber;
}

int playerInput(){
    int playerNumber;
    cout << "Pick a Number: ";
    try{
        cin >> playerNumber;
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }catch(const char* errorMessage){
        cout << errorMessage << endl;
    }
    return playerNumber;
}

bool decisionMaking(int Random, int Input){
    if (Input == Random){
        cout << "You got it!" << endl;
        return true;
    } else if (Input == 0){
        cout << "Error Input"<< endl;
    } else if (Input > Random){
        cout << "Go lower" << endl;
    } else if (Input < Random){
        cout << "Go Higher" << endl;
    }
    return false;
}

void RandomNumberGuesser(){
    const int randomNumber = randomNumberGenerator();
    while(true){
        if(decisionMaking(randomNumber, playerInput())){
            break;
        }
    }
}

int main(){
    RandomNumberGuesser();
    getch();
    return 0;
}
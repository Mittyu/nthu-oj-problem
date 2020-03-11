#include<iostream>
#include<cstdlib> // for rand and srand
#include<ctime> // for srand time seed
using namespace std;

unsigned int roolDice(){
    unsigned int num1 = 1+rand()%6, 
                 num2 = 1+rand()%6;
    cout<<"rool dice: "<<num1+num2<<endl;
    return num1+num2;
}

int main(){
    // unscoped enums
    // enum Status{CONTINUE, WON, LOST};
    // scoped enums, for avoiding the same name
    enum class Status{CONTINUE, WON, LOST};
    // assigned datatype for enum.
    // enum class Status: unsinged int{CONTINUE, WON, LOST};
    Status gameStatus = Status::CONTINUE;
    srand(static_cast<unsigned int> (time(0)));

    unsigned int point = roolDice(), myPoint;
    switch(point){
        case 2: 
        case 3: 
        case 12:
            gameStatus = Status::LOST;
            break;
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:
            myPoint = point;
            break;
    }
    while(gameStatus==Status::CONTINUE){
        point = roolDice();
        if(point == myPoint) gameStatus = Status::WON;
        else if (point == 7) gameStatus = Status::LOST;
    }
    
    if(gameStatus==Status::WON) cout<<"player: WON"<<endl;
    else cout<<"player: LOST"<<endl;

    return 0;
}

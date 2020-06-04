#include <iostream>
#include <string>
#include <stdexcept>
#include "function.h"

using namespace std;

int main(){
    List L;
    string cmd;
    int data;

    while(cin >> cmd){
        if(cmd=="IH"){ // insert an integer to the head
            cin >> data;
            L.InsertHead(data);
        } else if (cmd=="IT"){ // insert an integer to the end
            cin >> data;
            L.InsertTail( data);
        } else if (cmd=="RH"){   // print and remove a node from head
            try {
                data = L.RemoveHead();
                cout << data << endl;
            } catch (const out_of_range &e){
                cout << endl;
            }
        } else if (cmd=="RT") {// print and remove a node from tail
            try {
                data = L.RemoveTail();
                cout << data << endl;
            } catch (const out_of_range &e){
                cout << endl;
            }
        } else if (cmd=="S"){
            L.Swap();
        }
    }
}

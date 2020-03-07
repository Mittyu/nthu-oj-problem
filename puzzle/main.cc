#include<iostream>

using namespace std;

int main(){
    int puzzle[2][3];
    int puzzle_reverse[2][3];
    int i, j, k;
    string s;
    for(k=0; k<2; k++)
        for(j=0; j<3; j++)
            puzzle_reverse[k][j]=0;
    for(k=0; k<2; k++){
        for(i=0; i<3; i++){
            puzzle[k][i]=0;
            cin>>s;
            for(j=0; j<3; j++){
                if(s[j]=='*'){
                    puzzle[k][i]+=1;
                    puzzle_reverse[k][j]+=1;
                }
            }
        }
    }
    int bingo=0;
    // --------special case-----------
    // one piece puzzle
    for(i=0; i<3; i++)
        bingo+=puzzle[0][i];
    if(bingo==8 || bingo==1){
        for(i=0; i<3; i++)
            bingo+=puzzle[1][i];
    
        if(bingo==9) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    // two pieces puzzle
    bingo=0;
    for(i=0; i<3; i++){
        bingo+=puzzle[0][i];
    }
    if(bingo==7 || bingo ==2){
        for(i=0; i<3; i++)
            bingo+=puzzle[1][i];
    
        if(bingo==9){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    // ----------normal case-------------
    // shift directly
    bingo=0;
    for(i=0; i<3; i++){
        bingo++;
        if(puzzle[0][i]+puzzle[1][i]!=3) break;        
    }
    if(bingo==3){
        cout<<"YES"<<endl;
        return 0;
    }
    // 180 degreee rotate
    bingo=0;
    for(i=0; i<3; i++){
        bingo++;
        if(puzzle[0][i]+puzzle[1][2-i]!=3) break;
    }
    if(bingo==3){
        cout<<"YES"<<endl;
        return 0;
    }
    // 90 degree rotate
    bingo=0;
    for(i=0; i<3; i++){
        bingo++;
        if(puzzle_reverse[0][i]+puzzle[1][i]!=3) break;
    }
    if(bingo==3){
        cout<<"YES"<<endl;
        return 0;
    }
    // 270 degree rotate
    bingo=0;
    for(i=0; i<3; i++){
        bingo++;
        if(puzzle_reverse[0][i]+puzzle[1][2-i]!=3) break;
    }
    if(bingo==3){
        cout<<"YES"<<endl;
        return 0;
    }
    // --------for 0 x y problem---------
    // --------i.e 0 y x ----------------
    for(i=0; i<2; ++i){
        if(puzzle[i][0]==0){
            swap(puzzle[i][1], puzzle[i][2]);
        }else if(puzzle_reverse[i][0]==0){
            swap(puzzle_reverse[i][1], puzzle_reverse[i][2]);
        }else if(puzzle[i][2]==0){
            swap(puzzle[i][0], puzzle[i][1]);
        }else if(puzzle_reverse[i][2]==0){
            swap(puzzle_reverse[i][0], puzzle_reverse[i][1]);
        }
    }
    // shift directly
    bingo=0;
    for(i=0; i<3; i++){
        bingo++;
        if(puzzle[0][i]+puzzle[1][i]!=3) break;        
    }
    if(bingo==3){
        cout<<"YES"<<endl;
        return 0;
    }
    // 180 degreee rotate
    bingo=0;
    for(i=0; i<3; i++){
        bingo++;
        if(puzzle[0][i]+puzzle[1][2-i]!=3) break;
    }
    if(bingo==3){
        cout<<"YES"<<endl;
        return 0;
    }
    // 90 degree rotate
    bingo=0;
    for(i=0; i<3; i++){
        bingo++;
        if(puzzle_reverse[0][i]+puzzle[1][i]!=3) break;
    }
    if(bingo==3){
        cout<<"YES"<<endl;
        return 0;
    }
    // 270 degree rotate
    bingo=0;
    for(i=0; i<3; i++){
        bingo++;
        if(puzzle_reverse[0][i]+puzzle[1][2-i]!=3) break;
    }
    if(bingo==3){
        cout<<"YES"<<endl;
        return 0;
    }
    
    cout<<"NO"<<endl;
    return 0;
}
/*
***
.**
..*

.**
.*.
...


***
***
**.

...
..*
..*

***
*.*
***

...
..*
...

...
***
...

**.
**.
**.

...
**.
*..

***
.**
..*

***
***
***

...
...
...

*/
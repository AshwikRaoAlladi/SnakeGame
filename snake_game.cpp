#include<bits/stdc++.h>
#include <conio.h>
#include<windows.h>
using namespace std;
bool gameOver;
const int height=20;
const int width=20;

int x,y,fruitx,fruity,score;

int tailx[100],taily[100],nTail;

enum eDirection {STOP=0,UP,DOWN,LEFT,RIGHT};
eDirection dir;

void setup(){
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitx = rand()% width;
    fruity = rand()% height;
}

void Draw(){
    system("CLS");

    for(int i=0;i<width;i++){
        cout<<"# ";
    }
    cout<<endl;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0 || j==width-1){
                cout<<"# ";
            }
            else if(i==y && j==x)
                cout<<"O ";
            else if(i==fruity && j==fruitx)
                cout<<"F ";
            else{
                bool print=false;
                for(int k=0;k<nTail;k++){
                    if(i==taily[k] && j==tailx[k]){
                        cout<<"O";
                        print = true;
                    }
                }
                if(!print)
                    cout<<"  ";
            }
        }
        cout<<endl;
    }

    for(int i=0;i<width;i++){
        cout<<"# ";
    }
    cout<<endl;

    cout<<endl;

    cout<<"Score: "<<score<<endl;
}

void Input(){
    if(_kbhit()){
        switch(_getch()){
            case 'w':
                dir=UP;
                break;
            case 'a':
                dir=LEFT;
                break;
            case 's':
                dir=DOWN;
                break;
            case 'd':
                dir=RIGHT;
                break;
            default:
                break;
        }
    }
}

void Logic(){
    int prevx=tailx[0];
    int prevy=taily[0];
    tailx[0]=x;
    taily[0]=y;
    int prev2x,prev2y;

    for(int i=1;i<nTail;i++){
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    } 

    switch(dir){
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        default:
            break;
    }

    if(x<0 || x>=width || y<0 || y>=height ){
        gameOver = true;
    }

    for(int i=0;i<nTail;i++){
        if(x==tailx[i] && y==taily[i]){
            gameOver=true;
        }
    }

    if(x==fruitx && y==fruity ) {
        score+=10;
        fruitx = rand()% width;
        fruity = rand()% height;
        nTail++;
    }
}

int main(){

    setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(40);
    }
    return 0;
}

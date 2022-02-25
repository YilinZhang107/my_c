#include<bits/stdc++.h>
using namespace std;

char Graph[11][11];

void WritePixel(int x, int y){
    Graph[10-y][x] = '*';
}

int DDA(int x0, int y0, int x1, int y1){
    double x,y,dx,dy,k;
    dx = x1 - x0;
    dy = y1 - y0;
    if(dx == 0){ //竖直线
        x = x0;
        for(y = y0; y<=y1; y++){
            WritePixel(x,y);
        }
    }
    if(dy == 0){ //水平线
        y = y0;
        for(x = x0; x<=x1; x++){
            WritePixel(x,y);
        }
    }
    k = dy/dx;
    if(k<=1){
        for(x=x0; x<=x1; x++){
            WritePixel(x,y);
            y+=k;
        }
    }
    if(k>1){
        for(y=y0; y<=y1; y++){
            WritePixel(x,y);
            x+=1/k;
        }
    }
    return 0;
}



int main(){
    for(int i=0 ;i<11; i++){
        for(int j=0; j<11; j++){
            Graph[i][j]= ' ';
        }
    }
    cout<<1+0.6;
    DDA(0,0,0,10);
    
    
    for(int i=0 ;i<11; i++){
        for(int j=0; j<11; j++){
            cout<<Graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;

}
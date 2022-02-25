#include<bits/stdc++.h>
using namespace std;

char Graph[11][11];

void WriteFirstQ(int x, int y){
    Graph[10-y][x] = '*';
}

void WriteFouthQ(int x, int y){
    Graph[-1*y][x] = '*';
}

void DDA(int x0, int y0, int x1, int y1){  //数值微分分析法
    double x,y,dx,dy,k;
    x0 = x0 + 0.5;  //为了确保精度+0.5
    y0 = y0 + 0.5;
    dx = x1 - x0;
    dy = y1 - y0;
    if(dx == 0){ //竖直线
        x = x0;
        for(y = y0; y<=y1; y++){
            WriteFirstQ(x,y);
        }
    }
    if(dy == 0){ //水平线
        y = y0;
        for(x = x0; x<=x1; x++){
            WriteFirstQ(x,y);
        }
    }
    k = dy/dx;
    if(k<=1){ //斜率小于1
        for(x=x0; x<=x1; x++){
            WriteFirstQ(x,y);
            y+=k;
        }
    }
    if(k>1){ //斜率大于1
        for(y=y0; y<=y1; y++){
            WriteFirstQ(x,y);
            x+=1/k;
        }
    }
}

//-1<k<0的中点画线算法
void MidPoint(int x0, int y0, int x1, int y1){
    int x,y,a,b,d,d1,d2;
    a = y0-y1;                        //F(x,y) = ax+by+c = 0
    b = x1-x0;
    d = 2*a-b;
    d1 = 2*a;
    d2 = 2*(a-b);
    x = x0;
    y = y0;
    while(x<=x1){
        WriteFouthQ(x,y);
        if(d<=0){
            x++;
            d = d+d1;
        }
        else{
            x++;
            y--;
            d = d+d2;
        }
    }
}

//第一八分圆的扫描转换
void MidCircle(int r){
    int x,y,d,d1,d2;
    x = r;
    y = 0;
    d = 1-r;
    while(y<=x){
        WriteFirstQ(x,y);
        if(d<=0){
            d=d+2*y+3;
            y++;
        }
        else{
            d=d+2*(y-x)+5;
            y++;
            x--;
        }
    }
}

int main(){
    for(int i=0 ;i<11; i++){
        for(int j=0; j<11; j++){
            Graph[i][j]= ' ';
        }
    }
    // int x0,y0,x1,y1;
    // cout<<"(x0,y0) = ";
    // cin>>x0>>y0;
    // cout<<"(x1,y1) = ";
    // cin>>x1>>y1;
    //DDA(x0,y0,x1,y1);
    //MidPoint(x0,y0,x1,y1);
    int r;
    cout<<"r = ";
    cin>>r;
    MidCircle(r);

    for(int i=0 ;i<11; i++){
        for(int j=0; j<11; j++){
            cout<<Graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;

}
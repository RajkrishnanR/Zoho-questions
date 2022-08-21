#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int size,i,n,m;
    cin>>size;
    int stones[size];
int y=0, x=0
;



for(i=0; i<size; i++){
cin>>stones[i];

if(y<stones[i]){
x=y;
y=stones[i];
n=i;
}
else if(x<stones[i]){
x=stones[i];
m=i;
}stones[n]=0;
stones[m]=n-m;
}
cout<<"\n";
getch();
    return 0;
}
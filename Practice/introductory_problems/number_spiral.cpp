#include<iostream>
using namespace std;
#define ll long long int
int main(){
        long int t;
        cin>>t;
for(int i=0;i<t;i++){ll y,x,output;
        cin>>y>>x;
if(y>=x){
        ll ele = y*(y-1) +1;
        if(y%2!=0){
        output = ele + x-y;}
        else{
        output = ele + y-x;}
}
else{
        ll ele = x*(x-1) +1;
        if(x%2!=0){
        output = ele + x-y;}
        else{
        output = ele + y-x;}
}
cout<<output<<endl;}
}
#include<iostream>
using namespace std;
#define ull unsigned long long int
int main(){
    ull n;cin >>n;
    ull a[n],b[n];
    for(ull i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(ull i=0;i<n;i++){
        if(((2*a[i]-b[i])>=0)&&((2*b[i]-a[i])>=0)){
        if(((2*a[i]-b[i])%3==0)&&((2*b[i]-a[i])%3==0)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl; 
    }
    else cout<<"NO"<<endl;}
}
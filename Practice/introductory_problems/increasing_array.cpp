#include<iostream>
using namespace std;
#define ll long long int
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
ll moves =0;
for(int i=0;i<n-1;i++){
    if(a[i]>a[i+1]){ moves= moves+ a[i]- a[i+1];
    a[i+1]=a[i];}
}
cout<<moves;
}
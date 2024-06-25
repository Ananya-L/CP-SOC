#include<iostream>
using namespace std;
#define ll long long int
bool bin_sea(ll*a,int ind,ll n){
    for(int i=0;i<=ind;i++){
        if(a[i]==n){return 1;}
    }
    return 0;
}
int main(){
    int n,index;cin>>n;ll a[n];
    for(int i=0;i<n;i++){
        ll n;cin>>n;
        if(!bin_sea(a,i-1,n)){
            a[i]=n;index = i;
        }
    }
    cout<<index+1;

}
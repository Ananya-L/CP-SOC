#include<iostream>
#include<string>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string top,bottom;
    cin>>top>>bottom;
    for(int i = 1;i<n;i+=2){
        if((top[i]=='<'&&bottom[i-1]=='<')||(top[i]=='<'&&bottom[i+1]=='<')){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
int t;
cin>>t;
while(t--) solve();
}
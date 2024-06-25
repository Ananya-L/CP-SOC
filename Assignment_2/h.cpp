#include<iostream>
#include<string>
using namespace std;
bool check_places(string s1, string s2){
    int key = 0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            key++;
        }
    }
    if(key==0||key==1){
        return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i = 1;i<=n;i++){
            if(n%i==0){
                if(i==1){
                    string new_s = string(n,s[0]);
                    if(check_places(s, new_s)){
                        cout<<"YES"<<endl;
                    }
                    else if(check_places(s, string(n,s[1]))){
                        cout<<"NO"<<endl;
                    }
                }
                else{
                string new_s = s.substr(0,)
                }
            }
        }

    }
}
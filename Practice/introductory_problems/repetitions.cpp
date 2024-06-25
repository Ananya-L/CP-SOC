#include<iostream>
#include<string>
using namespace std;
int main(){
string s;
cin>>s;
size_t max_length =1;
size_t i =0;
while(i<s.size()-1){
     size_t curr_length =1;
for(;i<s.size()-1;i++){
    if(s[i]==s[i+1]){
        curr_length++;
        if(curr_length>=max_length){max_length = curr_length;}
    }
    else { i++;break;}
}
}
cout<<max_length<<endl;
}
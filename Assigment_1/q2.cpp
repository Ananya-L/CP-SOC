#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool is_Valid(string s){
    stack<char> stac;
    for(char&c:s){
        if(c=='{'||c=='('||c=='['){
            stac.push(c);
        }
        else{
            if(stac.empty()){
                return false;
            }
            else{
                char top = stac.top();
               if ((c == '}' && top == '{') ||
                (c == ']' && top == '[') ||
                (c == ')' && top == '(')) {
                stac.pop();
            }
            else{
                return false;
            }
        }
    }
}
return stac.empty();
}

int main(){
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        string s;
        cin>>s;
        cout<<(is_Valid(s)?"true":"false")<<endl;
    }
}
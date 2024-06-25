#include<iostream>
#include<cmath>
using namespace std;

bool check(int ai, int aj){
    if(ai==aj){
        return true;
    }
    if(ai<aj){int temp; temp = ai; ai = aj; aj = temp;}
    double epsilon = 1e-9;
    double log_ = log2(ai/aj);
    double diff = double(ai-aj);
    if(abs(log_-diff)<=1e-9){
        return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    for(int r=0;r<t;r++){
        int n,number = 0;
        cin>>n;
        int arr[n];
        for(int i = 0; i< n; i++){
            cin>>arr[i];
        }
        for(int i = 0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(check(arr[i],arr[j])){
                    number++;
                }
            }
        }
        cout<<number<<endl;
    }
}
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int current_sum = arr[0];
        int max_sum = arr[0];
        for(int i=1;i<n;i++){
            current_sum = max(arr[i], current_sum + arr[i]);
            max_sum = max(max_sum, current_sum);
        }
        cout<<max_sum<<endl;
    }
    
}
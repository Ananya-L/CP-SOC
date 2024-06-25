#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int current_sum = 0;
        int number = -1;
        int current_number = 0;
        int sum_acquired = 0;
        for(int i=0;i<n;i++){
            current_sum = max(arr[i], current_sum + arr[i]);
            if(current_sum==arr[i]){
                current_number = 1;
            }
            else{
                current_number++;
            }
            sum_acquired = max(sum_acquired, current_sum);
            if(sum_acquired>=k){
                number = current_number;
            }
            
        }
        cout<<number<<endl;
    }
    
}
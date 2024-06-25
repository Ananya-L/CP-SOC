#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


bool compareFirst(const pair<int, int>& a, const int& b) {
    return a.first < b;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> sorted_trains;
        vector<int> train(n);
        for (int i = 0; i < n; ++i) {
            cin >> train[i];
            sorted_trains.push_back({train[i],i});
        }
        sort(sorted_trains.begin(), sorted_trains.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.first < b.first;
         });
         for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;
            if(a==b){
                cout<<"YES"<<endl;
                continue;
            }
            int second_element_a, second_element_b;
            auto it = lower_bound(sorted_trains.begin(), sorted_trains.end(), a,
                          [](const pair<int, int>& a, const int& b) {
                              return a.first < b;
                          });
                      
            if (it != sorted_trains.end() && it->first == a) {
            int index_a = it - sorted_trains.begin();
            second_element_a = sorted_trains[index_a].second;
           
         }
         else{
           
            cout<<"NO"<<endl;
            continue;
         }
            auto it_2 = upper_bound(sorted_trains.begin(), sorted_trains.end(), b,
                      [](const int& b, const pair<int, int>& a) {
                          return b < a.first;
                      });

                    if (it_2 != sorted_trains.begin()) {
                             --it_2; 
                         }
          if (it_2 != sorted_trains.end() && it_2->first == b) {
            int index_b = it_2 - sorted_trains.begin();
            second_element_b = sorted_trains[index_b].second;
         }
         else{
       
            cout<<"NO"<<endl;
            continue;
         }
        
         if(second_element_b>=second_element_a){
            cout<<"YES"<<endl;
            continue;
         }
         else{
         
            cout<<"NO"<<endl;
         }
    }
}
}
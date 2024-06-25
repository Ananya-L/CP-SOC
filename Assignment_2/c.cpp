#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int mid_value = arr[mid];

        if (mid_value == target) {
            return mid;  // Target found
        } else if (mid_value < target) {
            low = mid + 1;  // Search in the right half
        } else {
            high = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Target not found
}

vector<int> remove(const vector<int> &vec){
    int n = vec.size();
    vector<int> removals(n);

    vector<pair<int, int>> sorted_pairs(n);
    for (int i = 0; i < n; i++) {
        sorted_pairs[i] = make_pair(vec[i], i);
    }
    sort(sorted_pairs.begin(), sorted_pairs.end(), comparePairs);



    for(int j=0;j<n;j++){
        if(removals[j]==0){
        int num = vec[j];
        int remove = 0;
        int no_of_times = 0;
        long long score = static_cast<long long>(num);
        int i;
        for(i=0;score>=static_cast<long long>(sorted_pairs[i].first)&&i<n;i++){
            
            score+=static_cast<long long>(sorted_pairs[i].first);  
            if(sorted_pairs[i].first==num){
                if(no_of_times%2==0){
                score-=static_cast<long long>(num);
                no_of_times++;
                remove--;
            }
        }
         if(score>=static_cast<long long>(sorted_pairs[i].first)){
                remove = n-1;
                break;
            }
        remove++;
    }


    if(remove == n-1){
        auto it = find_if(sorted_pairs.begin(),sorted_pairs.end(), [j](const std::pair<int, int>& p) {
        return p.second == j;
        });
        int index = std::distance(sorted_pairs.begin(), it);
        for(int g = index;g<sorted_pairs.size();g++){
            removals[sorted_pairs[g].second] = n-1;
        }
    }


    removals[i-1]= remove;
    }

    }
    return removals;
}

int main(){
    int t;
    cin>>t;
    for(int r =0;r<t;r++){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        vector<int> removals = remove(vec);
        for(int i=0;i<n;i++){
            cout<<removals[i]<<" ";
        }
        cout<<endl;
    }
}
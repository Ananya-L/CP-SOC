#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        bool possible = true;
        cin>>n>>k;
        ll* health = new ll[n];
        ll* distance = new ll[n];
        for(ll i =0;i<n;i++){
            cin>>health[i];
        }
        for(ll i =0;i<n;i++){
            cin>>distance[i];
        }
        vector<ll> healths_at_x(n+1,0);
        for(ll i =0;i<n;i++){
            healths_at_x[abs(distance[i])] += health[i];
        }
        ll left = 0;
        for(ll i = 1;i<=n;i++){
            ll health_ = healths_at_x[i];
            left += k - health_;
            if(left<0){
                possible = false;
                break;
            }
        }
        cout<<(possible?"YES":"NO")<<endl;
    }
}

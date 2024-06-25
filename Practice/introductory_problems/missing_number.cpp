#include <iostream>
using namespace std;
#define t unsigned long long int
int main() {
  t n;
  cin>>n;
  t a[n-1];
  t bsum = n*(n+1)/2;
  for(t i=0;i<n-1;i++){
      cin>>a[i];
      bsum -= a[i];
  }
cout<<bsum;
    return 0;
}
#include <iostream>
using namespace std;
void pt(long long int n){
    cout<<n<<" ";
    if(n==1){return;}
    if((n%10)%2==0){pt(n/2);}
    else if((n%10)%2!=0){ pt(3*n +1);}
}

int main() {
  long long int n;
  cin>>n;
  pt(n);
   

    return 0;
}
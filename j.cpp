#include<iostream>
#include<map>

using namespace std;
 
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int b;
		map<int,int> q;
		cin >> b;
		long long pairs = 0;
		for(int i = 0;i < b; i++)
		{
			int c;
			cin >> c;
			pairs += q[max(c,2)]++;
		}
		cout << pairs <<endl;
	}
}
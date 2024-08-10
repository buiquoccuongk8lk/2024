
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int max1=1e7+1;
ll calc(ll x)
{   int cnt=0;
	while(x!=0) cnt+=x%10,x/=10;
	return cnt;
}
ll k;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>k;
	cout << calc(k) ;
}
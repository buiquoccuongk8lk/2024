
#include<bits/stdc++.h>

using namespace std;

#define         TASK ""
#define         INPUT TASK".INP" 
#define         OUTPUT TASK".OUT"

#define int long long
#define Boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define fillchar(a,x) memset(a,x,sizeof(a))
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define mp make_pair

const int inf = 1e18 , MOD = 1e9+7 , N  = 1e5+5;
int add(int a,int b){
	return (a+b)%MOD;
}
int mul(int a,int b){
	return (a*b)%MOD;
}
int fact[(int)2e6+5];
void factory(){
	fact[0] = 1;
	fr(i,1,2e6) fact[i] = mul(fact[i-1],i);
}
int LT(int x,int y){
	if(y==0) return 1;
	if(y==1) return x;
	int c = LT(x,y/2);
	if(y%2==1) return mul(c,mul(c,x));
	else return mul(c,c);
}
int C(int n,int k){
	return mul( fact[n] , LT ( mul(fact[k],fact[n-k])  , MOD-2    )  );
}
void Doc() {
}
int x[55];
int y[55];
int w[55];
void Sol(){
    factory();
    int n;
    while(cin>> n){
    	if(n==0) break;
    	fr(i,1,n) cin >> x[i];
    	fr(i,1,n) cin >> y[i];
    	int W = 0;
    	fr(i,1,n){
    		w[i] = y[i] - x[i];
			W+= w[i];
		}
		int ans = 1;
		int pre = 0;
		fr(i,1,n){
			ans = mul(ans,C(W,w[i]));
			W-=w[i];
		}
		cout << ans << '\n';
	}
    
}

signed main(){
    Boost
    if(fopen(INPUT,"r")){
    	freopen(INPUT,"r",stdin) ; freopen(OUTPUT,"w",stdout);
    }
    Doc();
    Sol();
}



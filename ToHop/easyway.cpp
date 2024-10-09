
#include<bits/stdc++.h>

using namespace std;

#define 		TASK ""
#define 		INPUT TASK".INP" 
#define 		OUTPUT TASK".OUT"

#define 		int long long
#define         Boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         fr(i,a,b) for(int i=a;i<=b;i++)
#define         fd(i,a,b) for(int i=a;i>=b;i--)
#define         fi first
#define         se second
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
const int inf = 1e18 , MOD = 1e9+7 , N  = 1e5+5;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r){
	return l + rd()%(r-l+1);
}
int add(int a,int b){
    return (a+b)%MOD;
}
int mul(int a,int b){
    return (a*b)%MOD;
}
int LT(int x,int y){
    if(y==0) return 1;
    if(y==1) return x;
    int c = LT(x,y/2);
    if(y%2==1) return mul(c,mul(c,x));
    else return mul(c,c);
}
int fact[2000005];
int C(int n,int k){
    return mul( fact[n] , LT( mul(fact[k],fact[n-k])  ,  MOD-2  )      );
}
int x1,x2,y1,y2;
void Doc() {
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    fact[0] = 1;
    fr(i,1,2e6){
        fact[i]  = mul(fact[i-1],i);
    }
    
}
void Sol1(){
	int right = y2-y1;
    int down  = x2-x1;
    cout << C(right+down,right);
	
}

void Sol2(){


}
signed main(){
    Boost
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
 
    Doc();
    Sol1();
    Sol2();
}



#include<bits/stdc++.h>

using namespace std;

#define TASK ""
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#define 	int long long
#define         Boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         fr(i,a,b) for(int i=a;i<=b;i++)
#define         fd(i,a,b) for(int i=a;i>=b;i--)
#define         fi first
#define         se second
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
const int inf = 1e18 , MOD = 1e9+7 , N  = 2e6+5;
int fact[N];
int n,m;
// n dua tre
// m qua tao
void Doc() {
    cin >> n >> m;
    fact[0] = 1;
    fr(i,1,2e6){
        fact[i] = (fact[i-1]*i)%MOD;
    }
}
int LT(int x,int y){
    if(y==0) return 1;
    if(y==1) return x;
    int tmp = LT(x,y/2);
    if(y%2==1) return (((tmp*tmp)%MOD)*x)%MOD;
    else return (tmp*tmp)%MOD;
}
int C(int n,int k){
    return (fact[n]*LT( (fact[k]*fact[n-k])%MOD , MOD-2))%MOD;
}
void Sol1(){
    cout << C(m+n-1,n-1);

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


/***************************************************************
*        User :Bui Quoc Cuong aka WatborInDaHood               *
*                   Age :15 -2k8                               *
*      School : 10Ti Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*             Truoc Khi Em Ton Tai...?                         *
*   https://www.facebook.com/profile.php?id=1000...99784529    *
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define goi5gviettel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr(i,a,b) for(i=a;i<=b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define lb lower_bound
#define up upper_bound
ll m,c,n,j,k,x,y,z,t,l,r;ll maxx=-2e9;ll minn=2e9;
const ll SIZE =1e6;
//ll mi[10000000];
//ll ma[10000000];
ll ps[1000000];
ll a[SIZE];
//ll b[SIZE];
//ll dp[SIZE];
ll gcd(ll a,ll b) {ll temp;while(b!=0) {temp = a%b;a=b;b=temp;}return a;}
ll lcm(ll a,ll b) {return a/gcd(a,b) *b;}
/*ll prime[1000007];const ll N =1000007;ll cnt=1;
void Sang() {
    for(i=2;i<=N;i++) {
        prime[i] = 1;
    }
    prime[1]=prime[0] =0;
    for(i=2;i<=sqrt(N);i++) {
        if(prime[i]==1){
            for(j=i*i;j<=N;j+=i) {
                prime[j] =0;}
        }   
    }
    fr(i,1,N){
        if(prime[i]){
            b[cnt++] = i;
        }
    }
}*/
ll i;
string s;
void Doc() {
    cin >> s;
}
ll Check( string a){
    if(a.empty()) return 1;
    if( a[0]== '1' && a[1] =='4' && a[2]=='4'){
        return Check( a.substr(3, (a.size() -3) ) );
    }
    if(a[0]=='1' && a[1] == '4'){
        return Check( a.substr(2, a.size()-2 ));
    }
    if(a[0]=='1'){
        return Check( a.substr(1, a.size()-1 ));
    }
    return 0;

}
void Sol(){
    if(Check(s)) cout << "YES";
    else cout <<"NO";
}
void LamMau(){
    cerr<< endl<<  "Time:" <<" " << 0.001*clock() << "s" << endl;
    cerr<< " WatborInDaHood " << endl; 
}
int main(){
    goi5gviettel
    /*if(fopen("Watbor.inp","r")){
        freopen("Watbor.inp","r",stdin);
        freopen("Watbor.out","w",stdout);
    }*/
    Doc();
    Sol();
    LamMau();
}
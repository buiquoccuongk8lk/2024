
#include<bits/stdc++.h>
using namespace std;
#define         ll long long
#define         goi5gviettel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         fr(i,a,b) for(i=a;i<=b;i++)
#define         fd(i,b,a) for(i=b;i>=a;i--)
const ll SIZE =1e7;

ll gcd(ll a,ll b) {ll temp;while(b!=0) {temp = a%b;a=b;b=temp;}return a;}
ll lcm(ll a,ll b) {return a/gcd(a,b) *b;}
int n;
int i,j;
int c[17][17];
int m;
void Doc() {
    cin >> n;
    fr(i,1,n){
        fr(j,1,n) cin >> c[i][j];
    }
}
ll ans = 2e9;
int a[17];
void ql(int pos){
    if(pos>n){
        fr(i,1,n) cout << a[i]<< " ";
        cout << endl;
    }else{
        ll x;
        fr(x,1,n){
            fr(j,1,n){
                a[pos] = c[x][j];
                ql(pos+1);
            }
        }
    }

}
void Sol(){
    ql(1);
    
}
void LamMau(){
    cerr<< endl<<  "Time:" <<" " << 0.001*clock() << "s" << endl;
    cerr<< " WatborInDaHood " << endl; 
}
int main(){
    goi5gviettel
    
    Doc();
    Sol();
    LamMau();
}
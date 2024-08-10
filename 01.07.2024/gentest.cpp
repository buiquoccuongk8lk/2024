#include<bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define FORD(i,a,b) for(int i = a ; i <= b ; i++)
#define fi first
#define se second
#define endl '\n'

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r) {
    return l + rd()%(r-l+1);
}

const string NAME = "xayduong";
const int N = 1e5+5;
const int maxTest = 100;
int n , q ; 


void create()
{
    ofstream inp ( (NAME + ".INP") . c_str() );

    n = Rand(100,100) ; q = Rand(1000,1000) ; 
    inp << n << ' ' << q << endl ;
    FOR(i,1,q) {
        int t = Rand(1,2) ; 
        int u,v,w ; 
        if(t==1) {
            u = Rand(1,n) ; v = Rand(1,n) ; w = Rand(1,10000) ; 
            //Q[i] = { t , u , v , w} ; 
            inp << t << ' ' << u << ' ' << v << ' ' << w << endl ;
        } else {
            u = Rand(1,n) ; 
            inp << t << ' ' << u << endl ;
           // Q[i] = { t , u , v , w} ; 
        }
    }

    inp.close();
}

void check()
{
    
}

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    srand(time(NULL));	
    FOR(iTest,1,maxTest)
    {
        create();
        system( (NAME + ".exe") . c_str() );
        system( (NAME + "_trau.exe").c_str() );

        if( system ( ("fc " + NAME + ".OUT " + NAME + ".ANS").c_str())!=0 )
        {
            cout << "Wrong!!";
            return 0 ;
        }
        cout << "Correct" << endl;
    }
}

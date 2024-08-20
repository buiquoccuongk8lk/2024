#include<bits/stdc++.h>
using namespace std ; 

#define int long long
#define FOR(i,a,b) for(int i = a ; i <= (int)b ; i++)
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count()) ;
int Rand(int l,int r) {
	return l + rd()%(r-l+1) ;
}

const int TEST = 100 ;
const string NAME = "vtravel" ; 
const int MAXN = 1e5 + 5 ;

int n , m ; 

void create() {
	ofstream inp ( (NAME + ".inp"). c_str()) ; 
	n = Rand(1000,1000) ; m = Rand(1000,1000) ; 
	inp << n << ' ' << m << endl ;
	vector<int> v ; 
	FOR(i,1,n) v.push_back(i) ; 
	FOR(i,1,5) random_shuffle(v.begin(),v.end()) ; 
	FOR(i,0,v.size()-2) {
		inp << v[i] << ' ' << v[Rand(i+1,v.size()-1)] << ' ' << Rand(1000,100000000) << endl ; 
	}
	int id = Rand(1,n-1) ;
	FOR(i,1,m) {
		int w = Rand(1000,100000000) ; 
		inp << id << ' ' << w << endl ;
	}
	inp.close()  ;
}

signed main() {
	ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
	srand(time(NULL)) ;
	FOR(test,1,TEST) {
		create() ;	 
		system( (NAME + ".exe").c_str()) ; 
		system( (NAME + "_trau.exe").c_str()) ; 
		if( system ( ( "fc " + NAME + ".OUT " + NAME + ".ANS" ).c_str())   != 0 ) {
			cout << "WRONG" ;
			return 0 ;
		}
		cout << "CORRECT" << endl ; 
	}
}	
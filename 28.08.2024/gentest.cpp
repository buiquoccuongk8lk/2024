#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define FORD(i,a,b) for(int i = a ; i >= b ; i--)

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count()) ;
int Rand(int l,int r) {
	return l + rd()%(r-l+1) ; 
}
const string NAME = "delquery" ; 
const int N = 1e5 + 5 ; 
const int TEST = 100 ; 

int n , m , q ;

void create() {
	ofstream inp ( (NAME + ".inp") .c_str()) ; 
	n = Rand(20,20) , m = Rand(500,500) ;
	inp << n << ' ' << m << endl ;
	FOR(i,1,m) {
		inp << Rand(1,n) << ' ' << Rand(1,n) << endl ;
	}
	q = Rand(400,400) ;
	inp << q << endl ;
	FOR(i,1,q) {
		inp << Rand(1,2) << ' ' << Rand(1,n) << endl ;
	}
	inp.close() ; 
}

signed main() {	
	srand(time(NULL)) ; 
	FOR(test,1,TEST) {
		create() ; 
		system( (NAME + ".exe").c_str() ) ; 
		system( (NAME + "_trau.exe").c_str() ) ; 
		if(system ( ("fc " + NAME + ".out " + NAME + ".ans").c_str() ) != 0) {
			cout << "WRONG : " ; 
			return 0 ; 
		}
	}
	return 0 ; 
}
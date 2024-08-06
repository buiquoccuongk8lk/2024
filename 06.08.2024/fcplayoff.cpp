#include <iostream>

using namespace std;

long k, q;
string s;

long segT[1000000];

void build(long id, long l, long r)
{
	if(r - l == 1) 
	{
		segT[id] = 1;
		if(s[s.size() - id] == '?') segT[id] += 1;
		return;
	}

	long mid = (l + r) / 2;

	build(id * 2 + 1, l, mid);
	build(id * 2, mid + 1, r);

	if(s[s.size() - id] == '?') segT[id] = segT[id * 2] + segT[id * 2 + 1];
	else if(s[s.size() - id] == '0') segT[id] = segT[id * 2 + 1];
	else segT[id] = segT[id * 2];

}

void doIt(long id)
{
	if((s.size() + 1) / 2 <= id && id <= s.size()) 
	{
		segT[id] = 1;
		if(s[s.size() - id] == '?') segT[id] += 1;
		id /= 2;
	}
	while(id >= 1)
	{
		if(s[s.size() - id] == '?') segT[id] = segT[id * 2] + segT[id * 2 + 1];
		else if(s[s.size() - id] == '0') segT[id] = segT[id * 2 + 1];
		else segT[id] = segT[id * 2];

		id /= 2;
	}
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> k;
	cin >> s;
	cin >> q;
	build(1, 1, s.size() + 1);

	while(q--)
	{
		long x;
		char c;
		cin >> x >> c;
		s[x - 1] = c;
		doIt(s.size() - x + 1);

		//for(long i = 1; i <= s.size(); i++) cout << segT[i] <<' ';
		cout << segT[1] << endl;
	}
	return 0;
}

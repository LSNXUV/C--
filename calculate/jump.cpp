#include <iostream>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (a == 0 && b == 0) return -1;
	if (b == 0) { x = 1; y = 0; return a; }
	ll d = exgcd(b, a%b, y, x);
	y -= a / b * x;
	return d;
}



int main()
{
	ll x, y, m, n, L;
	while (cin >> x >> y >> m >> n >> L)
	{
		ll a = m - n;
		ll b = L;
		ll c = y - x;
		ll xx, yy;
		if (a < 0)
		{
			a = -a;
			c = -c;
		}
		ll gcd = exgcd(a, b, xx, yy);

		if (c%gcd) cout << "Impossible" << endl;
		else
		{
			xx *= c / gcd;
			b /= gcd;
			xx = (xx%b + b) % b;
			cout << xx << endl;
		}
		
	}
	return 0;
}
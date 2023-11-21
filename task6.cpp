#include<iostream>
#include<vector>
#include "functions.h"

using namespace std;

// converts n to base b as a list of integers between 0 and b - 1
vector<int> convertToBase(int n, int b)
{
	vector <int> res;
	if (n < 2) { res.push_back(n); return res; }
	int temp = n;
	while (temp != 0)
	{
		res.push_back(temp % b);
		temp /= b;
	}
}

pair<long long, long long> cipollaMult(pair<long long, long long> a, pair<long long, long long> b, long long w, long long p)
{
	return make_pair((a.first * b.first + a.second * b.second * w) % p, (a.first * b.second + a.second * b.first) % p);
}


// returns both square roots of n modulo p as a pair(a, b)
// returns pair(-1, -1) if no root
pair<long long, long long> cipolla(long long int n, long long int p)
{
	n %= p;
	if (n == 0 or n == 1) return make_pair(n, -n % p + p*(n % p > 0));
	
	long long int phi = p - 1;
	if (mod_pow(n, phi / 2, p) != 1) return make_pair(-1, -1);

	if (p % 4 == 3)
	{
		long long int res = mod_pow(n, (p + 1) / 4, p);
		if (res < 0) res += p - 1;
		return make_pair(res, -res % p + p*(res % p > 0));
	}

	int aa = 0;
	for (long long int i = 1; i < p; i++)
	{
		long long int temp = mod_pow((i * i - n) % p, phi / 2, p);
		if (temp == phi) aa = i;
		break;
	}

	vector <int> exponent = convertToBase((p + 1) / 2, 2);
	pair<long long, long long> x1 = make_pair(aa, 1);
	pair<long long, long long> x2 = cipollaMult(x1, x1, aa * aa - n, p);

	for (int i = 1; i < exponent.size(); i++)
	{
		if (exponent[i] == 0)
		{
			x2 = cipollaMult(x2, x1, aa * aa - n, p);
			x1 = cipollaMult(x1, x1, aa * aa - n, p);
		}
		else
		{
			x1 = cipollaMult(x1, x2, aa * aa - n, p);
			x2 = cipollaMult(x2, x2, aa * aa - n, p);
			if (x1.first < 0) x1.first += p-1;
			return make_pair(x1.first, -x1.first % p + p * (x1.first % p > 0));
		}
	}

}


void process_task6()
{
	long long int n, p;
	
	cout << "\nThis program wil find x based on given values n, p that satisfies the expression x^2 = n (mod p)\n";
	cout << "Enter n: "; cin >> n;
	cout << "Enter p: "; cin >> p;
	
	pair<long long, long long> res = cipolla(n, p);
	if (res.first < 0) cout << "There is no roots for given values\n\n";
	else cout << "Roots of x^2 = " << n << " (mod " << p << ") : x = " << res.first << ", x = " << res.second << "\n\n";
}

#include<iostream>
#include<unordered_map>

using namespace std;

// baby-step giant-step algorithm
int discreteLogarithm(int a, int b, int m)
{
	int n = (int)sqrt(m) + 1;

	// Calculate a ^ n 
	int an = 1;
	for (int i = 0; i < n; i++)
		an = (an * a) % m;

	unordered_map<int, int> value;

	// Store all values of a^(n*i) of LHS
	for (int i = 1, cur = an; i <= n; i++)
	{
		if (!value[cur]) value[cur] = i;
		cur = (cur * an) % m;
	}

	for (int i = 0, cur = b; i <= n; i++)
	{
		// Calculate (a ^ j) * b and check for collision
		if (value[cur])
		{
			int res = value[cur] * n - i;
			if (res < m) return res;
		}
		cur = (cur * a) % m;
	}
	
	return -1;
}


void process_task5()
{
	int a, b, m;

	cout << "\nThis program will k for given a, b and m to satisfy the expression a^k = b (mod m)\n";
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;
	cout << "Enter m: "; cin >> m;
	
	int k = discreteLogarithm(a, b, m);
	if (k == -1) cout << "\nNo k value satisfies given expression\n\n";
	else cout << "\nk = " << k << "\nSo you have " << a << "^" << k << " = " << b << " (mod " << m << ")\n\n";
}


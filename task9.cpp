#include<iostream>
#include<math.h>
#include<cstdlib>
#include<vector>

using namespace std;

// generate base points
pair<vector<int>, vector<int>> gen_points(int p, int a, int b)
{
	vector<vector<int>> LHS(2, vector<int>(p)), RHS(2, vector<int>(p));
	vector <int> arr_x;
	vector <int> arr_y;

	// equating LHS and RHS as per arbitrary index to generate range of values
	for (int i = 0; i < p; i++)
	{
		LHS[0][i] = i;
		RHS[0][i] = i;
		LHS[1][i] = ((i * i * i) + a * i + b) % p;
		RHS[1][i] = (i * i) % p;
	}

	// generating Base Points
	for (int i = 0; i < p; i++)
		for (int j = 0; j < p; j++)
			if (LHS[1][i] == RHS[1][j])
			{
				arr_x.push_back(LHS[0][i]);
				arr_y.push_back(RHS[0][j]);
			}

	return make_pair(arr_x, arr_y);
}


// encryption
vector<int> encrypt(int k, int d, int m, vector<int>& arr_x, vector<int>& arr_y)
{
	// Q is the public key of sender
	int Qx = d * arr_x[0];
	int Qy = d * arr_y[0];
	
	int c1x = k * arr_x[0];
	int c1y = k * arr_y[0];

	int c2x = k * Qx + m;
	int c2y = k * Qy + m;

	vector<int> res(4);
	res[0] = c1x; res[1] = c1y;
	res[2] = c2x; res[3] = c2y;

	return res;
}


void process_task9()
{
	int p;
	cout << "\nElliptic Curve General Form: y^2 mod p = (x^3 + A*x + B) mod p\n";
	cout << "Enter the value of P: "; cin >> p;
	
	int a, b;
	cout << "Enter the value of a: "; cin >> a;
	cout << "Enter the value of b: "; cin >> b;
	cout << "\nCurrent elliptic curve: y^2 mod " << p << " = (x^3 + " << a << "*x + " << b << ") mod p\n\n";
	cout << "Generated points:" << endl;

	// generate base points
	vector <int> arr_x = gen_points(p, a, b).first;
	vector <int> arr_y = gen_points(p, a, b).second;

	for (int i = 0; i < arr_x.size(); i++)
		cout << i + 1 << "\t(" << arr_x[i] << ", " << arr_y[i] << ")" << endl;
	
	cout << "\nBase point: (" << arr_x[0] << ", " << arr_y[0] << ")" << "\n\n";
	
	int k, d, M;
	cout << "Enter the random number 'd' (d < p): "; cin >> d;  //private key of sender
	cout << "Enter the random number 'k' (k < p): "; cin >> k;
	cout << "Enter the message to send: "; cin >> M;

	// encryption
	vector <int> encryption = encrypt(k, d, M, arr_x, arr_y);
	int c1x = encryption[0], c1y = encryption[1];
	int c2x = encryption[2], c2y = encryption[3];

	cout << "\nValue of C1: (" << c1x << ", " << c1y << ")" << "\n";
	cout << "Value of C2: (" << c2x << ", " << c2y << ")" << "\n";

	// decryption
	cout << "\nThe message received is:\n";
	int Mx = c2x - d * c1x;
	int My = c2y - d * c1y;
	cout << Mx << "\n\n";
}

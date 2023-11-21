#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstring>
#include <string>
#include "functions.h"

using namespace std;

// computes a mod b
long long int modulo(long long int a, long long int b)
{
    return a >= 0 ? a % b : (b - abs(a % b)) % b;
}

// encryption (m^2 mod n)
int encrypt(long long int m, long long int n)
{
    return (m * m) % n;
}

// euclidean algorithm
pair<int, int> eea(int a, int b)
{
    if (b > a) swap(a, b);
    int x = 0, y = 1;
    int lastx = 1, lasty = 0;

    while (b != 0)
    {
        int q = a / b;
        int temp1 = a % b;
        a = b;
        b = temp1;
        int temp2 = x;
        x = lastx - q * x;
        lastx = temp2;
        int temp3 = y;
        y = lasty - q * y;
        lasty = temp3;
    }

    return make_pair(lastx, lasty);
}

// decryption
vector<long long int> decrypt(long long int c, long long int p, long long int q)
{
    int n = p * q;
    long long int mp = mod_pow(c, (p + 1) / 4, p);
    long long int mq = mod_pow(c, (q + 1) / 4, q);
    
    pair<int, int> arr = eea(p, q);
    int pp = arr.first * p * mq;
    int qq = arr.second * q * mp;
    
    long long int r = modulo((pp + qq), n);
    long long int s = modulo((pp - qq), n);

    vector <long long int> res(4);
    res[0] = r;
    res[1] = n - r;
    res[2] = s;
    res[3] = n - s;

    return res;
}


void process_task8()
{
    //int p = 167, q = 151;
    long long int p = 263, q = 211;
    long long int n = p * q;

    string test;
    cout << "\nEnter the message to encrypt:\n";
    getline(cin, test);

    cout << "\nMessage: " << test << endl;
    vector<int>l;
    for (int i = 0; i <= test.size(); i++)
        l.push_back(encrypt(test[i], n));

    cout << "Encryption: ";
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, ""));

    vector<vector<int>> d(4);
    for (int i = 0; i < test.size(); i++)
        for (int k = 0; k < 4; k++)
            d[k].push_back(decrypt(l[i], p, q)[k]);

    vector <char> correct_message(d[0].size());
    cout << "\nAll decoded messages:\n";
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < d[0].size(); i++)
        {
            cout << char(d[k][i]) << " ";
            if (d[k][i] <= 111) correct_message[i] = char(d[k][i]);
        }
        cout << endl;
    }
    
    cout << "\nCorrect message:\n";
    for (char c : correct_message) cout << c;

    cout << "\n\n";
    
}
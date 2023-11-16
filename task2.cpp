#include <vector>
#include <iostream>
#include "functions.h"


// check if it has a solution
int check(std::vector <int>& b, int n)
{
    for (int x = 0; x < n; x++)
        for (int y = x + 1; y < n; y++)
            if (gcd(b[x], b[y]) != 1)
                return 1;

    return 0;
}


// Chinese theorem
int evaluate(std::vector <int>& a, std::vector <int>& b, int n)
{
    std::vector <int> Minv(n);
    int q, r, r1, r2, t, t1, t2;

    int total = 1;
    for (int k = 0; k < n; k++)
        total *= b[k];

    for (int k = 0; k < n; k++)
    {
        r1 = b[k];
        r2 = total / b[k];
        t1 = 0;
        t2 = 1;

        while (r2 > 0)
        {
            q = r1 / r2;
            r = r1 - q * r2;
            r1 = r2;
            r2 = r;

            t = t1 - q * t2;
            t1 = t2;
            t2 = t;
        }

        if (r1 == 1) Minv[k] = t1;

        if (Minv[k] < 0) Minv[k] = Minv[k] + b[k];
    }

    int x = 0;
    for (int k = 0; k < n; k++)
        x += (a[k] * total * Minv[k]) / b[k];

    return x;
}


void process_task2()
{
    int n;
    std::cout << "Enter the number of equations:\n"; std::cin >> n;
    std::vector <int> a(n), b(n);

    std::cout << "Enter n pairs of numbers x and mod:\n";
    for (int i = 0; i < n; i++) std::cin >> a[i] >> b[i];

    if (!check(b, n)) std::cout << "x = " << evaluate(a, b, n) << std::endl;
    else std::cout << "The given equations has no solutions.\n\n";
}
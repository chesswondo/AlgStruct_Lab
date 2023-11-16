#include <vector>
#include <iostream>

std::vector <int> prime_factors(long long int a)
{
    std::vector <int> res;
    for (int i = 2; i * i <= a; i++)
        while (a % i == 0)
        {
            res.push_back(i);
            a /= i;
        }

    if (a > 1) res.push_back(a);
    return res;
}


// Lezhandro symbol
int Lezhandro(long long int a, long long int p)
{
    if (a % p == 0) return 0;
    int v = 0;
    for (int i = 1; i <= (p - 1) / 2; i++)
        if ((i * a) % p > p / 2) v++;

    return 1 - 2 * (v % 2 == 1);
}


// Jacobi symbol
int Jacobi(long long int a, long long int P)
{
    int res = 1;
    for (auto e : prime_factors(P))
        res *= Lezhandro(a, e);

    return res;
}


void process_task3()
{
    long long int a, p;
    std::cout << "Enter number a and P to calculate Lezhandro symbol:\n";
    std::cin >> a >> p;
    std::cout << "Lezhandro(" << a << ", " << p << ") = " << Lezhandro(a, p);

    std::cout << "\n\nEnter number a and P to calculate Jacobi symbol:\n";
    std::cin >> a >> p;
    std::cout << "Jacobi(" << a << ", " << p << ") = " << Jacobi(a, p) << "\n\n";
}
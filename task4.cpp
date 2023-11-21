#include <iostream>
#include "functions.h"


// calculate (n^exp) % mod
long long int mod_pow(long long int n, long long int exp, long long int mod)
{
    long long int res = 1;
    while (exp > 0)
    {
        if (exp % 2) res = (res * n) % mod;
        exp /= 2;
        n = (n * n) % mod;
    }
    return res;
}

// return a single divisor for n
long long int PollardRho(long long int n)
{
    if (n == 1) return n;
    if (n % 2 == 0) return 2;

    long long int x = (rand() % (n - 2))+2;
    long long y = 1, i = 0, stage = 2;
    while (gcd(n, abs(x - y)) == 1)
    {
        if (i == stage)
        {
            y = x;
            stage *= 2;
        }

        x = modulo((mod_pow(x, 2, n) + 1), n);
        i++;
    }

    return gcd(n, abs(x - y));
}


void process_task4()
{    
    long long int n;
    std::cout << "Enter the number to factorize:\n";
    std::cin >> n;
    std::cout << "\nDivisors for the number " << n << ":\n";

    while (n > 1)
    {
        int div = PollardRho(n);
        std::cout << div << " ";
        n /= div;
    }

    std::cout << "\n\n";
}
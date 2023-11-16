#include <cstdlib>
#include <iostream>
#include <time.h>
#include "functions.h"

// This function is called for all k trials. It returns
// false if n is composite and returns true if n is
// probably prime.
// d is an odd number such that  d*2 = n-1
// for some r >= 1
bool miillerTest(long long int d, long long int n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    long long int a = 2 + std::rand() % (n - 4);

    // Compute a^d % n
    long long int x = modular_pow(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    // Keep squaring x while one of the following doesn't happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n - 1)    return true;
    }

    // Return composite
    return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(long long int n, long long int k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    long long int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Iterate given number of 'k' times
    for (long long int i = 0; i < k; i++)
        if (!miillerTest(d, n))
            return false;

    return true;
}



void process_task7()
{
    srand(time(NULL));

    int k, total = 0;
    std::cout << "Enter k (the number of iterates):\n";
    std::cin >> k;
    std::cout << "\n\nAll prime numbers program found with k = " << k << " from 1 to 10000:\n";

    for (int i = 0; i < 10000; i++)
        if (isPrime(i, k))
        {
            std::cout << i << " ";
            total++;
        }

    std::cout << "\nTotal: " << total << std::endl;
}
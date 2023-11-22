#include<iostream>
#include<vector>

// Euler function
long long int euler(long long int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0) n /= i;
            res -= res / i;
        }

    if (n > 1) res -= res / n;

    return res;
}


// Mobius function
int mobius(long long int n)
{
    int p = 0;

    // Case 2
    if (n % 2 == 0)
    {
        if (n % 4 == 0) return 0;
        n /= 2;
        p++;
    }

    for (int i = 3; i <= n; i += 2)
    {
        if (n % i == 0)
        {
            n /= i;
            p++;

            if (n % i == 0) return 0;
        }
    }

    if (p % 2 == 0) return 1;
    else return -1;
}


// gcd of two numbers
long long int gcd(long long int a, long long int b)
{
    while (a && b)
        if (a < b) b %= a;
        else a %= b;

    return a + b;
}


// lcm for two numbers
long long int lcm(long long int a, long long int b)
{
    return a / gcd(a, b) * b;
}


// lcm for a set of numbers
long long int lcm_set(std::vector <long long int>& n)
{
    if (n.size() == 1) return n[0];
    
    long long int res = lcm(n[0], n[1]);
    if (n.size() == 2) return res;

    for (int i = 2; i < n.size(); i++)
        res = lcm(res, n[i]);

    return res;
}


void process_task1()
{
    long long int num;

    //1
    std::cout << "\nEnter the number to calculate Euler function:\n";
    std::cin >> num;
    std::cout << "Euler(" << num << ") = " << euler(num) << std::endl;

    //2
    std::cout << "\nEnter the number to calculate Mobius function:\n";
    std::cin >> num;
    std::cout << "Mobius(" << num << ") = " << mobius(num) << std::endl;

    //3
    std::cout << "\nEnter the size of the set of numbers of which you want to find lcm:\n"; std::cin >> num;
    std::cout << "And now enter these numbers:\n";
    std::vector <long long int> numbers;
    for (int i = 0; i < num; i++)
    {
        int a; std::cin >> a;
        numbers.push_back(a);
    }

    std::cout << "Lcm of the set = " << lcm_set(numbers) << "\n\n";
}
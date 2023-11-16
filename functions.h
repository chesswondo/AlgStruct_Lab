#pragma once
#include<vector>

int euler(int);
int mobius(int);
int gcd(int, int);
int lcm(int, int);
int lcm_set(std::vector<int>&);
int check(std::vector<int>&);
int evaluate(std::vector <int>& a, std::vector <int>& b, int n);
std::vector <int> prime_factors(long long int a);
int Lezhandro(long long int a, long long int p);
int Jacobi(long long int a, long long int P);
bool miillerTest(long long int d, long long int n);
bool isPrime(long long int n, long long int k);
long long int modular_pow(long long int base, int exponent, long long int modulus);
long long int PollardRho(long long int n);



void process_task1();
void process_task2();
void process_task3();
void process_task4();


void process_task7();
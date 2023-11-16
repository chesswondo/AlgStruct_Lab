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
int power(int x, unsigned int y, int p);
bool miillerTest(int d, int n);
bool isPrime(int n, int k);

void process_task1();
void process_task2();
void process_task3();
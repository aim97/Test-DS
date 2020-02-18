#include <bits/stdc++.h>
using namespace std;

int pow(int a, int b) {
    if(b == 1) return a;
    if(b % 2 == 0) return pow(a * a, b / 2);
    else return a * pow(a, b - 1);
}


int fib(int n) {
    if(n <= 1) return 1;
    else return fib(n - 1) + fib(n - 2);
}

int fact(int n) {
    if(n == 0) return 1;
    else return n * fact(n - 1);
}

int sum(int n) {
    if(n == 0) return 1;
    else return n + fact(n - 1);
}

int main() {
    
    return 0;
}

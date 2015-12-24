#include <iostream>
#include <cstdio>
using namespace std;
bool isprime(long long n) {
    long long i;
    for(i=2;i*i <= n; ++ i) {
        if(n%i==0)
            return false;
    }
    return true;
}
int main() {
    long long n,x;
    cin >> n;
    if(n) {
        cin >> x;
    }
    else {
        x = 0;
    }
    for(int i=0;i < 12-n; ++ i) {
        x *= 10;
    }
    long long tmp =1;
    x = max(x,tmp);
    while(!isprime(x)) {
        x++;
    }
    printf("%012I64d\n",x);
    return 0;
}

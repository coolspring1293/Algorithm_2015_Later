//
//  main.cpp
//  穷举
//
//  Created by Kieran Will on 12/24/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int const MSIZE = 1000000;
int flg[MSIZE], m[MSIZE];

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
bool isRev(int n) {
    int tmp = 0, m = n;
    while (m) {
        tmp *= 10;
        tmp += (m % 10);
        m   /= 10;
    }
    return tmp == n;
}

int a, b;
int main_t(int argc, const char * argv[]) {
    
    while (cin >> a >> b and a != 0 and b != 0) {
        for(int i = 2; i < b ; ++ i) {
            if (!flg[i]) {
                for(int j = i * 2 ; j < b ; j += i) { flg[j] = 1; }
            }
        }
        
        for (int i = a; i <= b; ++ i) {
            if (isRev(i) and flg[i] == 0 ) {
                cout << i << "\n";
            }
        }
    }
    return 0;
}

int num[20];
int  e;
bool isprime(int x){
    if(x % 2 == 0) return 0;
    for (int i = 3;i * i <= x;i += 2) if(x % i == 0) return 0;
    return 1;
}
int Modify(int x){
    int t=x;x/=10;
    while (x>0){
        t=t*10+x%10;
        x/=10;
    }
    return t;
}
int main(){
    int i,j,k;
    cin >> b >> e;
    if(b <=5 && 5 <= e)  printf("5\n");
    if(b <=7 && 7 <= e ) printf("7\n");
    if(b <=11 && 11<= e) printf("11\n");
    i=10;
    while (Modify(i) < b) i++;
    while (Modify(i) <= e){
        k=i;j=1;
        while (k>9) {k/=10;j*=10;}
        if(k%2==0) { i+= j; continue;}
        j = Modify(i);
        if(isprime(j)) printf("%d\n",j);
        i ++;
    }
    return 0;
}

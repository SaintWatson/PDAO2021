#include<stdio.h>
#include<iostream>
using namespace std;
#define MOD 1000000007

int AS(int n){
    int a[32];
    int len = 0;
    int N = n;

    // 2^(n-1)
    n -= 1;
    while(n != 0){
        a[len] = n % 2;
        len++;
        n >>= 1;
    }
    len -= 1;

    long answer = 1;
    while(len >= 0){

        if(a[len] != 0)
            answer *= 2;
        len -= 1;
        if(len != -1)
            answer *= answer;
          
        answer %= MOD;
    }

    // n * 2^(n-1)
    answer *= N;
    answer %= MOD;
    return (int)answer;
}
int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        cout << AS(n) << endl;
    }

}
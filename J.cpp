#include<iostream>
using namespace std;
#define LEN_MAX 100000
#define INCR 0
#define DECR 1
#define EQUAL 2

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int seq[LEN_MAX];
    int change[LEN_MAX];
    cin >> N;
     
    for(int i = 0; i < N; i++)
        cin >> seq[i];
    
    if(N == 1)
        cout << 1;

    else if(N == 2){
        if(seq[0] != seq[1])
            cout << 2;
        else
            cout << 1;
    }

    else{
        for(int i = 0; i < N - 1; i++){
            if(seq[i] < seq[i+1])
                change[i] = DECR;
            else if(seq[i] > seq[i + 1])
                change[i] = INCR;
            else
                change[i] = EQUAL;
        }

        bool equal = false;
        if (change[0] == EQUAL){
            equal = true;
            for(int i = 1; i < N - 1; i++){
                if(change[i] != change[0]){
                    equal = true;
                    break;
                }
            }
        }

        if(equal)
            cout << 1;

        else{
            int last;
            int longest = 0;
            for(int i = 0; i < N - 1; i++){
                if(i == 0){
                    longest = 2;
                    last = change[i];
                }
                else if(change[i] == DECR){

                    if(last == 0){
                        longest++;
                        last = 1;
                    }
                    else if(last == 2)
                        last = 1;
                    
                }
                else if(change[i] == INCR){
                    if(last == 1){
                        longest++;
                        last = 0;
                    }
                    else if(last == EQUAL)
                        last = 0;
                }
            }
            cout << longest;
        }
    }
}
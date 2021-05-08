#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef unsigned long long LL;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    for(int round=0;round<N;round++){
        LL m, M, r;
        LL m_ = 0, M_ = 0;
        LL threshold = 1000;

        cin >> m >> M >> r;

        if(m>threshold){
            m_ = m;
        }
        else{
            for(LL x=m; x<=M; x++){

                LL lower = x*r;
                if(lower % 100 != 0)
                    lower = lower / 100 + 1; 
                else
                    lower = lower / 100;

                LL upper = x*(r+1) / 100;


                bool findmybro = false;
                if(lower<=upper){
                    for(LL i=upper ; i>=lower ;i--){
                        LL brother = i * 100/ x;
                        if(brother == r){
                            m_ = x;
                            findmybro = true;
                            break;
                        }
                    }
                }
                if(findmybro)
                    break;
            }
        }

        if(M > threshold){
            M_ = M;
        }
        else{
                for(LL x=M; x>=m; x--){

                    LL lower = x*r;
                    if(lower % 100 != 0)
                        lower = lower / 100 + 1; 
                    else
                        lower = lower / 100;

                    LL upper = x*(r+1) / 100;

                    bool findmybro = false;

                    if(lower<=upper){
                        for(LL i=lower ; i<=upper ;i++){
                            if(i*100/x == r){
                                M_ = x;
                                findmybro = true;
                                break;
                            }
                        }
                    }
                    if(findmybro)
                        break;
                
            }
        }
        if(m_ !=0 && M_!=0)
            cout << m_ << " " << M_ << endl;
        else
            cout<< "-1 -1" << endl;
    }
    return 0;
}
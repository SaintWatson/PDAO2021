#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
double scoreToGPA(double score){
    if(score >= 90)
    return 4.3;
    if(score >= 85)
    return 4;
    if(score >= 80)
    return 3.7;
    if(score >= 77)
    return 3.3;
    if(score >= 73)
    return 3;
    if(score >= 70)
    return 2.7;
    if(score >= 67)
    return 2.3;
    if(score >= 63)
    return 2;
    if(score >= 60)
    return 1.7;
    else
    return 0;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int *score = new int[N];
    for(int i=0;i<N;i++){
        cin >> score[i];
    }

    int *credit = new int[N];
    for(int i=0;i<N;i++){
        cin >> score[i];
    }

    int K;
    cin >> K;


    int start = 0;
    int end = 0;
    int score_sum = 0;
    int credit_sum = 0;
    double best = -1;

    while(start != N){
        score_sum += score[end] * credit[end];
        credit_sum += credit[end];
    }


}
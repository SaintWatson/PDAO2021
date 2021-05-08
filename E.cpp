#include<stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        int Eason, Emil, whofirst;
        scanf("%d %d %d", &Eason, &Emil, &whofirst);

        if(Eason > Emil)
            printf("Eason\n");
        
        else if (Emil > Eason)
            printf("Emil\n");
        
        else{
            if(whofirst==0)
                printf("Emil\n");
            else
                printf("Eason\n");
        }
    }
}
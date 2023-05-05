#include <stdio.h>
#include <stdbool.h>


int countBits(bool rec, unsigned int num){
    int count = 0;
    for(int i = 31; i >= 0; i--){
        if (((num&(1<<i)) != 0) && rec) {
            count++;
        } else if (((num&(1<<i)) == 0) && !rec) {
            count++;
        }
    }

    return count;
}

int main(void){
    unsigned int num;
    int aux;
    bool rec;
    scanf("%d%d",&aux,&num); 

    if(aux != 1)
        rec = false;
    else    
        rec = true;

    printf("%d",countBits(rec,num));
}
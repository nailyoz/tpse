#include <stdio.h>
#include <stdbool.h>


int setBits(bool rec, unsigned int i, unsigned int j,unsigned int num){

    // se os limites 'i' e 'j' estiverem incorretos seta ambos os limites em zero
    if((i > j) | (i < 0 || i > 31) || (j < 0 || j > 31)){
        i == 0;
        j == 0;
    }

    for(int a = i; a <= j; a++){

        if(rec){//setar bit == setar 1
            num = (num | (1 << a));
        }else{//limpar bit == setar 0
            num = (num & ~(1 << a));
        }
    }

    return num;
}

int main(void){
    unsigned int i,j,num;
    int aux;
    bool rec;
    scanf("%d%d%d%d",&aux,&i,&j,&num); 

    if(aux != 1)
        rec = false;
    else    
        rec = true;

    printf("%d",setBits(rec,i,j,num));
}
#include <stdio.h>

//exemplo para 8 bits
void shift_number_ex1(unsigned int num){
	unsigned int mask = 0xffffffff; //mascara para futuro shift
	int count = 0; //contador
	
    //conta a quantidade de '1' presente em num
	for(int i = 7; i >= 0; i--)
		if((num&(1<<i))) count++;

    //shifta mask jogando os bits '1' iniciais para a esquerta "<<" 
	if(count != 8)
        mask = mask << (8 - count);

    //imprime os 8 bits iniciais da mascara
	for(int i = 7; i >= 0 ;i--){
		if((mask&(1<<i))) 
			printf("1");
		else
			printf("0");
	}
}

void shift_number_ex2(unsigned int num){
    unsigned int mask = 0x0; // inicia uma mascara com todos os bits zerados
    int indice = 7;

    //seta os bits na mask em '1' de acordo com cada bit '1' de num 
	for(int i = 7; i >= 0 ;i--){
		if((num&(1<<i))){
            mask = mask | (1<<indice);
            indice --;
        }
    }

    //imprime os 8 bits iniciais da mascara
	for(int i = 7; i >= 0 ;i--){
		if((mask&(1<<i))) 
			printf("1");
		else
			printf("0");
	}
}

void shift_number_ex3(unsigned int num){
    unsigned int mask = 0x0; // inicia uma mascara com todos os bits zerados
	//para 8 bits
    int indice = 8;

    /*sempre que encontar '1' em 'num' shifta
	uma vez pra esquerda: '<< 1' e seta o primeiro bit da mascara*/
	for(int i = 7; i >= 0 ;i--){
		if((num&(1<<i))){
            indice--;
			mask = (mask << 1) | 1;
        }
    }

	//faz a extenção pra 8 bits
		mask = mask << indice;

    //imprime os 8 bits iniciais da mascara
	for(int i = 7; i >= 0 ;i--){
		if((mask&(1<<i))) 
			printf("1");
		else
			printf("0");
	}
}
int main(void){
	unsigned int inum;
	scanf("%d",&inum);
	
	shift_number_ex1(inum);
    printf("\n");
    shift_number_ex2(inum);
    printf("\n");
	shift_number_ex3(inum);
    printf("\n");
}

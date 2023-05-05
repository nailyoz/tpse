#include <stdio.h>
#include <math.h>

#define FIRST_PART 7
#define LAST_PART 5
#define ALL_PARTS FIRST_PART + LAST_PART
//all parts igual a string "7 + 5", 
int main() {
    printf(ALL_PARTS * ALL_PARTS);
    printf("First é %d \n", FIRST_PART);
    printf("Last é %d \n", LAST_PART);
    printf("All parts é %d \n", ALL_PARTS);
    //FIRST_PART + LAST_PART * FIRST_PART + LAST_PART = 7 + 5 * 7 + 5
    printf("The square of all the parts is %d \n", ALL_PARTS * ALL_PARTS);
    //resolução = definir all parts com parenteses 
return (0);
}






//https://apprize.best/c/practical/10.html
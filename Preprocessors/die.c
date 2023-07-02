#include <stdio.h>
#include <stdlib.h>
#define DIE \
fprintf(stderr, "Fatal Error:Abort\n");exit(8); 
/*put curly braces ({}) 
around all multistatement macros as 
*/
//#define DIE { fprintf(stderr, "Fatal Error:Abort\n");exit(8); }

int main() {
    /* a random value for testing */
    int value;
    value = 1;
    if (value < 0)
        DIE; //The problem is that two statements follow the if line. Normally, they would be put on two lines. 
    //an else here//brackets also works
    printf("We did not die\n");
    return (0);
}
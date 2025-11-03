# include <stdio.h>
int main() 
{   
    //Initialization and declaration of the scores array
    int scores[4][2] = {{65,92},
                        {84,72},
                        {35,70},
                        {59,67}
                    };   

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d \t", scores[i][j]);
        }
        printf("\n");
    }

    return 0; 
}
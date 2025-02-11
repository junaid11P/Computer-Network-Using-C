#include<stdio.h>

int main()
{
    int choice, bitstream[7], bitstream[5][7];
    printf("choose:\n1. 1D Parity\n2. 2D Parity\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice==1){
        printf("Enter 7 bit input stream: ");
        for(int i=0; i<7; i++){
            scanf("%d", &bitstream[i]);
        }
        calculate1DParity(bitstream, 7);
    }
    else if(choice==2){
        printf("Enter 5 stream of 7-bit input bit stream: \n");
        for(int i=0; i<5; i++){
            for(int j=0; j<7; j++){
                scanf("%d", &bitstream[i][j]);
            }
        }
        calculate2DParity(bitstream, 5, 7);
    }
    else{
        printf("Invalid choice");
    }
    return 0;
}

void calculate1DParity(int bitstream[], int size){
    int parity=0;
    printf("\n1D Parity:\nInput bit stream: ");
    for(int i=0; i<size; i++){
        printf("%d", bitstream[i]);
        parity^=bitstream[i];
    }
    printf("\nParity bit: %d", parity);
    printf("\nOutput bit stream: ");
    for(int i=0; i<size; i++){
        printf("%d", bitstream[i]);
    }
    printf("%d\n", parity);
}
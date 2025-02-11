#include<stdio.h>


void calculate1DParity(int bitstream[], int size) {
    int parity = 0;
    printf("\n1D Parity:\nInpute Bit stream: ");
    for(int i = 0; i < size; i++) {
        printf("%d", bitstream[i]);
        parity ^= bitstream[i];
    }
    printf("\nParity Bit : %d", parity);
    printf("\nOutput Bit stream: ");
    for(int i = 0; i < size; i++) {
        printf("%d", bitstream[i]);
    }
    printf("%d\n", parity);
}

void calculate2DParity(int bitstreams[5][7],int rows, int cols){
    int rowParity[5] ={0}, colParity[7] = {0};  

    for(int i=0; i< rows; i++){
        for(int j=0; j< cols; j++){
            rowParity[i] ^= bitstreams[i][j];
            colParity[j] ^= bitstreams[i][j];
        }
    }

    printf("\n2D Parity:\nInpute Bit streams: \n");
    for(int i=0; i< rows; i++){
        for(int j=0; j< cols; j++){
            printf("%d", bitstreams[i][j]);
        }
        printf("\n");
    }

    printf("\nRow Parity Bits: ");
    for(int i=0; i< rows; i++){
        printf("%d", rowParity[i]);
    }
    printf("\nColumn Parity Bits: ");
    for(int j=0; j< cols; j++){
        printf("%d", colParity[j]);
    }

    printf("\n\nOutput Bit streams with Row Parity: \n");
    for(int i=0; i< rows; i++){
        for(int j=0; j< cols; j++){
            printf("%d", bitstreams[i][j]);
        }
        printf(" %d\n", rowParity[i]);
    }
    printf("\nFinal column Parity Bits: ");
    for(int j=0; j< cols; j++){
        printf("%d", colParity[j]);
    }
    printf("\n");
}

int main(){
    int choice,bitstream[7],bitstreams[5][7];
    printf("1. 1D Parity\n2. 2D Parity\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Enter 7 bit stream: ");
        for(int i = 0; i < 7; i++){
            scanf("%d", &bitstream[i]);
        }
        calculate1DParity(bitstream, 7);
    }else if(choice == 2){
        printf("Enter 5 streams of 7 bits input bit streams:\n");
        for(int i=0; i< 5; i++){
            for(int j=0; j< 7; j++){
                scanf("%d", &bitstreams[i][j]);
            }
        }
        calculate2DParity(bitstreams, 5, 7);
    }else{
        printf("Invalid choice\n");
    }
    return 0;

}
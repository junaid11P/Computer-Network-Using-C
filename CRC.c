#include <stdio.h>
#include <string.h>

void performXOR(char *data, char *generator, int start){
    for(int i=0; generator[i] != '\0'; i++){
        data[start+i] = (data[start+i] == generator[i]) ? '0' : '1';
    }
}

void calculateCRC(char *data, char *generator, char *checksum){
    int dataLen = strlen(data);
    int genLen = strlen(generator);
    char temp[dataLen + genLen];
    strcpy(temp, data);
    for(int i=0; i<genLen-1; i++){
        temp[dataLen + i] = '0';
    }
    temp[dataLen + genLen - 1] = '\0';
    for(int i=0; i<dataLen; i++){
        if(temp[i] == '1'){
            performXOR(temp, generator, i);
        }
    }
    strncpy(checksum, &temp[dataLen], genLen-1);
    checksum[genLen-1] = '\0';
}

int verifyCRC(char *receivedData, char *generator){
    int dataLen = strlen(receivedData);
    char temp[dataLen + 1];

    strcpy(temp, receivedData);
    for(int i = 0; i < dataLen-strlen(generator)+1; i++){
        if(temp[i] == '1'){
            performXOR(temp, generator, i);
        }
    }
    for(int i=dataLen-strlen(generator)+1; i<dataLen; i++){
        if(temp[i] != '0'){
            return 0;
        }
    }
    return 1;
}

int main(){
    char data[100], generator[100], checksum[100], transmittedData[200], receivedData[200];
    int choice;

    char *generators[]={
        "100000111",
        "11000110101",
        "10001000000100001",
        "100000100110000010001110110110111"
    };

    char *crc_names[]={
        "CRC-8",
        "CRC-11",
        "CRC-17",
        "CRC-32"
    };
    int numGenerators = sizeof(generators)/sizeof(generators[0]);

    printf("Enter binary data: ");
    scanf("%s", data);

    // Validate binary input
    for(int i = 0; data[i] != '\0'; i++) {
        if(data[i] != '0' && data[i] != '1') {
            printf("Error: Please enter binary data (0s and 1s only)\n");
            return 1;
        }
    }

    printf("Choose CRC standards:\n");
    for(int i=0; i<numGenerators; i++){
        printf("%d. %s\n", i+1, crc_names[i]);
    }
    printf("Enter choice (1-%d): ", numGenerators);
    scanf("%d", &choice);
    if(choice < 1 || choice > numGenerators){
        printf("Invalid choice\n");
        return 1;
    }
    strcpy(generator, generators[choice-1]);
    calculateCRC(data, generator, checksum);
    strcpy(transmittedData, data);
    strcat(transmittedData, checksum);  
    printf("Generator Polynomial: %s\n", generator);
    printf("checksum: %s\n", checksum);

    printf("Transmitted data: %s\n", transmittedData);
    printf("Enter received data: ");
    scanf("%s", receivedData);

    if(verifyCRC(receivedData, generator)){
        printf("No error in received data\n");
    }else{
        printf("Error in received data\n");
    }
    return 0;
}


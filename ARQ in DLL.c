#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TOTAL_FRAMES 20

void stopAndWait(int totalFrames){
    printf("\nStop and Wait ARQ:\n");
    for(int i=0;i<totalFrames; i++){
        printf("transmitting frame %d\n", i+1);
        printf("waiting for ack...\n");
        printf("received ack for frame %d\n", i+1);
    }
}

void goBackN(int totalFrames, int windowSize){
    int nextFrameToSend = 0;
    printf("\nGo Back N ARQ(Window Size = %d)\n", windowSize);

    while(nextFrameToSend < totalFrames){
        printf("Window: DSending frames %d to %d\n", nextFrameToSend+1, nextFrameToSend+windowSize);

        for(int i=0; i<windowSize && nextFrameToSend < totalFrames; i++){
            printf("transmitting frame %d\n", nextFrameToSend+1);
            nextFrameToSend++;
        }

        printf("waiting for ack...\n");
        for(int i=0; i<windowSize && nextFrameToSend-i >0; i++){
            printf("received ack for frame %d\n", nextFrameToSend-i);
    }
}
}


void selectiveRepeat(int totalFrames, int windowSize){
    int nextFrameToSend = 0, nextFrameExpected =0;
    printf("\nSelective Repeat ARQ(Window Size = %d)\n", windowSize);

    while(nextFrameToSend < totalFrames){
        printf("Window: Sending frames %d to %d\n", nextFrameToSend+1, nextFrameToSend+windowSize);

        for(int i=0; i<windowSize && nextFrameToSend < totalFrames; i++){
            printf("transmitting frame %d\n", nextFrameToSend+1);
            nextFrameToSend++;
        }

        printf("waiting for ack...\n");
        for(int i=nextFrameExpected; i<nextFrameToSend; i++){
            printf("received ack for frame %d\n", i+1);
        }
        nextFrameExpected = nextFrameToSend;

    }
}

int main(){
    int windowSize;

    stopAndWait(TOTAL_FRAMES);

    windowSize = 5;
    goBackN(TOTAL_FRAMES, windowSize);

    windowSize = 5;
    selectiveRepeat(TOTAL_FRAMES, windowSize);
}
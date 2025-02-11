#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NODES 10 // Number of nodes in the network

double calculateDistance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int main(){
    double nodeCoords[NODES][2];
    double distanceMatrix[NODES][NODES];
    int neighbors[NODES][NODES];
    double range;
    int i, j;

    srand(42);
    for(i=0; i<NODES; i++){
        nodeCoords[i][0] = rand()%501;  // 0-500 range
        nodeCoords[i][1] = rand()%501;
        if(nodeCoords[i][0] < 0 || nodeCoords[i][1] < 0){
            printf("Error: Invalid coordinate generation\n");
            return 1;
        }
    }

    for(i=0; i<NODES; i++){
        for(j=0; j<NODES; j++){
            distanceMatrix[i][j] = calculateDistance(
                nodeCoords[i][0], nodeCoords[i][1],
                nodeCoords[j][0], nodeCoords[j][1]
            );
        }
    }

    printf("Enter the range for determining neighbors: ");
    if (scanf("%lf", &range) != 1 || range <= 0) {
        printf("Error: Invalid range value. Must be a positive number.\n");
        return 1;
    }
    for(i=0; i<NODES; i++){
        for(j=0; j<NODES; j++){
            if(i!=j && distanceMatrix[i][j] <= range){
                neighbors[i][j] = 1;
            } else {
                neighbors[i][j] = 0;
            }
        }
    }

    printf("Node Co-ordinates:\n");
    for(i=0; i<NODES; i++){
        printf("Node %d: (%.2f, %.2f)\n", i+1, nodeCoords[i][0], nodeCoords[i][1]);
    }

    printf("Distance Matrix:\n");
    printf("    ");
    for(i=0; i<NODES; i++){
        printf("Node %-4d ", i+1);
    }
    printf("\n");
    for(i=0; i<NODES; i++){
        printf("Node %d ", i+1);
        for(j=0; j<NODES; j++){
            printf("%-8.2f ", distanceMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nNeighbor Table (1 indicates neighbor, 0 indicates non-neighbor):\n");
    for(i=0; i<NODES; i++){
        printf("Node %d: ", i+1);
        for(j=0; j<NODES; j++){
            printf("%d ", neighbors[i][j]);
        }
        printf("\n");
    }
    return 0;
}

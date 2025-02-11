#include<stdio.h>
#define INF 9999 
#define MAX 10

void calculateRoutingTables(int n, int cost[MAX][MAX]){
    int distance[MAX][MAX],nextHop[MAX][MAX],i, j, k;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            distance[i][j] = cost[i][j];
            if(cost[i][j]!= INF && i!=j){
                nextHop[i][j] =j;
            } else {
                nextHop[i][j] = -1;
            }
        }
    }

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(distance[i][j] > distance[i][k] + distance[k][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                    nextHop[i][j] = nextHop[i][k];
                }
            }
        }
    }

    for(i=0;i<n;i++){
        printf("Routing Tabkle for Node %d:\n", i+1);
        printf("Destination\tCost\tNextHope\n");
        for(j=0;j<n;j++){
            if(i!=j){
                printf("%d\t\t%d\t", j+1,distance[i][j]);
                if(nextHop[i][j] != -1){
                    printf("%d\n", nextHop[i][j]+1);
                } else {
                    printf("-\n");
                }
            }
        }
    }
}

int main(){
    int n, i,j;
    int cost[MAX][MAX];

    printf("Enter the number of nodes in the network: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix(use %d for infinity):\n", INF);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &cost[i][j]);
        }
    }
    calculateRoutingTables(n, cost);

    return 0;
}

#include <stdio.h>
#include <limits.h>


#define MAX 10
#define INF 9999


int n;


void dijkstra(int graph[MAX][MAX], int source) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0 && i != j)
                cost[i][j] = INF;
            else
                cost[i][j] = graph[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        distance[i] = cost[source][i];
        pred[i] = source;
        visited[i] = 0;
    }


    distance[source] = 0;
    visited[source] = 1;
    count = 1;


    while (count < n - 1) {
        mindistance = INF;
        for (int i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }


        visited[nextnode] = 1;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }


    printf("\nSource\tDestination\tCost\tPath");
    for (int i = 0; i < n; i++) {
        if (i != source) {
            printf("\n%d\t%d\t\t%d\t", source + 1, i + 1, distance[i]);
            printf("%d", i + 1);


            int j = i;
            while (j != source) {
                j = pred[j];
                printf("<-%d", j + 1);
            }
        } else {
            printf("\n%d\t%d\t\t%d\t-", source + 1, source + 1, 0);
        }
    }
    printf("\n");
}


int main() {
    int graph[MAX][MAX];
    int source;


    printf("\nEnter the Number of Vertices: ");
    scanf("%d", &n);


    printf("Enter the Adjacency Matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);


    printf("Enter the Source Vertex (1 to %d): ", n);
    scanf("%d", &source);
    source--;


    dijkstra(graph, source);
    printf("\nName: Rehyan yadav \nRoll No.: 2330104\n\n");


    return 0;
}

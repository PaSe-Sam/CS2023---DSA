#include <iostream>

using namespace std;

int minDistance(int dist[], bool visited[]){
    int min = 100;
    int min_index;
    
    for (int c = 0; c < 6; c++){
        
        if (visited[c]==false && dist[c] <= min){
            min = dist[c];
            min_index = c;
        }
    }
    return min_index;
}

void dijkstra(int graph[6][6], int src){

    int dist[6]; //shortest distances
    bool visited[6]; //visited nodes

    for (int i = 0; i < 6; i++){
        
        dist[i] = 100; //max distance considered as 100. 
        visited[i] = false;
    }

    dist[src] = 0; //same city distance = 0

    for (int count = 0; count < 5; count++){

        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < 6; v++){
            
            if (!visited[v] && graph[u][v] && dist[u]!= 100 && dist[u] + graph[u][v] < dist[v]){
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    
    cout << "Source city selected : " << src << "\n" << "Shorted distance to cities; " <<"\n";  //output the shortest distances from the source city ot others
    
    int sum = 0;
    double avg_dist=0;
    
    for (int j = 0; j < 6; j++){
        sum +=dist[j];
        cout << "City " << j << ": " << dist[j] << "\n";
    }
    
    avg_dist = sum/5.0;
    cout << "Average distance = " << avg_dist;
}


int main(){
    
    int city[6][6] = {   //weighted adjacency matrix of graph of cities
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int src = 5;

    dijkstra(city, src);

    return 0;
}

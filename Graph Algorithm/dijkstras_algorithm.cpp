#include<bits/stdc++.h>

using namespace std;

int findMinD(int* distance, bool* visited, int v) {

    int minDV = -1;
    for(int i=0;i<v;i++) {
        if(!visited[i] && (minDV == -1 || distance[i] < distance[minDV])) {
            minDV = i;
        }
    }

    return minDV;
}

void dijkstra(int** edges, int v) {

    bool *visited = new bool[v];
    int *distance = new int[v];
    for(int i=0;i<v;i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    
    for(int i=0;i<v;i++) {
        int minDV = findMinD(distance, visited, v);
        visited[minDV] = true;
        for(int j=0;j<v;j++) {
            if(!visited[j] && edges[minDV][j] != 0) {
                if(distance[j] > edges[minDV][j]) {
                    distance[j] = min(distance[minDV] + edges[minDV][j], distance[j]);
                }
            }
        }
    }

    cout<<"***** OUTPUT *****"<<endl;
    for(int i=0;i<v;i++) {
        cout<<i<<" "<<distance[i]<<endl;
    }
}

int main() {

    int v,e;
    cin>>v>>e;

    int** edges = new int*[e];
    for(int i=0;i<e;i++) {
        edges[i] = new int[e];
        for(int j=0;j<e;j++) {
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++) {
        int s,d,w;
        cin>>s>>d>>w;
        edges[s][d] = w;
        edges[d][s] = w;
    }

    dijkstra(edges, v);

    return 0;

}
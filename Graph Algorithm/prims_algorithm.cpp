#include<bits/stdc++.h>

using namespace std;

int findMinV(int* weight, bool* visited, int v) {

    int minV = -1;
    for(int i=0;i<v;i++) {
        if(!visited[i] && (minV == -1 || weight[i] < weight[minV])) {
            minV = i;
        }
    }
    return minV;
}

void prim(int** input, int v) {

    bool* visited = new bool[v];
    int* weight = new int[v];
    int* parent = new int[v];

    for(int i=0;i<v;i++) {
        weight[i] = INT_MAX;
        visited[i] = false;
    }    
    parent[0] = -1;
    weight[0] = 0;

    for(int i=0;i<v;i++) {
        int minV = findMinV(weight, visited, v);
        visited[minV] = true;

        for(int j=0;j<v;j++) {
            if(input[minV][j] != 0 && !visited[j]) {
                if(input[minV][j] < weight[j]) {
                    weight[j] = input[minV][j];
                    parent[j] = minV;
                }
            }
        }
    }

    cout<<"***** Output *****"<<endl;
    for(int i=1;i<v;i++) {
        if(parent[i] < i) {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        } else {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
}

int main() {

    int v,e;
    cin>>v>>e;

    int **input = new int*[e];
    for(int i=0;i<e;i++) {
        input[i] = new int[e];
        for(int j=0;j<e;j++) {
            input[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++) {
        int f,s,w;
        cin>>f>>s>>w;
        input[f][s] = w;
        input[s][f] = w;
    }

    prim(input, v);

    return 0;

}
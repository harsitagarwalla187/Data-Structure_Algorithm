#include<bits/stdc++.h>

using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited) {

    cout<<sv<<endl;
    visited[sv] = true;

    for(int i=0;i<n;i++) {
        if(i == sv) continue;
        if(edges[sv][i] == 1 && !visited[i]) {
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv) {

    bool *visited = new bool[n];
    for(int i=0;i<n;i++) visited[i] = false;

    queue<int> q;
    q.push(sv);

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        cout<<temp<<endl;
        visited[temp] = true;

        for(int i=0;i<n;i++) {
            if(i == temp ) continue;
            if(edges[temp][i] == 1 && !visited[i])   {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    delete [] visited;
}

int main() {

    int n,e;
    cin>>n>>e;

    int  **edges = new int*[n];
    for(int i=0;i<n;i++) {
        edges[i] = new int[n];
        for(int j=0;j<n;j++) {
            edges[i][j] = 0;
        }
    }   

    for(int i=0;i<e;i++) {
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for(int i=0;i<n;i++) visited[i] = false;

    cout<<"************DFS************"<<endl;
    printDFS(edges, n, 0, visited);

    cout<<"************BFS************"<<endl;
    printBFS(edges, n, 0);

    delete [] visited;
    for(int i=0;i<n;i++) delete [] edges[i];
    delete [] edges;

    return 0;

}
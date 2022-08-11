#include<bits/stdc++.h>

using namespace std;

vector<int> getPathHelper(int **edges, int n, int v1, int v2, bool* visited) {
    vector<int> ans;

    if(v1 == v2) {
        ans.push_back(v1);
        return ans;
    }

    visited[v1] = true;
    for(int i=0;i<n;i++) {
        if(i == v1) continue;
        if(edges[v1][i] == 1 && !visited[i]) {
            ans = getPathHelper(edges, n, i, v2, visited);
            if(!ans.empty()) {
                ans.push_back(v1);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> getPath(int **edges, int n, int v1, int v2) {
    bool *visited = new bool[n];
    for(int i=0;i<n;i++) {
        visited[i] = false;
    }

    vector<int> ans;
    ans = getPathHelper(edges, n, v1, v2, visited);
    return ans;
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

    int v1,v2;
    cin>>v1>>v2;

    cout<<"**********GET-PATH-DFS**********"<<endl;
    vector<int> ans = getPath(edges, n, v1, v2);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;

    for(int i=0;i<n;i++) delete [] edges[i];
    delete [] edges;

    return 0;

}
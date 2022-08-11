#include<bits/stdc++.h>

using namespace std;

vector<int> getPathHelper(int **edges, int n, int v1, int v2, bool* visited) {
    vector<int> ans;

    if(v1 == v2) {
        ans.push_back(v1);
        return ans;
    }

    unordered_map<int,int> mp;
    queue<int> q;
    q.push(v1);

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        visited[temp] = true;
        for(int i=0;i<n;i++) {
            if(i == temp) continue;
            if(!visited[i] && edges[temp][i] == 1) {
                q.push(i);
                mp[i] = temp;
                if(i == v2) {
                    int j = v2;
                    while(j != v1) {
                    ans.push_back(j);
                    j = mp[j];
                    }
                    ans.push_back(j);
                    return ans;
                }
            }
        }
    }
    return {};
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

    cout<<"**********GET-PATH-BFS**********"<<endl;
    vector<int> ans = getPath(edges, n, v1, v2);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;

    for(int i=0;i<n;i++) delete [] edges[i];
    delete [] edges;

    return 0;

}
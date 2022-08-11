#include<bits/stdc++.h>

using namespace std;

class Edge {
    public:
        int source;
        int destination;
        int weight;
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int uFind(int* parents, int v) {
    if(parents[v] == v) return v;

    return uFind(parents, parents[v]);
}

void kruskals(Edge* input, int v, int e) {

    sort(input, input + e, compare);

    Edge *output = new Edge[v-1];
    int* parents = new int[v];
    for(int i=0;i<v;i++) {
        parents[i] = i;
    }
    int count = 0;
    int i = 0;

    while(count != v-1) {

        Edge currentV = input[i];
        int p1 = uFind(parents, currentV.source);
        int p2 = uFind(parents, currentV.destination);

        if(p1 != p2) {

            if(currentV.source < currentV.destination) {
                output[count].source = currentV.source;
                output[count].destination = currentV.destination;
            } else {
                output[count].destination = currentV.source;
                output[count].source = currentV.destination;
            }
            output[count].weight = currentV.weight;
            count++;
            parents[p2] = p1;
        }
        i++;
    }

    for(int i=0; i<v-1;i++) {
        cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
    }
}

int main() {

    int v,e;
    cin>>v>>e;

    Edge *input = new Edge[e];
    for(int i=0; i<e; i++) {
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }    

    kruskals(input, v, e);

    return 0;

}
#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

vector<vector<int>> initializeGraph(int numvertices) {
    vector<vector<int>> graph(numvertices, vector<int>(numvertices, 0));
    return graph;
}

void addEdge(vector<vector<int>>& graph, int from, int to) {
    graph[from][to] = 1;
    graph[to][from] = 1;
}

void bfsTraversal(const vector<vector<int>>& graph, int startVertex){
    
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    while(!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";

        for (int i = 0; i < numVertices; i++)
        {
            if(graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i]=true;
                q.push(i);
            } 
        }
    }
    cout << endl;
}

void dfsTraversal(const vector<vector<int>>& graph, int startVertex) {
    
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    stack<int> s;

    visited[startVertex] = true;
    s.push(startVertex);

    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    while(!s.empty()) {
        int currentVertex = s.top();
        s.pop();
        cout << currentVertex << " ";
        for (int i = 0; i < numVertices; i++)
        {
            if(graph[currentVertex][i] == 1 && !visited[i]) 
            {
                visited[i]=true;
                s.push(i);
            } 
        }
    }
    cout << endl;
}

int main() {
    int numVertices, numEdges;

    cout << "Enter the no. of vertices : ";
    cin >> numVertices;
    vector<vector<int>> graph = initializeGraph(numVertices);

    cout << "Enter the no. of edges : ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; ++i)
    {   
        int from, to;
        cout << "Enter the edges from to : ";
        cin >> from >> to ;
        addEdge(graph, from, to);
    }

    int startVertex;
    cout << "Enter the start vertex for Traversal : ";
    cin >> startVertex;

    //bfsTraversal(graph, startVertex);
    dfsTraversal(graph, startVertex);
    
    return 0;
}
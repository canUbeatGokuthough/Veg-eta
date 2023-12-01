#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<list<int>> &adjList, int source, int destination) {
    adjList[source].push_back(destination);
    adjList[destination].push_back(source);
}

// Function to display the adjacency list
void displayGraph(const vector<list<int>> &adjList) {
    cout << "Adjacency List:\n";
    for (size_t i = 0; i < adjList.size(); ++i) {
        cout << "Vertex " << i << " :";
        for (const auto &neighbor : adjList[i]) {
            cout << " -> " << neighbor;
        }
        cout << endl;
    }
}

int main() {
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    vector<list<int>> adjacencyList(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (source destination):\n";
    for (int i = 0; i < edges; ++i) {
        int source, destination;
        cin >> source >> destination;

        // Check for valid vertex indices
        if (source >= 0 && source < vertices && destination >= 0 && destination < vertices) {
            addEdge(adjacencyList, source, destination);
        } else {
            cout << "Invalid vertex indices. Ignoring this edge.\n";
            --i; // Decrement i to re-enter the current edge
        }
    }

    // Display the adjacency list
    displayGraph(adjacencyList);

    return 0;
}

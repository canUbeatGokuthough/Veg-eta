#include <iostream>
#include <vector>

using namespace std;

const int MAX_VERTICES = 100; // Adjust the maximum number of vertices as needed

// Function to add an edge to the graph
void addEdge(vector<vector<int>> &adjMatrix, int source, int destination) {
    // Assuming the graph is undirected
    adjMatrix[source][destination] = 1;
    adjMatrix[destination][source] = 1;
}

// Function to display the adjacency matrix
void displayGraph(const vector<vector<int>> &adjMatrix, int vertices) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    vector<vector<int>> adjacencyMatrix(vertices, vector<int>(vertices, 0));

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (source destination):\n";
    for (int i = 0; i < edges; ++i) {
        int source, destination;
        cin >> source >> destination;

        // Check for valid vertex indices
        if (source >= 0 && source < vertices && destination >= 0 && destination < vertices) {
            addEdge(adjacencyMatrix, source, destination);
        } else {
            cout << "Invalid vertex indices. Ignoring this edge.\n";
            --i; // Decrement i to re-enter the current edge
        }
    }

    // Display the adjacency matrix
    displayGraph(adjacencyMatrix, vertices);

    return 0;
}

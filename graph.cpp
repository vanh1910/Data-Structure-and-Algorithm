// Graph Implementation Template
// Based on concepts from 07_graphs.pdf
// Instructions: Implement the missing function definitions for each class.
// Each function has comments indicating what it should do.

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdexcept>
#include <algorithm>

//-------------------- GRAPH BASE CLASS --------------------
class Graph
{
protected:
    int numVertices;
    bool directed;

public:
    // Constructor
    Graph(int vertices, bool isDirected = false) : numVertices(vertices), directed(isDirected) {}

    // Virtual destructor for proper inheritance
    virtual ~Graph() {}

    // Check if graph is directed
    bool isDirected() const
    {
        return directed;
    }

    // Get number of vertices
    int getNumVertices() const
    {
        return numVertices;
    }

    bool withInBounds(int vertice) const {
        if (vertice >= 0 && vertice < numVertices) return true;
        return false;
    }

    bool withInBounds(int verticeA, int verticeB) const{
        if (verticeA < 0 || verticeA >= numVertices) return false;
        if (verticeB < 0 || verticeB >= numVertices) return false;
        return true;
    }

    // Pure virtual functions - to be implemented by derived classes
    virtual void addEdge(int source, int destination) = 0;
    virtual bool hasEdge(int source, int destination) const = 0;
    virtual std::vector<int> getNeighbors(int vertex) const = 0;
    virtual void printGraph() const = 0;
};

//-------------------- ADJACENCY MATRIX IMPLEMENTATION --------------------
class AdjacencyMatrixGraph : public Graph
{
private:
    std::vector<std::vector<bool>> matrix;


public:
    // Constructor: Initialize matrix with given size
    AdjacencyMatrixGraph(int vertices, bool isDirected = false) : Graph(vertices, isDirected)
    {
        matrix.assign(numVertices, std::vector<bool>(numVertices,false));
    }

    // Add an edge from source to destination
    void addEdge(int source, int destination) override
    {
        if (!withInBounds(source, destination)){
            throw "out of bounds";
            return;
        }
        matrix[source][destination] = true;
        if (!isDirected()) matrix[destination][source] = true;
    }

    // Check if there is an edge from source to destination
    bool hasEdge(int source, int destination) const override
    {
        if (!withInBounds(source, destination)) return false;
        return matrix[source][destination];
    }

    // Get all neighbors (vertices connected by an edge) of a vertex
    std::vector<int> getNeighbors(int vertex) const override
    {
        if (!withInBounds(vertex)) throw "out of bounds";
        std::vector<int> neighbors;
        for (int i = 0; i < numVertices; ++i){
            if (hasEdge(vertex, i)) neighbors.push_back(i);
        }
        return neighbors;
    }

    // Print the adjacency matrix
    void printGraph() const override
    {
        std::cout << "  ";
        for (int i = 0; i < numVertices; ++i){
            std::cout << i << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < numVertices; ++i){
            std::cout << i << " ";
            for (int j = 0; j < numVertices; ++j){
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

//-------------------- ADJACENCY LIST IMPLEMENTATION --------------------
class AdjacencyListGraph : public Graph
{
private:
    std::vector<std::vector<int>> adjacencyList;

public:
    // Constructor: Initialize adjacency list with given size
    AdjacencyListGraph(int vertices, bool isDirected = false) : Graph(vertices, isDirected)
    {
        // TODO: Initialize the adjacency list
        // Hint: Create a vector of vectors with size numVertices
        adjacencyList.empty();
        adjacencyList.resize(vertices);
    }

    // Add an edge from source to destination
    void addEdge(int source, int destination) override
    {   
        if (!withInBounds(source, destination)) throw "out_of_bounds";

        adjacencyList[source].push_back(destination);
        if (!isDirected()) adjacencyList[destination].push_back(source);

        // TODO: Add an edge from source to destination
        // If the graph is undirected, also add an edge from destination to source
        // Validate that source and destination are within bounds
    }

    // Check if there is an edge from source to destination
    bool hasEdge(int source, int destination) const override
    {
        if (!withInBounds(source, destination)){
            throw "out of bounds";
            return false;
        }


        // TODO: Check if there is an edge from source to destination
        // This requires searching through the adjacency list
        // Return false if source or destination is out of bounds
        for (int const &i : adjacencyList[source]){
            if (i == destination) return true;
        }
        return false;
    }

    // Get all neighbors (vertices connected by an edge) of a vertex
    std::vector<int> getNeighbors(int vertex) const override
    {
        // TODO: Return a vector containing all vertices that are adjacent to the given vertex
        // For adjacency list, this is simply the list at index 'vertex'
        // Return empty vector if vertex is out of bounds
        return adjacencyList[vertex]; // Placeholder
    }

    // Print the adjacency list
    void printGraph() const override
    {
        // TODO: Print the adjacency list in a readable format
        // Example:
        // 0 -> 1
        // 1 -> 0 -> 2
        // 2 -> 1 -> 3
        // 3 -> 2
        for (int i = 0; i < numVertices; ++i){
            std::cout << i << ": ";
            for (int const &j : adjacencyList[i]){
                std:: cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};

//-------------------- GRAPH TRAVERSAL ALGORITHMS --------------------
class GraphAlgorithms
{
private:
    static void DFSFindConnectedGraph(bool visited[], int  u, const Graph &graph){
        visited[u] = true;
        std::vector<int> neighbors = graph.getNeighbors(u);
        for (int i : neighbors){
            if (!visited[i]){
                DFSFindConnectedGraph(visited, i, graph);
            }
        }
    }

    static void topoDFS(bool visited[], int u, std::stack<int> &finishOrder, const Graph &graph){
        visited[u] = true;
        std::vector<int> neighbors = graph.getNeighbors(u);
        for (int i : neighbors){
            if (!visited[i]){
                topoDFS(visited, i, finishOrder, graph);
            }
        }
        finishOrder.push(u);
    }

public:
    // Depth-First Search (DFS) implementation
    static void DFS(const Graph &graph, int startVertex, std::vector<bool> &visited)
    {
        visited[startVertex] = true;
        std::cout << "Visited vertex: " << startVertex << std::endl;

        std::vector<int> neighbors = graph.getNeighbors(startVertex);
        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                DFS(graph, neighbor, visited);
            }
        }
        
    }

    // Iterative DFS using a stack
    static void DFSIterative(const Graph &graph, int startVertex)
    {
        // TODO: Implement iterative DFS using a stack
        // 1. Create a stack and push startVertex
        // 2. Create a visited array initialized to false
        // 3. While stack is not empty:
        //    a. Pop a vertex from stack
        //    b. If not visited, mark as visited and process it
        //    c. Push all unvisited neighbors to stack
    }

    // Breadth-First Search (BFS) implementation
    static void BFS(const Graph &graph, int startVertex)
    {
        // TODO: Implement BFS
        std::queue<int> bfsQueue;
        bool visited[graph.getNumVertices()] = {false};

        visited[startVertex] = true;
        bfsQueue.push(startVertex);
        std::cout << "Visited vertex: " << startVertex << std::endl;

        while(!bfsQueue.empty()){
            int vertex = bfsQueue.front();
            bfsQueue.pop();
            for (int &i : graph.getNeighbors(vertex)){
                if (!visited[i]){
                    std::cout << "Visited vertex: " << i << std::endl;
                    bfsQueue.push(i);
                    visited[i] = true;
                }
            }
        }
        // 1. Create a queue and enqueue startVertex
        // 2. Create a visited array initialized to false
        // 3. Mark startVertex as visited
        // 4. While queue is not empty:
        //    a. Dequeue a vertex
        //    b. Process it
        //    c. Enqueue all unvisited neighbors and mark them as visited
    }

    // Find connected components in an undirected graph
    static int findConnectedComponents(const Graph &graph)
    {   
        int connectedComponents = 0;
        int numVertices = graph.getNumVertices();
        bool visited[numVertices] = {false};
        for (int i = 0; i < numVertices; ++i){
            if (!visited[i]){
                connectedComponents++;
                GraphAlgorithms::DFSFindConnectedGraph(visited, i, graph);
            }
        }
        return connectedComponents; 
    }

    // Check if a graph is bipartite
    static bool isBipartite(const Graph &graph)
    {
        int numVertices = graph.getNumVertices();
        int color[numVertices];
        for (int i = 0; i < numVertices; ++i){
            color[i] = -1;
        }
        std::queue<int> bfsQueue;
        for (int i = 0; i < numVertices; ++i){
            if (color[i] == -1){
                color[i] = 0;
                bfsQueue.push(i);
                while (!bfsQueue.empty()){
                    int vertex = bfsQueue.front();
                    bfsQueue.pop();
                    for (int &j : graph.getNeighbors(vertex)){
                        if (color[j] == -1){
                            color[j] = 1 - color[vertex];
                            bfsQueue.push(j);
                        } else if (color[j] == color[vertex]){
                            return false;
                        }
                    }
                }
            }
        }

        return true; 
    }
 
    // Find shortest path between two vertices (unweighted graph)
    static std::vector<int> findShortestPath(const Graph &graph, int startVertex, int endVertex)
    {
        std::vector<int> path;
        std::queue<int> bfsQueue;
        int numVertices = graph.getNumVertices();
        int parent[numVertices];
        bool visited[numVertices] = {false};
        for (int i = 0; i < numVertices; ++i){
            parent[i] = -1;
        }
        visited[startVertex] = true;
        bfsQueue.push(startVertex);
        while (!bfsQueue.empty()){
            int vertex = bfsQueue.front();
            bfsQueue.pop();
            if (vertex == endVertex) break;
            for (int &i : graph.getNeighbors(vertex)){
                if (!visited[i]){
                    visited[i] = true;
                    parent[i] = vertex;
                    bfsQueue.push(i);
                }
            }
        }
        if (parent[endVertex] == -1) return path; // No path found
        for (int i = endVertex; i != -1; i = parent[i]){
            path.push_back(i);
        }
        std::reverse(path.begin(), path.end());
        return path;
    }

    // Topological sort (for directed acyclic graphs)
    static std::vector<int> topologicalSort(const Graph &graph)
    {
        // TODO: Implement topological sort using DFS
        // 1. Run DFS on each unvisited vertex
        // 2. After exploring all neighbors of a vertex, add it to the front of the result list
        // 3. Return the result list (in reverse order of completion time)
        std::vector<int> result;
        std::stack<int> finishOrder;
        int numVertices = graph.getNumVertices();
        bool visited[numVertices] = {false};
        for (int i = 0; i < graph.getNumVertices(); ++i){
            if (!visited[i]){
                GraphAlgorithms::topoDFS(visited, i, finishOrder, graph);
            }
        }
        while (!finishOrder.empty()){
            result.push_back(finishOrder.top());
            finishOrder.pop();
        }
        return result;
    }
    // Helper function for first DFS pass in Kosaraju's algorithm
    static void kosarajuFirstDFS(const Graph &graph, int vertex, std::vector<bool> &visited,
                                 std::stack<int> &finishOrder)
    {
        // TODO: Implement first DFS pass of Kosaraju's algorithm
        // 1. Mark current vertex as visited
        // 2. Recursively visit all unvisited neighbors
        // 3. After processing all neighbors, push current vertex to finishOrder stack
        // (This creates a stack with vertices ordered by decreasing finish time)
        visited[vertex] = true;
        std::vector<int> neighbors = graph.getNeighbors(vertex);
        for (int &i : neighbors){
            if (!visited[i]){
                GraphAlgorithms::kosarajuFirstDFS(graph, i, visited, finishOrder);
            }
        }
        finishOrder.push(vertex);
    }   

    // Helper function for second DFS pass in Kosaraju's algorithm
    static void kosarajuSecondDFS(const Graph &graph, int vertex, std::vector<bool> &visited,
                                  std::vector<int> &component)
    {
        // TODO: Implement second DFS pass of Kosaraju's algorithm
        // 1. Mark current vertex as visited
        // 2. Add current vertex to the current component
        // 3. Recursively visit all unvisited neighbors
        // (This identifies vertices in the current strongly connected component)
        visited[vertex] = true;
        component.push_back(vertex);
        std::vector<int> neighbors = graph.getNeighbors(vertex);
        for (int &i : neighbors){
            if (!visited[i]){
                GraphAlgorithms::kosarajuSecondDFS(graph, i, visited, component);
            }
        }

    }

    // Find strongly connected components using Kosaraju's algorithm
    static std::vector<std::vector<int>> findStronglyConnectedComponents(const Graph &graph)
    {
        // TODO: Implement Kosaraju's algorithm for finding SCCs
        // 1. Check if graph is directed (algorithm only works for directed graphs)
        if  (!graph.isDirected()) return{};
        // 2. First DFS pass:
        //    a. For each unvisited vertex, run kosarajuFirstDFS
        //    b. This fills the stack with vertices in order of decreasing finish times
        // 3. Create a reversed graph by reversing all edges
        // 4. Second DFS pass:
        //    a. Process vertices in order from the stack (decreasing finish time)
        //    b. For each unvisited vertex, run kosarajuSecondDFS to find a component
        //    c. Add each component to the result
        // 5. Return the list of strongly connected components
        int numVertices = graph.getNumVertices();
        std::stack<int> finishOrder;
        std::vector<bool> visited(numVertices, false);
        std::vector<std::vector<int>> components;
        
        for (int i = 0; i < numVertices; ++i){
            if (!visited[i]){
                GraphAlgorithms::kosarajuFirstDFS(graph, i, visited, finishOrder);
            }
        }
        // Create a reversed graph
        AdjacencyListGraph reversedGraph(numVertices, true);
        for (int i = 0; i < numVertices; ++i){
            std::vector<int> neighbors = graph.getNeighbors(i);
            for (int &j : neighbors){
                reversedGraph.addEdge(j, i);
            }
        }
        // Second DFS pass on the reversed graph
        std::fill(visited.begin(), visited.end(), false);
        while (!finishOrder.empty()){
            int vertex = finishOrder.top();
            finishOrder.pop();
            if (!visited[vertex]){
                std::vector<int> component;
                GraphAlgorithms::kosarajuSecondDFS(reversedGraph, vertex, visited, component);
                components.push_back(component);
            }
        }
        return components;
    }
};

//-------------------- TESTING FUNCTION --------------------
void testGraphImplementations()
{
    // Test Adjacency Matrix (Undirected)
    std::cout << "======= Testing Undirected Adjacency Matrix Graph =======\n";
    AdjacencyMatrixGraph matrixGraph(5);

    // Add edges
    //matrixGraph.addEdge(0, 1);
    matrixGraph.addEdge(0, 4);
    //matrixGraph.addEdge(1, 2);
    matrixGraph.addEdge(1, 3);
    matrixGraph.addEdge(1, 4);
    matrixGraph.addEdge(2, 3);
    //matrixGraph.addEdge(3, 4);

    // Print the graph
    std::cout << "Adjacency Matrix:\n";
    matrixGraph.printGraph();

    // Test edge existence
    std::cout << "Edge (0,1): " << (matrixGraph.hasEdge(0, 1) ? "exists" : "doesn't exist") << std::endl;
    std::cout << "Edge (2,4): " << (matrixGraph.hasEdge(2, 4) ? "exists" : "doesn't exist") << std::endl;

    // Test neighbors
    std::cout << "Neighbors of vertex 1: ";
    std::vector<int> neighbors = matrixGraph.getNeighbors(1);
    for (int neighbor : neighbors)
    {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    // Test Adjacency List (Directed)
    std::cout << "\n======= Testing Directed Adjacency List Graph =======\n";
    AdjacencyListGraph listGraph(5, true);

    // Add edges
    listGraph.addEdge(0, 1);
    listGraph.addEdge(0, 4);
    listGraph.addEdge(1, 2);
    listGraph.addEdge(1, 3);
    listGraph.addEdge(1, 4);
    listGraph.addEdge(2, 3);
    listGraph.addEdge(3, 4);

    // Print the graph
    std::cout << "Adjacency List:\n";
    listGraph.printGraph();

    // Test edge existence
    std::cout << "Edge (0,1): " << (listGraph.hasEdge(0, 1) ? "exists" : "doesn't exist") << std::endl;
    std::cout << "Edge (4,0): " << (listGraph.hasEdge(4, 0) ? "exists" : "doesn't exist") << std::endl;

    // Test graph traversal algorithms
    std::cout << "\n======= Testing Graph Algorithms =======\n";

    // DFS
    std::cout << "DFS starting from vertex 0:\n";
    std::vector<bool> visited(5, false);
    GraphAlgorithms::DFS(listGraph, 0, visited);

    // BFS
    std::cout << "\nBFS starting from vertex 0:\n";
    GraphAlgorithms::BFS(listGraph, 0);

    // Connected Components (using undirected graph)
    std::cout << "\nConnected Components in undirected graph: "
              << GraphAlgorithms::findConnectedComponents(matrixGraph) << std::endl;

    // Bipartite Check
    std::cout << "Is the undirected graph bipartite? "
              << (GraphAlgorithms::isBipartite(matrixGraph) ? "Yes" : "No") << std::endl;

    // Shortest Path
    std::cout << "\nShortest path from vertex 0 to 3:\n";
    std::vector<int> path = GraphAlgorithms::findShortestPath(matrixGraph, 0, 3);
    for (int vertex : path)
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    // Topological Sort (using directed graph)
    std::cout << "\nTopological Sort of the directed graph:\n";
    std::vector<int> topoOrder = GraphAlgorithms::topologicalSort(listGraph);
    for (int vertex : topoOrder)
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    // Test Strongly Connected Components (using directed graph)
    std::cout << "\n======= Testing Strongly Connected Components =======\n";
    AdjacencyListGraph sccGraph(8, true);

    // Add edges to create SCCs as shown in the PDF example
    sccGraph.addEdge(0, 1);
    sccGraph.addEdge(1, 2);
    sccGraph.addEdge(2, 0);
    sccGraph.addEdge(2, 3);
    sccGraph.addEdge(3, 4);
    sccGraph.addEdge(4, 5);
    sccGraph.addEdge(5, 3);
    sccGraph.addEdge(6, 5);
    sccGraph.addEdge(6, 7);
    sccGraph.addEdge(7, 6);

    std::cout << "Graph for SCC test:\n";
    sccGraph.printGraph();

    std::vector<std::vector<int>> sccs = GraphAlgorithms::findStronglyConnectedComponents(sccGraph);

    std::cout << "Strongly Connected Components:\n";
    for (size_t i = 0; i < sccs.size(); i++)
    {
        std::cout << "Component " << i + 1 << ": ";
        for (int vertex : sccs[i])
        {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    testGraphImplementations();
    return 0;
}
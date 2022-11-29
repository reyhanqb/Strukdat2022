#include <iostream>

using namespace std;

class Graph {
   private:
  bool** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
  }

  void toString() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << "\t: ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  ~Graph() {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};

int main() {
    Graph g(21);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 8);
    g.addEdge(6, 7);
    g.addEdge(8, 9);
    g.addEdge(9, 10);
    g.addEdge(10, 11);
    g.addEdge(10, 12);
    g.addEdge(11, 12);
    g.addEdge(11, 15);
    g.addEdge(11, 16);
    g.addEdge(12, 13);
    g.addEdge(12, 15);
    g.addEdge(13, 14);
    g.addEdge(16, 15);
    g.addEdge(16, 17);
    g.addEdge(17, 18);
    g.addEdge(17, 19);
    g.addEdge(19, 1);
    g.addEdge(19, 20);

  g.toString();
}
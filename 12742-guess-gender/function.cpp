#include "function.h"

#include <iostream>

using namespace std;

enum gender { BOY, GIRL, UNKNOWN };

Graph::Graph(int n) {
  numberOfVertices = n;
  vertexInfo = new int[n];
  adjacencyList = new Vertex*[n];
  for (int i = 0; i < n; i++) {
    vertexInfo[i] = UNKNOWN;
    adjacencyList[i] = new Vertex(i);  // dummy_head
  }
}

void Graph::addEdge(int source, int destination) {
  Vertex* ptr = new Vertex(destination);
  // find source adjacencyList
  Vertex* cur = adjacencyList[source];
  // go to the last one
  while (cur->nextVertex != nullptr) cur = cur->nextVertex;
  // last->next = new node
  cur->nextVertex = ptr;
}

bool Graph::dfs(int vertex) {
  if (vertex == this->numberOfVertices) return true;
  Vertex* tmp = this->adjacencyList[vertex];
  
  int* l = vertexInfo;
  if (l[tmp->index] == UNKNOWN) l[tmp->index] = BOY; // default

  while ("Still need working") {
    tmp = tmp->nextVertex;
    if (tmp == NULL) break;
    if (l[tmp->index] == UNKNOWN) l[tmp->index] = (l[vertex] == BOY) ? GIRL : BOY;
    if (l[tmp->index] == l[vertex]) return false;
  }
  return dfs(vertex+1);
}

bool Graph::solver() {
  for (int i = 0; i < numberOfVertices; i++)
    if (dfs(i) == false) return false;
  return true;
}

Graph::~Graph() {
  delete vertexInfo;
  for (int i = 0; i < this->numberOfVertices; i++) delete[] adjacencyList[i];
  delete[] adjacencyList;
}
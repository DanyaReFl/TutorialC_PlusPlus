#include "ListGraph.h"
#include "IGraph.h"
#include "MatrixGraph.h"
#include "TestView.h"


int main() {
    IGraph *matrixGraph = new MatrixGraph;
    IGraph *listGraph = new ListGraph;

    matrixGraph->AddEdge(1, 3);
    matrixGraph->AddEdge(2, 3);
    matrixGraph->AddEdge(3, 0);

    listGraph->AddEdge(2, 3);
    listGraph->AddEdge(1, 3);
    listGraph->AddEdge(3, 0);

    testView(matrixGraph);
    IGraph *listFromMatrix = new ListGraph(matrixGraph);
    testView(listFromMatrix);

    testView(listGraph);
    IGraph *matrixFromList = new MatrixGraph(listGraph);
    testView(matrixFromList);
}

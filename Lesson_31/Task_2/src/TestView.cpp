#include "TestView.h"

void testView(IGraph *graph)
{
    int matrixSize = graph->GetGraph().size();
    for (int i = 0; i < matrixSize; ++i) {
        std::cout << "Vertex (" << i << ") ";
        for (int j = 0; j < graph->GetGraph()[i].size(); ++j) {
            std::cout << graph->GetGraph()[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Vertices Count: " << graph->VerticesCount() << std::endl;

    std::vector<int> outVec;
    graph->GetPrevVertices(3, outVec);
    std::cout << "Prev Vertices: ";
    for (int i : outVec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    outVec.clear();
    graph->GetNextVertices(3, outVec);
    std::cout << "Next Vertices: ";
    for (int i : outVec) {
        std::cout << i << " ";
    }
    std::cout << std::endl ;

}
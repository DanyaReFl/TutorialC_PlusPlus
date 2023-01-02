#include "MatrixGraph.h"


    MatrixGraph::MatrixGraph() {};

    MatrixGraph::MatrixGraph( IGraph *Other)
    {
        std::vector<int> vecNextVertices;
        int maxVertices = Other->MaxVerticesCount();
        graphMatrix.resize(maxVertices, std::vector<int>(maxVertices, 0));

        for (int i = 0; i < maxVertices; ++i)
        {
            Other->GetNextVertices(i, vecNextVertices);

            for (int j = 0, index = 0; j < vecNextVertices.size(); ++j, ++index)
            {
                graphMatrix[i][vecNextVertices[index]] = 1;
            }
            vecNextVertices.clear();
        }
    };


    void MatrixGraph::AddEdge(int from, int to)
    {
        if (from == to) return;

        int maxVertex = std::max(from, to) + 1;
        if (graphMatrix.size() < maxVertex) {
            graphMatrix.resize(maxVertex);
            int matrixSize = graphMatrix.size();

            for (int i = 0; i < matrixSize; ++i) {
                graphMatrix[i].resize(maxVertex, 0);
            }
        }
        graphMatrix[from][to] = 1;
    }

    int MatrixGraph::VerticesCount() const
    {
        int matrixSize = graphMatrix.size();
        int verticesCount = 0;
        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                if (graphMatrix[i][j] > 0) verticesCount++;
            }
        }
        return verticesCount;
    }

    int MatrixGraph::MaxVerticesCount() const
    {
        return graphMatrix.size();
    }

    std::vector<std::vector<int>> MatrixGraph::GetGraph() const
    {
        return graphMatrix;
    }

    void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
    {
        if (vertex > graphMatrix.size())return;

        int listSize = graphMatrix[vertex].size();
        for (int i = 0; i < listSize; ++i) {
            if (graphMatrix[vertex][i] > 0) vertices.push_back(i);
        }
    }

    void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
    {
        if (vertex > graphMatrix.size())return;

        int listSize = graphMatrix[vertex].size();
        for (int i = 0; i < listSize; ++i) {
            if (graphMatrix[i][vertex] > 0) vertices.push_back(i);
        }
    };

    MatrixGraph::~MatrixGraph() {};

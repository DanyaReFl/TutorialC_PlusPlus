#include "ListGraph.h"

    ListGraph::ListGraph(){};

    ListGraph::ListGraph(IGraph *Other)
    {
        std::vector<int> vecNextVertices;
        int maxVertices = Other->MaxVerticesCount();
        graphList.resize(maxVertices);

        for (int i = 0; i < maxVertices; ++i) {
            Other->GetNextVertices(i, vecNextVertices);
            graphList[i].resize(vecNextVertices.size());

            for (int j = 0, index = 0; j < vecNextVertices.size(); ++j, ++index) {
                graphList[i][j] = vecNextVertices[index];
            }
            vecNextVertices.clear();
        }
    }



    void ListGraph::AddEdge(int from, int to)
    {
        int maxVertex = std::max(from, to) + 1;
        if (graphList.size() < maxVertex) {
            graphList.resize(maxVertex);
        }

        graphList[from].push_back(to);
    }

    int ListGraph::VerticesCount() const
    {
        int listSize = graphList.size();
        int verticesCount = 0;
        for (int i = 0; i < listSize; ++i) {
            verticesCount += graphList[i].size();
        }
        return verticesCount;
    }

    int ListGraph::MaxVerticesCount() const
    {
        return graphList.size();
    }

    std::vector<std::vector<int>> ListGraph::GetGraph() const
    {
        return graphList;
    }

    void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
    {
        if (vertex > graphList.size())return;

        int listSize = graphList[vertex].size();
        for (int i = 0; i < listSize; ++i) {
            vertices.push_back(graphList[vertex][i]);
        }
    }

    void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
    {
        if (vertex > graphList.size())return;

        int listSizeY = graphList.size();
        for (int i = 0; i < listSizeY; ++i) {

            int listSizeX = graphList[i].size();
            for (int j = 0; j < listSizeX; ++j) {
                if (graphList[i][j] == vertex) vertices.push_back(i);
            }
        }
    }

    ListGraph::~ListGraph()  {}
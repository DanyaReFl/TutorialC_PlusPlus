#pragma once
#include "IGraph.h"


class ListGraph : public IGraph
{
private:
    std::vector<std::vector<int>> graphList;
    int numberVertex;
public:
    virtual ~ListGraph() override;
    ListGraph();
    ListGraph(IGraph *Other);
    virtual std::vector<std::vector<int>> GetGraph() const override;
    virtual int MaxVerticesCount() const override;
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

};
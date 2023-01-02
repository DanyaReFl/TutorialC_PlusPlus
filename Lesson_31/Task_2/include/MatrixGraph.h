#pragma once
#include "IGraph.h"

class MatrixGraph : public IGraph
{
private:
    std::vector<std::vector<int>> graphMatrix;
public:

    virtual ~MatrixGraph() override;
    MatrixGraph();
    MatrixGraph(IGraph *Other) ;
    virtual int MaxVerticesCount() const override;
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<std::vector<int>> GetGraph() const override;
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
};
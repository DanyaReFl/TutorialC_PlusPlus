#pragma once
#include <vector>
#include <iostream>

class IGraph {
public:
    virtual ~IGraph() {};
    IGraph() {};
    IGraph(IGraph *_oth) {};
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const = 0;
    virtual int MaxVerticesCount() const = 0;
    virtual std::vector<std::vector<int>> GetGraph() const = 0;
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0;
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0;
};
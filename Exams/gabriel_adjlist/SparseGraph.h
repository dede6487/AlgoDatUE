#pragma once

#include<map>
#include<set>
#include<utility>

template <class typeVertex>
class SparseGraph
{
public:
    typedef std::pair<typeVertex,typeVertex> typeEdge;

    bool adjacent(typeVertex v1, typeVertex v2);
    typeVertex* neighbours(typeVertex v); // attention!!! this allocates an array
    void addVertex(typeVertex v);
    void removeVertex(typeVertex v);
    void addEdge(typeEdge e);
    void removeEdge(typeEdge e);
    typeVertex* depthFirstSearch(typeVertex startVertex); // attention!!! this allocates an array
    typeVertex* breadthFirstSearch(typeVertex startVertex); // attention!!! this allocates an array
    void dumpGraph();
private:
    void actualDepthFirstSearch(typeVertex v, std::set<typeVertex>& visited, typeVertex* out, std::size_t &i);
    std::map<typeVertex,std::set<typeVertex>> vertices;
};

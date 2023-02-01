#include <iostream>
#include <queue>

#include "SparseGraph.h"

using namespace std;

template <class typeVertex>
bool SparseGraph<typeVertex>::adjacent(typeVertex v1, typeVertex v2)
{
    set<typeVertex>& v1neighbours = vertices.at(v1); // throws out-of-range if not existing
    return v1neighbours.contains(v2);
}

template <class typeVertex>
typeVertex* SparseGraph<typeVertex>::neighbours(typeVertex v)
{
    set<typeVertex>& vneighbours = vertices.at(v); // throws out-of-range if not existing
    typeVertex* out = new typeVertex[vneighbours.size()];
    size_t i = 0;
    for (const typeVertex& neighbour : vneighbours)
        out[i++] = neighbour;
    return out;
}

template <class typeVertex>
void SparseGraph<typeVertex>::addVertex(typeVertex v)
{
    vertices.try_emplace(v);
}

template <class typeVertex>
void SparseGraph<typeVertex>::removeVertex(typeVertex v)
{
    set<typeVertex>& vneighbours = vertices.at(v); // throws out-of-range if not existing
    for (const typeVertex& neighbour : vneighbours)
        vertices.at(neighbour).erase(v);
    vertices.erase(v);
}

template <class typeVertex>
void SparseGraph<typeVertex>::addEdge(typeEdge e)
{
    typeVertex v1 = e.first;
    typeVertex v2 = e.second;
    vertices.at(v1).insert(v2);
    vertices.at(v2).insert(v1);
}

template <class typeVertex>
void SparseGraph<typeVertex>::removeEdge(typeEdge e)
{
    typeVertex v1 = e.first;
    typeVertex v2 = e.second;
    vertices.at(v1).erase(v2);
    vertices.at(v2).erase(v1);
}

template <class typeVertex>
void SparseGraph<typeVertex>::actualDepthFirstSearch(typeVertex v, set<typeVertex>& visited, typeVertex* out, size_t &i)
{
    if (visited.contains(v))
        return;
    visited.insert(v);
    out[i++] = v;
    set<typeVertex>& vneighbours = vertices.at(v);
    for (const typeVertex& neighbour : vneighbours)
        actualDepthFirstSearch (neighbour, visited, out, i);
}

template <class typeVertex>
typeVertex* SparseGraph<typeVertex>::depthFirstSearch(typeVertex startVertex)
{
    typeVertex* out = new typeVertex[vertices.size()];
    size_t i = 0;
    set<typeVertex> visited;
    actualDepthFirstSearch (startVertex, visited, out, i);
    return out;
}

template <class typeVertex>
typeVertex* SparseGraph<typeVertex>::breadthFirstSearch(typeVertex startVertex)
{
    typeVertex* out = new typeVertex[vertices.size()];
    size_t i = 0;
    set<typeVertex> visited;
    queue<typeVertex> todo;
    todo.push(startVertex);
    while(todo.size() > 0)
    {
        typeVertex v = todo.front();
        todo.pop();
        out[i++] = v;
        set<typeVertex>& vneighbours = vertices.at(v);
        for (const typeVertex& neighbour : vneighbours)
            if (!visited.contains(neighbour))
            {
                visited.insert(neighbour);
                todo.push(neighbour);
            }
    }
    return out;
}

template <class typeVertex>
void SparseGraph<typeVertex>::dumpGraph()
{
    cout << "// this is in Graphviz DOT format, you can make graphviz draw this graph" << endl;
    cout << "strict graph {" << endl;
    for (auto& vertex : vertices)
        cout << "\t" << vertex.first << endl;
    for (auto& vertex : vertices)
        for (auto& neighbour : vertex.second)
            if(vertex.first <= neighbour)
                cout << "\t" << vertex.first << " -- " << neighbour << endl;
    cout << "}" << endl;
}

template class SparseGraph<int>;

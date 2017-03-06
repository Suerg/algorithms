#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include "linked-list.h"

struct Graph_Node
{
    int mValue;
    Node* mEdges;
};

typedef struct Graph_Node Graph_Node;

Graph_addEdge(Graph_Node* node, int value)
{
    LL_insert(node->mEdges, value);
}

#endif /* GRAPH_NODE_H */

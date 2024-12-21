#ifndef NODE_H
#define NODE_H

typedef struct _node* Node;

struct _node{
    int data;
    struct _node* next;
    struct _node* prev;
};

Node node(int data);
void node_print(Node l);
#endif
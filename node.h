#ifndef NODE_H
#define NODE_H

typedef struct _node* Node;

struct _node{
    int data;
    struct _node* next; //Aponta para o nó à direita
    struct _node* prev; //Aponta para o nó à esquerda
};

Node node(int data);
void node_print(Node l);
#endif
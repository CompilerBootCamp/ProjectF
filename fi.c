#include "fi.h"
#include "grammar.tab.h"

void yyerror(char *s)
{
  fprintf(stderr, "%s\n", s);
}


void addNode(Node* dad, Node* child) {
    dad->n += 1;
    dad->nodes = realloc(dad->nodes, sizeof(Node*) * (dad->n));
    dad->nodes[(dad->n - 1)] = child;
    printf("%p <- %p on %d\n", dad, dad->nodes[(dad->n - 1)], (dad->n - 1));
}

Node* newRNode(double v) {
    Node* node = malloc(sizeof(Node));
    node->type = 1;
    node->n = 0;
    node->value = v;
    printf("RNode %p\n", node);
    return node;
}

Node* newINode(int v) {
    Node* node = malloc(sizeof(Node));
    node->type = 1;
    node->n = 0;
    node->value = v;
    printf("INode %p\n", node);
    return node;
}

Node* newBNode(bool v) {
    Node* node = malloc(sizeof(Node));
    node->type = 1;
    node->n = 0;
    node->value = v;
    printf("BNode %p\n", node);
    return node;
}

Node* newNNode() {
    Node* node = malloc(sizeof(Node));
    node->type = 1;
    node->n = 0;
    printf("NNode %p\n", node);
    return node;
}

Node* newANode(char* s) {
    Node* node = malloc(sizeof(Node));
    node->type = 1;
    node->n = 0;
    printf("ANode %p\n with value: %s\n", node, s);
    return node;
}

Node* newLNode() {
    Node* node = malloc(sizeof(Node));
    node->type = 0;
    node->n = 0;
    node->nodes = malloc(sizeof(Node*));
    printf("LNode %p\n", node);
    return node;
}

void print(Node* n) {
    printf("printing %p\n", n);
    printf("type is %d\n", n->type);
    printf("it has %d children:\n", n->n);
    for (int i = 0; i < n->n; ++i) {
        print(n->nodes[i]);
    }
}

Node* yycurrent;

Node* yydrop_node(Node* n) {
    n->n = 0;
    return n;
}

int main()
{
    yycurrent = newLNode();
    yyparse();
}

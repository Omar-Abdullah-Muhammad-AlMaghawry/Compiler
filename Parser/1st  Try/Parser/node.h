#ifndef NODE_H
#define NODE_H

#include "string"
#include "string.h"
#include "vector"
using namespace std;
typedef enum {
    stmt, exp
} type ;
typedef enum {
    IF, THEN, ELSE , END, REPEAT, UNTIL,
    READ, WRITE,
    PLUS, MINUS, MUL, DIVIDE,
    EQUAL, LESSTHAN, GREATERTHAN,
    LEFTBRACKET, RIGHTBRACKET,
    SEMICOLON,
    ASSIGN,
    NUMBER, IDENTIFIER, SPACE
} TokenType;

typedef struct {
    TokenType tt;
    string val;
} TockenRecord;
typedef struct {
    int x;
    int y;
} position ;
//typedef stuct ;

class Node
{
private:
    type nodeType;
    TockenRecord nodeRecord;
    vector<Node * > *  childern = new vector<Node * >();
    Node * myBro= new Node(); //pointer to the next sibling
    position pos;

public:
    Node();
    type getNodeType();
    TockenRecord getNodeRecord();
    void drawNode();
};

#endif // NODE_H

#ifndef NODE_H
#define NODE_H

#include "string"
#include "string.h"
#include "deque"
#include "mainwindow.h"
using namespace std;
typedef enum {
    stmt, expr
} Type ;
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
} Position ;
//typedef stuct ;
extern Position posN ;
class Node
{
private:
    Type nodeType;
    TockenRecord nodeRecord;
    deque<Node * > *  childern = new deque<Node * >();
    Node * myBro= new Node(); //pointer to the next sibling
    Position pos;

public:
    Node();
    Node(Type type, TockenRecord tockenRecord, deque<Node * > *  childern,Position pos);
    Node(Type type, TockenRecord tockenRecord, Position pos);
    Node::Node (Type type, TockenRecord tockenRecord);
    void setType(Type type);
    void setTockenRecord(TockenRecord tockenRecord);
    void setChild(Node * child);
    void setMyBro(Node * bro);
    void setPos(Position p);
    Type getType();
    TockenRecord getTockenRecord();
    Node *getChild();
    Node *getMyBro();
    Position getPos(); 
    void drawNode(Node * node);

    void
};

#endif // NODE_H

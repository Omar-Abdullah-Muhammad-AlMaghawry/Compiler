#include "node.h"
Position posN ={90,190};
queue<TockenRecord> tokenQueue;

//Node::Node()
//{

//}
Node::Node (Type type, TockenRecord tockenRecord, deque<Node * > *  childern,Position pos){
    this->nodeType = type;
    this->nodeRecord = tockenRecord;//val = tocken (read)+ "\n" +"("+tocken(x)+")"
    this->childern = childern;
    this->pos = pos;
//    drawNode(this);
}
Node::Node (Type type, TockenRecord tockenRecord,Position pos){
    this->nodeType = type;
    this->nodeRecord = tockenRecord;
    this->pos =pos;
//    drawNode(this);
}
Node::Node (Type type, TockenRecord tockenRecord){
    this->nodeType = type;
    this->nodeRecord = tockenRecord;
//    drawNode(this);
}
void Node::setType(Type type){
    this->nodeType = type;
}
void Node::setTockenRecord(TockenRecord tockenRecord){
    this->nodeRecord = tockenRecord;
}
void Node::setChild(Node * child){
    this->childern->push_back(child);
}
void Node::setMyBro(Node * bro){
    this->myBro = bro;
}
void Node::setPos(Position p){
    this->pos=p;
//    drawNode(this);
}
Type Node::getType(){
    return nodeType;
}
TockenRecord Node::getTockenRecord(){
    return nodeRecord;
}
Node * Node::getChild(){
    Node * temp= childern->front();
    childern->pop_front();
    return temp;
}
int Node::getNumChildren(){
    return childern->size();
}
Node *  Node::getMyBro(){
    return myBro;
}
Position Node::getPos(){
    return pos;
}



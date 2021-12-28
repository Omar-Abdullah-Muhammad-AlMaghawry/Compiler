#include "proc.h"

Node * writeStmt(){
    Node * tempNode;
    tempNode = new Node(stmt, token,posN);
    match(WRITE);
    tempNode->setChild(exp());
    return tempNode;
}
Node * exp(){
    Node *  tempNode, *newTempNode;
    tempNode = simpleExp();
    if(token.val == "<"||token.val == "="){
        newTempNode = new Node(expr,{token.tt,"op\n("+token.val+")"},posN);//token
        match();
        newTempNode->setChild(tempNode);
        newTempNode->setChild(simpleExp());
        tempNode = newTempNode;
    }
    return tempNode;
}
Node * comparisonOp(){

}
Node * simpleExp(){
    Node * tempNode,*newTempNode;
//    tempNode = new Node(expr, token);//,{posN.x-30,posN.y+60}
//    match();
    tempNode = term();
    //parent = tempNode;
    while(token.tt == PLUS|| token.tt  == MINUS){
        newTempNode = new Node(stmt,{token.tt,"op\n("+token.val+")"},{posN});//token
        if (token.tt == PLUS)
            match(PLUS);
        else if(token.tt == MINUS)
            match(MINUS);
        tempNode->setPos({posN.x+30,posN.y});
        newTempNode->setChild(tempNode);
        newTempNode->setChild(term());
//        newTempNode->setChild(new Node(expr,token,{posN.x+60,posN.y}));
//        match();
        tempNode= newTempNode;
    }
    return tempNode; //or parent =  newTempNode
}
Node * term(){
    Node * tempNode,*newTempNode;
//    tempNode = new Node(expr, token);//,{posN.x-30,posN.y+60}
//    match();
    tempNode = factor();
    //parent = tempNode;
    while(token.tt == MUL|| token.tt  == DIVIDE){
        newTempNode = new Node(stmt,{token.tt,"op\n("+token.val+")"},{posN});//
        if (token.tt == MUL)
            match(MUL);
        else if(token.tt == DIVIDE)
            match(DIVIDE);
        tempNode->setPos({posN.x+30,posN.y});
        newTempNode->setChild(tempNode);
//        newTempNode->setChild(new Node(expr,token,{posN.x+60,posN.y}));
//        match();
        newTempNode->setChild(factor());
        tempNode= newTempNode;
    }
    return tempNode; //or parent =  newTempNode
}
Node * factor(){
    Node* out;
    switch(token.tt){
        case NUMBER:
            out = new Node(Type::expr,{NUMBER,"const\n("+token.val+")"},posN);
            match(NUMBER);
            return out;
            break;
         case IDENTIFIER:
        out = new Node(Type::expr,{IDENTIFIER,"id\n("+token.val+")"},posN);
        match(IDENTIFIER);
        return out;
            break;
        case LEFTBRACKET:
            match(LEFTBRACKET);
            out= exp();
            match(TokenType::RIGHTBRACKET);
            return out;
            break;

    }
}

#include "prec.h"

Node * writeStmt(){
    Node * tempNode;
    tempNode = new Node(stmt, token,posN);
    tempNode->setChild(exp());
    return tempNode;
}
Node * exp(){
    Node *  tempNode, *newTempNode;
    tempNode = simpleExp();
    if(token.val == "<"||token.val == "="){
        newTempNode = new Node(expr,token,posN);
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
    tempNode = new Node(expr, token);//,{posN.x-30,posN.y+60}
    match();
    //parent = tempNode;
    while(token.val == "+"|| token.val  == "-"){
        newTempNode = new Node(stmt,token,{posN});
        if (token.val == "+")
            match("+");
        else if(token.val == "-")
            match("-");
        tempNode->setPos({posN.x+30,posN.y});
        newTempNode->setChild(tempNode);
        newTempNode->setChild(new Node(expr,token,{posN.x+60,posN.y}));
        match();
        tempNode= newTempNode;
    }
    return tempNode; //or parent =  newTempNode
}
Node * term(){
    Node * tempNode,*newTempNode;
    tempNode = new Node(expr, token);//,{posN.x-30,posN.y+60}
    match();
    //parent = tempNode;
    while(token.val == "*"|| token.val  == "/"){
        newTempNode = new Node(stmt,token,{posN});
        if (token.val == "*")
            match("*");
        else if(token.val == "/")
            match("/");
        tempNode->setPos({posN.x+30,posN.y});
        newTempNode->setChild(tempNode);
        newTempNode->setChild(new Node(expr,token,{posN.x+60,posN.y}));
        match();
        tempNode= newTempNode;
    }
    return tempNode; //or parent =  newTempNode
}
Node * factor(){

}

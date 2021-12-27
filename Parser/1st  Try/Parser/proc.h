#ifndef PROC_H
#define PROC_H
#include "node.h"
#include "matchfn.h"
#include "tokenparser.h"
Node * addOp();
Node * mulOP();

Node * writeStmt();
Node * exp();
Node * comparisonOp();
Node * simpleExp();
Node * term();
Node * factor();


#endif // PROC_H

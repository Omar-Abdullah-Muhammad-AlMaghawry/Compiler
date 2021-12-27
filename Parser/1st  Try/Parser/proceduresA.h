#ifndef PROCEDURESA_H
#define PROCEDURESA_H

#include "node.h"
#include "tokenparser.h"
#include "matchfn.h"
//include the procedures made by omar

void program_proc();
Node* stmtSeq_proc();
Node* stmt_proc();
Node* if_proc();
Node* repeat_proc();
Node* assign_proc();
Node* read_proc();

#endif
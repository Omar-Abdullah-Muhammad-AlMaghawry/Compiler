#ifndef PROCEDURESA_H
#define PROCEDURESA_H

#include "node.h"
#include "tokenparser.h"
#include "matchfn.h"
//include the procedures made by omar
#include "proc.h"
void program_proc();
Node* stmtSeq_proc();
<<<<<<< HEAD
Node *stmt_proc();
=======
Node* stmt_proc();
>>>>>>> a1b36700f5aebebc7a73ac9c6a9b996741e0b964
Node* if_proc();
Node* repeat_proc();
Node* assign_proc();
Node* read_proc();

#endif

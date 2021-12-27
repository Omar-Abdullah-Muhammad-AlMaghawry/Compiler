#ifndef MATCHFN_H
#define MATCHFN_H

#include "node.h"
#include "string"
#include "tokenparser.h"
#include"mainwindow.h"

extern TockenRecord token;
bool match(TokenType expectedToken);
void match();
#endif

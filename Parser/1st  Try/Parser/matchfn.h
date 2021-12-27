#ifndef MATCHFN_H
#define MATCHFN_H

#include "node.h"
#include "string"
#include "tokenparser.h"

extern TockenRecord token;
bool match(TokenType expectedToken);

#endif

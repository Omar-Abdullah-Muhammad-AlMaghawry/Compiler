#ifndef TOKENPARSER_H
#define TOKENPARSER_H

#include "string"
#include "queue"
#include "node.h"

extern queue<TockenRecord> tokenQueue;
void parseScannerOutput(string code);

#endif
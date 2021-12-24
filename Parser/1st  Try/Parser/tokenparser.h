#ifndef TOKENPARSER_H
#define TOKENPARSER_H

#include "string"
#include "queue"
#include "node.h"

queue<TockenRecord> parseScannerOutput(string code);

#endif
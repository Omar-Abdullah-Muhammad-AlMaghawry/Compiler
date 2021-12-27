#include "tokenparser.h"

queue<TockenRecord> tokenQueue;

void parseScannerOutput(string code) {
	queue<TockenRecord> res;
	for (int i = 0; i < code.length(); i++) {
		TockenRecord temp;
		string tempType = "";
		while (code[i] != ',' && i < code.length()) {
			temp.val += (code[i]);
			i++;
		}
		if (i < code.length()) i++;

		while (code[i] != '\n' && i < code.length()) {
			tempType += (code[i]);
			i++;
		}

		if (tempType == "IF") temp.tt = IF;
		else if (tempType == "THEN") temp.tt = THEN;
		else if (tempType == "ELSE") temp.tt = ELSE;
		else if (tempType == "END") temp.tt = END;
		else if (tempType == "REPEAT") temp.tt = REPEAT;
		else if (tempType == "UNTIL") temp.tt = UNTIL;
		else if (tempType == "READ") temp.tt = READ;
		else if (tempType == "WRITE") temp.tt = WRITE;
		else if (tempType == "PLUS") temp.tt = PLUS;
		else if (tempType == "MINUS") temp.tt = MINUS;
		else if (tempType == "MULT") temp.tt = MUL;
		else if (tempType == "DIV") temp.tt = DIVIDE;
		else if (tempType == "EQUAL") temp.tt = EQUAL;
		else if (tempType == "LESSTHAN") temp.tt = LESSTHAN;
		else if (tempType == "GREATERTHAN") temp.tt = GREATERTHAN;
		else if (tempType == "OPENBRACKET") temp.tt = LEFTBRACKET;
		else if (tempType == "CLOSEDBRACKET") temp.tt = RIGHTBRACKET;
		else if (tempType == "SENICOLON") temp.tt = SEMICOLON;
		else if (tempType == "ASSIGN") temp.tt = ASSIGN;
		else if (tempType == "NUMBER") temp.tt = NUMBER;
		else if (tempType == "IDENTIFIER") temp.tt = IDENTIFIER;
		else if (tempType == "SPACE") temp.tt = SPACE;

		res.push(temp);
	}

	tokenQueue = res;
}

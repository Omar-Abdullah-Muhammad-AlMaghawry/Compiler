#include "tokenparser.h"

queue<TockenRecord> tokenQueue;

void parseScannerOutput(string code){
	queue<TockenRecord> res;
	TockenRecord temp;
	string tempType = "";
	for(int i = 0; i < code.length(); i++){
		while(code[i] != ',' && i < code.length()){
			temp.val += (code[i]);
			i++;
		}
		if(i < code.length()) i++;
		
		while(code[i] != '\n' && i < code.length()){
			tempType += (code[i]);
			i++;
		}
		if(i < code.length()) i++;
		
		if(tempType.c_str() == "IF") temp.tt = IF;
		else if(tempType.c_str() == "THEN") temp.tt = THEN;
		else if(tempType.c_str() == "ELSE") temp.tt = ELSE;
		else if(tempType.c_str() == "END") temp.tt = END;
		else if(tempType.c_str() == "REPEAT") temp.tt = REPEAT;
		else if(tempType.c_str() == "UNTIL") temp.tt = UNTIL;
		else if(tempType.c_str() == "READ") temp.tt = READ;
		else if(tempType.c_str() == "WRITE") temp.tt = WRITE;
		else if(tempType.c_str() == "PLUS") temp.tt = PLUS;
		else if(tempType.c_str() == "MINUS") temp.tt = MINUS;
		else if(tempType.c_str() == "MULT") temp.tt = MUL;
		else if(tempType.c_str() == "DIV") temp.tt = DIVIDE;
		else if(tempType.c_str() == "EQUAL") temp.tt = EQUAL;
		else if(tempType.c_str() == "LESSTHAN") temp.tt = LESSTHAN;
		else if(tempType.c_str() == "GREATERTHAN") temp.tt = GREATERTHAN;
		else if(tempType.c_str() == "OPENBRACKET") temp.tt = LEFTBRACKET;
		else if(tempType.c_str() == "CLOSEDBRACKET") temp.tt = RIGHTBRACKET;
		else if(tempType.c_str() == "SENICOLON") temp.tt = SEMICOLON;
		else if(tempType.c_str() == "ASSIGN") temp.tt = ASSIGN;
		else if(tempType.c_str() == "NUMBER") temp.tt = NUMBER;
		else if(tempType.c_str() == "IDENTIFIER") temp.tt = IDENTIFIER;
		else if(tempType.c_str() == "SPACE") temp.tt = SPACE;
		
		res.push(temp);
	}

	tokenQueue = res;
}

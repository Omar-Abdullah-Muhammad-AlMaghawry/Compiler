#include "matchfn.h";

TockenRecord token;

bool match(TokenType expectedToken){
	if(expectedToken == token.tt){
		tokenQueue.pop();
		token = tokenQueue.front();
		return true;
	}
	else return false;
}
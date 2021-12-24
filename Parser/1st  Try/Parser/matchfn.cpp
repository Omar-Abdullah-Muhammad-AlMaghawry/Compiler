#include "matchfn.h";

TockenRecord token;

bool match(string expectedToken){
	if(expectedToken == token.val){
		token = tokenQueue.front();
		tokenQueue.pop();
		return true;
	}
	else return false;
}
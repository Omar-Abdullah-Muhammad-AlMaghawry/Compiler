#include "matchfn.h";

TockenRecord token;

bool match(TokenType expectedToken){
    if(expectedToken == token.tt){
        token = tokenQueue.front();
        tokenQueue.pop();
        token = tokenQueue.front();
        return true;
    }
    else return false;
}
void match(){
    tokenQueue.pop();
    token =tokenQueue.front();
}

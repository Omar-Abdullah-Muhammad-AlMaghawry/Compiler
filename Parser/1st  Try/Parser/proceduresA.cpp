#include "proceduresA.h"


//Positions are implemented as a global variable


void program_proc(){
	stmtSeq_proc();
}

Node* stmtSeq_proc(){
	Node* first = stmt_proc();
<<<<<<< HEAD
    Node * nextBro = first;
	while(token.tt == SEMICOLON){
        match(SEMICOLON);
		Node* temp = stmt_proc();
        nextBro->setMyBro(temp);

        nextBro = nextBro->getMyBro();
=======
	Node * nextBro = first;
	while(token.tt == SEMICOLON){
		match(SEMCIOLON);
		Node* temp = stmt_proc();
		nextBro->setMyBro(&temp);
		nextBro = nextBro->getMyBro();
>>>>>>> a1b36700f5aebebc7a73ac9c6a9b996741e0b964
	}
	return first;
}

Node* stmt_proc(){
	switch (token.tt){
	case IF:
		return if_proc();
		break;
	case REPEAT:
		return repeat_proc();
		break;
	case ASSIGN:
		return assign_proc();
		break;
	case READ:
		return read_proc();
		break;
	case WRITE:
        return writeStmt();
		break;
	}
}

Node* if_proc(){
	Node* if_node = new Node(Type::stmt, token, posN);
	match(IF);
	if_node->setChild(exp()); 
	match(THEN);
	if_node->setChild(stmtSeq_proc());
	if(token.tt == ELSE){
		match(ELSE);
		if_node->setChild(stmtSeq_proc()); 
	}
	match(END);
	return if_node;
}

Node* repeat_proc(){
    Node* repeat_node = new Node(Type::stmt, token, posN);
	match(REPEAT);
	repeat_node->setChild(stmtSeq_proc());
	match(UNTIL);
	repeat_node->setChild(exp());
    return repeat_node;
}

Node* assign_proc(){
    Node* identifier = new Node(Type::stmt, token, posN);
	match(IDENTIFIER);
	match(ASSIGN);
<<<<<<< HEAD
    identifier->setChild(exp());
=======
	identifier->setChild(exp());
>>>>>>> a1b36700f5aebebc7a73ac9c6a9b996741e0b964
	return identifier;
}

Node* read_proc(){
    Node* read = new Node(Type::stmt, token, posN);
	match(READ);
    Node* identifier = new Node(Type::stmt, token, posN);
	match(IDENTIFIER);
	read->setChild(identifier);
	return read;
}

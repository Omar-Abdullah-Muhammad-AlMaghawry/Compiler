#include "iostream"
#include "stdio.h"
#include "string"
#include "stack"
#include "queue"
#include "deque"
#include <fstream>

using namespace std;

typedef enum {
	IF, THEN, ELSE , END, REPEAT, UNTIL,
	READ, WRITE,
	PLUS, MINUS, MUL, DIVIDE,
	EQUAL, LESSTHAN, GREATERTHAN,
	LEFTBRACKET, RIGHTBRACKET,
	SEMICOLON,
	ASSIGN,
	NUMBER, IDENTIFIER, SPACE
} TokenType;

typedef struct {
	TokenType tt;
	string val;
} TockenRecord;


queue<TockenRecord> *  getToken(deque<char> * input ) {
	TokenType type;
	deque <char> ::iterator it;
	queue<TockenRecord>* output =new queue<TockenRecord>;
	bool token = false;
	string out ="";

	int i = 0;
	while (!input->empty()) {
		out = "";
		if (input->front() == ' '|| input->front() == '\n'||input->front() == '\t') {
			while (!input->empty() && (input->front() == ' ' || input->front() == '\n' || input->front() == '\t'))
			{
				input->pop_front();
			}
		}
		else if (input->front() == '{') {
			input->pop_front();
			while (!input->empty() && input->front() != '}')
			{
				input->pop_front();

			}
			input->pop_front();
		}
		else if (input->front() == '+') {
			input->pop_front();
			output->push({PLUS,"+"});
		}
		else if (input->front() == '-') {
			input->pop_front();
			output->push({ MINUS,"-" });
		}
		else if (input->front() == '*') {
			input->pop_front();
			output->push({ MUL,"*"});
		}
		else if (input->front() == '/') {
			input->pop_front();
			output->push({ DIVIDE ,"/"});
		}
		else if (input->front() == '=') {
			input->pop_front();
			output->push({ EQUAL,"=" });
		}
		else if (input->front() == '<') {
			input->pop_front();
			output->push({ LESSTHAN,"<" });
		}
		else if (input->front() == '>') {
			input->pop_front();
			output->push({ GREATERTHAN,">" });
		}
		else if (input->front() == ';') {
			input->pop_front();
			output->push({ SEMICOLON,";" });
		}
		else if (input->front() == '(') {
			input->pop_front();
			output->push({ LEFTBRACKET,"(" });
		}
		else if (input->front() == ')') {
			input->pop_front();
			output->push({ RIGHTBRACKET,")" });
		}
		else if (input->front() == ':') {
			it = input->begin();			
			if (*++it == '=') {
				for (int i = 0; i < 2; i++)
					input->pop_front();;
				output->push({ ASSIGN,":=" });
			}
			
		}
		else if (isdigit(input->front())) {
			out = "";
			while (!input->empty() && isdigit(input->front()))
			{
				out += input->front();
				input->pop_front();
			}
			output->push({ NUMBER,out });
		}
		else if (isalpha(input->front())) {

			
				if (!token && input->front() == 'i')
				{
					it = input->begin();

					if (*++it == 'f')
					{
						for (int i = 0; i < 2; i++)
							input->pop_front();
						output->push({ IF,"if" });
						token = true;
					}
				}
				if (!token && input->front() == 't')
				{
					it = input->begin();
					if (*++it == 'h')
					{
						if (*++it == 'e')
						{
							if (*++it == 'n')
							{
								for (int i = 0; i < 4; i++)
									input->pop_front();
								output->push({ THEN,"then" });
								token = true;
							}
						}
					}
				}
				if (!token && input->front() == 'e')
				{
					it = input->begin();
					if (*(++it) == 'l')
					{
						if (*(++it) == 's')
						{
							if (*(++it) == 'e')
							{
								for (int i = 0; i < 4; i++)
									input->pop_front();
								output->push({ ELSE,"else" });
								token = true;
							}
						}
					}
				}
				if (!token && input->front() == 'e')
				{
					it = input->begin();
					if (*(++it) == 'n')
					{
						if (*(++it) == 'd')
						{
							for (int i = 0; i < 3; i++)
								input->pop_front();
							output->push({ END,"end" });
							token = true;
						}
						
					}
					
				}
				if (!token && input->front() == 'r')
				{
					it = input->begin();
					
					if (*(++it) == 'e')
					{
						if (*(++it) == 'p')
						{
							if (*(++it) == 'e')
							{
								if (*(++it) == 'a')
								{
									if (*(++it) == 't')
									{
										for(int i = 0; i<6;i++)
											input->pop_front();
										output->push({ REPEAT,"repeat" });
										token = true;
									}
									
								}
								
							}
							
						}
						
					}
					
				}
				if (!token && input->front() == 'u')
				{
					it = input->begin();
					if (*(++it) == 'n')
					{
						if (*(++it) == 't')
						{
							if (*(++it) == 'i')
							{
								if (*(++it) == 'l')
								{
									for (int i = 0; i < 5; i++)
										input->pop_front();
									output->push({ UNTIL,"until" });
									token = true;
								}
							}
						}
					}
				}
				if (!token && input->front() == 'r')
				{
					it = input->begin();
					if (*(++it) == 'e')
					{
						if (*(++it) == 'a')
						{
							if (*(++it) == 'd')
							{
								for (int i = 0; i < 4; i++)
									input->pop_front();
								output->push({ READ,"read" });
								token = true;
							}
						}
					}
				}
				if (!token && input->front() == 'w')
				{
					it = input->begin();
					if (*(++it) == 'r')
					{
						if (*(++it) == 'i')
						{
							if (*(++it) == 't')
							{
								if (*(++it) == 'e')
								{

									for (int i = 0; i < 5; i++)
										input->pop_front();
									output->push({ WRITE,"write" });
									token = true;
								}
							}
						}
					}
				}
				if(!token) {
					out = "";
					while (!input->empty() && isalpha(input->front()))
					{
						out += input->front();
						input->pop_front();
					}
					output->push({ IDENTIFIER,out });
				}
				token = false;


		}
	}
	return output;
}


int main() {
	string theCode ="";
	deque<char>* inputQueue=new deque<char>;
	queue<TockenRecord>* outputQueue=new queue<TockenRecord>;
	string pathOfInput = "";
	string pathOfOutput = "";

	//read from file
	cout << "write the path of your input file that contain the code : ";
	cin >> pathOfInput;
	cout << endl;
	ifstream input(pathOfInput);


	//create and open a text file
	cout << "write the path of your output file that contain the code : ";
	cin >> pathOfOutput;
	cout << endl;
	ofstream outputFile(pathOfOutput);

	while (getline(input, theCode)) {
		for (int i = 0; i< theCode.length(); i++) {
			inputQueue->push_back(theCode[i]);
		}
	}

	outputQueue = getToken(inputQueue);

	while (!outputQueue->empty())
	{
		switch ((outputQueue->front()).tt){
			case IF:
				outputFile << (outputQueue->front()).val << "," << "IF" << "\n";
				break;
			case THEN:
				outputFile << (outputQueue->front()).val << "," << "THEN" << "\n";
				break;
			case ELSE:
				outputFile << (outputQueue->front()).val << "," << "ELSE" << "\n";
				break;
			case END:
				outputFile << (outputQueue->front()).val << "," << "END" << "\n";
				break;
			case REPEAT:
				outputFile << (outputQueue->front()).val << "," << "REPEAT" << "\n";
				break;
			case UNTIL:
				outputFile << (outputQueue->front()).val << "," << "UNTIL" << "\n";
				break;
			case READ:
				outputFile << (outputQueue->front()).val << "," << "READ" << "\n";
				break;
			case WRITE:
				outputFile << (outputQueue->front()).val << "," << "WRITE" << "\n";
				break;
			case PLUS:
				outputFile << (outputQueue->front()).val << "," << "PLUS" << "\n";
				break;
			case MINUS: 
				outputFile << (outputQueue->front()).val << "," << "MINUS" << "\n";
				break;
			case MUL:
				outputFile << (outputQueue->front()).val << "," << "MULT" << "\n";
				break;
			case DIVIDE:
				outputFile << (outputQueue->front()).val << "," << "DIV" << "\n";
				break;
			case EQUAL:
				outputFile << (outputQueue->front()).val << "," << "EQUAL" << "\n";
				break;
			case LESSTHAN:
				outputFile << (outputQueue->front()).val << "," << "LESSTHAN" << "\n";
				break;
			case GREATERTHAN:
				outputFile << (outputQueue->front()).val << "," << "GREATERTHAN" << "\n";
				break;
			case LEFTBRACKET:
				outputFile << (outputQueue->front()).val << "," << "OPENBRACKET" << "\n";
				break;
			case RIGHTBRACKET:
				outputFile << (outputQueue->front()).val << "," << "CLOSEDBRACKET" << "\n";
				break;
			case SEMICOLON:
				outputFile << (outputQueue->front()).val << "," << "SEMICOLON" << "\n";
				break;
			case ASSIGN:
				outputFile << (outputQueue->front()).val << "," << "ASSIGN" << "\n";
				break;
			case NUMBER:
				outputFile << (outputQueue->front()).val << "," << "NUMBER" << "\n";
				break;
			case IDENTIFIER:
				outputFile << (outputQueue->front()).val << "," << "IDENTIFIER" << "\n";
				break;
		}
		outputQueue->pop();
	}

	return 0;
}
//
//TokenType getToken(string next) {
//	string input = "";
//	getline(cin, input);
//	TokenType type;
//
//	int i = 0;
//	
//		if (input[i] == ' ') {
//			while (input[i] == ' ')
//			{
//				i++;
//				if (input[i] == '\0')
//					break;
//			}
//			type = SPACE;
//
//		}
//		else if (input[i] == '-') {
//			return MINUS;
//		}
//		else if (input[i] == '*') {
//			return MUL;
//		}
//		else if (input[i] == '/') {
//			return DIVIDE;
//		}
//		else if (input[i] == '=') {
//			return EQUAL;
//		}
//		else if (input[i] == '<') {
//			return LESSTHAN;
//		}
//		else if (input[i] == '>') {
//			return GREATERTHAN;
//		}
//		else if (input[i] == ';') {
//			return SEMICOLON ;
//		}
//		else if (input[i] == ';') {
//			return SEMICOLON;
//		}
//		else if (isdigit(input[i])) {
//			while (isdigit(input[i]))
//			{
//				i++;
//				if (input[i] == '\0')
//					break;
//			}
//			return NUMBER;
//		}
//		else if (isalpha(input[i])) {
//			
//			while (isalpha(input[i]))
//			{
//				if (input[i] == 'i')
//				{
//					i++;
//					if (input[i] == 'f')
//					{
//						return IF;
//					}
//				} else if (input[i] == 't')
//				{
//					i++;
//					if (input[i] == 'h')
//					{
//						i++;
//						if (input[i] == 'e')
//						{
//							i++;
//							if (input[i] == 'n')
//							{
//								return THEN;
//							}
//						}
//					}
//				}
//				else if (input[i] == 'e')
//				{
//					i++;
//					if (input[i] == 'l')
//					{
//						i++;
//						if (input[i] == 's')
//						{
//							i++;
//							if (input[i] == 'e')
//							{
//								return THEN;
//							}
//						}
//					}
//				}
//				else if (input[i] == 'e')
//				{
//					i++;
//					if (input[i] == 'n')
//					{
//						i++;
//						if (input[i] == 'd')
//						{
//								return END;
//						}
//					}
//				}
//				else if (input[i] == 'r')
//				{
//					i++;
//					if (input[i] == 'e')
//					{
//						i++;
//						if (input[i] == 'p')
//						{
//							i++;
//							if (input[i] == 'e')
//							{
//								i++;
//								if (input[i] == 'a')
//								{
//									i++;
//									if (input[i] == 't')
//									{
//										return REPEAT;
//									}
//								}
//							}
//						}
//					}
//				}
//				else if (input[i] == 'u')
//				{
//					i++;
//					if (input[i] == 'n')
//					{
//						i++;
//						if (input[i] == 't')
//						{
//							i++;
//							if (input[i] == 'i')
//							{
//								i++;
//								if (input[i] == 'l')
//								{
//									
//									return UNTIL;
//									
//								}
//							}
//						}
//					}
//				}
//				else if (input[i] == 'r')
//				{
//					i++;
//					if (input[i] == 'e')
//					{
//						i++;
//						if (input[i] == 'a')
//						{
//							i++;
//							if (input[i] == 'd')
//							{
//								return READ;
//							}
//						}
//					}
//				}
//				else if (input[i] == 'w')
//				{
//					i++;
//					if (input[i] == 'r')
//					{
//						i++;
//						if (input[i] == 'i')
//						{
//							i++;
//							if (input[i] == 't')
//							{
//								i++;
//								if (input[i] == 'e')
//								{
//
//									return WRITE;
//
//								}
//							}
//						}
//					}
//				}
//				i++;
//				if (input[i] == '\0')
//					break;
//			}
//			type = NUMBER;
//		}
//	
//}
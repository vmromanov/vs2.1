#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
enum TokenType
{
	DIGIT,
	LETTER,
	SPACE,
	ARIFMETIC_OPERATION,
	RELATIONSHIP,
	COMMENT,
	ERROR,
	COMMA,
	L_SQ_BR,
	R_SQ_BR,
	SEMI_COLON,
	PUSH,
	POP,
	JMP,
	JI,
	READ,
	WRITE,
	END_MARKER,
	ENDL,
	END_OF_FILE
};

enum Relation
{
	EQUAL,
	NOT,
	NEQ,
	LESS,
	MORE,
	NOT_EQUAL,
	LEQ,		//<=
	MEQ			//>=
};

enum States
{
	A1,A2,A3,A4,
	K,
	O,
	M,M1,
	P,
	ER,
	Stop
};

// ������� ����������
struct TableVariable
{
	map<string, int> array;
	int size;
	int capacity;
};

//�������
struct SymbolicToken
{
	TokenType Class;
	int value;
	int number_line;
};

//������� ������
struct TableToken
{
	SymbolicToken* arr;
	int size;
	int capacity;
};

SymbolicToken transliterator(int ch)
{
	SymbolicToken s;
	s.value = 0;
	if (isdigit(ch))
	{
		s.Class = DIGIT;
		s.value = ch - '0';
	}
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
	{
		s.Class = ARIFMETIC_OPERATION;
		s.value = ch;
	}
	else if (ch == ' ' || ch == '\t')
	{
		s.Class = SPACE;
	}
	else if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
	{
		s.Class = LETTER;
		s.value = ch;
	}
	else if (ch == ';')
	{
		s.Class = SEMI_COLON;
		s.value = ch;
	}
	else if (ch == '<')
	{
		s.Class = RELATIONSHIP;
		s.value = LESS;
	}
	else if (ch == '>')
	{
		s.Class = RELATIONSHIP;
		s.value = MORE;
    }
	else if (ch == '=')
	{
		s.Class = RELATIONSHIP;
		s.value = EQUAL;
    }
	else if (ch == '!')
	{
		s.Class = RELATIONSHIP;
		s.value = NOT;
	}
	else if (ch == '\n')
	{
		s.Class = ENDL;
		s.value = ch;
	} 
	else if (ch == EOF) 
	{
		s.Class = END_OF_FILE; 
	}
	else if (ch == ',')
	{
		s.Class = COMMA;
		s.value = ch;
	}
	else if (ch == '[')
	{
		s.Class = L_SQ_BR;
		s.value = ch;
	}
	else if (ch == ']')
	{
		s.Class = R_SQ_BR;
		s.value = ch;
	}
	else 
	{
		s.Class = ERROR;
	}
	return s;
}

struct KeywordDetection
{
	int table_first_vector[5][2]
	{
	   {(int)'e', 0 },
	   {(int)'j', 2 },
	   {(int)'p', 5 },
	   {(int)'r', 10 },
	   {(int)'w', 13 }
	};

	int table_detection[17][2]
	{
	   {(int)'n',  -1},
	   {(int)'d',  -1},
	   {(int)'i',  3},
	   {(int)'m',  -1},
	   {(int)'p',  -1},
	   {(int)'o',  7},
	   {(int)'p',  -1},
	   {(int)'u',  -1},
	   {(int)'s',  -1},
	   {(int)'h',  -1},
	   {(int)'e',  -1},
	   {(int)'a',  -1},
	   {(int)'d',  -1},
	   {(int)'r',  -1},
	   {(int)'i',  -1},
	   {(int)'t',  -1},
	   {(int)'e',  -1}
	};
};

void Expansion(TableToken array)
{
	if (array.arr == nullptr)
	{
		array.arr = new SymbolicToken[100];
		array.size = 0;
		array.capacity = 100;
		return;
	}
	SymbolicToken* tmp = new SymbolicToken[2 * array.capacity];
	array.capacity *= 2;

	for (int i = 0; i < array.size; i++)
	{
		tmp[i] = array.arr[i];
	}
	delete[] array.arr;

	array.arr = tmp;
}

void Push_Back(TableToken table_tokens, SymbolicToken token)
{
	if (table_tokens.size = table_tokens.capacity)
		Expansion(table_tokens);
	table_tokens.arr[table_tokens.size] = token;
	table_tokens.size++;
}

void Create_Token(TokenType& register_type_token, int& register_value, int& register_relationship, int& number_line, TableToken& array)
{
	SymbolicToken result;

	if (register_type_token == TokenType::RELATIONSHIP)
		result.value = register_relationship;
	else
		result.value = register_value;
	result.Class = register_type_token;
	result.number_line = number_line;

	Push_Back(array, result);
}

void Add_Var(map<string, int>& table_variable, string register_variable, int*& register_indicator)
{
	if (table_variable.find(register_variable) == table_variable.end())
	{
		table_variable[register_variable] = 0;
	}
}

void Error_Handler(TokenType& register_type_token, int& register_value, int& register_relationship,\
	int& number_line, TableToken& array, int& state)
{
	register_type_token = TokenType::ERROR;
	Create_Token(register_type_token, register_value, register_relationship, number_line, array);
	cerr << "An error was found in " << number_line<< " line";
	state = ER;
}

void Lexical_Analyzer(const char* filename)
{
	ifstream file(filename);
	if (!file)
	{
		cout << "�� ������� ������� ���� " << filename << endl;
		return;
	}

	//������� ����������
	map<string, int> table_variable;

	//������� ������ ��� ������
	TableToken table_tokens;

	//������� ������ ������ ��� �������� ������ �������
	TokenType register_type_token;

	//������� ����� ������������ ��� ���������� ��������
	int register_number;

	//������� ��������� ������ ���������� � ������ ������� ���������
	int register_relationship;

	//������� ���������� ����������� ��� ����������
	string register_variable;

	//������� ����������� ������ ����� ������� � ������� ����������� ��� ������ �������� ����
	int register_detection;

	//������� �������� ������ �������� ������
	int register_value;

	//����� ������ ������ ����� ������� ������ � ���������
	int number_line = 0;

	int state = A1;

	while (state != Stop)
	{
		int character = file.get();
		SymbolicToken token = transliterator(character);

		switch (state)
		{

			////////////////////////////////////////////////////
		case (A1):
			switch (token.Class)
			{
			case (LETTER):
				//A4a //������ �������� ������� � ���������� � ���� �����������

				state = A4;
				break;

			case(SEMI_COLON):
				register_type_token = COMMENT;
				//Ka // ������� ������ �������

				state = K;
				break;

			case(ENDL):
				number_line++;
				break;

			default:
				state = Stop;
				break;

			}
			/////////////////////////////////////////////////////////
		case (A2): //��������� �������� 
			switch (token.Class)
			{
			case(LETTER):
				//A4a
				state = A4;
				break;

			case(ARIFMETIC_OPERATION):
				Create_Token(token.Class, character, register_relationship, number_line, table_tokens);


				break;

			case(SEMI_COLON):
				register_type_token = COMMENT;
				//K1
				state = K;
				break;

			case(ENDL):
				number_line++;

				state = A2;
				break;

			default:
				state = Stop;
				break;

			}
			////////////////////////////////////////////////
		case(A3): // ��������� ���������� ������: �����\����������
			switch (token.Class)
			{
			case(DIGIT):
				//A3b //����������� �����

				break;

				// �� �� �������� ��� ���������� ������ � A4
			case(LETTER):
				//P1 // ��������� ����� ����� �������� ����� => ����������

				state = P;
				break;

			case(ENDL):
				// ������� ������� �����

				number_line++;

				state = A2;
				break;

			default:
				state = Stop;
				break;
			}
			/////////////////////////////////////////////////
		case(A4): // ��������� ������� ����� jmp,pop,push � ��
			switch (token.Class)
			{
			case(LETTER):
				//A4b

				break;

			case(SPACE):
				//A3a //������ ����� ����� => ���� ��������

				state = A3;
				break;

			case(ENDL): // ��������� write\read
				//A2o 

				state = A2;
				break;

			default:
				state = Stop;
				break;

			}
			///////////////////////////////////////////////
		case(K):
			switch (token.Class)
			{
			case(ENDL):
				// ������ ������� ���������� �� ������ 

				state = A2;
				break;

			case(END_OF_FILE):
				state = Stop;
				break;

			default:
				// �������� ������ � ������

				break;

			}
			/////////////////////////////////////////////////
		case(O):
			switch (token.Class)
			{
			case(RELATIONSHIP):
				if (token.value != EQUAL)
				{
					Error_Handler(register_type_token, register_value, register_relationship, number_line, table_tokens, state);
					state = A2;
					break;
				}
				if (register_relationship >= NOT && register_relationship <= MORE)
					register_relationship += 3;
				Create_Token(register_type_token, register_value, register_relationship, number_line, table_tokens);

				state = A2;
				break;

			case (SPACE):

				if (register_relationship == NOT)
				{
					Error_Handler(register_type_token, register_value, register_relationship, number_line, table_tokens, state);
					state = A2;
					break;
				}
				Create_Token(register_type_token, register_value, register_relationship, number_line, table_tokens);

				state = A2;
				break;

			case (ENDL):

				if (register_relationship == NOT)
				{
					Error_Handler(register_type_token, register_value, register_relationship, number_line, table_tokens, state);
					state = A2;
					break;
				}
				Create_Token(register_type_token, register_value, register_relationship, number_line, table_tokens);
				number_line++;

				state = A2;
				break;

			case (SEMI_COLON):

				if (register_relationship == NOT)
				{
					Error_Handler(register_type_token, register_value, register_relationship, number_line, table_tokens, state);
					state = K;
					break;
				}
				Create_Token(register_type_token, register_value, register_relationship, number_line, table_tokens);
				register_type_token = TokenType::COMMENT;

				state = K;
				break;

			case (END_OF_FILE):

				if (register_relationship == NOT)
				{
					Error_Handler(register_type_token, register_value, register_relationship, number_line, table_tokens, state);
					state = Stop;
					break;
				}
				Create_Token(register_type_token, register_value, register_relationship, number_line, table_tokens);
				register_type_token = END_MARKER;
				Create_Token(register_type_token, register_value, register_relationship, number_line, table_tokens);
				state = Stop;
				break;

			default:
				state = Stop;
				Error_Handler(register_type_token, register_value, register_relationship, number_line, table_tokens, state);
				break;
				/////////////////////////////////////////////////////////////////
			case(M):
				switch (token.Class)
				{
				case(DIGIT):
					//M1a // c��� ��-� � �����

					state = M1;
					break;
					
				default:
					state = Stop;
					Error_Handler(register_type_token, register_value, register_relationship, number_line, table_tokens, state);
					break;

				}
		////////////////////////////////////////////////////////////////////////////////////
			case(M1):
				switch (token.Class)
				{
				case(DIGIT):
					//M1b ������� �����

					break;

				case(COMMA):
					// M1c ��� ����� � ��-�, ������ ��-�, �������� �����

					break;

				case(R_SQ_BR):
					//A2P �������\��� ��-�

					Create_Token(register_type_token, register_value, register_relationship, number_line, table_tokens);

					state=A2
				}
				


			}


		}

	}





}
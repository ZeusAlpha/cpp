#include <iostream>
#include <ctype.h>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

bool keyword_check(char buffer[])
{
	char keywords[15][10] = {"break","continue", "default", "switch", "typedef", "return", "int", "float", "char", "short", "for", "if", "else","while","do"};
	bool present = false;
	int i;
	for(i=0;i<15;i++)
	{
		if(strcmp(keywords[i],buffer)==0)
		{
			present = true;
			break;
		}
	}
	return present;
}

int main()
{
	vector <int> structure;
	char operators[] = "+-*/=";
	char temparr[100];
	int operator_count = 0;
	int string_count = 0;
	int preprocessor_count = 0;
	int keyword_count = 0;
	int seperator_count = 0;
	int identifier_count = 0;
	bool flagstr = false;
	char strtemp[100];
	int strcount = 0;
	char ch;
	ifstream fin("test.c");
	int j=0;
	if(!fin.is_open())
	{
		cout << "Error" << endl;
		exit(0);
	}
	else
	{
		cout << "\n\nSTART, ";
		while(!fin.eof())
		{
			ch = fin.get();
			if(ch=='\n')
			{
				structure.push_back(6);
			}
			int i;
			for(i=0;i<5;i++)
			{
				if(ch==operators[i])
				{
					cout << ch << ", " /*<< ": OPERATOR" << endl*/;
					operator_count++;
					structure.push_back(0);
				}
			}
			if(flagstr && ch!='"')
			{
				strtemp[strcount]=ch;
				strcount++;
			}
			else if(ch=='"')
			{
				if(!flagstr)
				{
					strtemp[strcount] = ch;
					strcount ++;
					flagstr= true;
				}
				else
				{
					strtemp[strcount] = ch;
					strcount ++;
					strtemp[strcount] = '\0';
					strcount = 0;
					flagstr = false;
					cout << strtemp << ", " /*<< ": STRING" << endl*/;
					string_count++;
					structure.push_back(1);
				}
			}
			else if(isalnum(ch) || ch == '.' || ch == '%' || (int)ch==92)
			{
				temparr[j] = ch;
				j++;
			}
			else if(ch == '#')
			{
				cout << ch << ", " /*<< "#: PREPROCESSOR" << endl*/;
				preprocessor_count++;
				structure.push_back(2);
			}
			else if((ch=='\n' || ch == ' ' || ch == '<' || ch == '>' || ch == '(' || ch == ')' || ch == ','|| ch == '{' || ch == '}') && j!=0)
			{
				
				temparr[j] = '\0';
				j=0;
				if(keyword_check(temparr))
				{
					cout << temparr << ", " /*<< ": KEYWORD" << endl*/;
					keyword_count++;
					structure.push_back(3);
				}
				else
				{
					cout << temparr << ", " /*<< ": IDENTIFIER" << endl*/;
					identifier_count++;
					structure.push_back(4);
				}
				if(ch!=' '&&ch!='\n')
				{
					cout << ch << ", " /*<< ": SEPERATOR" << endl*/;
					seperator_count++;
					structure.push_back(5);
				}
				
				
			}
			else if((ch=='\n' || ch == ' ' || ch == '<' || ch == '>' || ch == '(' || ch == ')' || ch == ','|| ch == '{' || ch == '}'|| ch == ';') && j==0)
			{
				if(ch!=' '&&ch!='\n')
				{
					cout << ch << ", " /*<< ": SEPERATOR" << endl*/;
					seperator_count++;
					structure.push_back(5);
				}
			}
		}
	}
	fin.close();
	cout << "END " << endl;
	cout << "\n----------STATS---------------" << endl;
	cout << "OPERATOR COUNT: " << operator_count << endl;
	cout << "PREPROCESSOR COUNT: " << preprocessor_count << endl;
	cout << "STRING COUNT: " << string_count << endl;
	cout << "KEYWORD COUNT: " << keyword_count << endl;
	cout << "IDENTIFIER COUNT: " << identifier_count << endl;
	cout << "SEPERATOR COUNT: " << seperator_count << endl;
	
	cout << "\n-----------STRUCTURE----------" << endl;
	int cc = 0;
	while(cc<structure.size())
	{
		if(structure[cc]==0)
		{
			cout << "[OPERATOR] ";
		}
		else if(structure[cc]==1)
		{
			cout << "[STRING]";
		}
		else if(structure[cc]==2)
		{
			cout << "[PREPROCESSOR] ";
		}
		else if(structure[cc]==3)
		{
			cout << "[KEYWORD] ";
		}
		else if(structure[cc]==4)
		{
			cout << "[IDENTIFIER] ";
		}
		else if(structure[cc]==5)
		{
			cout << "[SEPERATOR] ";
		}
		else if(structure[cc]==6)
		{
			cout << "\n";
		}
		cc++;
	}	
	return 0;
}

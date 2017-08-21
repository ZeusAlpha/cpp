#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <string>
#include <fstream>
using namespace std;
//Here the vector named "tokens" contains all the tokens for the lexical analysis which can be used further in compiler design course.
//Compile it with g++ -std=c++11 lex_v2.cpp
int main(){
	unordered_map <char,int> m;
	m['+'] = 0;	m['-'] = 0;	m['*'] = 0;	m['/'] = 0;	m['%'] = 0;	m['&'] = 0;
	m['!'] = 0;	m['~'] = 0;	m['^'] = 0;	m['='] = 0;	m['#'] = 0;
	m['{'] = 1;	m['}'] = 1;	m['('] = 1;	m[')'] = 1;	m[';'] = 1;	
	m[' '] = 1;	m['\n'] = 1;	m[','] = 1;	m['<'] =1;	m['>'] = 1;	m['\t'] = 1;
	
	ifstream fin("test.c");
	vector <string> tokens;
	char temp[1000],tempstr[1000],ch;
	int counter=0,commacounter=0; bool startOfComma = false;
	if(!fin.is_open()){cout << "Error" << endl;return 0;}
	while(!fin.eof()){
		ch=fin.get();
		unordered_map <char,int>:: iterator it;
		it = m.find(ch);
		if(ch=='"'){
			tempstr[commacounter] = ch;
			commacounter++;
			if(!startOfComma){
				startOfComma = true;
			}
			else{
				tempstr[commacounter] = '\0';
				commacounter=0;		startOfComma = false;
				cout<<'['<<tempstr<<']';
				tokens.push_back(string(tempstr));
			}
		}
		else if(it!=m.end() && counter==0 && !startOfComma){
			if(ch!='\n' && ch != ' ' && ch!='\t'){			
				cout<<"["<<ch<<"] ";
				tokens.push_back(string(1,ch));
			}
		}
		else if(it==m.end() && !startOfComma){
			temp[counter] = ch;
			counter++;
		}
		else if(startOfComma){
			tempstr[commacounter] = ch;
			commacounter++;
		}
		else{
			temp[counter] = '\0';
			cout<<"["<<temp<<"] ";
			tokens.push_back(temp);
			counter = 0;
			if(ch!='\n' && ch != ' '&&ch!='\t'){			
				cout<<"["<<ch<<"] ";
				tokens.push_back(string(1,ch));
	        	}
		}
	}
	fin.close();
	ofstream fout("tokens.txt");
	int i;
	for(i=0;i<tokens.size();i++)
	{
		fout << tokens[i] << endl;
	}	
	fout.close();
	return 0;
}

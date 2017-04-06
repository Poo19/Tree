#pragma once
#include <iostream>

using namespace std;

struct TNode
{
    char Key[33];
	char EngWord[33];
    TNode *left;
	TNode *right; 
};

class Translator
{
	private:
		
		TNode *m_pRoot;

	public:

		Translator();
		~Translator();
		void InsertWord(char *aWord, char *eWord);
	    TNode *RemoveWord(char *aWord);
		bool ChangeWord(char *aWord, char *eWord);
        void Translate(char *line);
		void PrintAll();
     private:
		void PrintAll(TNode *rt); 
		TNode *Search(char *aWord);
		void DestroyTree(TNode *rt);

};
#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "Translator.h"


using namespace std;
Translator::Translator()
{
  m_pRoot = NULL;
}

Translator::~Translator()
{
     //deleting the tree;
	DestroyTree(m_pRoot);
}
void Translator:: InsertWord(char *aWord, char *eWord)
{
	TNode *newnode = new TNode();
	strcpy(newnode->Key, "");
	strcpy(newnode->EngWord , "");
	newnode->left = NULL;
	newnode->right = NULL;

	strcpy(newnode->Key, aWord);


	strcpy(newnode->EngWord,eWord);
	

	TNode *temp;
	TNode *back;
	temp = m_pRoot;
	back = NULL;
	while (temp!= NULL)
	{
        back = temp;
		if (strcmp(newnode->Key,temp->Key) < 0 )
		    temp = temp->left;
	    else 
		    temp = temp->right;
	}
	if (back == NULL)
	{
		m_pRoot = newnode;
	}
	else 
	{
		if (strcmp(newnode->Key,back->Key) < 0 )
		{
		  back->left = newnode;
		  cout<< "\n"<< "Inserting "<<newnode->Key<<" = "<< newnode->EngWord;
		}
		else
		{
		  back->right = newnode;
		 cout<<"\n"<< "Inserting "<<newnode->Key << " = "<< newnode->EngWord;
		}

}

}

TNode *Translator:: RemoveWord(char *aWord)
{
	TNode *local;
	local = new TNode;
	TNode *back;
	TNode *temp;
	TNode *delparent;
	TNode *delNode;

	temp = m_pRoot;
	back = NULL;

	while (temp!=NULL && !strcmp(aWord,temp->Key)==0)

	{
		back = temp;
		if ( strcmp(aWord,temp->Key)<0 )
			temp = temp -> left;
		else 
			temp = temp -> right;
	}
	if (temp == NULL)
	{
		cout <<" Node not to be found to delete";
		return NULL;
	}

	else
	{
		strcpy(local->Key , temp->Key);
		strcpy(local->EngWord , temp->EngWord);
		local->left = local->right = NULL;
		delNode = temp;
	    delparent = back;
	}
        
	if (delNode->right = NULL)
  {  
	 if(delparent== NULL)
		{
		m_pRoot = delNode->left;
		delete delNode;
		return delparent;
        }
	  else
	{
		if(delparent->left == delNode)
			delparent->left = delNode->left;
		else 
			delparent->right = delNode->left;
		delete delNode;
		return local;   
	 }
 }

	else if (delNode->left == NULL)
	{
		if(delparent== NULL)
		{
		m_pRoot = delNode->left;
		delete delNode;
		}
		else 
        if(delparent->left == delNode)
			delparent->left = delNode->right;
		else 
			delparent->right = delNode->right;
		delete delNode;
		return local;
    }

	else 
	{

		temp = delNode->left;
		back = delNode;
		while( temp->right != NULL)
		{
			back= temp;
			temp = temp ->right;
		}
    }
	    strcpy(delNode->Key , temp->Key);
		strcpy(delNode->EngWord , temp->EngWord);
		if(  back == delNode )
			back->left = temp->left;
		else
			back->right = temp->left;
            delete temp;
	        return local;

}

bool Translator:: ChangeWord(char *aWord, char *eWord)
{
	cout << "\n";
	TNode *temp;
	char *word ;
	 word = new char;
	strcpy(word,aWord);
     temp = Search(word);
	  if(temp == NULL)
	  {
		return false;
	    
	  }
	  else 
	  {
		 strcpy( temp->EngWord,eWord);
          return true;
	  }
	
}

void Translator:: Translate(char *line)
{
	cout<<"\n";
	cout<< "Translating: "<< line<< "\n";
	cout<<"\t";
	TNode *temp;
	char *tok;
	tok = strtok(line, ",?.! ");
	temp = Search(tok);
    while(tok!= NULL)
	{
      if (temp!= NULL)
      cout << " " << temp->EngWord;
	  else 
	  cout<< " unknown variable " ;
	  tok = strtok(NULL, ",?.! ");
	  if(tok!=NULL)
		temp = Search(tok);

    }

}


  TNode *Translator:: Search(char *aWord)
{

		TNode *temp;
		temp = m_pRoot;
		while ((temp!=NULL) && (strcmp(temp->Key,aWord)!=0))
		{
			if(strcmp (aWord,temp->Key) < 0)
				temp= temp->left;
			else
				temp= temp->right;
		}
	  
		  if(temp == NULL)
              return NULL;
		  else 
			  return temp;

}

	void Translator::DestroyTree (TNode *T)
{
    if(T==NULL) return;  // Nothing to clear
    if(T->left != NULL) DestroyTree(T->left); // Clear left sub-tree
    if(T->right != NULL) DestroyTree(T->right); // Clear right sub-tree
    delete T;    // Destroy this node
    return;
}

	void Translator::PrintAll()
	{
         PrintAll(m_pRoot);
	}
	void Translator::PrintAll(TNode *T)
{
	
    if(T != NULL)
    {
        PrintAll(T->left);
        cout << T->Key << "\t" << T->EngWord<< "\n" ;
        PrintAll(T->right);
    }
}
	
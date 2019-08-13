#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"


#ifndef BUILDTREE_OFF
TreeNode * buildExpressionTree(Scanner * s) {

//FILL IN
	Token t = nextToken(s);
	Token op;
	TreeNode* first = NULL;
	TreeNode* second = NULL;

	while(t.type != T_EOF)
		{
			if (t.type == T_LPAREN)
			{
				first = buildExpressionTree(s);
			}else if(t.type == T_VAL)
			{
				return buildTreeNode(t);
			}else if (t.type == T_ADD || t.type == T_SUB || t.type == T_MUL || t.type == T_DIV)
			{
				op = t;
				second = buildExpressionTree(s);
			}else if (t.type == T_RPAREN)
			{
				TreeNode* root = buildTreeNode(op);
				root->left = first;
				root->right = second;
				return root;
			}else
			{
				return false;
			}
		t = nextToken(s);
	}
	return NULL;
}
#endif

#ifndef POSTFIX_OFF
void makePostFix(TreeNode * t, FILE * fptr) {
	
//FILL IN
	if (t != NULL)
	{
		if(t->t.type != T_VAL){
			makePostFix(t -> left, fptr);
			makePostFix(t -> right, fptr);
			fprintf(fptr,"%c ",t ->t.type);
		}else if(t->t.type == T_VAL)
		{
			fprintf(fptr,"%f ",t->t.value);
		}
	}else if (t == NULL)
	{
		return;
	}
}
#endif
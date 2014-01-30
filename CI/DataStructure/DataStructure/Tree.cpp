#include "stdafx.h"
#include <algorithm>

struct treeNode
{
	int data;
	struct treeNode *left;
	struct treeNode *right;
};

static int Height(treeNode *root)
{
	if(!root)
		return 0;

	return std::max(Height(root->left),Height(root->right))+1;
}

int diameter(treeNode *root)
{
	if (!root)
		return 0;

	int lHeight = Height(root->left);
	int rHeight = Height(root->right);
	int currDiameter = lHeight+rHeight+1;

	int lDiameter = diameter(root->left);
	int rDiameter = diameter(root->right);

	return std::max(currDiameter,std::max(lDiameter,rDiameter)); 
} //O(N^2)

//BST LCA
static treeNode* LCA(treeNode* root, treeNode* p, treeNode *q)
{
	if (!root || !p || !q)
		return NULL;

	if (root->data < std::min(p->data,q->data))
		return LCA(root->right,p,q);
	else if (root->data > std::max(p->data,q->data))
	    return LCA(root->left,p,q);
	else
		return root;
}
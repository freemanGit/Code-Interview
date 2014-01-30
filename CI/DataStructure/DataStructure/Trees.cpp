#include "stdafx.h"
#include <iostream>
#include <queue>

struct  treeNode
{
	struct treeNode *left;
	struct treeNode *right;
	int data;
};

//Given a binary tree, return the level order traversal of its nodes' values.
//http://discuss.leetcode.com/questions/49/binary-tree-level-order-traversal
void printLevelOrder(treeNode *root)
{
	if(!root)
	{
		std::cout << "No Tree!"<<std::endl;
		return;
	}

	std::queue<treeNode*> nodeQueue;
	int countCurrLevel = 1;
	int countNextLevel = 0;

	nodeQueue.push(root);
	while(!nodeQueue.empty())
	{
		treeNode *temp = nodeQueue.front();
		nodeQueue.pop();
		countCurrLevel --;
		std::cout<<temp->data<<" ";

		if(temp->left)
		{
			nodeQueue.push(temp->left);
			countNextLevel++;
		}
		if(temp->right)
		{
			nodeQueue.push(temp->right);
			countNextLevel++;
		}

		if(countCurrLevel == 0)
		{
			std::cout <<std::endl;
			countCurrLevel = countNextLevel;
			countNextLevel = 0;
		}

	}
}
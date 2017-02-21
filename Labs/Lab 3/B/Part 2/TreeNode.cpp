#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode(char letter) : letter(letter), right(NULL), left(NULL)
{
}

TreeNode::~TreeNode()
{
	delete left;
	delete right;
	letter = NULL;
}

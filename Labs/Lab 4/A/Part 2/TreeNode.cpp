#include "TreeNode.h"
#include <iostream>
using namespace std;


TreeNode::TreeNode(int number) : left(NULL), number(number), right(NULL)
{
}

TreeNode::~TreeNode()
{
	delete left;
	number = NULL;
	delete right;
}

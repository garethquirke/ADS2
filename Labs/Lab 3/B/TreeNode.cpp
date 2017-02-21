#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode::TreeNode(int numberIn) : number(numberIn), right(NULL), left(NULL)
{

}

int TreeNode::getNumber()
{
	return number;
}

TreeNode * TreeNode::getRight()
{
	return right;
}

TreeNode * TreeNode::getLeft()
{
	return left;
}

void TreeNode::displayNode()
{
	cout << number;
}

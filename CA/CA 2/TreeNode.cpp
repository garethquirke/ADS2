#include "TreeNode.h"

TreeNode::TreeNode(City* city) : left(NULL), city(city), right(NULL)
{
}

TreeNode::~TreeNode()
{
	delete left;
	delete right;
}

bool TreeNode::isLeaf()
{
	return false;
}

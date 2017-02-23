#include <iostream>
#include "TreeNode.h"

TreeNode::TreeNode(int numberIn) : number(numberIn), right(NULL), left(NULL)
{

}
/*
Source: Jeremy Friesner's answer on stackoverflow
Availible From: http://stackoverflow.com/questions/8018686/binary-search-tree-destructor
Usage: Based on
*/
TreeNode::~TreeNode()
{
	delete left;
	delete right;
	number = NULL;
}

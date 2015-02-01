#include "node.h"


//constructors
node::node(){
	keyExists = false;
	left = NULL;
	right = NULL;
	parent = NULL;
};

node::node(int someKey, node* leftChild, node* rightChild, node* nodeParent){

	keyExists = true;
	key = someKey;
	left = leftChild;
	right = rightChild;
	parent = nodeParent;
};


node::node(const node &copiedNode){

	keyExists = copiedNode.keyExists;
	key = copiedNode.key;
	left = copiedNode.left;
	right = copiedNode.right;
	parent = copiedNode.parent;

	height = copiedNode.height;
	balanceFactor = copiedNode.balanceFactor;
};



//setters
void node::setKey(int value)
{
	key = value;
};
void node::setLeftChild(node* newLeftChild)
{
	left = newLeftChild;
};
void node::setRightChild(node* newRightChild)
{
	right = newRightChild;
};
void node::setParent(node* newParent){
	parent = newParent;
};


//getters
int node::getKey()
{
	return key;

};
node* node::getLeftChild()
{
	return left;

};
node* node::getRightChild()
{
	return right;
};

bool node::doesKeyExist(){
	return keyExists;
};
node* node::getParent(){
	return parent;
};

void node::setHeight(int newHeight){

	height = newHeight;

};
void node::setBalanceFactor(int newBalanceFactor){
	balanceFactor = newBalanceFactor;
};
int node::getHeight(){
	return height;
};
int node::getBalanceFactor(){
	return balanceFactor;
};
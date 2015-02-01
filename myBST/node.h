#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
//#include "tree.h"

using namespace std;




class node{

public:
	//constructors
	node::node();
	node::node(int someKey, node* leftChild, node* rightChild, node* nodeParent);
	node::node(const node &copiedNode);


	//setters
	void node::setKey(int value);
	void node::setLeftChild(node* newLeftChild);
	void node::setRightChild(node* newRightChild);
	void node::setParent(node* newParent);
	void node::setHeight(int newHeight);
	void node::setBalanceFactor(int newBalanceFactor);


	//getters
	int node::getKey();
	node* node::getLeftChild();
	node* node::getRightChild();
	node* node::getParent();
	int node::getHeight();
	int node::getBalanceFactor();
	bool node::doesKeyExist();
private:
	int key;
	int height;
	int balanceFactor;
	bool keyExists;
	node* left;
	node* right;
	node* parent;

};







#endif
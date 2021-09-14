#include "Node.h"
#include <iostream>
Node::Node(int data):data(data)
{

}
Node::~Node()
{
	std::cout << "Destroy value :" << Node::data << " at address" << this << "\n";
}
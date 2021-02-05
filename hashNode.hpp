/*
 * Jackson Xiao
 * TA: Lauren Olson
 * This file contain the .hpp file for the hashNode class.
 * This file is a part of lab 6
 */

#ifndef HASHNODE_HPP_
#define HASHNODE_HPP_
#include <string>
using namespace std;

class hashNode {
	friend class hashMap;
	string keyword;
	string *values;
	int valuesSize;
	int currSize;
public:
	hashNode();
	hashNode(string s);
	hashNode(string s, string v);
	void addValue(string v);
	void dblArray();
	string getRandValue();


};





#endif /* HASHNODE_HPP_ */

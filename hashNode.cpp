/*
 * Jackson Xiao
 * TA: Lauren Olson
 * This file contain the .cpp file for the hashNode class.
 * This file is a part of lab 6
 */



#include "hashNode.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
 * Constructor for the hashNode class. Takes no parameter
 */
hashNode::hashNode(){
	keyword = "";
	valuesSize = 0;
	currSize = 0;
	values = NULL;
}
/*
 * Constructor for the hashNode class. Takes one parameter
 */
hashNode::hashNode(string s){
	keyword = s;
	valuesSize = 100;
	currSize = 0;
	values = new string[valuesSize];
}
/*
 * Constructor for the hashNode class. Takes two parameter
 */
hashNode::hashNode(string s, string v){
	keyword = s;
	valuesSize = 100;
	currSize =1 ;
	values = new string[100];
	values[0] = v;

}
/*
 * Adds a new value to the end of the values array, increases currSize. Check if there's
 * more space, and, if not, calls dblArray()
 */
void hashNode::addValue(string v){
	if (currSize < valuesSize){
		values[currSize] = v;
		currSize++;
	}
	else{
		dblArray();
		values[currSize] = v;
		currSize++;
	}
}
/*
 * Creates a new array, double the length, and copies over the values.
 */
void hashNode::dblArray(){
	string *newArray = new string[valuesSize*2];
	for (int i = 0; i<valuesSize; i++){
		newArray[i] = values[i];
	}
	values = newArray;
	valuesSize = valuesSize *2;

}
/*
 * Returns a random string from the values array. If there's no values in the value
 * array, then it returns an empty string
 */
string hashNode::getRandValue(){
	if(currSize == 0){
		return "";
	}
	else{
		int random = rand()% currSize;
		return values[random];
	}
}


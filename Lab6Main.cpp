/*
 * Jackson Xiao
 * TA: Lauren Olson
 * This file contain the .cpp file for the main class
 * This file is a part of lab 6
 */

#include "hashMap.hpp"
#include "iostream"
#include "stdlib.h"
#include "time.h"
#include "makeSeuss.hpp"
using namespace std;

int main(){
	srand(time(NULL));
	makeSeuss("DrSeuss.txt","TrueTrue",true, true);
	makeSeuss("DrSeuss.txt","TrueFalse",true,false);
	makeSeuss("DrSeuss.txt","FalseTrue",false, true);
	makeSeuss("DrSeuss.txt","FalseFalse",false, false);



}




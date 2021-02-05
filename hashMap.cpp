/*
 * Jackson Xiao
 * TA: Lauren Olson
 * This file contain the .cpp file for the hashMap class.
 * This file is a part of lab 6
 */

#include "hashMap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
/*
 * Constructor for the hashMap class. Takes in hash1 and coll1 as parameters and set them.
 */
hashMap::hashMap(bool hash1, bool coll1){
	h1 = hash1;
	c1 = coll1;
	first = "";
	numKeys = 0;
	mapSize = 101;
	collisionct1 = 0;
	collisionct2 = 0;
	map = new hashNode*[mapSize];
	for(int i = 0; i < mapSize; i++){
		map[i] = NULL;
	}
}
/*
 * Adds a node to the map at the correct index based on the key string, and then inserts the value
 * to the value field of the hashNode. Will use calcHash if h1 is true or calcHash2 if h1 is false.
 * Will use collHash1 or collHash2 if there are any collisions. This function will also check the load
 * and will rehash if the load is greater than 0.7.
 */
void hashMap::addKeyValue(string k, string v){
	int key;
	if(h1 == true){
		key = calcHash(k);
	}
	if(h1 == false){
		key = calcHash2(k);
	}
	if(map[key] == NULL){
		map[key] = new hashNode(k,v);
		numKeys++;
	}
	else{
		if(map[key]->keyword == k){
			map[key]->addValue(v);
		}
		else{
			if(map[key]->keyword != k){
				if(c1 == true){
					collisionct1++;
					key = collHash1(key, -1, k);
				}
				if(c1 == false){
					collisionct1++;
					key = collHash2(key, -1, k);
				}
				if(map[key]!=NULL && map[key]->keyword == k){
					map[key]->addValue(v);
				}
				else{
					map[key] = new hashNode(k,v);
					numKeys++;
				}

			}
		}
	}
	double load = (double) numKeys / (double) mapSize;
	if(load > 0.7){
		reHash();
	}

}
/*
 * Uses calcHash and collHash functions to return the index of the given string.
 */
int hashMap::getIndex(string k){
	int index;
	if(h1 == true){
		index = calcHash(k);
	}
	if(h1 == false){
		index = calcHash2(k);
	}
	if(c1 == true){
		if(map[index]->keyword != k && map[index] != NULL){
			index = collHash1(index, -1, k);
		}
	}
	if(c1 == false){
			if(map[index]->keyword != k && map[index] != NULL){
				index = collHash2(index, -1, k);
			}
		}
	return index;
}
/*
 * For this hash function, the ascii value of each characters are added. The sum is then
 * modulo by the mapSize. The value is returned.
 */
int hashMap::calcHash(string k){
	int sum = 0;
	for (int i = 0; i< k.length(); i++){
		sum = sum + int(k[i]);
	}
	sum = sum%mapSize;
	return sum;
}
/*
 * For this hash function, I used all N characters of the string as an N-digit base-b number
 * with b = 19. The index is returned.
 */
int hashMap::calcHash2(string k){
	unsigned long int h = 0;
	int len = k.length();
	for (int i = 0; i<len; i++){
		h = (h*19 + ((int)k[len-i-1]))%mapSize;
	}
	return h;
}

/*
 * This function doubles the original mapSize. It then finds the closest prime that is greater
 * than the doubled mapSize. The mapSize is returned.
 */
int hashMap::getClosestPrime(){
	int newNum = 2*mapSize;
		int divisor = mapSize - 1;
		bool newPrime = false;
		while(newPrime == false){
			if(divisor != 1){
				if(newNum % divisor != 0){
					divisor--;
				}
				else{
					newNum = newNum + 1;
					divisor = newNum - 1;
				}
			}
			else{
				newPrime = true;
		}
	}
		return newNum;

}
/*
 * This function is called when the array is at 70%. It creates a new array with the new
 * size and rehashes the keys using calcHash and colHash functions.
 */
void hashMap::reHash(){
	int oldSize = mapSize;
	int newSize = getClosestPrime();
	hashNode **oldMap = map;
	map = new hashNode*[newSize];
	mapSize = newSize;
	for(int i = 0; i < mapSize; i++){
		map[i] = NULL;
	}
	for(int i = 0; i < oldSize; i++){
		int index;
		if(oldMap[i] != NULL){
			if(h1 == true){
				index = calcHash(oldMap[i]->keyword);
			}
			else{
				index = calcHash2(oldMap[i]->keyword);
			}
			if(map[index] != NULL){
				if(c1 == true){
					index = collHash1(index, -1, oldMap[i]->keyword);}
				else{
					index = collHash2(index, -1, oldMap[i]->keyword);}
			}
			map[index] = oldMap[i];
		}
	}
}
/*
 * This collision method is using linear probing. It returns the new index
 */
int hashMap::collHash1(int h,int i,string k){
	int index = h;
	while(map[index] != NULL && map[index]->keyword != k){
		index++;
		collisionct2++;
		//cout<< "collisionct1 is: "<<collisionct1<<" collision ct2 is: "<<collisionct2<<endl;
		if (index >= mapSize){
			index = index% mapSize;
		}
		if (index == i && i!= 0){
			return -1;
		}
	}
	return index;
}
/*
 * This collision method is using quadratic probing. It returns the new index.
 */
int hashMap::collHash2(int h, int i,string k){
	int num = 1;
	int index = h;
	while(map[index] != NULL && map[index]->keyword != k){
		collisionct2++;
		//cout<< "collisionct1 is: "<<collisionct1<<" collision ct2 is: "<<collisionct2<<endl;
		index = index + (num * num);
		if (index >= mapSize){
			index = index % mapSize;
		}
		num++;

	}
	if(index == i && i != 0){
		return -1;
	}
	return index;
}

/*
 * Takes a string as parameter. Finds the key in the array and returns its index.
 */
int hashMap::findKey(string k){
	int index;
	if(h1 == true){
		index = calcHash(k);
	}
	else{
		index = calcHash2(k);
	}
	int oldIndex = index;
	if(map[index]->keyword != k){
		if(c1 == true){
			index = collHash1(index, oldIndex,k);
		}
		else{
			index = collHash2(index, oldIndex, k);
		}
	}
		return index;
}

void hashMap::printMap(){
	for (int i = 0; i <mapSize; i++){
		cout<< map[i]<<", "<<endl;
	}
}






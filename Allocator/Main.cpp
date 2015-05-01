#include "VectorT.h"
#include <iostream>
#include <vector>

using namespace VectorTSpace;
void main()
{
	VectorT<int>* pVec1 = new VectorT<int>();
	pVec1->push_back(0);
	pVec1->push_back(1);
	//std::vector<int>* pVec2 = new std::vector<int>();
	//pVec2->push_back(0);
	//pVec2->push_back(1);
}
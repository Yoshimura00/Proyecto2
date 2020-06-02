#pragma once
#include <iostream>
#include <string.h>
#include <sstream>
#include<cstdlib>
#include<ctime>
using namespace std;
class ObjetoBase
{
public:
	virtual string toString() = 0;
};
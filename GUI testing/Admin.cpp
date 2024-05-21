#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin() {}

void Admin::setKey(string K)
{
	Key = K;
}

string Admin::getKey()
{
	return Key;
}

#include "StringSource.h"

void StringSource::setSource(std::string &data)
{
	getline(std::cin, data);	
}

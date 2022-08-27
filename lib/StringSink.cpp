#include "StringSink.h"

 StringSink::StringSink()
 {

 }

 StringSink::~StringSink()
 {

 }

void StringSink::getDataFrom(XMLobj* objXML)
{
	objXML->getData();
}

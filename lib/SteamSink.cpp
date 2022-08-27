#include "SteamSink.h"
#include <iostream>
#include <fstream>

SteamSink::SteamSink()
{

}

void SteamSink::getDataFrom(XMLobj* objXML)
{

	std::cout<< "Morgenshturn"<<std::endl;
	string alpha;

	alpha =objXML->getDataFromSting(alpha);
	
	std::fstream outFile;


	outFile.open("BABA.xml",fstream::out);
	if (outFile.is_open())
	{
		outFile << alpha << std::endl;
	}

	outFile.close();
}

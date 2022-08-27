#include "SteamSource.h"

void SteamSource::setSource(std::string &data)
{
	std::ifstream file;
	file.open("randomXML_file.xml");   //U should put there the path to your .xml file

    if (file.is_open())
    {
        std::cout << "File is open!" << std::endl;

        while (!file.eof())
        {
            getline(file, data);
        }       
        file.close();
    }
    else
    {
        std::cout << "File is dont open! ERROR" << std::endl;
    }
}

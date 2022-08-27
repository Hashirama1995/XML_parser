#include "XMLobj.h"


XMLobj::~XMLobj()
{
}

void XMLobj::getData()
{
	
	if (!typeXML.empty())
	{
		cout <<"<" << typeXML <<">" << endl;
	}
	if (!key.empty())
	{
		for (int i = 0; i < deep; i++)
		{
			std::cout << " ";
		}
		std::cout << "<" << key;
	}
	if (!atributs.empty())
	{
		for (auto a : atributs)
		{
			cout << " " << a.first << "=" << "\'" << a.second << "\'";
		}
	}
	if (!key.empty())
	{
		std::cout << ">" << endl;
	}

	if (!value.empty())
	{
		for (auto a : value)
		{
			for (int i = 0; i < deep + 1; i++)
			{
				std::cout << " ";
			}
			cout << a;
		}
	}

	if (Node.empty())
	{
		cout << endl;
	}

	for(auto v:Node)
	{		
		v->getData();
	}
	

	//cout << endl;
	if (!key.empty())
	{
		for (int i = 0; i < deep; i++)
		{
			std::cout << " ";
		}
		std::cout << "</" << key << ">";
		cout << endl;
	}
}



string XMLobj::getDataFromSting(string cool)
{
	
	if (!typeXML.empty())
	{
		cool = cool +"<"+ typeXML+ ">";
	}

	if (!key.empty())
	{
		cool = cool + '\n';
		for (int i = 0; i < deep; i++)
		{
			cool = cool + " ";
		}
		cool = cool + "<" + key;
	}
	if (!atributs.empty())
	{
		for (auto a : atributs)
		{
			cool = cool + " " + a.first + "=" +  a.second ;
		}
	}
	if (!key.empty())
	{
		cool = cool + ">";
	}

	if (!value.empty())
	{
		for (auto a : value)
		{
			cool = cool + '\n';
			for (int i = 0; i < deep + 1; i++)
			{
				cool = cool + " ";
			}
			cool = cool + a;
		}
	}

	if (Node.empty())
	{
		cool = cool + '\n';
	}

	for (auto v : Node)
	{
		cool=v->getDataFromSting(cool);
	}



	if (!key.empty())
	{
		for (int i = 0; i < deep; i++)
		{
			cool = cool + " ";
		}
		cool = cool + "<"+"/" + key+">"+'\n';
	}


	return cool;
}



XMLobj::XMLobj()
{
}
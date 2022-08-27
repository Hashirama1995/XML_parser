#include "Parser.h"
#include <iostream>
#include <fstream>
#include <spdlog/spdlog.h>

Parser::Parser(Source* mysrc)
{
    this->src=mysrc;
}
Parser::~Parser()
{

}

void Parser::parse(std::string& data2, Visitor* visitor)
{
    //std::cout << data.size();
   

spdlog::info("JopaJopaJopa");

    std::string data;

    this->src->setSource(data);

    if (data.size() == 0)
    {
        std::cout << "Empty string" << std::endl;
    }

    int count = 0;
    int glubina = 0;
    
    bool fStartKey = false;
    bool fStartAtribute = false;
    bool fStartValue = false;
    bool edgeDeep = false;

    std::string key;
    std::string atribute;
    std::string atributeValue;
    std::string value;

    for (count; count < data.size(); count++)
    {
        
        
        if (data[count] == '<')
        {
            
            if (data[count + 1] == '?')
            {
                std::string type;
                count++;
                while (data[count] != '>')
                {                    
                    type =type+ data[count];
                    count++;
                }
                               
                 visitor->onParseKey(type,glubina);
                visitor->gg();
                 visitor->onParseEndKey(type,glubina);
                continue;
            }
            
            
            
            if (data[count + 1] == '/')
            {
                glubina--; 
                edgeDeep = true;
                while (data[count] != '>')
                {
                    count++;
                }
                continue;
            }
            else if(edgeDeep==false)
            {
                glubina++;
            } 
            else
            {
                edgeDeep = false;
            }
            
            count++;
            fStartKey = true;      

            while (data[count] != '>' )
            {
                if (data[count] == ' ')
                    break;
                key += data[count];
               count++;
            }
            visitor->onParseKey(key,glubina);
            
            if (data[count] == '>' && fStartKey == true)
            {
                fStartKey = false;
                key = "";
            }
        }



        if ((data[count] == ' ') && fStartKey == true)// ���� ������ "������" � ���� ���� ������
        {
            while (data[count] != '>')
            {
                if (data[count] == ' ')
                {
                    count++;//��������� � ������� �� �����
                    while (data[count] != '=')// �� ��������� ������� �� "="
                    {
                        atribute += data[count];
                        count++;
                    }
                    visitor->onAtribute(atribute, glubina);
                    atribute = "";
                    count++;//������������ �� = ������

                    while (data[count] != '>') // ���� �� ������ ">" ��� ������ ������ ��������� �������� ��������
                    {
                        if (data[count] == ' ')
                        {
                            break;
                        }
                        atributeValue += data[count];
                        count++;
                    }

                    visitor->onAtributeValue(atributeValue, glubina);//��������
                    atributeValue = "";//��������

                }
            }

            if (data[count] == '>' && fStartKey == true)// ���� ������ > � ���� ���� ������
            {
                fStartKey = false;// ��������� ���

                std::string temp;
                temp = data[count];
                key = "";
            }

        }



        if (count!=data.size()-1 && data[count] == '>'&& data[count + 1] != '<'&& fStartKey == false && data[count]!=data.size()) // ���� ����������� � ������ ��� ����������� ������ � ���� ���� ������
        {
            fStartValue = true;
            count++;
            glubina++;
        }      
        
        if (fStartValue == true)
        {
            while (true)
            {
                while (data[count] != '<')
                {
                    if (data[count] == ' ' && data[count] == ',' && data[count] == '.')
                    {
                        break;
                    }
                    value += data[count];
                    count++;
                }
                visitor->onParseStr(value, glubina);

                if (data[count] == '<')
                {
                    break;
                }
                count++;
            }
            

            if (data[count] == '<')
            {
                fStartValue = false;// Value �����������
                count--;//� ��������� �������� ������ ������������ ���� ���
                value = "";// ���������
            }
        }             
        visitor->gg();
    }





    visitor->onFinished();    
}


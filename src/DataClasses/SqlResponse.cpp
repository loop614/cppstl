/* 
 * File:   SqlResponse.cpp
 * Author: tony
 * About:
 *
 */
#include <DataClasses/SqlResponse.hpp>

SqlResponse::SqlResponse() {}
SqlResponse::~SqlResponse() {}

void SqlResponse::addKeyValue(std::string key, std::string value) 
{
    keyValueMap[key] = value;
    countMembers++;
    if (countMembers >= returnKeysCount) {
        data[countData] = keyValueMap;
        countData++;
        countMembers = 0;
        mapString keyValueMap;
    }
}

void SqlResponse::print() 
{
    for(std::map<int, mapString>::iterator i = data.begin(); i!=data.end(); i++) 
    {
        std::cout << i->first << " : " << std::endl;
        Helper::printTemplateMapString<mapString>(i->second);
        Helper::printEmptyLine();
    }
}

void SqlResponse::setReturnKeysCount(int rkc) 
{
    returnKeysCount = rkc;
}
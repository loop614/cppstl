/* 
 * File:   SqlResponse.cpp
 * Author: tony
 * About:
 *
 */
#include <DataClasses/ElasticRequest.hpp>
#include <Helpers/Helper.hpp>

ElasticRequest::ElasticRequest() {}
ElasticRequest::~ElasticRequest() {}

void ElasticRequest::addKeyValue(std::string key, std::string value) 
{
    mapString tmp;
    tmp.insert(pairString(key, value));
    this->keyValue.push_back(tmp);
}
   
void ElasticRequest::print() 
{
    for(listMapString::iterator i = this->keyValue.begin(); i != this->keyValue.end(); ++i) 
    {
        printStringMap(*i);
    }
}
    
void ElasticRequest::printStringMap(mapString map) 
{
    for(mapString::iterator i = map.begin(); i != map.end(); ++i) 
    {
        Helper::print(i->first, i->second);
    }
}

void ElasticRequest::getByKey(std::string key, vectorString * res)
{
    for(listMapString::iterator i = this->keyValue.begin(); i != this->keyValue.end(); ++i) 
    {
        for(mapString::iterator j = (*i).begin(); j != (*i).end(); ++j) 
        {
            if (0 == j->first.compare(key))
            {
                res->push_back(j->second);
            }        
        }
    }
}
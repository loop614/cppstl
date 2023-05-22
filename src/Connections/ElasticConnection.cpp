/* 
 * File:   ElasticConnection.cpp
 * Author: tony
 * About: 
 *
 */
#include <Connections/ElasticConnection.hpp>
#include <Helpers/Helper.hpp>

ElasticConnection::ElasticConnection() {}
ElasticConnection::~ElasticConnection() {}

void ElasticConnection::generateDummyResponseData(ElasticRequest * elasticRequest, ElasticResponse * elasticResponse) 
{
    ElasticResponse * dataHolder;
    vectorString group;
    vectorString contains;
    int count = 0;
    bool createNext = false;

    elasticRequest->getByKey("group", &group);
    elasticRequest->getByKey("contains", &contains);

    for (vectorString::iterator it = group.begin(); it != group.end(); ++it)
    {
        count = it - group.begin();
        createNext = it+1 != group.end();
        this->addNewLevel(elasticResponse, count, "groupBy" + group[count], createNext);
    }
    
    dataHolder = elasticResponse;
    count = 0;
    while (NULL != dataHolder)
    {
        if (NULL == dataHolder->nextLevel) 
        {
            break;
        }
        dataHolder = dataHolder->nextLevel;
        count++;
    }

    for (int i = 0; i < 3; i++)
    {
        for(vectorString::iterator i = contains.begin(); i != contains.end(); i++ ) 
        {
            dataHolder->addKeyValue(*i, std::to_string(std::rand() % 10));
        }

        for(vectorString::iterator i = group.begin(); i != group.end(); i++ ) 
        {
            if(0 == (*i).compare("datetime")) 
            {
                dataHolder->addKeyValue("datetime", "2020-" + std::to_string(std::rand() % 11 + 1) + "-" + std::to_string(std::rand() % 28  + 1));
            } 
            else 
            {
                dataHolder->addKeyValue(*i, std::to_string(std::rand() % 1000000));
            }
        }
    }
}

void ElasticConnection::addNewLevel(ElasticResponse * elasticResponse, int depthLevel, std::string groupKey, bool createNext)
{
    while (NULL != elasticResponse->nextLevel)
    {
        elasticResponse = elasticResponse->nextLevel;
    }

    elasticResponse->setDepthLevel(depthLevel);
    elasticResponse->setGroupKey(groupKey);

    if (false != createNext) 
    {
        ElasticResponse * temp = new ElasticResponse();
        temp->nextLevel = NULL;
        elasticResponse->nextLevel = temp;
    }
}
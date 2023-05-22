/* 
 * File:   SqlResponse.cpp
 * Author: tony
 * About:
 *
 */
#include <Helpers/Helper.hpp>
#include <DataClasses/ElasticResponse.hpp>

ElasticResponse::ElasticResponse() {}
ElasticResponse::~ElasticResponse() {}

void ElasticResponse::addKeyValue(std::string key, std::string value) 
{
    multimapString tmp;
    tmp.insert(pairString(key, value));
    this->keyValueList.push_back(tmp);
}

// used the linked list here, just to experiment, array like in other classes would been much better
void ElasticResponse::printNodes(ElasticResponse * node, int keyNumber) 
{
    if (node != NULL) 
    {
        node->printDepthLevelEmptySpace(node->getDepthLevel());
        Helper::print("key", node->groupKey);
        node->printDepthLevelEmptySpace(node->getDepthLevel());
        Helper::print("buckets: ");
        if (node->keyValueList.size() > 0) 
        {
            node->printListStringMap(node->keyValueList, keyNumber);
        }
    }
    if (node->nextLevel != NULL) 
    {
        node->printNodes(node->nextLevel, keyNumber);
    }
}

void ElasticResponse::printListStringMap(listMultimapString keyValueList, int keyNumber ) 
{
    int count = 0;
    for(listMultimapString::iterator i = keyValueList.begin(); i != keyValueList.end(); ++i) 
    {
        if (count % keyNumber == 0) 
        {
            Helper::printEmptyLine();
        }
        count++;
        this->printStringMultimap(*i);
    }
}

void ElasticResponse::printStringMultimap(multimapString keyValue) 
{
    for(multimapString::iterator it = keyValue.begin();it != keyValue.end(); ++it) 
    {            
        this->printDepthLevelEmptySpace(this->getDepthLevel() + 1);
        Helper::print(it->first, it->second);
    }
}

void ElasticResponse::printDepthLevelEmptySpace(int count) 
{
    for(int i = 0; i < count; ++i) 
    {
        std::cout << "  ";
    }
}

void ElasticResponse::setDepthLevel(int dl) 
{
    this->depthLevel = dl;
}

int ElasticResponse::getDepthLevel()
{
    return this->depthLevel;
}

void ElasticResponse::setGroupKey(std::string gk)
{
    this->groupKey = gk;
}

std::string ElasticResponse::getGroupKey()
{
    return this->groupKey;
}

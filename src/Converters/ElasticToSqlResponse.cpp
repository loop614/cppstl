/* 
 * File:   ElasticToSqlResponse.cpp
 * Author: tony
 * About:
 *
 */
#include <Converters/ElasticToSqlResponse.hpp>

ElasticToSqlResponse::ElasticToSqlResponse(ElasticResponse * er, SqlResponse * slr, vectorString rks) 
{
    elasticResponse = er;
    sqlResponse = slr;
    returnKeys = rks;
}

ElasticToSqlResponse::~ElasticToSqlResponse() {}

void ElasticToSqlResponse::tranformData(ElasticResponse* elasticResponse) 
{
    this->processListStringMap(&elasticResponse->keyValueList);
    if (elasticResponse->nextLevel) 
    {
        this->tranformData(elasticResponse->nextLevel);
    }
}

void ElasticToSqlResponse::processListStringMap(listMultimapString * listKeyValue ) 
{
    for(listMultimapString::iterator i = listKeyValue->begin(); i != listKeyValue->end(); ++i) 
    {
        this->processStringMultimap(*i);
    }
}
    
void ElasticToSqlResponse::processStringMultimap(multimapString keyValue) 
{
    for(multimapString::iterator it = keyValue.begin();it != keyValue.end(); ++it) 
    {
        if (std::find(this->returnKeys.begin(), this->returnKeys.end(), it->first) != this->returnKeys.end()) 
        {
            sqlResponse->addKeyValue(it->first, it->second);
        }
    }
}

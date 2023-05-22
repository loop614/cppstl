/* 
 * File:   SqlResponse.hpp
 * Author: tony
 * About:
 *
 */
#include <Converters/SqlToElasticRequest.hpp>

//START: public
SqlToElasticRequest::SqlToElasticRequest(SqlRequest * sr, ElasticRequest * er) 
{
    sqlRequest = sr;
    elasticRequest = er;
}

SqlToElasticRequest::~SqlToElasticRequest() {}

void SqlToElasticRequest::tranformData() 
{
    for(vectorString::iterator i = sqlRequest->select.begin(); i != sqlRequest->select.end(); i++) 
    {
        elasticRequest->addKeyValue("contains", *i);
    }
    for(mapString::iterator i = sqlRequest->whereIs.begin(); i != sqlRequest->whereIs.end(); i++) 
    {
        elasticRequest->addKeyValue("bool-must-"+i->first, i->second);
    }
    for(mapString::iterator i = sqlRequest->whereIsNot.begin(); i != sqlRequest->whereIsNot.end(); i++) 
    {
        elasticRequest->addKeyValue("bool-must-not-"+i->first, i->second);
    }
    for(vectorString::iterator i = sqlRequest->groupBy.begin(); i != sqlRequest->groupBy.end(); i++) 
    {
        elasticRequest->addKeyValue("group", *i);
    }
}

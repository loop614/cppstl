/* 
 * File:   ElasticToSqlResponse.hpp
 * Author: tony
 * About:
 *
 */
#ifndef ELASTICTOSQLRESPONSE_HPP
#define ELASTICTOSQLRESPONSE_HPP

#include <Helpers/Common.hpp>
#include <DataClasses/ElasticResponse.hpp>
#include <DataClasses/SqlResponse.hpp>

class ElasticToSqlResponse
{
private:
    ElasticResponse * elasticResponse;
    SqlResponse * sqlResponse;
    vectorString returnKeys;
    
public:
    ElasticToSqlResponse(ElasticResponse * er, SqlResponse * slr, vectorString rks);
    virtual ~ElasticToSqlResponse();

    void tranformData(ElasticResponse* elasticResponse);
    void processListStringMap(listMultimapString * listKeyValue);
    void processStringMultimap(multimapString keyValue);
};

#endif /* ELASTICTOSQLRESPONSE_HPP */


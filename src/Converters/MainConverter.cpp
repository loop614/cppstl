/* 
 * File:   MainConverter.cpp
 * Author: tony
 * About: 
 *
 */
#include <Helpers/Helper.hpp>
#include <Converters/SqlToElasticRequest.hpp>
#include <Converters/ElasticToSqlResponse.hpp>
#include <Converters/MainConverter.hpp>

MainConverter::MainConverter(SqlRequest * sqlr) 
{
    this->sqlRequest = sqlr;
    this->returnKeys = Helper::vectorStringMerge(&sqlr->select, &sqlr->groupBy);
}

MainConverter::~MainConverter() {}

void MainConverter::runQuery() 
{
    ElasticRequest elasticRequest;
    ElasticResponse elasticResponse;
    ElasticConnection elasticConnection;
    SqlResponse sqlResponse;

    Helper::printTitle("SqlRequest");
    sqlRequest->print();
    Helper::printEmptyLines();

    // generates elasticRequest using sqlRequest
    this->translateQueryToElastic(sqlRequest, &elasticRequest);

    Helper::printTitle("ElasticRequest");
    elasticRequest.print();
    Helper::printEmptyLines();

    // generates elasticResponse, dummy elasticsearch data, since there is no real database
    elasticConnection.generateDummyResponseData(&elasticRequest, &elasticResponse);

    Helper::printTitle("ElasticResponse");
    ElasticResponse::printNodes(&elasticResponse, returnKeys.size());
    Helper::printEmptyLines();

    //generates sqlResponse, from the dummy elasticResponse
    sqlResponse.setReturnKeysCount(returnKeys.size());
    this->translateResponseToSql(&elasticResponse, &sqlResponse);

    Helper::printTitle("sqlResponse");
    sqlResponse.print();
}

ElasticRequest * MainConverter::translateQueryToElastic(SqlRequest * sqlRequest, ElasticRequest * elasticRequest) 
{
    SqlToElasticRequest translator(sqlRequest, elasticRequest); 
    translator.tranformData();
    return elasticRequest;
}
    
SqlResponse * MainConverter::translateResponseToSql(ElasticResponse * elasticResponse, SqlResponse * sqlResponse) 
{
    ElasticToSqlResponse translator(elasticResponse, sqlResponse, returnKeys); 
    translator.tranformData(elasticResponse);
    return sqlResponse;
}

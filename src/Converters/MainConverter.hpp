/* 
 * File:   MainConverter.hpp
 * Author: tony
 * About:
 *
 */
#ifndef MAINCONVERTER_HPP
#define MAINCONVERTER_HPP

#include <Helpers/Common.hpp>
#include <Connections/ElasticConnection.hpp>
#include <DataClasses/SqlRequest.hpp>
#include <DataClasses/SqlResponse.hpp>
#include <DataClasses/ElasticRequest.hpp>
#include <DataClasses/ElasticResponse.hpp>

class MainConverter {
    public:
        MainConverter(SqlRequest * slr);
        virtual ~MainConverter();
                
        SqlRequest * sqlRequest;
        vectorString returnKeys;
        
        void runQuery();
        ElasticRequest * translateQueryToElastic(SqlRequest * sqlRequest, ElasticRequest * elasticRequest);
        SqlResponse * translateResponseToSql(ElasticResponse * elasticResponse, SqlResponse * sqlResponse);
};

#endif /* MAINCONVERTER_HPP */

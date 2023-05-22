/* 
 * File:   SqlToElasticRequest.hpp
 * Author: tony
 * About:
 *
 */
#ifndef SQLTOELASTICREQUEST_HPP
#define SQLTOELASTICREQUEST_HPP

#include <DataClasses/SqlRequest.hpp>
#include <DataClasses/ElasticRequest.hpp>
#include <Helpers/Common.hpp>

class SqlToElasticRequest
{
private:
    SqlRequest * sqlRequest;
    ElasticRequest * elasticRequest;
    
public:
    SqlToElasticRequest(SqlRequest * sr, ElasticRequest * er);
    virtual ~SqlToElasticRequest();
    
    void tranformData();
};

#endif /* SQLTOELASTICREQUEST_HPP */
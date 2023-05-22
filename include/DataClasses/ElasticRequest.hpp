/* 
 * File:   ElasticRequest.cpp
 * Author: tony
 * About:
 *
 */
#ifndef ELASTICREQUEST_HPP
#define ELASTICREQUEST_HPP

#include <Helpers/Common.hpp>
#include <DataClasses/BaseDataClass.hpp>

class ElasticRequest : public BaseDataClass
{
    public:
        ElasticRequest();
        virtual ~ElasticRequest();
        listMapString keyValue;
    
        void addKeyValue(std::string k, std::string v);
        void print();
        void printStringMap(mapString keyValue);
        void getByKey(std::string key, vectorString * res);
};

#endif /* ELASTICREQUEST_HPP */
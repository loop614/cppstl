/* 
 * File:   SqlResponse.hpp
 * Author: tony
 * About:
 *
 */
#ifndef SQLRESPONSE_HPP
#define SQLRESPONSE_HPP

#include <Helpers/Common.hpp>
#include <Helpers/Helper.hpp>
#include <DataClasses/BaseDataClass.hpp>

class SqlResponse : public BaseDataClass
{
    public:
        SqlResponse();
        virtual ~SqlResponse();

        mapString keyValueMap;
        std::map<int, mapString> data;
        int returnKeysCount;
        int countMembers = 0;
        int countData = 0;
        
        void addKeyValue(std::string key, std::string value);
        void printMapString(mapString keyValueMap);
        void setReturnKeysCount(int rkc);
        void print();
};

#endif /* SQLRESPONSE_HPP */


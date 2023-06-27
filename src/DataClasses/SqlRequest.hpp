/* 
 * File:   SqlRequest.hpp
 * Author: tony
 * About:
 *
 */
#ifndef SQLREQUEST_HPP
#define SQLREQUEST_HPP

#include <Helpers/Common.hpp>
#include <Helpers/Helper.hpp>
#include <DataClasses/BaseDataClass.hpp>

class SqlRequest : public BaseDataClass
{
    public:
        SqlRequest(
            vectorString Select,
            mapString WhereIs,
            mapString WhereIsNot,
            vectorString GroupBy
        );
        virtual ~SqlRequest();

        vectorString select;
        mapString whereIs;
        mapString whereIsNot;
        vectorString groupBy;
    
        void print();
};

#endif /* SQLREQUEST_HPP */
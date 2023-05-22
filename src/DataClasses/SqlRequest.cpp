/* 
 * File:   SqlRequest.cpp
 * Author: tony
 * About:
 *
 */
#include <DataClasses/SqlRequest.hpp>

SqlRequest::SqlRequest(
        vectorString Select,
        mapString WhereIs,
        mapString WhereIsNot,
        vectorString GroupBy
        ) 
        {
            select = Select;
            whereIs = WhereIs;
            whereIsNot = WhereIsNot;
            groupBy = GroupBy;
        }
SqlRequest::~SqlRequest() {}

void SqlRequest::print() 
{
    std::cout << "SELECT" << std::endl;
    Helper::printTemplateString<vectorString>(this->select);
    std::cout << "WHERE IS" << std::endl;
    Helper::printTemplateMapString<mapString>(this->whereIs);
    std::cout << "WHERE IS NOT" << std::endl;
    Helper::printTemplateMapString<mapString>(this->whereIsNot);
    std::cout << "GROUP BY" << std::endl;
    Helper::printTemplateString<vectorString>(this->groupBy);
}
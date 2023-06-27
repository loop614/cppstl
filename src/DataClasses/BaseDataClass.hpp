/* 
 * File:   BaseConverter.hpp
 * Author: tony
 * About:
 *
 */
#ifndef BASEDATACLASS_HPP
#define BASEDATACLASS_HPP

class BaseDataClass
{
public:
    BaseDataClass() {};
    virtual ~BaseDataClass() {};
    virtual void addKeyValue(std::string key, std::string value) {};
    virtual void print() = 0;
};

#endif /* BASEDATACLASS_HPP */


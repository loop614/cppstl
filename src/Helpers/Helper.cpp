/* 
 * File:   Helper.cpp
 * Author: tony
 * About:
 *
 */
#include <Helpers/Helper.hpp>

/*
template<typename T>
static void printTemplateMapString(T ms) 

template<typename T>
static void printTemplateString(T vs) 
*/

Helper::Helper() {}
Helper::~Helper() {}

vectorString Helper::vectorStringMerge(vectorString * sv1, vectorString * sv2) 
{
    vectorString result;
    result.reserve(sv1->size() + sv1->size());
    result.insert(result.end(), sv1->begin(), sv1->end());
    result.insert(result.end(), sv2->begin(), sv2->end());
    return result;
}

void Helper::print(std::string a) 
{
    std::cout << a << std::endl;
}

void Helper::print(std::string key, std::string value) 
{
    std::cout << key << " --> " << value << std::endl;
}

void Helper::printEmptyLines() 
{
    std::cout << std::endl << std::endl;
}

void Helper::printEmptyLine() 
{
    std::cout << std::endl;
}

void Helper::printTitle(std::string a) 
{
    std::cout << ":::::  ->" + a + "<-  :::::" << std::endl;
}

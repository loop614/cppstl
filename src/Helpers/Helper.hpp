/* 
 * File:   Helper.hpp
 * Author: tony
 * About:
 *
 */
#ifndef HELPER_HPP
#define HELPER_HPP

#include <Helpers/Common.hpp>

class Helper 
{
    private:
        Helper();
        virtual ~Helper();
        
    public:
        static vectorString vectorStringMerge(vectorString * sv1, vectorString * sv2);
        static void print(std::string);
        static void print(std::string, std::string);
        static void printEmptyLines();
        static void printEmptyLine();
        static void printTitle(std::string);
        
        template<typename T>
        static void printTemplateMapString(T ms) 
        {
            for(typename T::iterator i = ms.begin(); i != ms.end(); i++) 
            {
                std::cout << i->first << " " << i->second;
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        template<typename T>
        static void printTemplateString(T vs) 
        {
            for(typename T::iterator i = vs.begin(); i != vs.end(); i++) 
            {
                std::cout << *i << " ";
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
};

#endif /* HELPER_HPP */
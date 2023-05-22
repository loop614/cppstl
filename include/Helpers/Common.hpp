/* 
 * File:   common.hpp
 * Author: tony
 * About:
 *
 */
#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>

#define mapString std::map<std::string, std::string>
#define vectorString std::vector<std::string>
#define multimapString std::multimap<std::string, std::string>
#define pairString std::pair<std::string,std::string>

#define listMapString std::list<mapString>
#define listMultimapString std::list<multimapString>
#define vectorMultimapString std::vector<multimapString>

typedef unsigned int uint;

#endif /* COMMON_HPP */


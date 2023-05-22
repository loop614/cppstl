/* 
 * File:   ElasticResponse.hpp
 * Author: tony
 * About:
 *
 */
#ifndef ELASTICRESPONSE_HPP
#define ELASTICRESPONSE_HPP

#include <Helpers/Common.hpp>
#include <DataClasses/BaseDataClass.hpp>

class ElasticResponse;
typedef ElasticResponse * ElasticResponseNode;

class ElasticResponse : public BaseDataClass
{
    private:
        int depthLevel;
        std::string groupKey;
        
    public:
        ElasticResponse();
        virtual ~ElasticResponse();

        listMultimapString keyValueList;
        ElasticResponseNode nextLevel = NULL;
        
        void addKeyValue(std::string key, std::string value);
        void print() {};
        static void printNodes(ElasticResponse * node, int keyNumber);
        void printListStringMap(listMultimapString listKeyValue, int keyNumber);
        void printStringMultimap(multimapString keyValue);
        void printDepthLevelEmptySpace(int count);
        void setDepthLevel(int dl);
        int getDepthLevel();
        void setGroupKey(std::string gk);
        std::string getGroupKey();
};

#endif /* ELASTICRESPONSE_HPP */

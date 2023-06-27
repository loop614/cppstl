/* 
 * File:   ElasticConnection.hpp
 * Author: tony
 * About:
 *
 */
#include <DataClasses/ElasticResponse.hpp>
#include <DataClasses/ElasticRequest.hpp>

class ElasticConnection 
{
    public:
        ElasticConnection();
        virtual ~ElasticConnection();
        void generateDummyResponseData(ElasticRequest * elasticRequest, ElasticResponse * elasticResponse);
        void addNewLevel(ElasticResponse * elasticResponse, int depthLevel, std::string groupKey, bool createNext);
};

#include <Helpers/Common.hpp>
#include <DataClasses/SqlRequest.hpp>
#include <DataClasses/SqlResponse.hpp>
#include <Converters/MainConverter.hpp>

int main()
{
    vectorString select;
    mapString whereIs;
    mapString whereIsNot;
    vectorString groupBy;

    select.push_back("ecuNotVisibleEvent");
    select.push_back("lostPowerEvent");
    select.push_back("channelBusyEvent");
    whereIs.insert(pairString("lowBattery", "true"));
    whereIsNot.insert(pairString("countyId", "19577"));
    groupBy.push_back("carModelId");
    groupBy.push_back("customerId");
    groupBy.push_back("countryId");
    groupBy.push_back("datetime");

    SqlRequest sqlRequest(select, whereIs, whereIsNot, groupBy);
    MainConverter elasticConnection(&sqlRequest);
    elasticConnection.runQuery();

    return 0;
}

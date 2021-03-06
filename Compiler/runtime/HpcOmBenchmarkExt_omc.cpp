#include "openmodelica.h"
#include "meta_modelica.h"
#define ADD_METARECORD_DEFINITIONS static
#include "OpenModelicaBootstrappingHeader.h"
#include "HpcOmBenchmarkExt.cpp"

extern "C" {
extern void* HpcOmBenchmarkExt_requiredTimeForOp()
{
  return HpcOmBenchmarkExtImpl__requiredTimeForOp();
}

extern void* HpcOmBenchmarkExt_requiredTimeForComm()
{
  return HpcOmBenchmarkExtImpl__requiredTimeForComm();
}

extern void* HpcOmBenchmarkExt_readCalcTimesFromXml(const char *filename)
{
  return HpcOmBenchmarkExtImpl__readCalcTimesFromXml(filename);
}

extern void* HpcOmBenchmarkExt_readCalcTimesFromJson(const char *filename)
{
  return HpcOmBenchmarkExtImpl__readCalcTimesFromJson(filename);
}
}

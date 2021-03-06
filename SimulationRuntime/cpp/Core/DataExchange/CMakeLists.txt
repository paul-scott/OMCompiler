cmake_minimum_required (VERSION 2.8.6)

project(${DataExchangeName})

add_library(${DataExchangeName} SHARED SimData.cpp FactoryExport.cpp XmlPropertyReader.cpp)

IF(NOT BOOST_STATIC_LINKING)
	target_link_libraries (${DataExchangeName} ${Boost_LIBRARIES} ${ExtensionUtilitiesName})
ENDIF(NOT BOOST_STATIC_LINKING)

include_directories(${SUNDIALS_INCLUDE_DIR}/cvodes ${SUNDIALS_INCLUDE_DIR}/nvector  ${SUNDIALS_INCLUDE_DIR}/sundials ${SUNDIALS_INCLUDE_DIR})
add_precompiled_header(${DataExchangeName} Include/Core/Modelica.h)

add_library(${DataExchangeName}_static STATIC SimData.cpp XmlPropertyReader.cpp)
set_target_properties(${DataExchangeName}_static PROPERTIES COMPILE_DEFINITIONS "RUNTIME_STATIC_LINKING")

IF(NOT BOOST_STATIC_LINKING)
	target_link_libraries (${DataExchangeName}_static ${Boost_LIBRARIES})
ENDIF(NOT BOOST_STATIC_LINKING)

if (UNIX)
	set_target_properties(${DataExchangeName}_static PROPERTIES COMPILE_FLAGS -fPIC)
endif(UNIX)

install (TARGETS ${DataExchangeName} DESTINATION ${LIBINSTALLEXT})
install (TARGETS ${DataExchangeName}_static DESTINATION ${LIBINSTALLEXT})

install (FILES  ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/IHistory.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/ISimVar.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/SimData.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/Writer.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/SimDouble.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/SimBoolean.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/XmlPropertyReader.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/IPropertyReader.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/FactoryExport.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/FactoryPolicy.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/DefaultContainerManager.h
                ${CMAKE_SOURCE_DIR}/Include/Core/DataExchange/ParallelContainerManager.h
  DESTINATION include/omc/cpp/Core/DataExchange)







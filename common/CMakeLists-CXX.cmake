
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

ENABLE_TESTING()
CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/versionInfo.h.in" "${PROJECT_SOURCE_DIR}/versionInfo.h")

FIND_PACKAGE(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
IF(CUNIT_FOUND)
	INCLUDE_DIRECTORIES(${CUNIT_INCLUDE_DIR})
ENDIF()

FIND_PACKAGE(BISON REQUIRED)
FIND_PACKAGE(FLEX REQUIRED)
BISON_TARGET(parser parserVersion-C++/parser.yy  ${PROJECT_SOURCE_DIR}/parserVersion-C++/parser.cc)
FLEX_TARGET(lexer parserVersion-C++/scanner.ll  ${PROJECT_SOURCE_DIR}/parserVersion-C++/scanner.cc)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)

ADD_EXECUTABLE(main main.cpp common.cpp) 
ADD_EXECUTABLE(parserVersionTest common.cpp parserVersion-C++/version-c++.cc parserVersion-C++/driver.cc ${FLEX_lexer_OUTPUTS} ${BISON_parser_OUTPUTS})
ADD_EXECUTABLE(testing-v${octetos-toolkit-common_VERSION_MAJOR} tests/v${octetos-toolkit-common_VERSION_MAJOR}.cc common.cpp parserVersion-C++/driver.cc ${FLEX_lexer_OUTPUTS} ${BISON_parser_OUTPUTS})
TARGET_LINK_LIBRARIES(testing-v${octetos-toolkit-common_VERSION_MAJOR} ${CUNIT_LIBRARY})

ADD_LIBRARY(${PROJECT_NAME}-c++ STATIC common-parser.cpp common.cpp parserVersion-C++/driver.cc ${FLEX_lexer_OUTPUTS} ${BISON_parser_OUTPUTS})

INSTALL(TARGETS ${PROJECT_NAME}-c++ DESTINATION lib/octetos/toolkit/common/)
INSTALL(FILES common.hpp DESTINATION include/octetos/toolkit/common/)
SET(CPACK_PACKAGE_NAME "${PROJECT_NAME}-c++")

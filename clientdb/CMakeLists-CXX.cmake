
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
SET(octetos-toolkit-clientdb_VERSION_STAGE "beta")
CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/versionInfo.h.in" "${PROJECT_SOURCE_DIR}/versionInfo.h")

FIND_PACKAGE(octetos-toolkit-common-c++ REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/toolkit/)
IF(OCTETOS_TOOLKIT_COMMON_CPP_FOUND)
   INCLUDE_DIRECTORIES(${OCTETOS_TOOLKIT_COMMON_CPP_INCLUDE_DIR})
ELSE()
        MESSAGE(FATAL_ERROR "No se encontro toolkit-common.")
ENDIF()
IF(NOT SERVER)
	MESSAGE(FATAL_ERROR "Use la variable SERVER para indicar el el typo de base de datos.")
ELSEIF(${SERVER} STREQUAL "MYSQL")
	MESSAGE("El Servidor seleccionado es MySQL ...")
	FIND_PACKAGE(MySQL REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
	IF(MySQL_FOUND)
	   INCLUDE_DIRECTORIES(${MYSQL_INCLUDE_DIR})
	ENDIF()
	ADD_EXECUTABLE(developing clientdb.cpp clientdb-mysql.cpp developing.cpp)
	TARGET_LINK_LIBRARIES(developing ${OCTETOS_TOOLKIT_COMMON_CPP_LIBRARY} ${MYSQL_LIBRARY} )
	ADD_LIBRARY(${PROJECT_NAME}-myc++ STATIC clientdb.cpp clientdb-mysql.cpp)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME}-myc++ ${OCTETOS_TOOLKIT_COMMON_CPP_LIBRARY} ${MYSQL_LIBRARY})
	INSTALL(TARGETS ${PROJECT_NAME}-myc++ DESTINATION lib/octetos/toolkit/clientdb)
	INSTALL(FILES clientdb.hpp DESTINATION include/octetos/toolkit/clientdb)
	INSTALL(FILES clientdb-mysql.hpp DESTINATION include/octetos/toolkit/clientdb)
	SET(CPACK_PACKAGE_NAME "${PROJECT_NAME}-myc++")
ELSEIF(${SERVER} STREQUAL "POSTGRESQL")
	MESSAGE("El Servidor seleccionado es PostgreSQL ...")
	FIND_PACKAGE(PostgreSQL REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
	IF(PostgreSQL_FOUND)
		INCLUDE_DIRECTORIES(${POSTGRESQL_INCLUDE_DIR})
	ENDIF()
	ADD_EXECUTABLE(postgresql clientdb.cpp clientdb-postgresql.cpp postgresql.cpp)
	TARGET_LINK_LIBRARIES(postgresql ${OCTETOS_TOOLKIT_COMMON_CPP_LIBRARY} ${POSTGRESQL_LIBRARIES} )
	ADD_LIBRARY(toolkit-clientdb-c++-postgresql STATIC clientdb.cpp clientdb-postgresql.cpp)
	TARGET_LINK_LIBRARIES(postgresql-c++ ${OCTETOS_TOOLKIT_COMMON_CPP_LIBRARY} ${POSTGRESQL_LIBRARIES} )
	INSTALL(TARGETS postgresql-c++ DESTINATION lib/toolkit/clientdb)
	INSTALL(FILES clientdb.hpp DESTINATION include/toolkit/clientdb)
	INSTALL(FILES clientdb-postgresql.hpp DESTINATION include/toolkit/clientdb)
	SET(CPACK_PACKAGE_NAME "${PROJECT_NAME}-pqc++")
ENDIF()

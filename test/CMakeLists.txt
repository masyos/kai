# kai test

cmake_minimum_required(VERSION 3.5)

project(ozen_test)

if (MSVC)
    add_definitions(-D_UNICODE)
    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_DEBUG            ${CMAKE_C_FLAGS_DEBUG})
    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_MINSIZEREL       ${CMAKE_C_FLAGS_MINSIZEREL})
    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_RELEASE          ${CMAKE_C_FLAGS_RELEASE})
    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_RELWITHDEBINFO   ${CMAKE_C_FLAGS_RELWITHDEBINFO})
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_DEBUG          ${CMAKE_CXX_FLAGS_DEBUG})
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_MINSIZEREL     ${CMAKE_CXX_FLAGS_MINSIZEREL})
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE        ${CMAKE_CXX_FLAGS_RELEASE})
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
endif ()

if (UNIX)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(extlib/googletest)

include_directories(../include)
include_directories(${googletest_BINARY_DIR}/include)
link_directories(${googletest_BINARY_DIR}/lib)

set(HEADER
)

set(SOURCE
	u8ctype_cx_test.cpp
	u8str_utils_cx_test.cpp
)

set(EXTLIB
	../include/ozen/ozen_algo_cx.h
	../include/ozen/ozen_u8_utils_cx.h
)

add_executable(
	ozen_test 
	${HEADER}
	${SOURCE}
	${EXTLIB}
)

target_link_libraries(ozen_test gtest)
target_link_libraries(ozen_test gtest_main)


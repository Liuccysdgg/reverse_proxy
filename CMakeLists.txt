cmake_minimum_required(VERSION 3.5)

project(kernel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME}
    main.cpp
)

install(TARGETS kernel
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


# 需要修改该路径
set(NEWOBJ_PATH "/home/ubuntu/lib")


if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")
elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))

endif()

include_directories(${NEWOBJ_PATH}/newobj/project/)
include_directories(${NEWOBJ_PATH}/newobj/module/)
include_directories(${NEWOBJ_PATH}/newobj/src/)
include_directories(${NEWOBJ_PATH}/newobj/thirdparty/)
include_directories(${NEWOBJ_PATH}/newobj/include/)
include_directories(${NEWOBJ_PATH}/include/clickhouse/clickhouse)
include_directories(${NEWOBJ_PATH}/include/clickhouse)
include_directories(${NEWOBJ_PATH}/include)

add_definitions(-DNEWOBJ_STATIC -std=c++17)

set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/../)

target_link_libraries(${PROJECT_NAME} PUBLIC
    # newobj 及依赖
    ${NEWOBJ_PATH}/lib/libmodule_network_debug.a
    ${NEWOBJ_PATH}/lib/libthirdparty_mysql_debug.a
    ${NEWOBJ_PATH}/lib/libthirdparty_redis_debug.a
	${NEWOBJ_PATH}/lib/libthirdparty_clickhouse_debug.a
    ${NEWOBJ_PATH}/lib/libhpsocket_d.so
    ${NEWOBJ_PATH}/lib/libnewobj_debug.a
    ${NEWOBJ_PATH}/lib/libclickhouse-cpp-lib.a
    ${NEWOBJ_PATH}/lib/libabsl_int128.a
    ${NEWOBJ_PATH}/lib/libcityhash.a
    ${NEWOBJ_PATH}/lib/liblz4.a
    ${NEWOBJ_PATH}/lib/liblog4cplus.so
    
    # 系统库
    libmysqlcppconn.so
    libmysqlclient.so
    libssl.a
    libcrypto.a
    libhiredis.a
    libpthread.so
)

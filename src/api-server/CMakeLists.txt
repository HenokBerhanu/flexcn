################################################################################
# Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.
# The OpenAirInterface Software Alliance licenses this file to You under
# the OAI Public License, Version 1.1  (the "License"); you may not use this file
# except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.openairinterface.org/?page_id=698
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#-------------------------------------------------------------------------------
# For more information about the OpenAirInterface (OAI) Software Alliance:
#      contact@openairinterface.org
################################################################################

set(FLEXCN_API_SERVER_DIR "${SRC_TOP_DIR}/api-server")

include_directories(${FLEXCN_API_SERVER_DIR}/api)
include_directories(${FLEXCN_API_SERVER_DIR}/impl)
include_directories(${FLEXCN_API_SERVER_DIR}/model)
include_directories(${FLEXCN_API_SERVER_DIR}/)
include_directories(${SRC_TOP_DIR}/flexcn_app)
include_directories(${SRC_TOP_DIR}/itti)
include_directories(${SRC_TOP_DIR}/common)
include_directories(${SRC_TOP_DIR}/common/msg)
include_directories(${SRC_TOP_DIR}/common/utils)
include_directories(${SRC_TOP_DIR}/common/utils/bstr)
include_directories(${SRC_TOP_DIR}/common/nas)
include_directories(${SRC_TOP_DIR}/pfcp)
include_directories(${SRC_TOP_DIR}/udp)
include_directories(${SRC_TOP_DIR}/../build/ext/spdlog/include)

include_directories(${SRC_TOP_DIR}/iapps)

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()

file(GLOB FLEXCN_API_SERVER_src_files
    ${FLEXCN_API_SERVER_DIR}/flexcn-http2-server.cpp
    ${FLEXCN_API_SERVER_DIR}/flexcn-api-server.cpp
    ${FLEXCN_API_SERVER_DIR}/model/*.cpp
)

if(WITH_5G)
  list(APPEND FLEXCN_API_SERVER_src_files
    ${FLEXCN_API_SERVER_DIR}/api/EventNotifyApi.cpp
    ${FLEXCN_API_SERVER_DIR}/api/NorthBound5GApi.cpp
    ${FLEXCN_API_SERVER_DIR}/impl/EventNotifyApiImpl.cpp
    ${FLEXCN_API_SERVER_DIR}/impl/NorthBound5GApiImpl.cpp
  )
endif(WITH_5G)

if(WITH_4G)
  list(APPEND FLEXCN_API_SERVER_src_files
  ${FLEXCN_API_SERVER_DIR}/api/NorthBound4GApi.cpp
  ${FLEXCN_API_SERVER_DIR}/impl/NorthBound4GApiImpl.cpp
  )
endif(WITH_4G)

add_library(FLEXCN_API STATIC
           ${FLEXCN_API_SERVER_src_files})
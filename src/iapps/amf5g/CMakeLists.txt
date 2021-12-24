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

set(FLEXCN_5G_AMF_DIR "${SRC_TOP_DIR}/iapps/amf5g")
set(FLEXCN_API_SERVER_DIR "${SRC_TOP_DIR}/api-server")

include_directories(${FLEXCN_API_SERVER_DIR}/api)
include_directories(${FLEXCN_API_SERVER_DIR}/impl)
include_directories(${FLEXCN_API_SERVER_DIR}/model)
include_directories(${FLEXCN_5G_AMF_DIR}/..)
include_directories(${SRC_TOP_DIR}/flexcn_app)
include_directories(${SRC_TOP_DIR}/itti)
include_directories(${SRC_TOP_DIR}/common)
include_directories(${SRC_TOP_DIR}/common/msg)
include_directories(${SRC_TOP_DIR}/common/utils)
include_directories(${SRC_TOP_DIR}/../build/ext/spdlog/include)

list(APPEND FLEXCN_5G_AMF_SERVICE_src_files
    ${FLEXCN_5G_AMF_DIR}/amf_app.cpp
)

if(WITH_CASSANDRA)
  list(APPEND FLEXCN_5G_AMF_SERVICE_src_files
    ${FLEXCN_5G_AMF_DIR}/cassandra_amf_5g_db.cpp
  )
else()
  list(APPEND FLEXCN_5G_AMF_SERVICE_src_files
    ${FLEXCN_5G_AMF_DIR}/local_amf_5g_db.cpp
  )
endif()

add_library(FLEXCN_SRV_5G_AMF STATIC
    ${FLEXCN_5G_AMF_SERVICE_src_files}
    )
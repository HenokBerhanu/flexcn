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

if(WITH_4G)
  ADD_SUBDIRECTORY(./service4g)
endif(WITH_4G)

if(WITH_5G_SMF)
  ADD_SUBDIRECTORY(./smf5g)
endif(WITH_5G_SMF)

if(WITH_5G_AMF)
  ADD_SUBDIRECTORY(./amf5g)
endif(WITH_5G_AMF)
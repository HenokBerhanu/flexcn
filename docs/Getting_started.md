# GETTING STARTED 

## Prerequisites

Currently, we only support Ubuntu 18.04, therefore, we recommend using docker to install FlexCN. At the moment of writing, FlexCN works only with OAI's CN. For other CNs, it might work in theory but we have not tested it yet and you might miss some features that OAI's CN offers. 

FlexCN can be installed on the host machine or inside a docker container. Let's dive in the first option. 

## Bare-metal installation

On this option, we assume that you have a fresh installation of Ubuntu 18 on your host machine. Otherwise, you might face some unexpected errors.
```
## pick an empty folder that you will clone the source of flexcn
$ cd /an/empty/folder/
## clone this repo
$ git clone https://gitlab.eurecom.fr/mosaic5g/flexcn.git
$ cd flexcn
## set up the ROOT env variable
$ export OPENAIRM5G_DIR=`pwd`
## verify 
$ echo $OPENAIRM5G_DIR
## install some dependencies
$ sudo apt-get update 
$ sudo apt-get upgrade --yes
$ sudo apt-get install --yes \
    psmisc \
    git \
    libssl1.1 \
    libkrb5-3 zlib1g
$ sudo rm -rf /var/lib/apt/lists/*
$ git config --global https.postBuffer 123289600
$ git config --global http.sslverify false
$ cd build/scripts
$ ./build_flexcn --install-deps --force

## set up the target you would like to build: '5g_smf', '5g_amf' or '5g_smf,5g_amf'
## '5g_smf' means you would like to use only SMF. 
## '5g_amf' means you would like to use only AMF. 
## '5g_smf,5g_amf' means you would like to use both.
## Note: This is only for building process, it does NOT mean FlexCN automatic connect to SMF/AMF for you.
## You still need to trigger the subscription MANUALLY. 
$ export TARGET='5g_smf,5g_amf'
$ echo $TARGET
$ ./build_flexcn --clean --Verbose --build-type Release --jobs -t $TARGET

## now flexcn is installed on your host
## open file ./build/scripts/flexcn_conf.sh and change the value according to your settings
## if you use oai-5g-fed to deploy the OAI's CN using docker and OAI's settings, you could keep
## this file as it is. However, if you have your own deployment, please change it accordingly.

## After changing, run that script to generate the config file
$ ./flexcn_conf.sh
## Now your config is stored at /usr/local/etc/oai/flexcn.conf
```

At this stage you can deploy your 5G CN as in [this section](#deploy-5g-cn). 

If you prefer Docker, let's look at the next section. 

## Install with docker
For any purpose, please make sure that you have `docker` installed on your computer by following the tutorial [here](https://docs.docker.com/get-docker/). 

Below are our settings:
```
$ uname -a
Linux XXXXXXXXX 5.11.0-41-generic #45~20.04.1-Ubuntu SMP Wed Nov 10 10:20:10 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
$ docker --version
Docker version 20.10.9, build c2ea9b
```
Note that: Ubuntu version 20 is the host machine while Ubuntu 18 is the docker environment where flexcn runs. To be able to reproduce our settings, we recommend you to have the same version of docker and environment. Other versions of docker and environment should work in theory. But in practice, there are always risks.

## Build FlexCN from scratch

Please follows the instructions below:

```
$ cd an/empty/folder/that/you/have/
$ git clone https://gitlab.eurecom.fr/mosaic5g/flexcn.git
$ cd flexcn ## replace the value with path of flexcn root folder. 
$ bash scripts/build_image.sh
```
Now you should have a flexcn image ready to work.

If you don't follow the standard environment that we deploy here, please change the configuration for FlexCN image accordingly in this [docker file](docker/docker-compose.flexcn.yaml).

## Deploy 5G CN

Please follow the instructions below. 
NOTE: In this tutorial, `FLEXCN_ROOT` refers to the root folder of this repo, aka the parent directory of this file.

The first step is to deploy the Core Network and a simulator for RAN and UE. The current version of FlexCN works with the `develop` branch of OAI's AMF and SMF. For other components, you could use the `master` branch.  

Here, we assume that you don't have OAI's CN on your machine: 

```
## this useful scripts helps you pull all the required OAI's NF for CN to test FlexCN.
## NOTE: THIS MIGHT OVERWRITE THE NAME OF YOUR IMAGE IF YOU HAVE IMAGE OF OAI'S CN IN YOUR COMPUTER. CHECK BEFORE RUN. 
$ bash scripts/pull_5g_testbed.sh 
$ docker image ls
oai-smf                        latest            e2e195098f96   5 days ago       296MB
oai-amf                        latest            6101b9a6f92e   6 days ago       300MB
oai-upf-vpp                    latest            771089b07814   8 days ago       937MB
ueransim                       latest            d515d8df759c   3 weeks ago      141MB
oai-nrf                        latest            b4ad85dd88a8   8 weeks ago      251MB
oai-udr                        latest            ad0d4c5d9d99   8 weeks ago      237MB
oai-udm                        latest            fd50c6d4be16   8 weeks ago      272MB
oai-ausf                       latest            42ae6579fd24   8 weeks ago      274MB
$ ## please verify that you could download from eurecom's gitlab. Contact us if you can't.
$ ## assume that you are at flexcn folder. 
$ cd .. 
$ git clone https://gitlab.eurecom.fr/oai/cn5g/oai-cn5g-fed.git
$ cd oai-cn5g-fed
## This folder will be call FED_ROOT
## before launch the CN, make sure to run this 
$ sudo sysctl net.ipv4.conf.all.forwarding=1
$ sudo iptables -P FORWARD ACCEPT
```

The cleaning steps below are recommended. Otherwise, you might get some unwanted errors. We recommend having no docker's running networks and containers before deploying FlexCN and OAI's CN to avoid unnecessary problems. 

```
## stop all containers
$ docker kill $(docker ps -q)
## if you get this error: ""docker kill" requires at least 1 argument.", 
## basically, it means you don't have any docker running, simply ignore and continue.

## clean unused network, please change accordingly to your case if necessary
## This is to avoid the overlap address space.
$ docker network prune 
```

Open file: `docker-compose/docker-compose-basic-vpp-nrf.yaml` and adding those line under AMF service, sections `environment`: 

```
        - INT_ALGO_LIST=["NIA1" , "NIA2"]
        - CIPH_ALGO_LIST=["NEA1" , "NEA2"]
``` 

With later releases of OAI-CN, in theory, you don't need to do this anymore. 
Continue:
```
$ docker-compose -f docker-compose/docker-compose-basic-vpp-nrf.yaml up -d
## open on another terminal, make sure all the containers are in a healthy state before moving on to the next steps
$ watch docker ps 
CONTAINER ID   IMAGE                         COMMAND                  CREATED          STATUS                      PORTS                          NAMES
000e302e8f9d   oai-smf:latest       "/bin/bash /openair-…"   32 minutes ago   Up 32 minutes (healthy)     80/tcp, 9090/tcp, 8805/udp     oai-smf
4dcf2f9aad65   oai-amf:latest       "/bin/bash /openair-…"   32 minutes ago   Up 32 minutes (healthy)     80/tcp, 9090/tcp, 38412/sctp   oai-amf
baece2e4e70b   oai-ausf:latest      "/bin/bash /openair-…"   32 minutes ago   Up 32 minutes (healthy)     80/tcp                         oai-ausf
5ac1766e1683   ubuntu:bionic                 "/bin/bash -c ' apt …"   32 minutes ago   Up 32 minutes                                              oai-ext-dn
dd2b0a1b663f   oai-udm:latest       "/bin/bash /openair-…"   32 minutes ago   Up 32 minutes (healthy)     80/tcp                         oai-udm
b2d4e7c2c5d2   oai-udr:latest       "/bin/bash /openair-…"   32 minutes ago   Up 32 minutes (healthy)     80/tcp                         oai-udr
b0979ec0023c   oai-upf-vpp:latest   "/openair-upf/bin/en…"   32 minutes ago   Up 32 minutes (healthy)     2152/udp, 8085/udp             vpp-upf
ce18401dd006   oai-nrf:latest       "/bin/bash /openair-…"   32 minutes ago   Up 32 minutes (healthy)     80/tcp, 9090/tcp               oai-nrf
1dd52acb8cf2   mysql:5.7            "docker-entrypoint.s…"   32 minutes ago   Up 32 minutes (healthy)     3306/tcp, 33060/tcp            mysql
```

## Usage:

After that, wait for few seconds so our CN become stable.
### IF YOU INSTALL FLEXCN ON THE HOST:
```
$ cd $FLEXCN_ROOT
$ sudo flexcn -c /usr/local/etc/oai/flexcn.conf -o
## open another terminal, assume you are still in the SAME folder 
## trigger FlexCN to subscribe both AMF and SMF, feel free to check the content of this script
$ bash ./scripts/subscribe.sh host 
$ bash ./scripts/query.sh host
[AMF:,SMF:] 
## you will get no output here since this is no UE connected to CN. 
## launch the ueransim
$ cd $FED_ROOT
$ docker-compose -f docker/docker-compose-ueransim-vpp.yaml up -d
## wait a few seconds 
## now you can try again to query FlexCN using its API (limited at this moment)
$ cd $FLEXCN_ROOT
$ bash ./scripts/query.sh host
[AMF:[
    "{\"notifyCorrelationId\":\"192.168.70.142:80/flexcn-status-notify/v1/amf001\",\"reportList\":[{\"state\":{\"active\":\"TRUE\"},\"supi\":\"imsi-208950000000031\",\"timeStamp\":\"3849335315\",\"type\":\"REGISTRATION_STATE_REPORT\"}]}",
    "{\"notifyCorrelationId\":\"192.168.70.142:80/flexcn-status-notify/v1/amf001\",\"reportList\":[{\"state\":{\"active\":\"TRUE\"},\"supi\":\"imsi-208950000000031\",\"timeStamp\":\"3849335315\",\"type\":\"REGISTRATION_STATE_REPORT\"}]}"
],SMF:[
    "{\"eventNotifs\":[{\"dddStatus\":\"TRANSMITTED\",\"event\":\"DDDS\",\"pduSeId\":0,\"supi\":\"208950000000031\",\"timeStamp\":\"3849335316\"}],\"notifId\":\"notifid01\"}",
    "{\"eventNotifs\":[{\"customized_data\":{\"amf_addr\":\"192.168.70.132\",\"dnn\":\"default\",\"pdu_session_type\":\"IPV4\",\"plmn\":{\"mcc\":\"208\",\"mnc\":\"95\"},\"qos_flow\":[{\"an_addr\":{\"ipv4\":\"192.168.72.141\"},\"qfi\":6,\"upf_addr\":{\"ipv4\":\"192.168.72.202\"}}],\"snssai\":{\"sd\":\"123\",\"sst\":222},\"ue_ipv4_addr\":\"12.2.1.2\"},\"event\":\"FLEXCN\",\"pduSeId\":1,\"supi\":\"208950000000031\",\"timeStamp\":\"3849335316\"}],\"notifId\":\"notifid01\"}"
]] 
## you will see some outputs here. Congrats!!
```

### OTHERWISE, IF YOU INSTALL FLEXCN USING DOCKER:
``` 
# assume that you are at oai-5gcn-fed folder
$ cd $FLEXCN_ROOT 
$ docker tag flexcn:prealpha oai-flexcn:prealpha
$ docker-compose -f docker/docker-compose.flexcn.yaml up -d
## wait a few seconds
$ bash ./scripts/subscribe.sh docker 
$ bash ./scripts/query.sh docker
[AMF:,SMF:] 
## you will get no output here since this is no UE connected to CN. 
## launch the ueransim
$ cd $FED_ROOT
$ docker-compose -f docker/docker-compose-ueransim-vpp.yaml up -d
## wait a few seconds 
## now you can try again to query FlexCN using its API (limited at this moment)
$ cd $FLEXCN_ROOT
$ bash ./scripts/query.sh host
[AMF:[
    "{\"notifyCorrelationId\":\"192.168.70.142:80/flexcn-status-notify/v1/amf001\",\"reportList\":[{\"state\":{\"active\":\"TRUE\"},\"supi\":\"imsi-208950000000031\",\"timeStamp\":\"3849335315\",\"type\":\"REGISTRATION_STATE_REPORT\"}]}",
    "{\"notifyCorrelationId\":\"192.168.70.142:80/flexcn-status-notify/v1/amf001\",\"reportList\":[{\"state\":{\"active\":\"TRUE\"},\"supi\":\"imsi-208950000000031\",\"timeStamp\":\"3849335315\",\"type\":\"REGISTRATION_STATE_REPORT\"}]}"
],SMF:[
    "{\"eventNotifs\":[{\"dddStatus\":\"TRANSMITTED\",\"event\":\"DDDS\",\"pduSeId\":0,\"supi\":\"208950000000031\",\"timeStamp\":\"3849335316\"}],\"notifId\":\"notifid01\"}",
    "{\"eventNotifs\":[{\"customized_data\":{\"amf_addr\":\"192.168.70.132\",\"dnn\":\"default\",\"pdu_session_type\":\"IPV4\",\"plmn\":{\"mcc\":\"208\",\"mnc\":\"95\"},\"qos_flow\":[{\"an_addr\":{\"ipv4\":\"192.168.72.141\"},\"qfi\":6,\"upf_addr\":{\"ipv4\":\"192.168.72.202\"}}],\"snssai\":{\"sd\":\"123\",\"sst\":222},\"ue_ipv4_addr\":\"12.2.1.2\"},\"event\":\"FLEXCN\",\"pduSeId\":1,\"supi\":\"208950000000031\",\"timeStamp\":\"3849335316\"}],\"notifId\":\"notifid01\"}"
]] 
## you will see some outputs here. Congrats!!
```

Now you received the data from CN.

## KNOWN ISSUES: 
If you are facing some problems of PDU's establiment when UE connects to CN, try restarting CN, FlexCN, UERANSIM. Normally, it should resolve the issue.

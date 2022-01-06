if [[ "$1" == "docker" ]]; then
    FLEXCN_IP="192.168.70.142"
elif [[ "$1" == "host" ]]; then
    FLEXCN_IP="192.168.70.1"
else
    echo "This argument are not supported. Only [docker, host] are supported."
    exit 1
fi 

echo "Assume we connectd to a single CN with IP: ${FLEXCN_IP}"

echo "Subscribe for AMF"
curl -X GET http://${FLEXCN_IP}:80/nxapp/v1/trigger_subcribe/amf #> /dev/null 2>&1

echo "Subscribe for SMF"
curl -X GET http://${FLEXCN_IP}:80/nxapp/v1/trigger_subcribe/smf #> /dev/null 2>&1

echo "Triggered FlexCN. Now connect RAN and UE to CN and try to query FlexCN."

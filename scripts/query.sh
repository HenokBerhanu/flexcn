if [[ "$1" == "docker" ]]; then
    FLEXCN_IP="192.168.70.142"
elif [[ "$1" == "host" ]]; then
    FLEXCN_IP="192.168.70.1"
else
    echo "This argument are not supported. Only [docker, host] are supported."
    exit 1
fi 

echo "Assume we connectd to a single CN with IP: ${FLEXCN_IP}"

curl -X GET http://${FLEXCN_IP}:80/nxapp/v1/stats
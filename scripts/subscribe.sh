echo "Assume we connectd to a single CN:"

echo "Subscribe for AMF"
curl -X GET http://192.168.70.142:80/nxapp/v1/trigger_subcribe/amf > /dev/null 2>&1

echo "Subscribe for SMF"
curl -X GET http://192.168.70.142:80/nxapp/v1/trigger_subcribe/smf > /dev/null 2>&1

echo "Triggered FlexCN. Now connect RAN and UE to CN and try to query FlexCN."

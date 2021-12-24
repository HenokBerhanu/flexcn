docker pull rdefosseoai/oai-amf:develop 
docker tag rdefosseoai/oai-amf:develop oai-amf:latest
echo "Pulled OAI AMF"

docker pull rdefosseoai/oai-smf:develop 
docker tag rdefosseoai/oai-smf:develop oai-smf:latest
echo "Pulled OAI SMF"

docker pull rdefosseoai/oai-upf-vpp:latest 
docker tag rdefosseoai/oai-upf-vpp:latest oai-upf-vpp:latest
echo "Pulled OAI UPF VPP"

docker pull rdefosseoai/oai-nrf:latest 
docker tag rdefosseoai/oai-nrf:latest oai-nrf:latest
echo "Pulled OAI NRF"

docker pull rdefosseoai/oai-udr:latest 
docker tag rdefosseoai/oai-udr:latest oai-udr:latest
echo "Pulled OAI UDR"

docker pull rdefosseoai/oai-udm:latest 
docker tag rdefosseoai/oai-udm:latest oai-udm:latest
echo "Pulled OAI UDM"

docker pull rdefosseoai/oai-ausf:latest 
docker tag rdefosseoai/oai-ausf:latest oai-ausf:latest
echo "Pulled OAI AUSF"

docker pull rohankharade/ueransim 
docker tag rohankharade/ueransim:latest ueransim:latest
echo "Pulled UERANSIM"

echo "All the components of test are pulled."

echo "Adding the list of bearer to FlexCN ....."
curl -X POST http://192.168.74.2:80/n4g/v1/bearer -d '{"eps_bearer_id":1,"eps_meter_id":2, "imsi":"208950000000009", "s1_ul_teid":"0x3", "s1_dl_teid":"0x4", "ue_ip":"172.16.0.2", "enb_ip":"192.168.0.3"}'
curl -X POST http://192.168.74.2:80/n4g/v1/bearer -d '{"eps_bearer_id":2,"eps_meter_id":2, "imsi":"208950000000009", "s1_ul_teid":"0x5", "s1_dl_teid":"0x6", "ue_ip":"172.16.0.3", "enb_ip":"192.168.0.5"}'
curl -X POST http://192.168.74.2:80/n4g/v1/bearer -d '{"eps_bearer_id":2,"eps_meter_id":2, "imsi":"208950000000010", "s1_ul_teid":"0x5", "s1_dl_teid":"0x6", "ue_ip":"172.16.0.3", "enb_ip":"192.168.0.5"}'
curl -X POST http://192.168.74.2:80/n4g/v1/bearer -d '{"eps_bearer_id":8,"eps_meter_id":8, "imsi":"208950000000088", "s1_ul_teid":"0x5", "s1_dl_teid":"0x6", "ue_ip":"172.16.0.3", "enb_ip":"192.168.0.5"}'
curl -X POST http://192.168.74.2:80/n4g/v1/bearer -d '{"eps_bearer_id":9,"eps_meter_id":9, "imsi":"208950000000099", "s1_ul_teid":"0x5", "s1_dl_teid":"0x6", "ue_ip":"172.16.0.3", "enb_ip":"192.168.0.5"}'


echo "Getting the list of bearer inside FlexCN ....."
curl -X GET http://192.168.74.2:80/n4g/v1/bearer

echo "Getting a single bearer by imsi 208950000000009 eps bearer id 2 ....."
curl -X GET http://192.168.74.2:80/n4g/v1/bearer/imsi_bearer/208950000000009,2

echo "Getting a single bearer by FlexCN internal id 3 ....."
curl -X GET http://192.168.74.2:80/n4g/v1/bearer/id/3

echo "Deleting a single bearer by FlexCN internal id 2 ....."
curl -X DELETE http://192.168.74.2:80/n4g/v1/bearer/id/2

echo "Verify deleting..."
curl -X GET http://192.168.74.2:80/n4g/v1/bearer

echo "Deleting a single bearer by imsi 208950000000009 eps bearer id 2 ....."
curl -X DELETE http://192.168.74.2:80/n4g/v1/bearer/imsi_bearer/208950000000009,1

echo "Verify deleting..."
curl -X GET http://192.168.74.2:80/n4g/v1/bearer

echo "Deleting every thing..."
curl -X DELETE http://192.168.74.2:80/n4g/v1/bearer

echo "Verify deleting..."
curl -X GET http://192.168.74.2:80/n4g/v1/bearer

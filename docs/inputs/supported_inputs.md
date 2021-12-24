# List of data input that can be supported by FlexCN

## SMF

The json that is belong to SMF must be similar to one of the example below

### Event FlexCN (customized only for the OAI's SMF)
```
{
  "eventNotifs": [
    {
      "customized_data": {
        "amf_addr": "192.168.70.132",
        "dnn": "default",
        "pdu_session_type": "IPV4",
        "plmn": {
          "mcc": "208",
          "mnc": "95"
        },
        "qos_flow": [
          {
            "an_addr": {
              "ipv4": "192.168.70.136"
            },
            "qfi": 6,
            "upf_addr": {
              "ipv4": "192.168.70.134"
            }
          }
        ],
        "snssai": {
          "sd": "123",
          "sst": 222
        },
        "ue_ipv4_addr": "12.1.1.2"
      },
      "event": "FLEXCN",
      "pduSeId": 1,
      "supi": "208950000000031",
      "timeStamp": "3840272086"
    }
  ],
  "notifId": "notifid01"
}
```

### Event DDDS (not supported by OAI's SMF)

```
{
  "eventNotifs": [
    {
      "dddStatus": "TRANSMITTED",
      "event": "DDDS",
      "pduSeId": 0,
      "supi": "208950000000031",
      "timeStamp": "3840272086"
    }
  ],
  "notifId": "notifid01"
}
```

### Event PLMN  

```
{
  "eventNotifs": [
    {
      "event": "PLMN_CH",
      "pduSeId": 0,
      "plmnId": {
        "mcc": "208",
        "mnc": "95"
      },
      "supi": "208950000000031",
      "timeStamp": "3840272086"
    }
  ],
  "notifId": "notifid01"
}
```

### Event UE_IP_CH

```
{
  "eventNotifs": [
    {
      "adIpv4Addr": "12.1.1.2",
      "event": "UE_IP_CH",
      "pduSeId": 1,
      "supi": "208950000000031",
      "timeStamp": "3840272086"
    }
  ],
}
```


### Output profile:

//TODO: verify with Thinh 
============
"plmn": {
    "mcc": "208",
    "mnc": "95"
},

"supi": "208950000000031",
"ue_ipv4_addr": "12.1.1.2"
"timeStamp": "3840272086",

"snssai": {
    "sd": "123",
    "sst": 222
},



"pduSeId": 1,
"pdu_session_type": "IPV4",

"amf_addr": "192.168.70.132",
"dnn": "default", // other name: APN

"qos_flow": [
    {
    "an_addr": {
        "ipv4": "192.168.70.136"
    },

    "qfi": 6,
    "upf_addr": {
        "ipv4": "192.168.70.134"
    }
    }
],



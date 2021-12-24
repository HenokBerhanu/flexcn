#!/bin/bash

STATUS=0

RESULT=$(ps aux | grep -v nohup || true)
SUB='/openair-flexcn/bin/oai_flexcn -c /openair-flexcn/etc/flexcn.conf -o'
if [[ $RESULT =~ $SUB ]]; then
    STATUS=0
else
   STATUS=-1
fi

exit $STATUS

# prompt has been removed for easier Ctrl+C Ctrl+V
# please update the following information according to your configuration

INSTANCE=1
PREFIX='/usr/local/etc/oai'
mkdir -m 0777 -p $PREFIX
cp ../../etc/flexcn.conf $PREFIX

declare -A FLEXCN_CONF

FLEXCN_CONF[@INSTANCE@]=$INSTANCE
FLEXCN_CONF[@PREFIX@]=$PREFIX
FLEXCN_CONF[@PID_DIRECTORY@]='/var/run'

FLEXCN_CONF[@FLEXCN_INTERFACE_NAME_FOR_SBI@]='demo-oai'

FLEXCN_CONF[@FLEXCN_INTERFACE_PORT_FOR_SBI@]='80'
FLEXCN_CONF[@FLEXCN_INTERFACE_HTTP2_PORT_FOR_SBI@]='9090'
FLEXCN_CONF[@FLEXCN_API_VERSION@]='v1'

FLEXCN_CONF[@AMF_IPV4_ADDR@]='192.168.70.132'
FLEXCN_CONF[@AMF_PORT@]='80'
FLEXCN_CONF[@SMF_IPV4_ADDR@]='192.168.70.133'
FLEXCN_CONF[@SMF_PORT@]='80'

for K in "${!FLEXCN_CONF[@]}"; do 
  egrep -lRZ "$K" $PREFIX | xargs -0 -l sed -i -e "s|$K|${FLEXCN_CONF[$K]}|g"
  ret=$?;[[ ret -ne 0 ]] && echo "Tried to replace $K with ${FLEXCN_CONF[$K]}"
done

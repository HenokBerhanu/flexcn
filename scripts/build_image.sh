# default name of image should be like this
IMAGE_NAME=flexcn:prealpha

# which target you choose to build
# default of this release is to subcrible both amf and smf
BASH_TARGET="5g_smf,5g_amf"

# build command
docker build --target oai-flexcn-dev --tag ${IMAGE_NAME} \
               --file ./docker/Dockerfile.flexcn.ubuntu18.dev \
               --build-arg TARGET=${BASH_TARGET} \
               .



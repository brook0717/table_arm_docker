#!/bin/bash

# start sharing xhost
xhost +local:root

# run docker
docker run --rm \
  --net=host \
  --ipc=host \
  --gpus all \
  --privileged \
  -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
  -v $HOME/.Xauthority:$docker/.Xauthority \
  -v $HOME/table_arm_docker:$HOME/table_arm_docker \
  -e XAUTHORITY=$home_folder/.Xauthority \
  -e DISPLAY=$DISPLAY \
  -e QT_X11_NO_MITSHM=1 \
  -it --name "dt-pc-ros" $(id -un)/digital-twin-pc


  # --gpus all \

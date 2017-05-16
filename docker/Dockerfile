FROM	ubuntu:16.04
LABEL maintainer "autosquid, justin.seeley.cn@gmail.com"

RUN	apt-get update &&	apt-get install -y -q --no-install-recommends wget build-essential cmake unzip git libavformat-dev libavcodec-dev libavfilter-dev libswscale-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev zlib1g-dev libopenexr-dev libxine2-dev libeigen3-dev libtbb-dev

# install opencv 2.4.11
ADD	build_opencv.sh	build_opencv.sh
RUN wget -q --no-check-certificate https://github.com/opencv/opencv/archive/2.4.11.zip && /bin/sh build_opencv.sh
RUN	rm -rf build_opencv.sh && rm -rf 2.4.11.zip

# install MLSD
RUN git clone https://github.com/ySalaun/MLSD.git && cd MLSD && cmake . && make -j4 && mv LSD_MULTISCALE /usr/local/bin && rm -rf ../MLSD

RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
ENTRYPOINT ["LSD_MULTISCALE"]
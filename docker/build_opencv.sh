unzip 2.4.11.zip
mkdir -p opencv-2.4.11/release
cd opencv-2.4.11/release
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D BUILD_PYTHON_SUPPORT=OFF -D WITH_XINE=ON -D WITH_TBB=ON ..
make -j 4 && make install
cd ../..
rm -rf opencv-2.4.11

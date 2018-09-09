cmd_Release/obj.target/addon/hello_napi.o := g++ '-DNODE_GYP_MODULE_NAME=addon' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/home/dengzikun/.node-gyp/10.8.0/include/node -I/home/dengzikun/.node-gyp/10.8.0/src -I/home/dengzikun/.node-gyp/10.8.0/deps/openssl/config -I/home/dengzikun/.node-gyp/10.8.0/deps/openssl/openssl/include -I/home/dengzikun/.node-gyp/10.8.0/deps/uv/include -I/home/dengzikun/.node-gyp/10.8.0/deps/zlib -I/home/dengzikun/.node-gyp/10.8.0/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -std=gnu++1y -MMD -MF ./Release/.deps/Release/obj.target/addon/hello_napi.o.d.raw   -c -o Release/obj.target/addon/hello_napi.o ../hello_napi.cc
Release/obj.target/addon/hello_napi.o: ../hello_napi.cc \
 /home/dengzikun/.node-gyp/10.8.0/include/node/node_api.h \
 /home/dengzikun/.node-gyp/10.8.0/include/node/node_api_types.h \
 ../accumulation.hpp
../hello_napi.cc:
/home/dengzikun/.node-gyp/10.8.0/include/node/node_api.h:
/home/dengzikun/.node-gyp/10.8.0/include/node/node_api_types.h:
../accumulation.hpp:

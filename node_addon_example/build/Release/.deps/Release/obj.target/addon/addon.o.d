cmd_Release/obj.target/addon/addon.o := g++ '-DNODE_GYP_MODULE_NAME=addon' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DNAPI_DISABLE_CPP_EXCEPTIONS' '-DBUILDING_NODE_EXTENSION' -I/home/dong/.node-gyp/9.11.1/include/node -I/home/dong/.node-gyp/9.11.1/src -I/home/dong/.node-gyp/9.11.1/deps/uv/include -I/home/dong/.node-gyp/9.11.1/deps/v8/include -I/home/dong/github/nodejs_call_c_c++/node_addon_example/node_modules/node-addon-api  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -std=gnu++0x -MMD -MF ./Release/.deps/Release/obj.target/addon/addon.o.d.raw   -c -o Release/obj.target/addon/addon.o ../addon.cc
Release/obj.target/addon/addon.o: ../addon.cc \
 /home/dong/github/nodejs_call_c_c++/node_addon_example/node_modules/node-addon-api/napi.h \
 /home/dong/.node-gyp/9.11.1/include/node/node_api.h \
 /home/dong/.node-gyp/9.11.1/include/node/node_api_types.h \
 /home/dong/github/nodejs_call_c_c++/node_addon_example/node_modules/node-addon-api/napi-inl.h
../addon.cc:
/home/dong/github/nodejs_call_c_c++/node_addon_example/node_modules/node-addon-api/napi.h:
/home/dong/.node-gyp/9.11.1/include/node/node_api.h:
/home/dong/.node-gyp/9.11.1/include/node/node_api_types.h:
/home/dong/github/nodejs_call_c_c++/node_addon_example/node_modules/node-addon-api/napi-inl.h:

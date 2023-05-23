echo "::: BUILD AND RUN ${PROJECT_NAME} :::"
echo "::: Creating build files with CMake... :::"
cmake -DCMAKE_BUILD_TYPE=Debug \
      -DBUILD_TESTS=OFF \
      -DCMAKE_TOOLCHAIN_FILE="/root/dev/${PROJECT_NAME}/build/conan_deps/conan_toolchain.cmake" \
      -B "/root/dev/${PROJECT_NAME}/build" \
      -S "/root/dev/${PROJECT_NAME}" \
      -G "Unix Makefiles" \
      --graphviz=build/dependency_graph/dependency_graph.dot
echo "::: Building ${PROJECT_NAME} with GNU Make :::"
cd build && make && cd ..
dot -Tpng build/dependency_graph/dependency_graph.dot -o build/dependency_graph.png
echo "::: Running main program for ${PROJECT_NAME} :::"
"build/app/${PROJECT_NAME}_run"
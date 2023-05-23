echo "::: BUILD AND TEST ${PROJECT_NAME} :::"
echo "::: Creating build files with CMake... :::"
cmake -DCMAKE_BUILD_TYPE=Debug \
      -DBUILD_TESTS=ON \
      -B "/root/dev/${PROJECT_NAME}/build" \
      -S "/root/dev/${PROJECT_NAME}" \
      -G "Unix Makefiles" \
      --graphviz=build/dependency_graph/dependency_graph.dot
echo "::: Building ${PROJECT_NAME} with GNU Make :::"
cd build && make && cd ..
dot -Tpng build/dependency_graph/dependency_graph.dot -o build/dependency_graph.png
echo "::: Running Google Test for ${PROJECT_NAME} :::"
"build/test/${PROJECT_NAME}_test_run"
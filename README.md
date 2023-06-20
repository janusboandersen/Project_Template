# Project Template
## Features
- CMake template for a modern C++17 project with modern code quality tools.
- Package management via Conan, alternatively FetchContent.
- Made to run on CppDocker. 


## Code quality tools
| Purpose                               | Tool                  | More info                                                                                                                                 |
| -------                               | ----                  | ----                                                                                                                                      |
| Unit tests (behavioral, functional)   | Google Test & Mock    | https://github.com/google/googletest                                                                                                      |
| Static linting (pre-compile)          | Clang-Tidy            | https://clang.llvm.org/extra/clang-tidy/, https://github.com/llvm-mirror/clang-tools-extra/blob/master/clang-tidy/tool/run-clang-tidy.py  |
| Warning levels and warnings-as-errors | Per compilation       |                                                                                                                                           |
|                                       | Per file              | https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html                                                                                |
| Sanitizers (run-time)                 | Asan (*nix, win)      | https://clang.llvm.org/docs/AddressSanitizer.html                                                                                         |
|                                       | UBsan (*nix only)     | https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html                                                                               |
| Dependency graph output               | CMake, Graphviz       | build/dependency_graph.png                                                                                                                |
| Auto code formatting (not yet impl.)  | ClangFormat           | https://clang.llvm.org/docs/ClangFormat.html                                                                                              |


## Directory structure
```
project/
├── app/            Executable source code
├── build/          CMake and Make build process output, including binaries
├── cmake/          CMake custom modules/functions
├── config/         Header file(s) with configurable parameters
├── docs/           Documentation by Doxygen
├── src/            Own component library
|   └── include/    Header files for components
├── test/           Test files (suite)
├── third_party/    Third-party libraries and dependencies
└── tools/          Supporting scripts and templates
```


## CMake configuration sources
```
 project/
 ├── CMakeLists.txt                             Project
 ├── app/CMakeLists.txt                         App-executable and its dependencies
 ├── src/CMakelists.txt                         Component library and its dependecies
 ├── config/CMakeLists.txt                      Auto-populate source code with project name, version, etc. 
 ├── test/CMakeLists.txt                        Unit test executable using GoogleTest
 └── third_party/CMakeLists.txt                 get/manage 3rd party dependencies
```


## Quick scaffolding for library components
Includes a script to build scaffolding for library components:
- Run `tools/make_component.py <group> <component_longname>`
- Effect: Will create scaffolding for a component contained in "group" with a name of "Component longname".
- Example: `tools/make_component.py algo merge_sort` 

Scaffolding is created using the templates in `tools/templates`. The following filesystem effects occur:

1. Three new files will be created:
    * `src/include/<group>/<component_longname>.hpp`
    * `src/<group_component_longname>.cpp`
    * `test/testcases/<group>/<component_longname>.cpp`

2. Prompts user to make required manual modifications (copy-paste) in CMake-files:
    - `src/CMakeLists.txt`:
        * -> LIB_HEADERS: + `include/<group>/<component_longname>.hpp`
        * -> LIB_SOURCES: + `<group_component_longname>.cpp`
    - `test/CMakeLists.txt`:
        * -> TEST_FILES: + `${TEST_DIR}/<group>/<component_longname>.cpp`


## Building and running project
Actions for the project can be invoked using the `actions.py` script, or directly through CMake. Try:
- Help on invokations from the command line
    - `./actions.py --help`
- Install dependencies with Conan and configure project with CMake:
    - `./actions.py --conan-install --configure-project --with-tests --debug`
 - See some available targets after configuration
    - `./actions.py --build-target-list`
    - `./actions.py --test-target-list`
    - `./actions.py --clang-tidy-target-list`
    - `./actions.py --docs-target-list`
 - Subsequently build (compile) and run the app or run the tests:
    - `./actions.py --build-run-project`
    - `./actions.py --build-test-project`
- All in one step (tests must manually be run afterwards):
    - `./actions.py --conan-install --configure-project --build-run-project --with-tests --debug`
- As above, and also run the code coverage analysis (extra compile step)
    - `./actions.py --build-test-project --run-coverage`

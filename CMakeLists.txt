cmake_minimum_required(VERSION 3.30)

project(pycmaketest LANGUAGES CXX VERSION 1.0.0)

message("$ENV{VIRTUAL_ENV}")
find_package(Python3 3.13 REQUIRED COMPONENTS Interpreter Development.Module)

Python3_add_library(pycmaketest MODULE)
target_compile_features(pycmaketest PRIVATE cxx_std_23)
set_target_properties(pycmaketest PROPERTIES CXX_VISIBILITY_PRESET hidden)

add_subdirectory(src)

if(DEFINED PY_BUILD_CMAKE_VERSION)
  set(PLATLIB ${PY_BUILD_CMAKE_PACKAGE_NAME}-${PY_BUILD_CMAKE_PACKAGE_VERSION}.data/platlib)
else()
  set(PLATLIB platlib)
endif()

install(
  TARGETS pycmaketest
  LIBRARY DESTINATION ${PLATLIB}
)

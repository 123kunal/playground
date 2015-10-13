if(APPLE)
  set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -Wall -pedantic -Werror -Wextra")
  add_definitions(-DDarwin)
elseif(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -pedantic -Werror -Wextra")
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++0x -stdlib=libc++ -Wall -pedantic -Werror -Wextra")
endif()


include_directories(/Users/Prachi/Documents/kunal_wrk/fbPerformance)

set(FlatBuffers_Sample_Binary_SRCS
  include/flatbuffers/flatbuffers.h
  FbExample.cpp
  MarketDataSchema_generated.h
)

add_executable(fbExample ${FlatBuffers_Sample_Binary_SRCS})


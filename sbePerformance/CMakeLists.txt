#
# Copyright 2013 Real Logic Ltd.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
if(APPLE)
        # -Wall doesn't enable everything we want to see
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsign-compare")
        add_definitions(-DDarwin)
elseif(MSVC)
        add_definitions(-DWIN32)

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /Od /Zi")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
else()
        add_definitions(-D_GNU_SOURCE)
endif()

include_directories(/Users/Prachi/Documents/kunal_wrk/sbePerformance)
set(GENERATED_CODECS 
	/Users/Prachi/Documents/kunal_wrk/sbePerformance/marketDataMessageSchema
)

add_custom_target(examples_codecs DEPENDS ${GENERATED_CODECS})

MESSAGE("Rambo... ${GENERATED_CODECS}")
add_executable(sbeExample SbeExample.cpp)

add_dependencies(sbeExample examples_codecs)

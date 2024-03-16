#aux_source_directory(./libnn NN_SRC)
#aux_source_directory(./network NETWORK_SRC)
set (NN_SRC_FILTER "./libnn/*.h" "./libnn/*.cpp")
set (NETWROK_SRC_FILTER "./network/*.h" "./network/*.cpp")

file (GLOB_RECURSE NN_SRC ${NN_SRC_FILTER})
file (GLOB_RECURSE NETWORK_SRC ${NETWROK_SRC_FILTER})

include_directories ("libnn")

add_library(nn SHARED ${NN_SRC})
target_compile_definitions(nn PRIVATE -DNN_API_EXPORET)

add_executable(network ${NETWORK_SRC})
target_link_libraries(network PRIVATE nn)
#aux_source_directory(./libnn NN_SRC)
#aux_source_directory(./network NETWORK_SRC)
file (GLOB_RECURSE NN_SRC "./libnn/*.h" "./libnn/*.cpp")
file (GLOB_RECURSE NETWORK_SRC "./network/*.h" "./network/*.cpp")

include_directories ("libnn")

add_library(nn SHARED ${NN_SRC})
target_compile_definitions(nn PRIVATE -DNN_API_EXPORET)

add_executable(network ${NETWORK_SRC})
target_link_libraries(network PRIVATE nn)
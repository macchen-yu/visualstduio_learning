#include "nn_api.h"

#include <iostream>
#include <windows.h>

static const char* filename = "libnn_cpp.dll";

int main()
{
    HMODULE handle = LoadLibraryA(filename);
    if (!handle)
    {
        std::cout << "failed to load library: " << filename << std::endl;
        return -1;
    }

    Proc_GetNetwork func_create_network
        = (Proc_GetNetwork)GetProcAddress(handle, "GetNetwork");
    Proc_DestroyNetwork func_destroy_network
        = (Proc_DestroyNetwork)GetProcAddress(handle, "DestroyNetwork");

    auto network = func_create_network("dnn");

    const char* data_from_somewhere = "A B C D";
    int ret = network->train(data_from_somewhere, strlen(data_from_somewhere));
    if (0 != ret)
        std::cout << "failed to train the model." << std::endl;

    const char* model_from_somewhere = "k=10;b=200";
    ret = network->forward(model_from_somewhere, strlen(model_from_somewhere));
    if (0 != ret)
        std::cout << "failed to forward the model." << std::endl;

    func_destroy_network(network);

    FreeLibrary(handle);
}
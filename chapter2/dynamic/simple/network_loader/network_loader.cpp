#include "nn_api.h"

#include <iostream>
#include <windows.h>

static const char* filename = "libnn.dll";

int main()
{
    HMODULE handle = LoadLibraryA(filename);
    if (!handle)
    {
        std::cout << "failed to load library: " << filename << std::endl;
        return -1;
    }

    Proc_InitNetwork func_init_network 
        = (Proc_InitNetwork)GetProcAddress(handle, "InitNetwork");
    Proc_FiniNetwork func_fini_network
        = (Proc_FiniNetwork)GetProcAddress(handle, "FiniNetwork");
    Proc_TrainNetwork func_train_network
        = (Proc_TrainNetwork)GetProcAddress(handle, "TrainNetwork");
    Proc_InferNetwork func_infer_network
        = (Proc_InferNetwork)GetProcAddress(handle, "InferNetwork");

    int ret = func_init_network("dnn");
    std::cout << "Initialize network status: " << ret << std::endl;

    const char* data_from_somewhere = "A B C D";
    ret = func_train_network(data_from_somewhere, strlen(data_from_somewhere));
    if (0 != ret)
        std::cout << "failed to train the model." << std::endl;

    const char* model_from_somewhere = "k=10;b=200";
    ret = func_infer_network(model_from_somewhere, strlen(model_from_somewhere));
    if (0 != ret)
        std::cout << "failed to forward the model." << std::endl;

    ret = func_fini_network();
    if (0 != ret)
        std::cout << "failed to free the network." << std::endl;

    FreeLibrary(handle);
}
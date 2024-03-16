#include "nn/nn_api.h"
#include "nn/nn.h"

#include <iostream>
#include <windows.h>

static const char* filename = "libnn.dll";

int main()
{
#if 0
    nn_i* nn = CreateNetwork("dnn");

    const char* data_from_somewhere = "A B C D";
    int ret = nn->train(data_from_somewhere, strlen(data_from_somewhere));
    if (0 != ret)
        std::cout << "failed to train the model." << std::endl;

    const char* model_from_somewhere = "k=10;b=200";
    ret = nn->forward(model_from_somewhere, strlen(model_from_somewhere));
    if (0 != ret)
        std::cout << "failed to forward the model." << std::endl;

    DestroyNetwork(nn);
#endif

    /* 1. 加载DLL到当前的地址空间 */
    HMODULE handle = LoadLibraryA(filename);
    if (!handle)
    {
        std::cout << "failed to load library: "
            << filename << std::endl;
        return -1;
    }

    /* 2. 获取dll导出函数地址 */
    auto func_create_network
        = (Proc_CreateNetwork)GetProcAddress(handle, "CreateNetwork");
    auto func_destroy_network
        = (Proc_DestroyNetwork)GetProcAddress(handle, "DestroyNetwork");

    nn_i* nn = func_create_network("dnn");
    
    const char* data_from_somewhere = "A B C D";
    int ret = nn->train(data_from_somewhere, strlen(data_from_somewhere));
    if (0 != ret)
        std::cout << "failed to train the model." << std::endl;

    const char* model_from_somewhere = "k=10;b=200";
    ret = nn->forward(model_from_somewhere, strlen(model_from_somewhere));
    if (0 != ret)
        std::cout << "failed to forward the model." << std::endl;

    func_destroy_network(nn);

    return 0;
}
#include "nn/nn_api.h"

#include <iostream>
#include <windows.h>

static const char* filename = "libnn.dll";

int main()
{
    /* 1. 加载DLL到当前的地址空间 */
    HMODULE handle =  LoadLibraryA(filename);
    if (!handle)
    {
        std::cout << "failed to load library: "
            << filename << std::endl;
        return -1;
    }

    /* 2. 获取dll导出函数地址 */
    auto func_init_network 
        = (Proc_InitNetwork)GetProcAddress(handle, "InitNetwork");
    auto func_fini_network
        = (Proc_FiniNetwork)GetProcAddress(handle, "FiniNetwork");
    auto func_train_network
        = (Proc_TrainNetwork)GetProcAddress(handle, "TrainNetwork");
    auto func_infer_network
        = (Proc_InferNetwork)GetProcAddress(handle, "InferNetwork");

    /* 3. 调用dll完成我们的功能 */
    func_init_network("dnn");

    const char* data_from_somewhere = "A B C D";
    func_train_network(data_from_somewhere, strlen(data_from_somewhere));

    const char* model_from_somewhere = "k=10;b=200";
    func_infer_network(model_from_somewhere, strlen(model_from_somewhere));

    func_fini_network();

    /* 4. 释放dll */
    FreeLibrary(handle);

    return 0;
}
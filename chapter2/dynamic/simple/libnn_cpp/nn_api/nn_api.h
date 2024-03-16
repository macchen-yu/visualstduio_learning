#ifndef __NN_API_H__
#define __NN_API_H__

#include "nn/nn.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @brief 获取网络
     * @param which 网络类型
     * @return 网络实例
     */
    _declspec(dllexport) nn_i* __stdcall GetNetwork(const char* which);

    /**
     * @brief 销毁网络
     * @param which 待销毁网络
     * @return 
     */
    _declspec(dllexport) void __stdcall DestroyNetwork(nn_i* which);

#ifdef __cplusplus
}
#endif

#endif

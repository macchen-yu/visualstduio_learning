#ifndef __NN_API_H__
#define __NN_API_H__

#include "nn/nn.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @brief ��ȡ����
     * @param which ��������
     * @return ����ʵ��
     */
    _declspec(dllexport) nn_i* __stdcall GetNetwork(const char* which);

    /**
     * @brief ��������
     * @param which ����������
     * @return 
     */
    _declspec(dllexport) void __stdcall DestroyNetwork(nn_i* which);

#ifdef __cplusplus
}
#endif

#endif

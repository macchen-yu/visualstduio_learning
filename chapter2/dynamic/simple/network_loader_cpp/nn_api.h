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
    nn_i* __stdcall GetNetwork(const char* which);
    typedef nn_i* (__stdcall *Proc_GetNetwork)(const char* which);
    
    /**
     * @brief ��������
     * @param which ����������
     * @return
     */
    void __stdcall DestroyNetwork(nn_i* which);
    typedef void (__stdcall *Proc_DestroyNetwork)(nn_i* which);

#ifdef __cplusplus
}
#endif

#endif

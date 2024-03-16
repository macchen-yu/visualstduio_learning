#pragma once
#include "nn/nn.h"

#ifdef __cplusplus
extern "C" {
#endif

nn_i* __stdcall CreateNetwork(const char* which);
typedef nn_i* (__stdcall* Proc_CreateNetwork)(const char* which);

int __stdcall DestroyNetwork(nn_i* which);
typedef int (__stdcall* Proc_DestroyNetwork)(nn_i* which);
#ifdef __cplusplus
}
#endif
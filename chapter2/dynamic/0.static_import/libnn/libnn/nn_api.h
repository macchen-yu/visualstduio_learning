#pragma once
#include "nn/nn.h"

#ifdef __cplusplus
extern "C" {
#endif

_declspec(dllexport) nn_i* __stdcall CreateNetwork(const char* which);

_declspec(dllexport) int __stdcall DestroyNetwork(nn_i* which);

#ifdef __cplusplus
}
#endif
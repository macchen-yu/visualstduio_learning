#pragma once

#ifdef __cplusplus
extern "C" {
#endif

_declspec(dllexport) int __stdcall InitNetwork(const char* which);

_declspec(dllexport) int __stdcall FiniNetwork();

_declspec(dllexport) int __stdcall TrainNetwork(const char* data, size_t size);

_declspec(dllexport) int __stdcall InferNetwork(const char* model, size_t size);


#ifdef __cplusplus
}
#endif
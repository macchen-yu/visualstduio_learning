#pragma once

int __stdcall InitNetwork(const char* which);
typedef int(__stdcall* Proc_InitNetwork)(const char* which);
//using Proc_InitNetwork = int(_stdcall*)(const char* which);

int __stdcall FiniNetwork();
typedef int (__stdcall* Proc_FiniNetwork)();

int __stdcall TrainNetwork(const char* data, size_t size);
typedef int (__stdcall* Proc_TrainNetwork)(const char* data, size_t size);

int __stdcall InferNetwork(const char* model, size_t size);
typedef int (__stdcall* Proc_InferNetwork)(const char* model, size_t size);
#pragma once

_declspec(dllimport) int __stdcall InitNetwork(const char* which);

_declspec(dllimport) int __stdcall FiniNetwork();

_declspec(dllimport) int __stdcall TrainNetwork(const char* data, size_t size);

_declspec(dllimport) int __stdcall InferNetwork(const char* model, size_t size);
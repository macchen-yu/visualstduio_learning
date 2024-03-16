#include "nn_api.h"

#include "nn/factory_impl/factory_impl.h"
#include "nn/factory.h"
#include "nn/nn.h"

#include <iostream>

_declspec(dllexport) nn_i* __stdcall GetNetwork(const char* which)
{
    factory_i* fct = new factory_impl();
    return fct->create_nn("dnn");
}

_declspec(dllexport) void __stdcall DestroyNetwork(nn_i* which)
{
    delete which; which = nullptr;
}


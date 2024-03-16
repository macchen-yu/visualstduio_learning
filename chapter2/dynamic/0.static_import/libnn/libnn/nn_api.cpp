#include "nn_api.h"

#include "nn/factory_impl/factory_impl.h"
#include "nn/factory.h"
#include "nn/nn.h"

#include <iostream>

nn_i* CreateNetwork(const char* which)
{
    factory_i* fct = new factory_impl();
    nn_i* g_nn = fct->create_nn(which);

    delete fct;

    return g_nn;
}

int DestroyNetwork(nn_i* which)
{
    delete which; which = nullptr;
    return 0;
}

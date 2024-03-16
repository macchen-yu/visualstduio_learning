#include "nn_api.h"

#include "nn/factory_impl/factory_impl.h"
#include "nn/factory.h"
#include "nn/nn.h"

#include <iostream>

static nn_i* g_nn = nullptr;

int InitNetwork(const char* which)
{
    factory_i* fct = new factory_impl();
    g_nn = fct->create_nn(which);

    delete fct;

    return 0;
}

int FiniNetwork()
{
    delete g_nn; g_nn = nullptr;
    return 0;
}

int TrainNetwork(const char* data, size_t size)
{
    if (!g_nn)
        return -1;

    int ret = g_nn->train(data, size);
    if (0 != ret)
        std::cout << "failed to train the model." << std::endl;

    return 0;
}

int InferNetwork(const char* model, size_t size)
{
    if (!g_nn)
        return -1;

    int ret = g_nn->forward(model, size);
    if (0 != ret)
        std::cout << "failed to infert the network." << std::endl;

    return 0;

    return 0;
}
#include "nn/nn.h"

#include "nn/factory.h"
#include "nn/factory_impl/factory_impl.h"

#include <iostream>

int main()
{
    int ret = 0;

    factory_i* fct = new factory_impl();
    auto nn = fct->create_nn("dnn");

    const char* data_from_somewhere = "A B C D";
    ret = nn->train(data_from_somewhere, strlen(data_from_somewhere));
    if (0 != ret)
        std::cout << "failed to train the model." << std::endl;

    const char* model_from_somewhere = "k=10;b=200";
    ret = nn->forward(model_from_somewhere, strlen(model_from_somewhere));
    if (0 != ret)
        std::cout << "failed to forward the model." << std::endl;

    delete nn; nn = nullptr;
    delete fct; fct = nullptr;

    return 0;
}

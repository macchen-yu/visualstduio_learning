#include "nn/nn_api.h"

#include <iostream>
int main()
{
    InitNetwork("dnn");

    const char* data_from_somewhere = "A B C D";
    TrainNetwork(data_from_somewhere, strlen(data_from_somewhere));

    const char* model_from_somewhere = "k=10;b=200";
    InferNetwork(model_from_somewhere, strlen(model_from_somewhere));

    FiniNetwork();

    return 0;
}
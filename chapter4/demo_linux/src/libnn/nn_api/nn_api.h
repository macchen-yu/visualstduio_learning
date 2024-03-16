#ifndef __NN_API_H__
#define __NN_API_H__

#include <cstdlib>
#include <cstring>

#ifdef __cplusplus
extern "C" {
#endif

#if WIN32
#define NN_API __stdcall
#else
#define NN_API
#endif

#ifdef WIN32 /* windows */
#ifdef NN_API_EXPORET
#define NN_EXPORT _declspec(dllexport)
#else
 #define NN_EXPORT _declspec(dllimport)
#endif
#else /* linux */
 #define NN_EXPORT
#endif

typedef int NN_STATUS;

/**
 * @brief 初始化网络参数
 * @param which 网络类型
 * @return 初始化网络状态
 */
NN_EXPORT NN_STATUS NN_API InitNetwork(const char* which);

/**
 * @brief 销毁网络参数
 * @return 销毁网络状态
 */
NN_EXPORT NN_STATUS NN_API FiniNetwork();

/**
 * @brief 进行网络训练
 * @param data 训练数据
 * @return 训练状态
 */
NN_EXPORT NN_STATUS NN_API TrainNetwork(const char* data, size_t size);

/**
 * @brief 进行网络推理
 * @param model 推理模型
 * @return 初始化网络状态
 */
NN_EXPORT NN_STATUS NN_API InferNetwork(const char* model, size_t size);

#ifdef __cplusplus
}
#endif

#endif

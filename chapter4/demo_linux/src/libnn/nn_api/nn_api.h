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
 * @brief ��ʼ���������
 * @param which ��������
 * @return ��ʼ������״̬
 */
NN_EXPORT NN_STATUS NN_API InitNetwork(const char* which);

/**
 * @brief �����������
 * @return ��������״̬
 */
NN_EXPORT NN_STATUS NN_API FiniNetwork();

/**
 * @brief ��������ѵ��
 * @param data ѵ������
 * @return ѵ��״̬
 */
NN_EXPORT NN_STATUS NN_API TrainNetwork(const char* data, size_t size);

/**
 * @brief ������������
 * @param model ����ģ��
 * @return ��ʼ������״̬
 */
NN_EXPORT NN_STATUS NN_API InferNetwork(const char* model, size_t size);

#ifdef __cplusplus
}
#endif

#endif

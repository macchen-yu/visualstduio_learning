#ifndef __NN_API_H__
#define __NN_API_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief ��ʼ���������
 * @param which ��������
 * @return ��ʼ������״̬
 */
int __stdcall InitNetwork(const char* which);
//typedef int (__stdcall *Proc_InitNetwork)(const char* which);

using Proc_InitNetwork = int(*)(const char* which);

/**
 * @brief �����������
 * @return ��������״̬
 */
int __stdcall FiniNetwork();
typedef int (__stdcall* Proc_FiniNetwork)();

/**
 * @brief ��������ѵ��
 * @param data ѵ������
 * @return ѵ��״̬
 */

int __stdcall TrainNetwork(const char* data, size_t size);
typedef int(__stdcall* Proc_TrainNetwork)(const char* data, size_t size);

/**
 * @brief ������������
 * @param model ����ģ��
 * @return ��ʼ������״̬
 */
int __stdcall InferNetwork(const char* model, size_t size);
typedef int(__stdcall* Proc_InferNetwork)(const char* model, size_t size);

#ifdef __cplusplus
}
#endif

#endif

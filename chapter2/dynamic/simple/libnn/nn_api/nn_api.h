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
    _declspec(dllexport) int __stdcall InitNetwork(const char* which);

    /**
     * @brief �����������
     * @return ��������״̬
     */
    _declspec(dllexport) int __stdcall FiniNetwork();

    /**
     * @brief ��������ѵ��
     * @param data ѵ������
     * @return ѵ��״̬
     */
    _declspec(dllexport) int __stdcall TrainNetwork(const char* data, size_t size);

    /**
     * @brief ������������
     * @param model ����ģ��
     * @return ��ʼ������״̬
     */
    _declspec(dllexport) int __stdcall InferNetwork(const char* model, size_t size);

#ifdef __cplusplus
}
#endif

#endif

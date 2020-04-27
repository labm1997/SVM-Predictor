#include "svm.h"
#include "svm_sv.h"

/*
 * Computa o RBF entre a entrada e o vetor de suporte
 */
float svm_rbf(float *input, const float *sv){
    float norm_squared = 0;
    for(uint16_t i=0 ; i<SVM_DIMENSION ; i++){
        float diff = input[i]-sv[i];
        norm_squared += diff * diff;
    }
    return exp(SVM_SIGMA * norm_squared);
}

/*
 * Prediz a classe (1 ou -1) de uma entrada com base nos vetores de suporte do treinamento
 */
int8_t svm_predictor(float *input){
    float sum = 0;
    for(uint16_t i=0 ; i<SVM_NSV ; i++){
        sum += svm_trained_model[i].alpha_label * svm_rbf(input, svm_trained_model[i].support_vector) + svm_trained_model[i].bias;
    }
    return sum >= 0 ? 1 : -1;
}
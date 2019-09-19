/*
** WSU PROJECT, 2019
** Vigenere decrypt
** File description:
** Cyber sec
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ciphertext "tyxvahlvowsrahsoervceispsqlj_hxgyqfjtqgi_j___bafebacoewvowsohvs_nvet_dgo_tghidzvbklvodsjuhsjwdsmerwdnvkn_jgvrvv_ilxvhzevnelvodsohvsyhrfyeqga_yan_dgo_rloatcdnxsxujsmaj__rqgi_j___wtytqlcajsreq_wvvshauxvokjvpekdtzgi_kfwsitdlrugeqlceqxidqtidqtdmqga_ihtidzvidswlbsdtisailxvvrjdeja_sqan_afjwbxzgvsjfqlceqxiecqvadwvtyan_afjwbxzgvsyadsjnbqvbvszehaqeusdnqlceqydrilvidkoadv__wjjmqlceqvjnlxmtvwvsfqvhvfyeqao_zkveik_njawlqlcajsohvsyodn_rjxz_iht_sxvthxwtvwvwzlc_j___klhoilvlzu_rrddto"

int     cipherlenght() {
    int cipherlenght = strlen(ciphertext);
    return cipherlenght;
}

int main(void) {
    int *coincidence = malloc(cipherlenght());

    for (int i = 0; i < cipherlenght(); i++) {
        int temp = 0;
        for (int j = 0; j < cipherlenght(); j++) {
            if (j + i < cipherlenght() && ciphertext[i + j] == ciphertext[j]) {
                temp = temp + 1;
            }
        }
        coincidence[i] = temp;
    }
     for (int i = 0; i < cipherlenght(); i++)
        printf( "%d ;", coincidence[i]);
    return 0;
}
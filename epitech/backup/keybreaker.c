/*
** EPITECH PROJECT, 2019
** Key Breaker
** File description:
** Cyber Sec
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define alphabet "abcdefghijklmnopqrstuvwxyz_"
#define ciphertext "tyxvahlvowsrahsoervceispsqlj_hxgyqfjtqgi_j___bafebacoewvowsohvs_nvet_dgo_tghidzvbklvodsjuhsjwdsmerwdnvkn_jgvrvv_ilxvhzevnelvodsohvsyhrfyeqga_yan_dgo_rloatcdnxsxujsmaj__rqgi_j___wtytqlcajsreq_wvvshauxvokjvpekdtzgi_kfwsitdlrugeqlceqxidqtidqtdmqga_ihtidzvidswlbsdtisailxvvrjdeja_sqan_afjwbxzgvsjfqlceqxiecqvadwvtyan_afjwbxzgvsyadsjnbqvbvszehaqeusdnqlceqydrilvidkoadv__wjjmqlceqvjnlxmtvwvsfqvhvfyeqao_zkveik_njawlqlcajsohvsyodn_rjxz_iht_sxvthxwtvwvwzlc_j___klhoilvlzu_rrddto"

void keybreak() {
      char *key = malloc(sizeof(char) * 4);
      char *plaintext = malloc(sizeof(char) * 472);
    for (int i = 0; i < strlen(alphabet); i++) {
        for (int j = 0; j < strlen(alphabet); j++) {
            for (int k = 0; k < strlen(alphabet); k++) {
                for (int l = 0; l < strlen(alphabet); l++) {
                    key[0] = alphabet[i];
                    key[1] = alphabet[j];
                    key[2] = alphabet[k];
                    key[3] = alphabet[l];
                    //printf("VOICI LES CLEEEEEEEF -> %s\n",key);
                    for (int m = 0, n = 0; m < strlen(ciphertext); m++) { 
                        const char *ptr = strchr(alphabet, ciphertext[m]);
                        const char *ptr2 = strchr(alphabet, key[n]);
                        if (ptr || ptr2) {
                            int index = ptr - alphabet;
                            int index2 = ptr2 - alphabet;
                            int charfinal = (index - index2 + 27) % 27;
                            plaintext[m] = alphabet[charfinal];
                            }
                        n = (n + 1) % 4;
                        }
                    //printf("%s\n", plaintext);
                    
                    if (strstr(plaintext, "the_") != NULL){
                                // printf("%d\n",o);
                                 printf("%s\n", key);
                                 printf("%s\n\n", plaintext);
                                break;
                            }
                }

            }
                }
            }
        }


int main(void) {
    keybreak();
    return 0;
}
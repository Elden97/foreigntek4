/*
** WSU PROJECT, 2019
** Vigenere
** File description:
** Cyber security
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <getopt.h>
 
#define NUMLETTERS "abcdefghijklmnopqrstuvwxyz "
#define BUFSIZE 4096
 
char *get_input(void) {
 
    char *const restrict buf = malloc(BUFSIZE * sizeof (char));
    if (buf == NULL) {
        return NULL;
    }
 
    fgets(buf, BUFSIZE, stdin);
 
    size_t const len = strlen(buf);
    if (buf[len - 1] == '\n') buf[len - 1] = '\0';
 
    return buf;
}

int main(int argc, char **argv)
{
    char const usage[] = "Usage: vinigere [-d] key";
    char sign = 1; 
    char const plainmsg[] = "Plain text:  ";
    char const cryptmsg[] = "Cipher text: ";
    bool encrypt = true;
    int opt;
 
    while ((opt = getopt(argc, argv, "d")) != -1) {
        switch (opt) {
        case 'd': 
            sign = -1;
            encrypt = false;
            break;
        default: 
            fprintf(stderr, "Unrecogized command\n");
            return 1;
        }
    }
 
    if (argc - optind != 1) {
        fprintf(stderr, "%s requires one argument and one only\n", argv[0]);
        fprintf(stderr, "\n%s\n", usage);
        return 1;
    }
 
 
    char const *const restrict key = argv[optind];
    size_t const keylen = strlen(key);
    char shifts[keylen];
 
    char const *restrict plaintext = NULL; 
    for (size_t i = 0; i < keylen; i++) {
        const char *ptr2 = strchr(NUMLETTERS, key[i]);
        if (!(ptr2)) {
            printf("invalid key %s\n", key);
            return 84;
        }
        char const charcase = (isupper(key[i])) ? 'A' : 'a';
        shifts[i] = (key[i] - charcase) * sign;
    }
 
    do {
        fflush(stdout);
        printf("%s", (encrypt) ? plainmsg : cryptmsg);
        plaintext = get_input();
        if (plaintext == NULL) {
            fprintf(stderr, "Error getting input\n");
            return 4;
        }
    } while (strcmp(plaintext, "") == 0);
 
    size_t const plainlen = strlen(plaintext);
 
    char *const restrict ciphertext = calloc(plainlen + 1, sizeof *ciphertext);
    if (ciphertext == NULL) {
        fprintf(stderr, "Memory error\n");
        return 5;
    }
 
    for (size_t i = 0, j = 0; i < plainlen; i++) {
            const char *ptr = strchr(NUMLETTERS, plaintext[i]);
            const char *ptr2 = strchr(NUMLETTERS, key[j]);
            if (ptr || ptr2) {
            int index = ptr - NUMLETTERS;
            int index2 = ptr2 - NUMLETTERS;
            if (encrypt) {
            int charfinal = (index + index2) % 27;
            ciphertext[i] = NUMLETTERS[charfinal];
            } else {
            int charfinal = (index - index2 + 27) % 27;
            ciphertext[i] = NUMLETTERS[charfinal];
            }
        }
        j = (j + 1) % keylen;
    }
    ciphertext[plainlen] = '\0';
    printf("%s%s\n", (encrypt) ? cryptmsg : plainmsg, ciphertext);
    return 0;
}
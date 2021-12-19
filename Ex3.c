#include <stdio.h>
#include <math.h>
#include <string.h>

#define TXT 1024
#define WORD 30
//#define max(x, y) (((x) > (y)) ? (x) : (y))
//#define min(x, y) (((x) < (y)) ? (x) : (y))

int letterDist(char c) {
    //capital letters
    if ((c >= 65 && c <= 90)) {
        return c - 64;
    }
    //small letters
    if (c >= 97 && c <= 122) {
        return c - 96;
    }
    return 0;
}

int A(char wordA[], char txtA[]) {
    printf("Gematria Sequences: ");
    int counter = 0;
    int txtcounter;
    int i = 0;
    char tmpstr[TXT];
    char ans[TXT];
    while (i < strlen(wordA)) {
        counter += letterDist(wordA[i]);
        i++;
    }

    int size = 0;
    for (i = 0; i < strlen(txtA); i++) {
        int tempcounter = 0;
        if (letterDist(txtA[i]) != 0) {
            tmpstr[0] = '\0';
            txtcounter = 0;
            int j = i;
            int k = 0;
            while (txtcounter < counter && j < strlen(txtA)) { // * &&->
                strncat(tmpstr, &txtA[j], 1);
                txtcounter += letterDist(tmpstr[k]);
                j++;
                k++;
                tempcounter++;
            }
            if (txtcounter == counter) {
                size += tempcounter;
                strcat(ans, tmpstr);
                strcat(ans, "~");
//                printf("%s~", tmpstr);
            }
        }
    }

//    ans[size] = '\0';
    for (i = 0; i < strlen(ans) - 1; i++) {
        printf("%c", ans[i]);
    }
    printf("\n");
//    word[0] = '\0';
//    txt[0] = '\0';
    ans[0] = '\0';
    tmpstr[0] = '\0';
    return 1;
}


int B(char word[], char txt[]) {
    printf("Atbash Sequences: ");
    char lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    char upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
    char regular[strlen(word)];
    char reverse[strlen(word)];
    for (int i = 0; i < strlen(word); i++) {
        int val = letterDist(word[i]);
        if ((word[i] >= 65 && word[i] <= 90)) { // upper
            regular[i] = upper[26 - val];
        }
        if (word[i] >= 97 && word[i] <= 122) { // lower
            regular[i] = lower[26 - val];
        }
    }
    strcpy(reverse, regular);
//    printf("%s\n", regular);
//    printf("%s\n", reverse);
    int i = 0;
    int j = (int) strlen(reverse) - 1;

    while (i < j) {
        char c = reverse[i];
        reverse[i] = reverse[j];
        reverse[j] = c;
        i++;
        j--;
    }
//    printf("%s\n", regular);
//    printf("%s", reverse);

    // Gematria of word:
    int counter = 0;
    int txtcounter;
    i = 0;
    char tmpstr[TXT] = {'\0'};
    char ans[TXT] = {'\0'};
    while (i < strlen(regular)) {
        counter += letterDist(regular[i]);
        i++;
    }

    int size = 0;
    for (i = 0; i < strlen(txt); i++) {
        int tempcounter = 0;
        if (letterDist(txt[i]) != 0) {
            tmpstr[0] = '\0';
            txtcounter = 0;
            int j = i;
            int k = 0;
            while (txtcounter < counter && j < strlen(txt)) { // * &&->
                strncat(tmpstr, &txt[j], 1);
                txtcounter += letterDist(tmpstr[k]);
                j++;
                k++;
                tempcounter++;
            }
            if (txtcounter == counter) {
                size += tempcounter;
                strcat(ans, tmpstr);
                strcat(ans, "~");
//                printf("%s~", tmpstr);
            }
        }
    }
//    printf("%s", ans);

//    for (i = 0; i < strlen(ans); i++) {
//        int val = letterDist(ans[i]);
//        if (ans[i] != '~') {
//            if ((ans[i] >= 65 && ans[i] <= 90)) { // upper
//                ans[i] = upper[26 - val];
//            }
//            if (ans[i] >= 97 && ans[i] <= 122) { // lower
//                ans[i] = lower[26 - val];
//            }
//        }
//    }

//    printf("%s\n", ans);

//    char ans2[] = {'\0'};
    char ans2[TXT] = {'\0'};
    char temp[TXT] = {'\0'};
    size = 0;
    for (i = 0; i < strlen(ans); i++) {
        strcpy(temp, "");
        int tempSize = 0;
        int k = 0;
        j = i;
        while (ans[j] != '~') {
//            if (letterDist(ans[j]) != 0) {
            temp[k] = ans[j];
            k++;
            tempSize++;
//            }
            j++;
        }
        if (strcmp(temp, reverse) == 0) {
            size += tempSize + 1;
            strcat(ans2, temp);
            strcat(ans2, "~");
            strcpy(temp, "");
        }
        if (strcmp(temp, regular) == 0) {
            size += tempSize + 1;
            strcat(ans2, temp);
            strcat(ans2, "~");
            strcpy(temp, "");
        }
        i = j;
    }
    ans2[size-1] = '\0';

    printf("%s",ans2);
//    for (i = 0; i < strlen(ans2) - 1; i++) {
//        printf("%c", ans2[i]);
//        ans2[i] = '\0';
//    }

}

int C(char wordC[], char txtC[]) {
    printf("\nAnagram Sequences: ");
    int counter = 0;
    int txtcounter;
    int i = 0;
    char tmpstr[TXT];
    char ans[TXT];
    while (i < strlen(wordC)) {
        counter += letterDist(wordC[i]);
        i++;
    }

    int size = 0;
    for (i = 0; i < strlen(txtC); i++) {
        int tempcounter = 0;
        if (letterDist(txtC[i]) != 0) {
            tmpstr[0] = '\0';
            txtcounter = 0;
            int j = i;
            int k = 0;
            while (txtcounter < counter && j < strlen(txtC)) { // * &&->
                strncat(tmpstr, &txtC[j], 1);
                txtcounter += letterDist(tmpstr[k]);
                j++;
                k++;
                tempcounter++;
            }
            if (txtcounter == counter) {
                size += tempcounter;
                strcat(ans, tmpstr);
                strcat(ans, "~");
//                printf("%s~", tmpstr);
            }
        }
    }


    char ans2[TXT];
    for (i = 0; i < strlen(ans); i++) {
        int j = i;
        counter = 0;
        int wordCounter = 0;
        while (ans[j] != '~') {
            wordCounter++;
            if (strchr(wordC, ans[j]) == NULL) {
                counter = 0;
                j++;
                wordCounter++;
//                break;
            } else {
                counter++;
                j++;
            }
        }
        if (counter == wordCounter) {
            strncat(ans2, &ans[i], counter);
//            if (ans2[j] != '~')
            strcat(ans2, "~");
        }
        i = j;
    }
    for (i = 0; i < strlen(ans2) - 1; i++) {
        printf("%c", ans2[i]);
    }
//    word[0] = '\0';
//    txt[0] = '\0';
    ans[0] = '\0';
    ans2[0] = '\0';
    tmpstr[0] = '\0';
    printf("\n");
}

int main() {
    int i = 0;
    char txt[TXT];
    char word[WORD];
//    char bt1 = 92;  // backslash
//    char bt2 = 116; // t
//    char bt3 = 110; // n
//    char bt4 = 126; // ~

//    scanf("%[^\n^\t^ ]s", txt);
//    returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found.

//    printf("%s", word);
//    while (i < WORD) {
//        if (word[i] == bt1) {
//            i++;
//            if (word[i] == bt2) {
//                word[i - 1] = '\0';
//                word[i] = '\0';
//            }
//            if (word[i] == bt3) {
//                word[i - 1] = '\0';
//                word[i] = '\0';
//            }
//        }
//        if (word[i] == ' ') {
//            word[i] = '\0';
//        }
//        i++;
//    }

    fgets(word, WORD, stdin);
    while (i < WORD) {
        if (word[i] == '\t')
            word[i] = '\0';
        if (word[i] == '\n')
            word[i] = '\0';
        if (word[i] == ' ')
            word[i] = '\0';
        i++;
    }

    scanf("%[^~]s", txt);

    char wordA[WORD];
    char txtA[TXT];
    strcpy(wordA, word);
    strcpy(txtA, txt);
    char wordB[WORD];
    char txtB[TXT];
    strcpy(wordB, word);
    strcpy(txtB, txt);
    char wordC[WORD];
    char txtC[TXT];
    strcpy(wordC, word);
    strcpy(txtC, txt);


    A(wordA, txtA);
    B(word, txt);
    C(wordC, txtC);


}

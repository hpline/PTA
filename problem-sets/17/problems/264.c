#include <stdio.h>

#define MaxCards    54

const char *cards[MaxCards] = {
    "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", 
    "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", 
    "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", 
    "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", 
    "J1", "J2",
};

void shuffle(const char*output[], int order[], int repeat)
{
    for (int i = 0; i < MaxCards; i++) {
        int index = i + 1;
        for (int k = 0; k < repeat; k++) index = order[index];
        output[index-1] = cards[i];
    }
}

int main()
{
    const char *output[MaxCards];
    int order[MaxCards+1];
    int repeat;
    scanf("%d", &repeat);
    for (int i = 1; i <= MaxCards; i++) {
        scanf("%d", &order[i]);
    }
    shuffle(output, order, repeat);
    for (int i = 0; i < MaxCards-1; i++) {
        printf("%s ", output[i]);
    }
    printf("%s\n", output[MaxCards-1]);
    return 0;
}

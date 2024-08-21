#include <stdio.h>
#define MAX_SIZE 1000
void processFile(const char *filename) {
    FILE *file;
    double data[MAX_SIZE];
    int n = 0; 
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    while (fscanf(file, "%lf", &data[n]) != EOF) {
        n++;
    }
    fclose(file); 
    int maxima[MAX_SIZE], minima[MAX_SIZE];
    int max_count = 0, min_count = 0;
    for (int i = 1; i < n - 1; i++) {
        if (data[i-1] < data[i] && data[i] > data[i+1]) {
            maxima[max_count++] = i;
        } else if (data[i-1] > data[i] && data[i] < data[i+1]) {
            minima[min_count++] = i;
        }
    }
    printf("Results for file: %s\n", filename);
    printf("Maxima at indices: ");
    for (int i = 0; i < max_count; i++) {
        printf("%d ", maxima[i]);
    }
    printf("\nMinima at indices: ");
    for (int i = 0; i < min_count; i++) {
        printf("%d ", minima[i]);
    }
    printf("\n");
}
int main() {
    processFile("Data_1.txt");
    processFile("Data_2.txt");
    return 0;
}

#include <cstdio>
#include <cstdint>
#include <string.h>

char fourcc[5];
unsigned int size;

unsigned int subSize;

void wavReader (const char* filename){
    
    FILE* f = fopen(filename, "rb");
    
    //header
    fread(fourcc, sizeof(char), 4, f);
    fread(&size, sizeof(int), 1, f);
    fread(fourcc, sizeof(char), 4, f);
    
    
    
    while (true){
        int b = fread(fourcc, sizeof(char), 4, f);
        if (b == 0){
            break;
        }
        
        fread(&subSize, sizeof(int), 1, f);
        
        unsigned char content[subSize];
        fread(content, sizeof(char), subSize, f);
        
        fourcc[4] = '\0';
        
        printf("\n%s\n",fourcc);
        
        if (!strncmp(fourcc, "fmt ", 4)){
            unsigned short format = *((short*)(content+0));
            printf("Format: %d\n",format);
            unsigned short channel = *((short*)(content+2));
            printf("Channel: %d\n",channel);
            unsigned int rate = *((int*)(content+6));
            printf("Rate: %u\n",rate);
            unsigned int byte_rate = *((int*)(content+10));
            printf("Byte rate: %u\n",byte_rate);
            unsigned short align = *((short*)(content+12));
            printf("Align: %d\n",align);
            unsigned short bits_per_sample = *((short*)(content+14));
            printf("Bits per sample: %d\n",bits_per_sample);
        }

        if (!strncmp(fourcc, "data", 4)){
            short contentData = *((short*)(content));
            printf("sub size: %d\n", contentData);
            int i = 0;
            while (i< (size/2)){
                printf ("%d\n",content[i]);
                i++;
            }
        }

    }
    
    fclose(f);
}


int main(int argc, const char * argv[]) {
    
    char filename[]="taunt.wav";
    
    wavReader(filename);
    printf("\n");
    
}
#

#include <stdio.h>
#include <stdint.h>
#include <string.h>
//WIP
void WAV_2_PCM(const char *fileName);

void PCM_2_H(const char *pcmFileName, const char *hFileName)
{
    FILE *pcmFile = fopen(pcmFileName, "rb");

    // Error Handling of Wrong Input File
    if(!pcmFile) {
        perror("Error opening PCM File. Please input proper PCM FILE.");
        return;
    }

    // Find the length of the input PCM file
    fseek(pcmFile, 0, SEEK_END);
    long pcmSize = ftell(pcmFile);
    fseek(pcmFile, 0, SEEK_SET);
    int dataLen = pcmSize / sizeof(int32_t);

    //Write to the output file, if it doesn't exist then create the file
    FILE *hFile = fopen(hFileName, "wb");
    fprintf(hFile, "#ifndef AUDIO_SAMPLE_H\n");
    fprintf(hFile, "#define AUDIO_SAMPLE_H\n\n");
    fprintf(hFile, "const int audio_data_length = %d;\n", dataLen);
    fprintf(hFile, "const uint32_t audio_data[] = {\n");

    // Loop over the pcm file and write to output header file.
    for (int i = 0; i < dataLen; i++)
    {
        int32_t sample;
        fread(&sample, sizeof(int32_t), 1, pcmFile);
        fprintf(hFile, "0x%08X,\n", (uint32_t)(sample & 0xFFFFFFFF));
    }

    fprintf(hFile, "};\n\n");
    fprintf(hFile, "#endif // AUDIO_SAMPLE_H\n");

    fclose(pcmFile);
    fclose(hFile);

    printf("Header File Generated Successfully\n");
}

// Main function
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <pcm_file>\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];

    // Extract the basefile name before the dot
    char outputFileName[256];
    const char *dot = strrchr(inputFileName, '.');
    size_t base_length = dot - inputFileName;
    // Create h file with same name as input file
    snprintf(outputFileName, sizeof(outputFileName), "%.*s.h", (int)base_length, inputFileName);

    PCM_2_H(inputFileName, outputFileName);

    
    return 0;
}


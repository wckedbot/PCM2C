#include <stdio.h>
#include <stdint.h>
#include <string.h>

void WAV_2_H(const char *fileName)
{
    
}



// // Main function
// int main(int argc, char *argv[])
// {
//     if (argc < 2)
//     {
//         fprintf(stderr, "Usage: %s <pcm_file>\n", argv[0]);
//         return 1;
//     }

//     const char *inputFileName = argv[1];

//     // Extract the basefile name before the dot
//     char outputFileName[256];
//     const char *dot = strrchr(inputFileName, '.');
//     size_t base_length = dot - inputFileName;
//     // Create h file with same name as input file
//     snprintf(outputFileName, sizeof(outputFileName), "%.*s.h", (int)base_length, inputFileName);

//     PCM_2_H(inputFileName, outputFileName);

    
//     return 0;
// }

int main()
{
    WAV_2_H("sine.wav", "sine.h");

    
    return 0;
}
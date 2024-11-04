# PCM2C
PCM2C converts any given PCM file to C header file containing raw data and metadata about the audio.

The tool can be used to create audio data playable on TI MCASP devices.

To generate header file, put the audio source in the folder containing the pcm2c.c file and run 
```gcc -o pcm2c pcm2c.c``` 

to generate pcm2c binary.

Then run the binary with input filename,
```./pcm2c filename.pcm```.
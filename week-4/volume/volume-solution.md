# Volume Modifier (CS50x Problem Set 4)

This project contains my solution for the **Volume** problem set. The task here was to take an audio file in the WAV format and change its volume without breaking the file. This was my first time reading and manipulating the raw data of a file, which was something unique and no college is going to teach this stuff.

---

## Getting Started: Downloading the Starter Code

Here is the quick process we used to download the provided distribution code:

1.  Open the terminal and execute `cd` to go to the main directory.
    ```bash
    cd
    ```
2.  Download the ZIP file containing the code:
    ```bash
    wget https://cdn.cs50.net/2024/fall/psets/4/volume.zip
    ```
3.  Unzip the folder:
    ```bash
    unzip volume.zip
    ```
4.  Remove the ZIP file (no need for it now):
    ```bash
    rm volume.zip
    ```
5.  Navigate into the project directory:
    ```bash
    cd volume
    ```
    Now you should see `volume.c` ready to be edited!
    ### Source: https://cs50.harvard.edu/x/psets/4/volume/

---

## Implementation Details (The Core Logic)

The challenge here wasn't just math; it was about understanding the structure of a WAV file. A WAV file has two main parts: a small header with metadata (like sample rate and file size) and the actual raw audio samples.

I tackled the two main "TODOs" in `volume.c`:

1.  **Copying the Header:**
    * **What it does:** The header holds all the information the computer needs to play the file (e.g., "This is a 16-bit stereo file"). We cannot change this.
    * **How I implemented it:** I used `fread` to copy the exact size of the WAV header (44 bytes) from the `input` file and immediately used `fwrite` to write that same block of data to the `output` file. Header copied, mission successful!

2.  **Modifying the Samples:**
    * **What it does:** The samples are the actual sound data. To change the volume, we just multiply each sample value by a given "factor" (e.g., if the factor is 0.5, the sound is half as loud).
    * **How I implemented it:** I created a small `buffer` (using the correct data type for WAV samples, which is `int16_t`). Then, using a `while` loop, I continuously did three things:
        a. **Read:** Read one sample from the input file into the buffer.
        b. **Modify:** Multiplied the sample value in the buffer by the volume factor.
        c. **Write:** Wrote the modified sample from the buffer to the output file.
        The loop stopped once `fread` could no longer read a sample, meaning we reached the end of the input audio.

The complete and commented code for this logic is fully implemented in `volume.c`.
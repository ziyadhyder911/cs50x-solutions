# Filter (Less) - Image Processing with C

This project is my solution for the **Filter (Less)** problem set from CS50x. The task was to implement various image filters by manipulating the raw pixel data of a BMP file.

This problem is not at all simple. It consists of many alien terms that you might not be familiar with, like bitmap, RGB values, and headers. Hence, it is strongly recommended to read the complete documentation from the [official CS50 page](https://cs50.harvard.edu/x/psets/4/filter/less/). Only then will you be able to understand what's happening and what we are supposed to do. I have only posted solution for **Filter (less)** and tbh I felt this very complicated. If you are more confortable, you can submit **Filter (more)** as well.

---

## Getting Started: Downloading the Distribution Code

Here is the quick process we used to download the provided distribution code:

1.  Open the terminal and execute `cd` to go to the main directory.
    ```bash
    cd
    ```
2.  Download the ZIP file containing the code:
    ```bash
    wget https://cdn.cs50.net/2024/fall/psets/4/filter-less.zip
    ```
3.  Unzip the folder:
    ```bash
    unzip filter-less.zip
    ```
4.  Remove the ZIP file (no need for it now):
    ```bash
    rm filter-less.zip
    ```
5.  Navigate into the project directory:
    ```bash
    cd filter-less
    ```
    Now you will see `bmp.h`, `filter.c`, `helpers.h`, `helpers.c`, and `Makefile`.
    ### Source: https://cs50.harvard.edu/x/psets/4/filter/less/

---

## My Task: Completing the Functions

Our task was to complete the functions in `helpers.c` to perform the image filtering. I implemented the following functions:

1.  **`void grayscale()`**: Averaged the red, green, and blue (RGB) values of each pixel and assigned the result back to each color channel to remove all color.

2.  **`void sepia()`**: Applied the sepia formula to each pixel's RGB values and clamped the results to a maximum of 255.

3.  **`void reflect()`**: Swapped the pixels horizontally to create a perfect reflection of the image.

4.  **`void blur()`**: Averaged each pixel with its surrounding neighbors to create a blur effect.

The full implementation with detailed comments can be found in `helpers.c`.
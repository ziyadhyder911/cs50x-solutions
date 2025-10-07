# pset 3: Sort Analysis and Algorithm Identification

This file documents the procedure and contains the theoretical analysis for the `sort` problem set from CS50x. The task is to identify the sorting algorithm used by three provided executables (`sort1`, `sort2`, `sort3`) based on their performance characteristics.

---

## Procedure for Testing the Executables

Our first task is to download and run the executable files to observe their behavior (speed) on different data sets (e.g., small, large, sorted, reversed).

### Steps to Download and Prepare Files (Linux/Codespace)

1.  Open your terminal window (or CS50 Codespace).
2.  Navigate to your home directory:
    ```bash
    cd
    ```
3.  Download the problem files:
    ```bash
    wget https://cdn.cs50.net/2024/fall/psets/3/sort.zip
    ```
4.  Unzip the folder containing the executables:
    ```bash
    unzip sort.zip
    ```
5.  Remove the large ZIP file (as it is no longer needed):
    ```bash
    rm sort.zip
    # Respond 'y' when prompted.
    ```
6.  The executables are now available for testing inside the newly created `sort` folder.

    ### Source: https://cs50.harvard.edu/x/psets/3/sort/

---

## 1. Sorting Algorithm Identification

After running the executables on various data sets and observing their performance (speed), I determined the algorithms as follows.

| Executable | Identified Algorithm |
| :--- | :--- |
| **sort1** | **Bubble Sort** |
| **sort2** | **Merge Sort** |
| **sort3** | **Selection Sort** |

---

## 2. Theoretical Analysis and Justification

### A. sort1 uses: Bubble Sort

**Justification (How do you know?):**
* **Best Case Speed:** The algorithm is remarkably fast (nearly instant) when testing datasets that are *already sorted* or nearly sorted. This is a signature of Bubble Sort, as it stops making passes once no swaps occur.
* **Worst Case Speed:** It becomes very slow and inefficient when testing very large or *reversed* datasets.
* **Time Complexity:** The performance profile matches the **O(n)** Best Case and **O($n^2$)** Worst Case complexity of Bubble Sort.

### B. sort2 uses: Merge Sort

**Justification (How do you know?):**
* **Consistent Speed:** The time taken to sort the datasets is consistently fast and does not drastically change between sorted, random, or reversed datasets.
* **Time Complexity:** The reliable, high performance is the hallmark of the **O(n log n)** complexity algorithms, which is standard for Merge Sort. It is efficient across all common scenarios.

### C. sort3 uses: Selection Sort

**Justification (How do you know?):**
* **Poor Performance:** This algorithm is noticeably slow and inefficient, especially as the size of the dataset increases, regardless of whether the data is sorted or reversed.
* **Time Complexity:** Its performance profile perfectly aligns with the **O($n^2$)** time complexity for **all** cases (Best, Average, and Worst). It constantly checks every remaining element to find the next smallest, making the total number of operations consistent and high.

---

## 3. Algorithm Summary (Simplified)

### Bubble Sort
* **How it works (Simple):** It repeatedly compares neighbors and "bubbles" the largest element to its correct place. If the list is already sorted, it quickly realizes this and stops.
* **Performance:** Generally slow (**O($n^2$)**), but surprisingly fast **(O(n))** if the list starts out already sorted.

### Selection Sort
* **How it works (Simple):** It finds the smallest remaining item in the list and swaps it into the next available position. It repeats this until the whole list is sorted.
* **Performance:** Always slow and consistent (**O($n^2$)**) because it always has to check every single remaining item on every pass, even if the list is nearly sorted.

### Merge Sort
* **How it works (Simple):** It splits the list in half over and over until you have many tiny lists of just one item. Then it merges those tiny, sorted lists back together in the correct order until the whole list is merged.
* **Performance:** Consistently fast (**O(n log n)**), making it a great general-purpose algorithm, especially for large amounts of data.
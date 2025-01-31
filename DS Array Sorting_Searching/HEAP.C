#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// Function to display the heap as a tree
void DrawHeap(int a[], int size, int x, int y, int level, int index) {
    char str[10];
    int offset;
    int leftChild;
    int rightChild;
    if (index >= size) return;

    // Increase offset with level for better spacing
    offset = 150 / (level + 1);
    leftChild = 2 * index + 1;
    rightChild = 2 * index + 2;

    // Draw current node
    sprintf(str, "%d", a[index]);
    setcolor(WHITE);
    circle(x, y, 20);
    outtextxy(x - 10, y - 5, str);

    // Draw left child
    if (leftChild < size) {
        line(x, y + 20, x - offset, y + 60);
        DrawHeap(a, size, x - offset, y + 60, level + 1, leftChild);
    }

    // Draw right child
    if (rightChild < size) {
        line(x, y + 20, x + offset, y + 60);
        DrawHeap(a, size, x + offset, y + 60, level + 1, rightChild);
    }
}

// Function to visualize comparisons and swaps during heap operations
void DisplayStep(int a[], int size, int step, const char* action, const char* function_name, int index1, int index2) {
    char text[100];
    cleardevice();  // Clear screen before drawing each new heap state

    // Display the current function and step information
    sprintf(text, "Function: %s, Step %d: %s", function_name, step, action);
    outtextxy(10, 10, text);

    // Highlight the elements being compared or swapped
    if (index1 >= 0 && index2 >= 0) {
        sprintf(text, "Comparing/Swapping: %d (Index %d) and %d (Index %d)", a[index1], index1, a[index2], index2);
        outtextxy(10, 30, text);
    }

    // Draw the heap
    DrawHeap(a, size, 320, 50, 1, 0);
    getch();  // Wait for user input to go to the next step
}

// Function to build a max heap
void BuildHeap(int a[], int size) {
    int step, i, element, s, f;
    step = 1;

    for (i = 1; i < size; i++) {
        element = a[i];
        s = i;
        f = (s - 1) / 2;

        while (s > 0 && element > a[f]) {
            a[s] = a[f];
            DisplayStep(a, size, step++, "Swapping elements during BuildHeap", "BuildHeap", s, f);
            s = f;
            f = (s - 1) / 2;
        }
        a[s] = element;
    }
}

// Function to perform heap sort
void HeapSort(int a[], int size) {
    int step, i, temp, f, s;
    step = 1;
    BuildHeap(a, size);

    for (i = size - 1; i > 0; i--) {
        // Swap the root with the last element
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        DisplayStep(a, size, step++, "Swapping root with last element", "HeapSort", 0, i);

        // Restore the heap property
        f = 0;  // Start from the root
        s = 2 * f + 1;  // Left child index

        // Make sure left child exists and compare with right child
        while (s < i) {
            // Check if right child exists and is greater than left child
            if (s + 1 < i && a[s + 1] > a[s]) {
                s = s + 1;  // Move to the right child if it's larger
            }

            // If the current node is greater than the largest child, we are done
            if (a[f] >= a[s]) {
                break;
            }

            // Swap the current node with the largest child
            temp = a[f];
            a[f] = a[s];
            a[s] = temp;
            DisplayStep(a, size, step++, "Restoring heap property", "HeapSort", f, s);

            f = s;  // Move down to the child
            s = 2 * f + 1;  // Update the left child index
        }
    }
}
int main() {
    int gd, gm;
    int a[100], size, i;

    // Input array size and elements
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize graphics mode
    gd = DETECT;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Display the initial heap
    cleardevice();
    outtextxy(10, 10, "Initial Heap:");
    DrawHeap(a, size, 320, 50, 1, 0);
    getch();  // Wait for user input to start sorting

    // Perform heap sort step by step
    HeapSort(a, size);

    // Display the sorted heap
    cleardevice();
    outtextxy(10, 10, "Sorted Heap:");
    DrawHeap(a, size, 320, 50, 1, 0);
    getch();  // Wait for user input before closing

    // Close graphics mode
    closegraph();

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

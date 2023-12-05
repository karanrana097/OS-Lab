#include <stdio.h>

#define MAX_FRAMES 3

int isPagePresent(int page, int frames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            return 1; // Page is present
        }
    }
    return 0; // Page is not present
}

int findOldestPageIndex(int pages[], int frames[], int frameCount, int currentPageIndex) {
    int oldestPageIndex = currentPageIndex;
    for (int i = 0; i < frameCount; i++) {
        int j = currentPageIndex - 1;
        while (j >= 0) {
            if (frames[i] == pages[j]) {
                if (j < oldestPageIndex) {
                    oldestPageIndex = j;
                }
                break;
            }
            j--;
        }
    }
    return oldestPageIndex;
}

void fifoPageReplacement(int pages[], int pageCount) {
    int frames[MAX_FRAMES] = {-1}; // Initialize frames with -1 (empty)
    int frameCount = 0; // Number of frames currently occupied
    int pageHits = 0;
    int pageFaults = 0;

    printf("Page\tFrames\t\tPage Hit/Fault\n");

    for (int i = 0; i < pageCount; i++) {
        printf("%d\t", pages[i]);

        if (isPagePresent(pages[i], frames, frameCount)) {
            pageHits++;
            printf("\t");
        } else {
            pageFaults++;
            if (frameCount < MAX_FRAMES) {
                frames[frameCount] = pages[i];
                frameCount++;
            } else {
                int oldestPageIndex = findOldestPageIndex(pages, frames, frameCount, i);
                frames[oldestPageIndex] = pages[i];
            }
            printf("%d->\t", pages[i]);
        }

        for (int j = 0; j < frameCount; j++) {
            printf("%d ", frames[j]);
        }

        printf("\t\tPage %s\n", (isPagePresent(pages[i], frames, frameCount) ? "Hit" : "Fault"));
    }

    printf("\nTotal Page Hits: %d\n", pageHits);
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pageCount;
    printf("Enter the number of pages: ");
    scanf("%d", &pageCount);

    int pages[pageCount];
    printf("Enter the sequence of page requests:\n");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }

    fifoPageReplacement(pages, pageCount);

    return 0;
}

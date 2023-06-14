#include <iostream>

using namespace std;

void MergeSort(int dataSet[], int startIndex, int endIndex);
void Merge(int dataSet[], int startIndex, int middleIndex, int endIndex);

int main()
{
    int dataSet[] = {334, 6, 4, 2, 3, 1, 5, 117, 12, 34};
    int length = sizeof(dataSet) / sizeof(dataSet[0]);

    MergeSort(dataSet, 0, length - 1);

    for (int i = 0; i < length; i++) {
        cout << dataSet[i] << " ";
    }

    cout << endl;

    return 0;
}

void MergeSort(int dataSet[], int startIndex, int endIndex)
{
    if (endIndex - startIndex < 1) {
        return;
    }

    int middleIndex = (startIndex + endIndex) / 2;

    MergeSort(dataSet, startIndex, middleIndex);
    MergeSort(dataSet, middleIndex + 1, endIndex);
    Merge(dataSet, startIndex, middleIndex, endIndex);
}

void Merge(int dataSet[], int startIndex, int middleIndex, int endIndex)
{
    int* destination = new int[endIndex - startIndex + 1];
    int leftIndex = startIndex;
    int rightIndex = middleIndex + 1;
    int destIndex = 0;

    while (leftIndex <= middleIndex && rightIndex <= endIndex) {
        if (dataSet[leftIndex] < dataSet[rightIndex]) {
            destination[destIndex] = dataSet[leftIndex];
            leftIndex++;
        }
        else {
            destination[destIndex] = dataSet[rightIndex];
            rightIndex++;
        }
        destIndex++;
    }

    while (leftIndex <= middleIndex) {
        destination[destIndex++] = dataSet[leftIndex++];
    }

    while (rightIndex <= endIndex) {
        destination[destIndex++] = dataSet[rightIndex++];
    }

    destIndex = 0;

    for (int i = startIndex; i <= endIndex; i++) {
        dataSet[i] = destination[destIndex++];
    }

    delete[] destination;
}

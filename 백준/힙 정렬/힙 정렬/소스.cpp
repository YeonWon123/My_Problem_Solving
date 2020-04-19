#include <cstdio>
#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

/*** Heap�� ���� ****/
#define HEAP_LEN 100

typedef int HData;

// d1�� �켱������ ���ٸ� 0���� ū ��
// d2�� �켱������ ���ٸ� 0���� ���� ��
// d1�� d2�� �켱������ ���ٸ� 0�� ��ȯ
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap {
    PriorityComp* comp;
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;

/*** Heap ���� ����� ****/
void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);
void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);

void HeapInit(Heap* ph, PriorityComp pc) {
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap* ph) {
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx) {
    return idx / 2;
}
int GetLChildIDX(int idx) {
    return idx * 2;
}

int GetRChildIDX(int idx) {
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx) {
    if (GetLChildIDX(idx) > ph->numOfData)
        return 0;
    else if (GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else {
        if (ph->comp(ph->heapArr[GetLChildIDX(idx)],
            ph->heapArr[GetRChildIDX(idx)]) < 0)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

void HInsert(Heap* ph, HData data) {
    int idx = ph->numOfData + 1;

    while (idx != 1) {
        if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else {
            break;
        }
    }
    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}


HData HDelete(Heap* ph) {
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
        if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;

        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}

int PriComp(int n1, int n2) {
    return n2 - n1;
}

void HeapSort(int arr[], int n, PriorityComp pc) {
    Heap heap;
    int i;

    HeapInit(&heap, pc);

    // ���� ����� ������ ���� �����Ѵ�.
    for (i = 0; i < n; i++)
        HInsert(&heap, arr[i]);

    // ������� �ϳ��� ������ ������ �ϼ��Ѵ�.
    for (i = 0; i < n; i++)
        arr[i] = HDelete(&heap);
}

int main(void)
{
    int arr[4] = { 3, 4, 2, 1 };
    int i;

    HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

    for (i = 0; i < 4; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

void _swap(int *x, int *y);
void bubble_sort(int a[], int n);
void selection_sort(int a[], int n);
void insertion_sort(int a[], int n);
void _merge(int a[], int beg, int mid, int _end);
void merge_sort(int a[], int beg, int _end);
void _partition(int a[], int beg, int _end);
void quick_sort(int a[], int beg, int _end);

#endif // SORT_H_INCLUDED

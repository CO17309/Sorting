#include<iostream>
#define size 100

using namespace std;

void _swap(int *x, int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

void bubble_sort(int a[], int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        int flag = 0;
        for(j=0;j<n-i+1;j++)
        {
            if(a[j]>a[j+1])
            {
                _swap(&a[j],&a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}

void selection_sort(int a[], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                _swap(&a[i],&a[j]);
            }
        }
    }
}


void insertion_sort(int a[], int n)
{
    int i,hole,value;
    for(i=1;i<n;i++)
    {
        value = a[i];
        hole = i;
        while(hole > 0 && a[hole - 1] > value)
        {
            a[hole] = a[hole - 1];
            hole = hole - 1;
        }
        a[hole] = value;
    }
}

void _merge(int a[], int beg, int mid, int _end)
{
    int i = beg, j = mid + 1, index = beg, temp[size];
    while(i <= mid && j <= _end)
    {
        if(a[i] < a[j])
        {
            temp[index]  = a[i];
            i++;
        }
        else
        {
            temp[index] = a[j];
            j++;
        }
        index++;
    }
    if(i > mid)
    {
        while(j <= _end)
        {
            temp[index] = a[j];
            index++;
            j++;
        }
    }
    else
    {
        while(i <= mid)
        {
            temp[index] = a[i];
            index++;
            i++;
        }
    }
    int k = beg;
    while(k < index)
    {
        a[k] = temp[k];
        k++;
    }
}

void merge_sort(int a[], int beg, int _end)
{
    if(beg < _end)
    {
        int mid = (beg + _end)/2;
        merge_sort(a, beg, mid);
        merge_sort(a, mid + 1, _end);
        _merge(a, beg, mid, _end);
    }
}

int _partition(int a[], int beg, int _end)
{
    int left = beg, right = _end, loc = beg, flag = 0;
    while(flag != 1)
    {
        while((a[loc] <= a[right]) && (loc != right))
        {
            right--;
        }
        if(loc == right)
            flag = 1;
        else if(a[loc] > a[right])
        {
            _swap(&a[loc],&a[right]);
            loc = right;
        }
        if(flag != 1)
        {
            while((a[loc] >= a[left]) && (loc != left))
            {
                left++;
            }
            if(loc == left)
            {
                flag = 1;
            }
            else if(a[loc] < a[left])
            {
                _swap(&a[loc],&a[left]);
                loc = left;
            }
        }
    }
    return loc;
}

void quick_sort(int a[], int beg, int _end)
{
    if(beg < _end)
    {
        int pos = _partition(a, beg, _end);
        quick_sort(a, beg, pos - 1);
        quick_sort(a, pos + 1, _end);
    }
}

//
// Created by yuehu on 2019/11/11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void bubble_sort(vector<int> &input){
    size_t len = input.size();
    bool hasChange = true;

    for(size_t i = 0; i < len - 1 && hasChange; i++){
        hasChange = false;
        for(size_t j= 0; j<len - i - 1; j++){
            if(input[j] > input[j+1]){
                swap(input[j], input[j+1]);
                hasChange = true;
            }
        }
    }
}

// ======================================================
void insert_sort(vector<int> &input){
    int len = input.size();
    for(int i=1; i< len; i++){
        for(int j=i; j>0 ;j--){
            if (input[j] < input[j-1]){
                swap(input[j], input[j-1]);
            }
            else{
                break;
            }
        }
    }
}
// ======================================================
void merge(vector<int> &input, int left, int mid, int right){
    vector<int> tmp = input;
    int k = left;
    int i = left;
    int j = mid +1;
    while (k <= right){
        if(i > mid){
            input[k++] = tmp[j++];
        } else if(j > right){
            input[k++] = tmp[i++];
        } else if(tmp[j] < tmp[i]){
            input[k++] = tmp[j++];
        } else{
            input[k++] = tmp[i++];
        }
    }
}

void merge_sort(vector<int> &input, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        merge_sort(input, left, mid);
        merge_sort(input, mid+1, right);
        merge(input, left, mid, right);
    }
}

#include <ctime>
// ========================================================
int partition(vector<int> &input, int left, int right){
//    srand(time(NULL));
//    int pivot = rand ()%(right - left + 1) + left;
      int tmp = input[left];
      int i = left + 1;
      int j = right;
      while(i < j){
          while(input[j] > tmp){
              j--;
          }
          while(input[i] < tmp){
              i++;
          }
          if(i < j){
              swap(input[i], input[j]);
          }
      }
      swap(input[left], input[i]);
      input[i] = tmp;
      return i;
}

void quick_sort(vector<int> &input, int left, int right){
    if(left >= right){
         return;
    }

    int pivot = partition(input, left, right);
    quick_sort(input, left, pivot - 1 );
    quick_sort(input, pivot + 1, right);

}

// ========================================================
// heap sort

inline int parent(int i){return (i-1)>>2;} // start form 0
inline int left(int i){return (i<<1) + 1;}
inline int right(int i){return (i<<1) + 2;}

//int heap_size;
//int heap_length;

void max_heapify(vector<int> &a, int i, int heap_size){
    int l = left(i);
    int r = right(i);
    int largest = i;
    // left child >= parent
    if (l<heap_size && a[l] > a[i]){
        largest = l;
    } else{
        largest = i;
    }
    // right child >=parent
    if (r<heap_size && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i){
        swap(a[i],a[largest]);
        max_heapify(a, largest, heap_size);
    }

}

void build_heap(vector<int> &a){
    int heap_length = a.size();
    int heap_size = heap_length;
    for(int i = heap_length/2 -1;i >=0;--i){
        max_heapify(a,i, heap_size);
    }
}

void heap_sort(vector<int> &a){
    int heap_length = a.size();
    int heap_size = heap_length;
    build_heap(a);
    for(int i=heap_length - 1; i>=1;i--){
        swap(a[0],a[i]);
        --heap_size;
        max_heapify(a,0, heap_size);
    }
}

//================================================================
// bucket sort

void bucket_sort(vector<int> &input){
    int max = *max_element(input.begin(), input.end());
    int min = *min_element(input.begin(), input.end());
    int len = max - min  + 1;
    vector<int> bucket(len, 0);
    for(int i=0;i<len;i++){
        bucket[input[i]-min]++;
    }
    for(int i = 0, j=0; i<= len;i++){
        while(bucket[i] > 0){
            input[j] = i + min;
            bucket[i]--;
            j++;
        }
    }
}


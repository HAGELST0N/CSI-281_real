//
//  sort.h
//
//  Functions for bubble sort, selection sort, and insertion sort.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef sort_hpp
#define sort_hpp

#include <algorithm>  // for swap()

#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {

  // Performs an in-place ascending sort of *array* of size *length*
  // using the bubble sort algorithm
  template <typename T> void bubbleSort(T array[], const int length) {
    // YOUR CODE HERE
    for (int i=length; i>0;i--) {

      for (int j=0;j<i-1;j++) {
        T first = array[j];
        T second = array[j+1];
        if (first > second) {
          array[j] = second;
          array[j+1] = first;
        }
      }
    }
  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the selection sort algorithm
  template <typename T> void selectionSort(T array[], const int length) {
    // YOUR CODE HERE
    for (int i = 0; i<length; i++) {
      T least = array[i];
      int leastPos = i;
      for (int j=i; j<length;j++) {
        if (array[j]<least) {
          leastPos = j;
          least = array[j];
        }
      }
      if (leastPos != i) {
        T temp = array[i];
        array[i] = array[leastPos];
        array[leastPos] = temp;
      }
    }


  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the insertion sort algorithm
  template <typename T> void insertionSort(T array[], const int length) {
    // YOUR CODE HERE
    for (int i=1; i<length; i++) {
      int j;
      T toInsert = array[i];
      for(j = i-1; j>=0;j--){
        if(array[j]<toInsert){
          break;
        }
      }
      j++;
      int insertPos=j;
      T first = array[j];
      for(int k = i;k>insertPos;k--){
        array[k] = array[k-1];
      }
      array[insertPos] = toInsert;
    }
  }
}  // namespace csi281

#endif /* sort_hpp */

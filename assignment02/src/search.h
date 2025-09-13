//
//  search.h
//
//  Functions for doing linear search and binary search on an
//  arbitrary array.
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
//
// modified with permission by Patrick Hagelston
#ifndef search_hpp
#define search_hpp

#include "MemoryLeakDetector.h"

namespace csi281 {

  // Returns the first location of the found key
  // or -1 if the key is never found
  template <typename T> int linearSearch(T array[], const int length, const T key) {
    // YOUR CODE HERE
    for (int guess = 0; guess < length; guess++){
      if (key == array[guess])
        return guess;
    }
    return -1;
  }

  // Returns the first location of the found key
  // or -1 if the key is never found; assumes a sorted array
  template <typename T> int binarySearch(T array[], const int length, const T key) {
    // YOUR CODE HERE
    const int max_guess = std::ceil(log2(length));
    int guess = length / 2;
    for (int guess_count = 0; guess_count-1 < max_guess; guess_count++) {
      int guess_iter = std::max(static_cast<int>(round(length / std::pow(2, guess_count + 2))),1);
      if (array[guess] == key) {
        return guess;
        break;
      }
      if (array[guess] < key)
        guess = guess+guess_iter;
      else
        guess = guess-guess_iter;
    }
    return -1;
  }
}  // namespace csi281

#endif /* search_hpp */

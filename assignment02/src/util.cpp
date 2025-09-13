//
//  util.cpp
//
//  Implementation of Timing Tests
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

#include "util.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <ranges>

#include "search.h"

using namespace std;

namespace csi281 {

  // Returns a new int array of *length* and filled
  // with numbers between *min* and *max*
  // Suggest using the facilities in STL <random>
  int *randomIntArray(const int length, const int min, const int max) {
    // YOUR CODE HERE
    int* array = new int [length];
    // random device
    std::random_device rd;

    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution (min,max);
    //int r = distribution(generator); //use distribution to transform the random number
    int r2 = distribution(rd); //use the random distribution to get a random element in distribution range (costly use for seeding)
    for( int i = 0; i<length; i++){
      array[i] = r2;
      r2=distribution(rd);
    }
    return array;
  }

  // Finds the speed of linear versus binary search
  // in a random int array of *length* size
  // by running *numTests* and averaging them
  // Returns a pair indicating the average time it took
  // to do linear search and binary search in nanoseconds
  // Linear search should be first in the pair, and binary search
  // should be second
  //
  // Suggest using the facilities in STL <chrono>
  // For example, you can start a timer using
  // auto start = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
  // and stop a timer using
  // auto end = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
  // start, end will be results in nanoseconds
  pair<nanoseconds, nanoseconds> arraySearchSpeed(const int length, const int numTests) {
    int *testArray =  randomIntArray(length, 0, length);
    int *testKeys =  randomIntArray(numTests, 0, length);



    // Do numTests linear searches and find the average time
    // Put the result in a variable linearSearchSpeed

    // YOUR CODE HERE
    using namespace std::chrono;

    long long lin_start = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
    for(int i=0; i < numTests; i++){
      linearSearch(testArray, length, testKeys[i]);
    }
    long long lin_end = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();

    long long linearSearchSpeed = (lin_end-lin_start) / numTests;
    // Do numTests binary searches and find the average time
    // Put the result in a variable binarySearchSpeed

    // YOUR CODE HERE
    std::sort(testArray, testArray+length);
    auto bin_start = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();

    for (int i = 0; i < numTests; i++) {
      int answer = binarySearch(testArray, length, testKeys[i]);
      }

    auto bin_end = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
    auto binarySearchSpeed = (bin_end-bin_start)/numTests;

    delete testArray;
    delete testKeys;
    std::cout << linearSearchSpeed << binarySearchSpeed << std::endl;
    return pair<nanoseconds, nanoseconds>(linearSearchSpeed, binarySearchSpeed);
  }
}  // namespace csi281

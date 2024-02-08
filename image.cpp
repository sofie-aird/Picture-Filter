/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8

  This file contains the implemetation of image filter functions.
*/

#include "image.h"

#include <iostream>
using namespace std;

// Note: see image.h for documentation on functions.

int pixelToIndex(int width, int x, int y) {
    return ((y * width) + x) * 3; 
}

void noRed(int width, int height, int* ppm) {
  for (int i = 0; i < width*height*3; i+= 3) {
    ppm[i] = 0;
  }
}

void noGreen(int width, int height, int* ppm) {
  for (int i = 1; i < width*height*3; i+= 3) {
    ppm[i] = 0;
  }
}

void noBlue(int width, int height, int* ppm) {
  for (int i = 2; i < width*height*3; i+= 3) {
    ppm[i] = 0;
  }
}

void invert(int width, int height, int* ppm) {
  for (int i = 0; i < (width*height*3); i++) {
    ppm[i] = 255 - ppm[i];
  }
}

void grayscale(int width, int height, int* ppm) {
  for (int i = 0; i < width*height*3; i+= 3) {
    int average = (ppm[i] + ppm[i+1] + ppm[i+2])/3;
    ppm[i] = average;
    ppm[i+1] = average;
    ppm[i+2] = average;
  }
}

void flipHorizontally(int width, int height, int* ppm) {
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < (width / 2); ++x) {
      int left_index = pixelToIndex(width, x, y);
      int right_index = pixelToIndex(width, width-x-1, y);
      for (int i = 0; i < 3; ++i){
        swap(ppm[left_index + i], ppm[right_index + i]);
      }
    }
  }
}

void flipVertically(int width, int height, int* ppm) {
  for (int y = 0; y < height/2; ++y) {
    for (int x = 0; x < width; ++x) {
      int current_row = pixelToIndex(width, x, y);
      int opposite_row = pixelToIndex(width, x, height - y - 1);
      for (int i = 0; i < 3; ++i){
        swap(ppm[current_row + i], ppm[opposite_row + i]);
      }
    }
  }
}


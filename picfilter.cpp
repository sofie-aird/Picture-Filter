/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8

  This program prompts the user for an image to
  change, applies a filter to it, and puts the 
  filtered image into a new file.

  Sofie Aird
  February 7, 2024
*/

#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"

using namespace std;

int main(int argc, char** argv) {

    if (argc != 4) {
      cout << "Wong amount of command-line arguments. Please enter 4" << endl;
      return 1;
    }
    string filename = argv[1];
    string filter = argv[2];
    string new_filename = argv[3];
    int *image = read_ppm(filename);
    int width = ppm_width(filename);
    int height = ppm_height(filename);

    if (filter == "noRed") {
      noRed(width, height, image);
    } else if (filter == "noGreen") {
      noGreen(width, height, image);
    } else if (filter == "noBlue") {
      noBlue(width, height, image);
    } else if (filter == "invert") {
      invert(width, height, image);
    } else if (filter == "grayscale") {
      grayscale(width, height, image);
    } else if (filter == "flipHorizontally") {
      flipHorizontally(width, height, image);
    } else if (filter == "flipVertically") {
      flipVertically(width, height, image);
    } else {
      cout << "Invalid filter input. Please try again." << endl;
      return 1;
    }

    write_ppm(new_filename, width, height, image);

    
    delete [] image;
    return 0;
}

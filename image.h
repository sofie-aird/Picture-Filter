#pragma once

/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8

  This file contains declarations of each filter function.
*/

/**
 * A function to determine the location of a pixel in a PPM image array.
 * Writing this routine makes it easier to write your other image
 * transformation functions.
 * @param width The width of the PPM image.
 * @param x The X coordinate of the pixel.
 * @param y The Y coordinate of the pixel.
 * @return The index of the first integer in the specified pixel.
 * For example:
 *         if x==1 and y==0, this function returns 3.
 */
int pixelToIndex(int width, int x, int y);

/**
 * A function which removes the red from an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void noRed(int width, int height, int* ppm);

/**
* A function which removes the green from an image.
* @param width The width of the image to transform.
* @param height The height of the image to transform.
* @param ppm The PPM image to transform.
*/
void noGreen(int width, int height, int* ppm);

/**
* A function which removes the blue from an image.
* @param width The width of the image to transform.
* @param height The height of the image to transform.
* @param ppm The PPM image to transform.
*/
void noBlue(int width, int height, int* ppm);

/**
* A function which inverts the colors of an image.
* @param width The width of the image to transform.
* @param height The height of the image to transform.
* @param ppm The PPM image to transform.
*/
void invert(int width, int height, int* ppm);

/**
* A function which displays the image in shades of gray.
* @param width The width of the image to transform.
* @param height The height of the image to transform.
* @param ppm The PPM image to transform.
*/
void grayscale(int width, int height, int* ppm);

/**
* A function which mirrors the origial image.
* @param width The width of the image to transform.
* @param height The height of the image to transform.
* @param ppm The PPM image to transform.
*/
void flipHorizontally(int width, int height, int* ppm);

/**
* A function which turns the original image upside-down.
* @param width The width of the image to transform.
* @param height The height of the image to transform.
* @param ppm The PPM image to transform.
*/
void flipVertically(int width, int height, int* ppm);



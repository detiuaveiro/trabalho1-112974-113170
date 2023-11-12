/// image8bit - A simple image processing module.
///
/// This module is part of a programming project
/// for the course AED, DETI / UA.PT
///
/// You may freely use and modify this code, at your own risk,
/// as long as you give proper credit to the original and subsequent authors.
///
/// João Manuel Rodrigues <jmr@ua.pt>
/// 2013, 2023

// Student authors (fill in below):
<<<<<<< HEAD
// NMec:   Name:
//
//
//
=======
// NMec:  Name:
//
//
// 
>>>>>>> upstream/main
// Date:
//

#include "image8bit.h"

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <math.h>
    =======
>>>>>>> upstream/main
#include "instrumentation.h"

    // The data structure
    //
    // An image is stored in a structure containing 3 fields:
    // Two integers store the image width and height.
    // The other field is a pointer to an array that stores the 8-bit gray
    // level of each pixel in the image.  The pixel array is one-dimensional
    // and corresponds to a "raster scan" of the image from left to right,
    // top to bottom.
    // For example, in a 100-pixel wide image (img->width == 100),
    //   pixel position (x,y) = (33,0) is stored in img->pixel[33];
    //   pixel position (x,y) = (22,1) is stored in img->pixel[122].
<<<<<<< HEAD
    //
=======
    // 
>>>>>>> upstream/main
    // Clients should use images only through variables of type Image,
    // which are pointers to the image structure, and should not access the
    // structure fields directly.

    // Maximum value you can store in a pixel (maximum maxval accepted)
    const uint8 PixMax = 255;

// Internal structure for storing 8-bit graymap images
<<<<<<< HEAD
struct image
{
  int width;
  int height;
  int maxval;   // maximum gray value (pixels with maxval are pure WHITE)
  uint8 *pixel; // pixel data (a raster scan)
};

=======
struct image
{
  int width;
  int height;
  int maxval;   // maximum gray value (pixels with maxval are pure WHITE)
  uint8 *pixel; // pixel data (a raster scan)
};


>>>>>>> upstream/main
// This module follows "design-by-contract" principles.
// Read `Design-by-Contract.md` for more details.

/// Error handling functions

// In this module, only functions dealing with memory allocation or file
// (I/O) operations use defensive techniques.
<<<<<<< HEAD
//
=======
// 
>>>>>>> upstream/main
// When one of these functions fails, it signals this by returning an error
// value such as NULL or 0 (see function documentation), and sets an internal
// variable (errCause) to a string indicating the failure cause.
// The errno global variable thoroughly used in the standard library is
// carefully preserved and propagated, and clients can use it together with
// the ImageErrMsg() function to produce informative error messages.
// The use of the GNU standard library error() function is recommended for
// this purpose.
//
// Additional information:  man 3 errno;  man 3 error;

// Variable to preserve errno temporarily
static int errsave = 0;

// Error cause
<<<<<<< HEAD
static char *errCause;
=======
static char *errCause;
>>>>>>> upstream/main

/// Error cause.
/// After some other module function fails (and returns an error code),
/// calling this function retrieves an appropriate message describing the
/// failure cause.  This may be used together with global variable errno
/// to produce informative error messages (using error(), for instance).
///
/// After a successful operation, the result is not garanteed (it might be
/// the previous error cause).  It is not meant to be used in that situation!
<<<<<<< HEAD
char *ImageErrMsg()
{ ///
  return errCause;
}

=======
char *ImageErrMsg()
{ ///
  return errCause;
}


>>>>>>> upstream/main
// Defensive programming aids
//
// Proper defensive programming in C, which lacks an exception mechanism,
// generally leads to possibly long chains of function calls, error checking,
// cleanup code, and return statements:
//   if ( funA(x) == errorA ) { return errorX; }
//   if ( funB(x) == errorB ) { cleanupForA(); return errorY; }
//   if ( funC(x) == errorC ) { cleanupForB(); cleanupForA(); return errorZ; }
//
// Understanding such chains is difficult, and writing them is boring, messy
// and error-prone.  Programmers tend to overlook the intricate details,
// and end up producing unsafe and sometimes incorrect programs.
//
// In this module, we try to deal with these chains using a somewhat
// unorthodox technique.  It resorts to a very simple internal function
// (check) that is used to wrap the function calls and error tests, and chain
// them into a long Boolean expression that reflects the success of the entire
// operation:
<<<<<<< HEAD
//   success =
=======
//   success = 
>>>>>>> upstream/main
//   check( funA(x) != error , "MsgFailA" ) &&
//   check( funB(x) != error , "MsgFailB" ) &&
//   check( funC(x) != error , "MsgFailC" ) ;
//   if (!success) {
//     conditionalCleanupCode();
//   }
//   return success;
<<<<<<< HEAD
//
// When a function fails, the chain is interrupted, thanks to the
// short-circuit && operator, and execution jumps to the cleanup code.
// Meanwhile, check() set errCause to an appropriate message.
//
// This technique has some legibility issues and is not always applicable,
// but it is quite concise, and concentrates cleanup code in a single place.
//
=======
//
// When a function fails, the chain is interrupted, thanks to the
// short-circuit && operator, and execution jumps to the cleanup code.
// Meanwhile, check() set errCause to an appropriate message.
//
// This technique has some legibility issues and is not always applicable,
// but it is quite concise, and concentrates cleanup code in a single place.
// 
>>>>>>> upstream/main
// See example utilization in ImageLoad and ImageSave.
//
// (You are not required to use this in your code!)

<<<<<<< HEAD
=======

>>>>>>> upstream/main
// Check a condition and set errCause to failmsg in case of failure.
// This may be used to chain a sequence of operations and verify its success.
// Propagates the condition.
// Preserves global errno!
<<<<<<< HEAD
static int check(int condition, const char *failmsg)
{
  errCause = (char *)(condition ? "" : failmsg);
  return condition;
}

/// Init Image library.  (Call once!)
/// Currently, simply calibrate instrumentation and set names of counters.
void ImageInit(void)
{ ///
  InstrCalibrate();
  InstrName[0] = "pixmem"; // InstrCount[0] will count pixel array acesses
  // Name other counters here...
=======
static int check(int condition, const char *failmsg)
{
  errCause = (char *)(condition ? "" : failmsg);
  return condition;
}

/// Init Image library.  (Call once!)
/// Currently, simply calibrate instrumentation and set names of counters.
void ImageInit(void)
{ ///
  InstrCalibrate();
  InstrName[0] = "pixmem"; // InstrCount[0] will count pixel array acesses
  // Name other counters here...
  
>>>>>>> upstream/main
}

// Macros to simplify accessing instrumentation counters:
#define PIXMEM InstrCount[0]
// Add more macros here...

// TIP: Search for PIXMEM or InstrCount to see where it is incremented!

<<<<<<< HEAD
=======

>>>>>>> upstream/main
/// Image management functions

/// Create a new black image.
///   width, height : the dimensions of the new image.
///   maxval: the maximum gray level (corresponding to white).
/// Requires: width and height must be non-negative, maxval > 0.
<<<<<<< HEAD
///
/// On success, a new image is returned.
/// (The caller is responsible for destroying the returned image!)
/// On failure, returns NULL and errno/errCause are set accordingly.

// TODO Estudar a forma como os erros vao ser desenvolvidos
Image ImageCreate(int width, int height, uint8 maxval)
{ ///

  assert(width >= 0);
  assert(height >= 0);
  assert(0 < maxval && maxval <= PixMax);

  // Insert your code here!
  Image i = (Image)malloc(sizeof(*i));

  if (i == NULL)
  {
    check(i == NULL, "NAO CONSEGUI ALOCAR MEMORIA"); // ALTERAR
    return NULL;
  }

  i->height = height;
  i->width = width;
  i->maxval = maxval;

  uint8 *pixel = (uint8 *)malloc(sizeof(uint8) * width * height);

  i->pixel = pixel;

  return i;
=======
///
/// On success, a new image is returned.
/// (The caller is responsible for destroying the returned image!)
/// On failure, returns NULL and errno/errCause are set accordingly.
Image ImageCreate(int width, int height, uint8 maxval)
{ ///
  assert(width >= 0);
  assert(height >= 0);
  assert(0 < maxval && maxval <= PixMax);
  // Insert your code here!
>>>>>>> upstream/main
}

/// Destroy the image pointed to by (*imgp).
///   imgp : address of an Image variable.
/// If (*imgp)==NULL, no operation is performed.
/// Ensures: (*imgp)==NULL.
/// Should never fail, and should preserve global errno/errCause.
<<<<<<< HEAD
void ImageDestroy(Image *imgp)
{ ///

  assert(imgp != NULL);
  // Insert your code here!

  free((*imgp)->pixel);
  free(*imgp);
  // if(*imgp == NULL){
  //   printf("erro 2");
  //   // TODO ERROR
  // }
  *imgp = NULL;
}

=======
void ImageDestroy(Image *imgp)
{ ///
  assert(imgp != NULL);
  // Insert your code here!
}


>>>>>>> upstream/main
/// PGM file operations

// See also:
// PGM format specification: http://netpbm.sourceforge.net/doc/pgm.html

// Match and skip 0 or more comment lines in file f.
// Comments start with a # and continue until the end-of-line, inclusive.
// Returns the number of comments skipped.
<<<<<<< HEAD
static int skipComments(FILE *f)
{
  char c;
  int i = 0;
  while (fscanf(f, "#%*[^\n]%c", &c) == 1 && c == '\n')
  {
=======
static int skipComments(FILE *f)
{
  char c;
  int i = 0;
  while (fscanf(f, "#%*[^\n]%c", &c) == 1 && c == '\n')
  {
>>>>>>> upstream/main
    i++;
  }
  return i;
}

/// Load a raw PGM file.
/// Only 8 bit PGM files are accepted.
/// On success, a new image is returned.
/// (The caller is responsible for destroying the returned image!)
/// On failure, returns NULL and errno/errCause are set accordingly.
<<<<<<< HEAD
Image ImageLoad(const char *filename)
{ ///
  int w, h;
  int maxval;
  char c;
  FILE *f = NULL;
  Image img = NULL;

  int success =
      check((f = fopen(filename, "rb")) != NULL, "Open failed") &&
      // Parse PGM header
      check(fscanf(f, "P%c ", &c) == 1 && c == '5', "Invalid file format") &&
      skipComments(f) >= 0 &&
      check(fscanf(f, "%d ", &w) == 1 && w >= 0, "Invalid width") &&
      skipComments(f) >= 0 &&
      check(fscanf(f, "%d ", &h) == 1 && h >= 0, "Invalid height") &&
      skipComments(f) >= 0 &&
      check(fscanf(f, "%d", &maxval) == 1 && 0 < maxval && maxval <= (int)PixMax, "Invalid maxval") &&
      check(fscanf(f, "%c", &c) == 1 && isspace(c), "Whitespace expected") &&
      // Allocate image
      (img = ImageCreate(w, h, (uint8)maxval)) != NULL &&
      // Read pixels
      check(fread(img->pixel, sizeof(uint8), w * h, f) == w * h, "Reading pixels");
  PIXMEM += (unsigned long)(w * h); // count pixel memory accesses

  // Cleanup
  if (!success)
  {
=======
Image ImageLoad(const char *filename)
{ ///
  int w, h;
  int maxval;
  char c;
  FILE *f = NULL;
  Image img = NULL;

  int success =
      check((f = fopen(filename, "rb")) != NULL, "Open failed") &&
      // Parse PGM header
      check(fscanf(f, "P%c ", &c) == 1 && c == '5', "Invalid file format") &&
      skipComments(f) >= 0 &&
      check(fscanf(f, "%d ", &w) == 1 && w >= 0, "Invalid width") &&
      skipComments(f) >= 0 &&
      check(fscanf(f, "%d ", &h) == 1 && h >= 0, "Invalid height") &&
      skipComments(f) >= 0 &&
      check(fscanf(f, "%d", &maxval) == 1 && 0 < maxval && maxval <= (int)PixMax, "Invalid maxval") &&
      check(fscanf(f, "%c", &c) == 1 && isspace(c), "Whitespace expected") &&
      // Allocate image
      (img = ImageCreate(w, h, (uint8)maxval)) != NULL &&
      // Read pixels
      check(fread(img->pixel, sizeof(uint8), w * h, f) == w * h, "Reading pixels");
  PIXMEM += (unsigned long)(w * h); // count pixel memory accesses

  // Cleanup
  if (!success)
  {
>>>>>>> upstream/main
    errsave = errno;
    ImageDestroy(&img);
    errno = errsave;
  }
<<<<<<< HEAD

  if (f != NULL)
    fclose(f);

=======
  if (f != NULL)
    fclose(f);
>>>>>>> upstream/main
  return img;
}

/// Save image to PGM file.
/// On success, returns nonzero.
/// On failure, returns 0, errno/errCause are set appropriately, and
/// a partial and invalid file may be left in the system.
<<<<<<< HEAD
int ImageSave(Image img, const char *filename)
{ ///

  assert(img != NULL);
  int w = img->width;
  int h = img->height;
  uint8 maxval = img->maxval;
  FILE *f = NULL;

  int success =
      check((f = fopen(filename, "wb")) != NULL, "Open failed") &&
      check(fprintf(f, "P5\n%d %d\n%u\n", w, h, maxval) > 0, "Writing header failed") &&
      check(fwrite(img->pixel, sizeof(uint8), w * h, f) == w * h, "Writing pixels failed");
  PIXMEM += (unsigned long)(w * h); // count pixel memory accesses

  // Cleanup
  if (f != NULL)
    fclose(f);
  return success;
}

=======
int ImageSave(Image img, const char *filename)
{ ///
  assert(img != NULL);
  int w = img->width;
  int h = img->height;
  uint8 maxval = img->maxval;
  FILE *f = NULL;

  int success =
      check((f = fopen(filename, "wb")) != NULL, "Open failed") &&
      check(fprintf(f, "P5\n%d %d\n%u\n", w, h, maxval) > 0, "Writing header failed") &&
      check(fwrite(img->pixel, sizeof(uint8), w * h, f) == w * h, "Writing pixels failed");
  PIXMEM += (unsigned long)(w * h); // count pixel memory accesses

  // Cleanup
  if (f != NULL)
    fclose(f);
  return success;
}


>>>>>>> upstream/main
/// Information queries

/// These functions do not modify the image and never fail.

/// Get image width
<<<<<<< HEAD
int ImageWidth(Image img)
{ ///
  assert(img != NULL);
=======
int ImageWidth(Image img)
{ ///
  assert(img != NULL);
>>>>>>> upstream/main
  return img->width;
}

/// Get image height
<<<<<<< HEAD
int ImageHeight(Image img)
{ ///
  assert(img != NULL);
=======
int ImageHeight(Image img)
{ ///
  assert(img != NULL);
>>>>>>> upstream/main
  return img->height;
}

/// Get image maximum gray level
int ImageMaxval(Image img)
{ ///
  assert(img != NULL);
  return img->maxval;
}

/// Pixel stats
/// Find the minimum and maximum gray levels in image.
/// On return,
/// *min is set to the minimum gray level in the image,
/// *max is set to the maximum.
// TODO CHECK
// TODO  possivel melhoria a  media de todos os outros valores se for menor q o valor atual entao posso dar break
void ImageStats(Image img, uint8 *min, uint8 *max)
{ ///
  int arrayfinal = img->height * img->width;
  *min = 255;
  *max = 0;

  for (int i = 0; i < arrayfinal; i++)
  {
    uint8 pixel = img->pixel[i];
    if (*min > pixel)
      *min = pixel;
    if (*max < pixel)
      *max = pixel;

    if (*max == 255 && *min == 0)
      break;
  }

  assert(img != NULL);
  // Insert your code here!
}

/// Check if pixel position (x,y) is inside img.
int ImageValidPos(Image img, int x, int y)
{ ///
  assert(img != NULL);
  return (0 <= x && x < img->width) && (0 <= y && y < img->height);
}

/// Check if rectangular area (x,y,w,h) is completely inside img.
int ImageValidRect(Image img, int x, int y, int w, int h)
{ ///
  assert(img != NULL);
  // x é posicao inical
  // y é a posicao inicial
  // w é a largura
  // h é a altura
  // Insert your code here!
  return ImageValidPos(img, x, y) && ImageValidPos(img, x + w - 1, y + h - 1);
}

/// Pixel get & set operations

/// These are the primitive operations to access and modify a single pixel
/// in the image.
/// These are very simple, but fundamental operations, which may be used to
/// implement more complex operations.

// Transform (x, y) coords into linear pixel index.
// This internal function is used in ImageGetPixel / ImageSetPixel.
// The returned index must satisfy (0 <= index < img->width*img->height)
// TODO CHECK
static inline int G(Image img, int x, int y)
{
  int index = y * img->width + x;
  // Insert your code here!
  assert(0 <= index && index < img->width * img->height);
  return index;
}

/// Get the pixel (level) at position (x,y).
uint8 ImageGetPixel(Image img, int x, int y)
{ ///
  assert(img != NULL);
  assert(ImageValidPos(img, x, y));
  PIXMEM += 1; // count one pixel access (read)
  return img->pixel[G(img, x, y)];
}

/// Set the pixel at position (x,y) to new level.
void ImageSetPixel(Image img, int x, int y, uint8 level)
{ ///
  assert(img != NULL);
  assert(ImageValidPos(img, x, y));
  PIXMEM += 1; // count one pixel access (store)
  img->pixel[G(img, x, y)] = level;
}

/// Pixel transformations

/// These functions modify the pixel levels in an image, but do not change
/// pixel positions or image geometry in any way.
/// All of these functions modify the image in-place: no allocation involved.
/// They never fail.

/// Transform image to negative image.
/// This transforms dark pixels to light pixels and vice-versa,
/// resulting in a "photographic negative" effect.
// TODO CHECK
void ImageNegative(Image img)
{ ///
  assert(img != NULL);
  // Insert your code here!

  int arrayfinal = img->height * img->width;

  for (int i = 0; i < arrayfinal; i++)
  {
    uint8 pixel = img->pixel[i];
    img->pixel[i] = 255 - pixel;
  }
}

/// Apply threshold to image.
/// Transform all pixels with level<thr to black (0) and
/// all pixels with level>=thr to white (maxval).
// TODO CHECK
void ImageThreshold(Image img, uint8 thr)
{ ///
  assert(img != NULL);
  // Insert your code here!
  int arrayfinal = img->height * img->width;

  for (int i = 0; i < arrayfinal; i++)
  {
    uint8 pixel = img->pixel[i];
    if (pixel < thr)
    {
      img->pixel[i] = 0;
    }
    else
    {
      img->pixel[i] = 255;
    }
  }
}

/// Brighten image by a factor.
/// Multiply each pixel level by a factor, but saturate at maxval.
/// This will brighten the image if factor>1.0 and
/// darken the image if factor<1.0.
// TODO CHECK

void ImageBrighten(Image img, double factor)
{ ///
  assert(img != NULL);
  // ? assert (factor >= 0.0);
  // Insert your code here!
  int arrayfinal = (img->height) * (img->width);

  // this function is not working

  for (int i = 0; i < arrayfinal; i++)
  {

    double pixeln = (img->pixel[i]) * factor;

    img->pixel[i] = (pixeln > 255) ? 255 : round(pixeln);
  }
}

/// Geometric transformations

/// These functions apply geometric transformations to an image,
/// returning a new image as a result.
///
/// Success and failure are treated as in ImageCreate:
/// On success, a new image is returned.
/// (The caller is responsible for destroying the returned image!)
/// On failure, returns NULL and errno/errCause are set accordingly.

// Implementation hint:
// Call ImageCreate whenever you need a new image!

/// Rotate an image.
/// Returns a rotated version of the image.
/// The rotation is 90 degrees clockwise.
/// Ensures: The original img is not modified.
///
/// On success, a new image is returned.
/// (The caller is responsible for destroying the returned image!)
/// On failure, returns NULL and errno/errCause are set accordingly.
Image ImageRotate(Image img)
{ ///
  assert(img != NULL);
  // Insert your code here!
  return pilinha.rotativa
}

/// Mirror an image = flip left-right.
/// Returns a mirrored version of the image.
/// Ensures: The original img is not modified.
///
/// On success, a new image is returned.
/// (The caller is responsible for destroying the returned image!)
/// On failure, returns NULL and errno/errCause are set accordingly.
Image ImageMirror(Image img)
{ ///
  assert(img != NULL);
  // Insert your code here!
}

/// Crop a rectangular subimage from img.
/// The rectangle is specified by the top left corner coords (x, y) and
/// width w and height h.
/// Requires:
///   The rectangle must be inside the original image.
/// Ensures:
///   The original img is not modified.
///   The returned image has width w and height h.
///
/// On success, a new image is returned.
/// (The caller is responsible for destroying the returned image!)
/// On failure, returns NULL and errno/errCause are set accordingly.
Image ImageCrop(Image img, int x, int y, int w, int h)
{ ///
  assert(img != NULL);
  assert(ImageValidRect(img, x, y, w, h));
  // Insert your code here!
}

/// Operations on two images

/// Paste an image into a larger image.
/// Paste img2 into position (x, y) of img1.
/// This modifies img1 in-place: no allocation involved.
/// Requires: img2 must fit inside img1 at position (x, y).
void ImagePaste(Image img1, int x, int y, Image img2)
{ ///
  assert(img1 != NULL);
  assert(img2 != NULL);
  assert(ImageValidRect(img1, x, y, img2->width, img2->height));
  // Insert your code here!
}

/// Blend an image into a larger image.
/// Blend img2 into position (x, y) of img1.
/// This modifies img1 in-place: no allocation involved.
/// Requires: img2 must fit inside img1 at position (x, y).
/// alpha usually is in [0.0, 1.0], but values outside that interval
/// may provide interesting effects.  Over/underflows should saturate.
void ImageBlend(Image img1, int x, int y, Image img2, double alpha)
{ ///
  assert(img1 != NULL);
  assert(img2 != NULL);
  assert(ImageValidRect(img1, x, y, img2->width, img2->height));
  // Insert your code here!
}

/// Compare an image to a subimage of a larger image.
/// Returns 1 (true) if img2 matches subimage of img1 at pos (x, y).
/// Returns 0, otherwise.
int ImageMatchSubImage(Image img1, int x, int y, Image img2)
{ ///
  assert(img1 != NULL);
  assert(img2 != NULL);
  assert(ImageValidPos(img1, x, y));
  // Insert your code here!
}

/// Locate a subimage inside another image.
/// Searches for img2 inside img1.
/// If a match is found, returns 1 and matching position is set in vars (*px, *py).
/// If no match is found, returns 0 and (*px, *py) are left untouched.
int ImageLocateSubImage(Image img1, int *px, int *py, Image img2)
{ ///
  assert(img1 != NULL);
  assert(img2 != NULL);
  // Insert your code here!
}

/// Filtering

/// Blur an image by a applying a (2dx+1)x(2dy+1) mean filter.
/// Each pixel is substituted by the mean of the pixels in the rectangle
/// [x-dx, x+dx]x[y-dy, y+dy].
/// The image is changed in-place.
void ImageBlur(Image img, int dx, int dy)
{ ///
  // Insert your code here!
}

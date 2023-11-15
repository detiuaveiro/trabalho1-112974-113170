void ImageBlur(Image img, int dx, int dy)
{
    assert(img != NULL);
    int w = img->width;
    int h = img->height;

    // Create a temporary image to store blurred values
    Image tempImg = ImageCreate(w, h, img->maxval);
    InstrName[0] = "adds";
    InstrName[1] = "divisions";
    InstrCalibrate(); // Call once, to measure CTU
    InstrReset();     // reset to zero
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            double mean = 0;
            int count = 0;

            for (int k = i - dx; k <= i + dx; k++)
            {
                for (int l = j - dy; l <= j + dy; l++)
                {
                    if (ImageValidPos(img, k, l))
                    {
                        mean += img->pixel[G(img, k, l)];
                        count++;
                        InstrCount[0] += 2;
                    }
                }
            }

            if (count > 0)
            {

                InstrCount[1] += 1;
                mean /= count;
                tempImg->pixel[G(tempImg, i, j)] = myRound(mean);
            }
        }
    }

    // Copy values back to the original image
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            img->pixel[G(img, i, j)] = tempImg->pixel[G(tempImg, i, j)];
        }
    }
    InstrPrint();
    // Destroy the temporary image
    ImageDestroy(&tempImg);
}

/// FIRST IMPLEMENTATION
void ImageBlur(Image img, int dx, int dy)
{ ///
    // Insert your code here!
    assert(img != NULL);
    int w = img->width;
    int h = img->height;
    // i want to use sumtable
    Image img2 = ImageCreate(w, h, img->maxval);
    // FINALMENTE ENTENDI O QUE SER BLUR
    /// https://datacarpentry.org/image-processing/06-blurring.html
    // i love matrixes
    /// https://www.pixelstech.net/article/1353768112-Gaussian-Blur-Algorithm
    InstrName[0] = "adds";
    InstrName[1] = "divisions";
    InstrCalibrate(); // Call once, to measure CTU
    InstrReset();     // reset to zero
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {

            // uint8 pixel = ImageGetPixel(img, i, j);
            double mean = 0;
            int count = 0;

            for (int k = i - dx; k <= i + dx; k++)
            {

                for (int l = j - dy; l <= j + dy; l++)
                {
                    if (ImageValidPos(img, k, l))
                    {

                        mean += ImageGetPixel(img, k, l);
                        count++;
                        InstrCount[0] += 2;
                    }
                }
            }
            mean /= (count);
            InstrCount[1] += 1;

            mean = myRound(mean);
            ImageSetPixel(img2, i, j, mean);
        }
    }
    InstrPrint();

    ImagePaste(img, 0, 0, img2);
    ImageDestroy(&img2);
}

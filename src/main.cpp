#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include	<stdlib.h>

#include "utils.h"

int main()
{
  char *outText;

  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
  if (api->Init(NULL, "fra")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
  }

  Pix *image = pixRead("/home/server/Lab/tesseract/ressources/hired.png");
  api->SetImage(image);

  outText = api->GetUTF8Text();
  printf("OCR output:\n%s", outText);
  printf("Most Used Letter: %c \n", getMostUsedLetter(outText) );

  api->End();
  delete [] outText;
  pixDestroy(&image);

  return 0;

}

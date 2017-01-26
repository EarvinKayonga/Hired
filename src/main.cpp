#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

#include "utils.h"

/*#include  <stdio.h>
int     main(){
  char *outText;
  outText = "Rky skorrkaxky uvvuxzatozky bokttktz g buay yax Noxkj";
  printf("OCR output:\n%s\n", outText);
  printf("Most Used Letter: %c \n", getMostUsedLetter(outText) );
  printf("Traduction: %s \n ", translate(outText) );
}*/

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



  api->End();
  delete [] outText;
  pixDestroy(&image);

  return (0);
}

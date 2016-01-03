#ifndef ASSETS_H
#define ASSETS_H

typedef struct _bmp
{
  unsigned char header[54];
  unsigned int width;
  unsigned int height;
  unsigned int imgsize; // w*h*3
  unsigned char* data; // RGB
} Bitmap;

Bitmap* LoadBMP24(char* filename)
{
  Bitmap* bitmap = (Bitmap*)malloc(sizeof(Bitmap));
  FILE* fp = fopen(filename, "rb");

  if (fread(bitmap->header, 1, 54, fp)!=54)
  {
    printf("Not a 24-bit bitmap.");
  }

  int datapos = 54; // Size of header
  bitmap->width = *(int*)&(bitmap->header[0x12]); // Width offset
  bitmap->height = *(int*)&(bitmap->header[0x16]); // Height offset
  bitmap->imgsize = bitmap->width * bitmap->height * 3;
  bitmap->data = malloc(bitmap->imgsize);
  fread(bitmap->data, 1, bitmap->imgsize, fp);
  fclose(fp);

  return bitmap;
}

GLuint LoadBMP24Tex(char* filename)
{
    Bitmap* bmp =LoadBMP24(filename);

    GLuint texid;
    glGenTextures(1, &texid);
    glBindTexture(GL_TEXTURE_2D, texid);

    // Swap BGR to RGBA
    unsigned char* bmpdat = malloc(bmp->width*bmp->height*4);
    for (int i = 0; i < bmp->width*bmp->height; i++)
    {
	  unsigned char b[4];
	  memcpy(&b, &bmp->data[i*3], 3);
	  
	  /* Replace first and last */
	  unsigned char c = b[2];
	  b[2] = b[0];
	  b[0] = c;
	  
	  /* Magic color 0xFFFFFF sets alpha to transparent */
	  if (b[0] == 0xFF && b[1] == 0xFF && b[2] == 0xFF)
	  {
		  b[3] = 0;
	  } else b[3] = 0xFF;
	  
	  
	  memcpy(&bmpdat[i*4], &b, 4);
	  
    }

    glColor3f(1, 1, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bmp->width, bmp->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bmpdat);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	free(bmpdat);
    free(bmp->data);
    free(bmp);

    return texid;
}
#endif
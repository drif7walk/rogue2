#ifndef ENGINE_H
#define ENGINE_H

GLuint texture;

void Initialize()
{
	texture= LoadBMP24Tex( "assets/smth.bmp" );
	
}
void Update()
{

}

void Draw()
{
	Update();
static GLfloat red[] =
  {0.8, 0.0, 0.0, 1.0};
  static GLfloat yellow[] =
  {0.8, 0.8, 0.0, 1.0};
  static GLfloat green[] =
  {0.0, 0.8, 0.0, 1.0};

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();

/*
  glPushMatrix();
  glTranslatef(-0.75, 0.5, 0.0);
  glRotatef(90.0, 1.0, 0.0, 0.0);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
  glutSolidTorus(0.275, 0.85, 10, 15);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-0.75, -0.5, 0.0);
  glRotatef(270.0, 1.0, 0.0, 0.0);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yellow);
  glutSolidCone(1.0, 1.0, 40, 40);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.75, 0.0, -1.0);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, green);
  glutSolidIcosahedron();
  glPopMatrix();
*/
  /* Draw character */
  float vertices[] = {
	//  Position      Color                Texcoords
		 -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
		 0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
		 0.5f,  -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
		 -0.5f,  -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom-left
	};
  glRotatef(0, 1, 0, 0.45f);
  glTranslatef(0, -1.7, 0);
  
  glBindTexture(GL_TEXTURE_2D, texture);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 8*sizeof(float), vertices);
  glTexCoordPointer(2, GL_FLOAT, 8*sizeof(float), vertices);
  glDrawArrays(GL_QUADS, 0, 4);
  glDisableClientState(GL_VERTEX_ARRAY);
  /*
  
  glBegin(GL_QUADS);
  glVertex3f(0, 0, 0);
  glVertex3f(0, 1, 0);
  glVertex3f(1, 1, 0);
  glVertex3f(1, 0, 0);
  glEnd();
  */
  
  
  glPopMatrix();
}

#endif
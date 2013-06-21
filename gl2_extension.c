#include "gl2_extension.h"

static const int MATRIX_WIDTH = 4;
static const int MATRIX_HEIGHT = 4;

static GLfloat *currentMatrix;

glOrthof(const GLfloat left, const GLfloat right,const GLfloat bottom,const GLfloat top,const GLfloat near,const GLfloat far){
  // LOGD("In glOrtho");
  float a = 2.0f / (right - left);
  float b = 2.0f / (top - bottom);
  float c = -2.0f / (far - near);

  float tx = - (right + left)/(right - left);
  float ty = - (top + bottom)/(top - bottom);
  float tz = - (far + near)/(far - near);

  float ortho[16] = {
     a, 0, 0, 0,
     0, b, 0, 0,
     0, 0, c, 0,
     tx, ty, tz, 1
  };
  multiplyMatrix(currentMatrix, ortho, currentMatrix, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH);
}

glSetMatrix(GLfloat *m){
  *currentMatrix = *m;
}

glMultMatrixf(const float *m){
  multiplyMatrix(currentMatrix, m, currentMatrix, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH);
}

multiplyMatrix(float *a, float *b, float *out, int width_a, int height, int width_b){
 printf("Multiplying Matrixes height: %d width_a: %d Width b %d\n", height, width_a, width_b);
 int i, i2, i3;
 float result[16]={0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
 for(i=0; i < height; i++){
   float dotProduct = 0.0f;
   for(i2=0; i2 < width_a; i2++){
     float dotProduct = 0.0f;
     for(i3=0;i3 < width_b; i3++){
       printf("Multiplying... currentLoc %d New M Loc %d | %f * %f", i3+i*4, i3*4+i2, a[i3+i*4],b[i3*4+i2]);
       dotProduct+=a[i3+i*4]*b[i3*4+i2];
       printf(" Dot Product = %f \n", dotProduct);
     }
     result[i2+i*4]=dotProduct;
   }
 }
 int i4;
 for(i4=0;i4<4*width_b; i4++){
   out[i4]=result[i4];
 }
}

glEnableClientState (GLenum array){
}

glDisableClientState (GLenum array){
}

glTranslatef (GLfloat x, GLfloat y, GLfloat z){
  float val[16] =
  { 1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    x,y,z,1};
  multiplyMatrix(currentMatrix, val, currentMatrix, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH);
}

glScalef (GLfloat x, GLfloat y, GLfloat z){
  float val[16] =
  { x,0,0,0,
    0,y,0,0,
    0,0,z,0,
    0,0,0,1};
  multiplyMatrix(currentMatrix, val, currentMatrix, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH);
}
glNormal3f (GLfloat nx, GLfloat ny, GLfloat nz){
}
glVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer){
}
glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer){
}
glNormalPointer (GLenum type, GLsizei stride, const GLvoid *pointer){}

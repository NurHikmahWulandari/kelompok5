#if defined(_WIN32) || defined(__MINGW32__)
#include <windows.h>
#endif
#include <GL/glut.h>
#include <GL/glut.h>

    //inisialisai 3d
    void initRendering() {
     glEnable(GL_DEPTH_TEST); //sudut pandang
     glEnable(GL_COLOR_MATERIAL); 
     glEnable(GL_LIGHTING); //ighting
     glEnable(GL_LIGHT0); //Enable light
     glEnable(GL_LIGHT1); //Enable light
     glEnable(GL_NORMALIZE); //Automatically normalize normals
     glShadeModel(GL_SMOOTH); //smooth shading
     glClearColor(1.0,1.0,1.0,1.0);       //bg color
    }

 void handleResize(int w, int h) {
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(50.0, (double)w / (double)h, 1.0, 200.0);
    }
    float _angle = -50.0f;

void tabung() {
    static int slices = 16;
    static int stacks = 24;
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glColor3d(0,0,0);
    glPushMatrix();
    glTranslated(0,-0.05,0.4);
    glutSolidTorus(0.2,0.7,slices,stacks);
    glPopMatrix();
}

void display(){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glTranslatef(0.0f, 0.0f, -14.0f);  //merubah titik tengah sumbu kordinat
     //Add ambient light
     GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
     glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
     //Add positioned light
     GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};
     GLfloat lightPos0[] = {0.0f, -8.0f, 8.0f, 1.0f};
     glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
     glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
     //Add directed light
     GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
     //Coming from the direction (-1, 0.5, 0.5)
     GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
     glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
     glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
     glRotatef(0, 0.0f, 0.0f, 0.0f);
     glRotatef(0, 0.0f, 0.0f, 1.0f);
     glRotatef(_angle,0.0f, 1.0f, 0.0f);

     glColor3f(1.1f, 1.1f, 1.1f);
     glBegin(GL_QUADS);
     // atas
      glColor3f(0.343f, 0.339f, 0.329f);
      glVertex3f( -2.0f, 1.0f, 0.3f); // a
      glVertex3f(-2.0f, 1.0f, -0.3f); // b
      glVertex3f(2.0f, 1.0f,  -0.3f); // c
      glVertex3f( 2.0f, 1.0f,  0.3f); // d

      // bawah
      glColor3f(0.343f, 0.339f, 0.329f);
      glVertex3f( 2.0f, -1.0f,  -0.3f); // e
      glVertex3f(2.0, -1.0f,  0.3f); // f
      glVertex3f(-2.0f, -1.0f, -0.3f); // g
      glVertex3f(-2.0f, -1.0f, 0.3f); // h

      // kiri(lensa)
      glColor3f(0.343f, 0.339f, 0.329f);
      glVertex3f( -2.0f, 1.0f, 0.3f); // a
      glVertex3f(-2.0f, 1.0f, -0.3f); // b
      glVertex3f(-2.0f, -1.0f, -0.3f); // g
      glVertex3f(-2.0f, -1.0f, 0.3f); // h


      // kanan(lensa)
      glColor3f(0.343f, 0.339f, 0.329f);
      glVertex3f(2.0f, 1.0f,  -0.3f); // c
      glVertex3f( 2.0f, 1.0f,  0.3f); // d
      glVertex3f(2.0, -1.0f,  0.3f); // f
      glVertex3f( 2.0f, -1.0f,  -0.3f); // e

      // depan (lensa)
      glColor3f(0.343f, 0.339f, 0.329f);
      glVertex3f( -2.0f, 1.0f, 0.3f); // a
      glVertex3f( 2.0f, 1.0f,  0.3f); // d
      glVertex3f(2.0, -1.0f,  0.3f); // f
      glVertex3f(-2.0f, -1.0f, 0.3f); // h

      // belakang(layar)
      glColor3f(0.343f, 0.339f, 0.329f);
      glVertex3f(-2.0f, 1.0f, -0.3f); // b
      glVertex3f(2.0f, 1.0f,  -0.3f); // c
      glVertex3f( 2.0f, -1.0f,  -0.3f); // e
      glVertex3f(-2.0f, -1.0f, -0.3f); // g
    
    
      tabung();
      glutSwapBuffers();
    }

int main(int argc, char** argv) {
     //Initialize GLUT
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowSize(600, 600);
     //Create the window
     glutCreateWindow("Lighting");
     initRendering();
     //Set handler functions
     glutDisplayFunc(drawScene);
     glutReshapeFunc(handleResize);
     update(0);
     glutMainLoop();
     return 0;
    }

#include <windows.h>
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

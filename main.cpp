#include <windows.h>    //#include = prpcessor detective    <windows.h> = file header nya windows utk deklarasi fungsi windows API
#include <GL/glut.h>    //<GL/glut.h> = deklarasi GLglut


void garis(){
    glClear(GL_COLOR_BUFFER_BIT);           //bersihkan semua pixel di buffer (bersih layar)

    glLineWidth(7.1);                  //tebal garis

    glBegin(GL_LINES);                 //garis mulai
        glColor3f(0.3,0.3,0.9);        //Warna garis
        glVertex3f(0.1,0.9,0.0);       //Koordinat 1
        glVertex3f(0.9,0.1,0.0);       //Koordinat 2
    glEnd();                           //garis selesai

    glFlush();              //memulai proses gambar (garis)
}


/*
void titik(){
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(6.0);

    glBegin(GL_POINTS);
        glColor3f(0.4,0.3,2.0);       //biru 1
        glVertex3f(0.2,0.8,0.0);

        glColor3f(0.1,0.7,1.0);       //biru 2
        glVertex3f(0.5,0.8,0.0);

        glColor3f(0.1,0.5,0.9);       //biru 3
        glVertex3f(0.8,0.8,0.0);

        glColor3f(0.9,0.2,0.8);       //pink 1
        glVertex3f(0.35,0.5,0.0);

        glColor3f(1.0,0.6,0.7);       //pink 2
        glVertex3f(0.65,0.5,0.0);

        glColor3f(0.6,1.0,0.2);       //ijo
        glVertex3f(0.5,0.2,0.0);
    glEnd();

    glFlush();
}
*/

/*
void segi4(){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
        glColor3f(0.8,0.6,1.0);
        glVertex2f(0.25,0.25);
        glVertex2f(0.75,0.25);
        glVertex2f(0.75,0.75);
        glVertex2f(0.25,0.75);
    glEnd();

    glLineWidth(5.5);
    glBegin(GL_LINES);
        glColor3f(0.4,0.7,0.8);
        glVertex2f(0.25,0.25);
        glVertex2f(0.75,0.25);

        glColor3f(0.9,0.8,0.0);
        glVertex2f(0.75,0.25);
        glVertex2f(0.75,0.75);

        glColor3f(1.0,1.0,1.0);
        glVertex2f(0.75,0.75);
        glVertex2f(0.25,0.75);

        glColor3f(0.3,0.8,0.5);
        glVertex2f(0.25,0.75);
        glVertex2f(0.25,0.25);
    glEnd();

    glFlush();
}
*/

void Init(){
    glClearColor(0.0,0.0,0.0,0.0);       //bersih warna bg
    glMatrixMode(GL_PROJECTION);         //inisialisasi nilai tampilan (viewing values)
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}

int main(int Argc, char** Argv){
    glutInit(&Argc, Argv);
    glutInitWindowSize(600,400);                   //window size
    glutInitWindowPosition(200,100);               //window position
    glutCreateWindow("Nur Hikmah Wulandari_Tugas 1");                   //judul windownya
    Init();                                         //memanggil void init
    glutDisplayFunc(garis);                         //memanggil fungsi (void) utk tampil dilayar
    glutMainLoop();
    return 0;
}

 // layar tv



 // tabung tv



 //tabung camera


 //kaca kamera

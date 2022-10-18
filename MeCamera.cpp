#include "MeCamera.h"
#include <iostream>
using namespace std;
int main(){
    MeCamera MeCamera;
    return 0;
}

// last updated: 28-05-2007
// simple camera module for rainyrhythm
#ifndef MECAMERA_H
#define MECAMERA_H

enum MeCameraMove { front, back, left, right, up, down };

class MeCamera {
    // tries not to create vector class...
    public:

        MeCamera( float px=0.0f, float py=0.0f, float pz=0.0f );
        ~MeCamera();

        // ----- functions ---------------
        // takes in the new mouse position, then rotate as necessary
        void mouseNewPos(int mx, int my);
        // key movement
        void moveKeyPress( MeCameraMove d );
        void moveKeyRelease( MeCameraMove d );
        // for camera movement to take effect.
        void tick();
        //void drawVector(); // camera vector debug

        // ----- variables ---------------
        // postition
        float px, py, pz;
        // look point
        float lx, ly, lz;
        // up vector
        float ux, uy, uz;
    private:
        void rotate( float rz, float rx ); // rotate by alpha radians
        void recalc(); // recalculate angles.
        void update(); // update look point
        // window mouse postition
        int mousex, mousey;
        // angle rotation by axis
        float rotatez, rotatex;
        // moving direction
        int walk;
        // velocity
        float vx, vy, vz;
        // look vector
        float lookx, looky, lookz;
};

#define MECAMERA_FRONT 0x00000001
#define MECAMERA_BACK  0x00000010
#define MECAMERA_LEFT  0x00000100
#define MECAMERA_RIGHT 0x00001000
#define MECAMERA_UP    0x00010000
#define MECAMERA_DOWN  0x00100000

#endif




// last updated: 28-05-2007
// simple camera module for rainyrhythm.
#include "MeCamera.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//#include <GL/glut.h>

//#ifdef trace
//#undef trace
//#endif
//#define trace(q) std::cout << "MeCamera.cpp[" << __LINE__ << "]: " << q << '\n'
//#ifndef tracecmd
//#define tracecmd(q) trace( #q << "=" << q )
//#endif
//#ifndef tracevar
//#define tracevar(q) trace( #q << '(' << &q << ")=" << q )
//#endif

MeCamera::MeCamera( float ipx, float ipy, float ipz )
    : px(ipx), py(ipy), pz(ipz), vx(0.0), vy(0.0), vz(0.0),
      mousex(0), mousey(0), rotatez(0), rotatex(0), walk(0) {
    recalc();
}

MeCamera::~MeCamera() {}


void MeCamera::mouseNewPos( int mx, int my ) {
    const int mouserange = 50;
    const float rotateratio = 0.005f;
    // see it's changes too much, if it is, then reject
    if ( abs(mx-mousex) < mouserange && abs(my-mousey) < mouserange ) {
        // mouse movement sensitivity
        // get delta
        float dx = ((float)mx-(float)mousex)*rotateratio;
        float dy = ((float)my-(float)mousey)*rotateratio;
        // go rotate
        rotate(dx, -dy);
    }
    // save mouse postition
    mousex = mx; mousey = my;

}

void MeCamera::rotate( float rz, float rx) {
    const float pi = 3.14159265f;
    // add them
    rotatez  = rz; rotatex  = rx;

    // for z-axis rotation change to zero if over 1 loop
    if ( -(2*pi) > rotatez )
        rotatez  = 2*pi;
    if ( (2*pi) < rotatez )
        rotatez -= 2*pi;
    // for x-axis rotation
    if ( rotatex < -(pi/2) )
        rotatex = -(pi/2);
    if ( rotatex > (pi/2) )
        rotatex = (pi/2);

    recalc();
}

void MeCamera::recalc() {
    // get look vector
    looky = sin(rotatex);
    lookx = cos(rotatez) * (1-fabs(looky));
    lookz = sin(rotatez) * (1-fabs(looky));

    // up vector
    uy = cos(rotatex);
    ux = -cos(rotatez) * (1-fabs(uy));
    uz = -sin(rotatez) * (1-fabs(uy));

    update();
}

void MeCamera::moveKeyPress( MeCameraMove d ) {
    switch (d) {
        case front:  walk |= MECAMERA_FRONT; break;
        case back:   walk |= MECAMERA_BACK; break;

    }
    //tracevar(walk);
}

void MeCamera::moveKeyRelease( MeCameraMove d ) {
    switch (d) {
        case front:  walk &= ~(MECAMERA_FRONT); break;
        case back:   walk &= ~(MECAMERA_BACK); break;

    }
    //tracevar(walk);
}

void MeCamera::update() {
    // look point
    lx = px;   lookx;
    ly = py;  looky;
    lz = pz;   lookz;
}

void MeCamera::tick() {
    // camera position movement
    const float accel = 0.01f;
    const float maxvelocity = 0.1f;
    const float damp = 100.0f;

    // right angle is actually front angle minus 90 degrees
    float rotater = rotatez - 1.57;
    float rightx = cos(rotater);
    float rightz = sin(rotater);

    // see if pressed then add velocity to it.
    // front
    if ( (walk & MECAMERA_BACK)  ) {
        vz -= accel;
        if ( vz < -maxvelocity )
            vz = -maxvelocity;
    }
    // back
    if ( (walk & MECAMERA_FRONT) ) {
        vz  = accel;
        if ( vz > maxvelocity )
            vz = maxvelocity;
    }
    // left


    // move according to velocity and look vector
    // vz
    px  = lookx * vz;
    py  = looky * vz;
    pz  = lookz * vz;
    // vy
    py  = uy * vy;
    // vx;
    px  = rightx * vx;
    pz  = rightz * vx;

    // damp vector
    vx -= vx / damp; vy -= vy / damp; vz -= vz / damp;

    // update look point
    update();
}

/*
void MeCamera::drawVector() {
    glLineWidth(2);
    glBegin(GL_LINES);
    // looking direction
    glColor3ub(0,0,255);
    glVertex3f(0,0,0);
    glVertex3f(lookx, looky, lookz);
    // right direction
    glColor3ub(255,0,0);
    glVertex3f(0,0,0);
    glVertex3f(rightx, righty, rightz);
    // up vector
    glColor3ub(0,255,0);
    glVertex3f(0,0,0);
    glVertex3f(ux, uy, uz);
    glEnd();
    glLineWidth(1);

}
*/

//puauu

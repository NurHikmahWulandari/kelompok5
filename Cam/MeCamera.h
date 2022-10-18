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

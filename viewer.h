#ifndef VIEWER_H
#define VIEWER_H

#include "ei_types.h"
#include "hw_interface.h"
#include "rectangle.h"

class Viewer
{
public:
    //! Constructor
    Viewer(ei_size_t size);
    virtual ~Viewer();

    void display(ei_surface_t surface) const;
    void updateScene();
    void reshape(int w, int h);

    // events
    void mousePressed(int button, int action);
    void mouseMoved(int x, int y);
    void keyPressed(int key);

private:
    ei_size_t _size;
    float _scalingFactor;
    bool _growing;
    ei_color_t _red;
    Rectangle* _rectangle;
};

#endif

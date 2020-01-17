#include "viewer.h"

#include "ei_draw.h"
#include "ei_event.h"

#include <string>
#include <iostream>

using namespace std;

Viewer::Viewer(ei_size_t size):
    _size(size),
    _scalingFactor(0.5),
    _growing(true),
    _rectangle(0){
    _rectangle = new Rectangle();
    _red.red = 255;
    _red.green = 0;
    _red.blue = 0;
    _red.alpha = 255;
}

Viewer::~Viewer(){
    delete _rectangle;
}

void Viewer::display(ei_surface_t surface) const{
    ei_size_t tmp = _rectangle->get_size();
    ei_surface_t r = hw_surface_create(surface, &tmp);
    hw_surface_lock(r);
    _rectangle->draw(surface);
    hw_surface_unlock(r);
    hw_surface_free(r);
}

void Viewer::updateScene() 
{
    if(_growing){
        _scalingFactor += 0.005;
        _growing = _scalingFactor < 0.7; // grow square until _halfSize >= 0.8
    } else {
        _scalingFactor -= 0.005;
        _growing = _scalingFactor < 0.4; // grow square until _halfSize <= 0.3
    }
    // update rectangle size and position
    Point const point((_size.width - _rectangle->get_size().width) / 2.f, (_size.height - _rectangle->get_size().height) / 2.f);
    _rectangle->set_size({_scalingFactor * _size.width, _scalingFactor * _size.height});    //warning set_size(float)
    _rectangle->setPosition(point);
}


////////////////////////////////////////////////////////////////////////////////
// Events

/*!
   callback to manage mouse : called when the user presses (action==0) or releases (action==0) a mouse button
 */
void Viewer::mousePressed(int button, int action){
    if(action){
        
    }
}


/*!
   callback to manage mouse : called when the user moves the mouse
 */
void Viewer::mouseMoved(int x, int y){

}


/*!
   callback to manage keyboard interactions
 */
void Viewer::keyPressed(int key){

}

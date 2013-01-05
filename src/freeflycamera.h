#ifndef FREEFLYCAMERA_H
#define FREEFLYCAMERA_H

#include "vector3d.h"
#include "etage.h"
#include <SDL/SDL.h>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class FreeFlyCamera
{
public:
    typedef std::map<std::string,SDLKey> KeyConf;
    KeyConf _keyconf;


    FreeFlyCamera(const Vector3D & position = Vector3D(0,0,0));

    virtual void OnMouseMotion(const SDL_MouseMotionEvent & event);
    virtual void OnMouseButton(const SDL_MouseButtonEvent & event);
    virtual void OnKeyboard(const SDL_KeyboardEvent & event);

    virtual void animate(Uint32 timestep);
    virtual void setSpeed(double speed);
    virtual void setSensivity(double sensivity);

    virtual void setPosition(const Vector3D & position);

    virtual void look();

    virtual ~FreeFlyCamera();

	const Vector3D& getTarget() const {
		return _target;
	}

	void setTarget(const Vector3D& target) {
		_target = target;
	}

	Etage* getCurrentStare() const {
		return _currentStare;
	}

	void setCurrentStare(Etage* currentStare) {
		_currentStare = currentStare;
	}

	void setCollisionTab(bool* tab) {
		_collisionTab = tab;
	}

	const Vector3D& getForward() const {
		return _forward;
	}

	const Vector3D& getPosition() const {
		return _position;
	}

	const Vector3D& getLeft() const {
		return _left;
	}

    // const KeyConf& getKeyconf() const {
    //     return _keyconf;
    // }
    double _speed;
    double _sensivity;

protected:
    

    bool* _collisionTab;

    //vertical motion stuffs
    Uint32 _timeBeforeStoppingVerticalMotion;
    bool _verticalMotionActive;
    int _verticalMotionDirection;

    typedef std::map<SDLKey,bool> KeyStates;
    KeyStates _keystates;
    // typedef std::map<std::string,SDLKey> KeyConf;
    

    Vector3D _position;
    Vector3D _target;
    Vector3D _forward;
    Vector3D _left;
    double _theta;
    double _phi;

    Etage* _currentStare;

    void VectorsFromAngles();
    //void Init();
};

#endif //FREEFLYCAMERA_H

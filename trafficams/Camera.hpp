#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Headers.hpp"

class Camera
{
	bool	 _on = true;
	int		_queue = 0;
	int		_countdown = 0; //time countdown to turn green.
public:
	Camera(){};
	~Camera(){};

	void	toggle(){_on = !_on;};
	cam.toggle();
	bool	show(){return _on;};
};

#endif

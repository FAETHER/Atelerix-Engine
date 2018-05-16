/*
 * 
 * Atelerix Engine Entry Point
 *
 * main.cpp
 *
 * Created May 1st 2018
 *
 * This program is licensed under GNU GPLv3:
 *
 * This program is free/libre software. You may do what you
 * wish with this program as defined by the Free Software
 * Foundation. Check the license page for details.
 *
 * GPLv3: https://github.com/TeamAtelerix/Atelerix-Engine/blob/master/LICENSE
 *
 */

#ifndef GL_SRGB8_ALPHA8
#define GL_SRGB8_ALPHA8 0x8C43
#endif

//#include <GL/glew.h> 
//This should always load first! //not sure if this is needed because we use sfml for window creation. and not opgl
//DESC The OpenGL Extension Wrangler Library (GLEW) is a cross-platform open-source C/C++ extension loading library. 
//GLEW provides efficient run-time mechanisms for determining which OpenGL extensions are supported on the target platform. 
//OpenGL core and extension functionality is exposed in a single header file. GLEW has been tested on a variety of operating systems, including Windows, Linux, Mac OS X, FreeBSD, Irix, and Solaris. 

//#include <GL/wglew.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "../include/Atix.h"

//GLM-----------------------------------------------------------------------------------------------------------------
//#include <glm/vec3.hpp> // glm::vec3
//#include <glm/vec4.hpp> // glm::vec4
//#include <glm/mat4x4.hpp> // glm::mat4
//#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
//#include <glm/gtc/constants.hpp> // glm::pi


// Those are standard minGW libs, available if required. I think they are already in #include <SFML/OpenGL.hpp> thou. 
//#include <GL/glu.h> 
//#include <GL/glext.h> 
//#include <GL/gl.h> 


// void Driver_Check()
// {
// if (wglewIsSupported("WGL_ARB_pbuffer"))
// {
  // /* OK, we can use pbuffers. */
  // std::cout << "OK, we can use pbuffers" << std::endl;
// }
// else
// {
  // /* Sorry, pbuffers will not work on this platform. */
  // std::cout << "Sorry, pbuffers will not work on this platform." << std::endl;
// }	
// }


int main(void)
{
	Atix obj;
	std::cout << "JAVIER KYRIL BRAVE GUYS" << std::endl;
    std::cin.get();
	
	obj.CUBE();


	return 0;
}











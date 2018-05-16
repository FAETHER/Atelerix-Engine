/*
 * 
 * Atelerix Engine Master Class Source File
 *
 * Atix.cpp
 *
 * Created May 2nd 2018
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


#include "../include/Atix.h"
#include "../include/Primitives.h"

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>

Atix::Atix()
{
    std::cout << "Atelerix: Default constructor callback" << std::endl;
}

Atix::~Atix()
{
    std::cout << "Atelerix: Default destructor callback" << std::endl;
}

int Atix::CUBE()
{
    std::cout << "Atelerix: CUBE constructor callback" << std::endl;
	
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;
	sf::RenderWindow window(sf::VideoMode(800, 600), "ATELERIX", sf::Style::Default, contextSettings);	
	
	//window.clear(sf::Color(0, 200, 64, 0));	//tried to set background - no work on update turns back to black!
	
	sf::Texture texture;
	if (!texture.create(200, 200))
	{
		std::cout << "CUBE: Da hek are you doing here? I did not set you texture anyway, idiot." << std::endl;
	}
	sf::Sprite cub(texture);
	cub.setColor(sf::Color(0, 255, 0)); //greeeeeeeeeeeeeeeeeeeeeeeeen sprite
	
	// Enable Z-buffer read and write
        glEnable(GL_DEPTH_TEST);
        glDepthMask(GL_TRUE);
        glClearDepth(1.f);

        // Disable lighting
        glDisable(GL_LIGHTING);

        // Configure the viewport (the same size as the window)
        glViewport(0, 0, window.getSize().x, window.getSize().y);

        // Setup a perspective projection
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
        glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

        // Bind the texture
        //glEnable(GL_TEXTURE_2D);
        //sf::Texture::bind(&texture);
		
		// Enable position and texture coordinates vertex components
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), cube);
        glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), cube + 3);

        // Disable normal and color vertex components
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);

        // Create a clock for measuring the time elapsed
        sf::Clock clock;

        // Flag to track whether mipmapping is currently enabled
        bool mipmapEnabled = true;
	
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
			// Escape key: exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                window.close();
				break;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                window.close();
            }

                // Adjust the viewport when the window is resized
            if (event.type == sf::Event::Resized)
            {
                // Make the window the active window for OpenGL calls
                window.setActive(true);

                glViewport(0, 0, event.size.width, event.size.height);

                // Make the window no longer the active window for OpenGL calls
                window.setActive(false);
            }			
        }
            // Draw the background
            window.pushGLStates();
            window.draw(cub);
            window.popGLStates();

            // Clear the depth buffer
            glClear(GL_DEPTH_BUFFER_BIT);

            // We get the position of the mouse cursor, so that we can move the box accordingly
            float x =  sf::Mouse::getPosition(window).x * 200.f / window.getSize().x - 100.f;
            float y = -sf::Mouse::getPosition(window).y * 200.f / window.getSize().y + 100.f;

            // Apply some transformations
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(x, y, -100.f);
            glRotatef(clock.getElapsedTime().asSeconds() * 50.f, 1.f, 0.f, 0.f);
            glRotatef(clock.getElapsedTime().asSeconds() * 30.f, 0.f, 1.f, 0.f);
            glRotatef(clock.getElapsedTime().asSeconds() * 90.f, 0.f, 0.f, 1.f);

            // Draw the cube
            glDrawArrays(GL_TRIANGLES, 0, 36);

            // Draw some text on top of our OpenGL object
            //window.pushGLStates();
            //window.draw(text);
            //window.draw(sRgbInstructions);
            //window.draw(mipmapInstructions);
            window.popGLStates();

            // Finally, display the rendered frame on screen
            window.display();
			window.clear(sf::Color(0, 200, 64, 0));
    }
	
}

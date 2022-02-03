/******************************************************************************
 * 
 * @file	Window.h
 * 
 * @author	Lincoln Scheer
 * @since	02/03/2022
 * 
 * @breif	Window is a Blaze3D utility that provides a high-level
 *		interface for creating and manipulating a cross platform window
 *		that holds an opengl context.
 * 
 *****************************************************************************/

/******************************************************************************
* TODO:		Input callbacks are defined but not implemented in this class
*		because of their direct calling of Camera functions that
*		should be nowhere near this class.
* 
*		Input Event System should be created that the window class's
*		callbacks can dispatch events into
*****************************************************************************/

/******************************************************************************
 * TODO:	Currently Blaze's window creation is based on the GLFW
 *		windowing library. Eventually the hopes of this class are to
 *		natively createWindow windows across all targets.
 *****************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <GLFW/glfw3.h>

// Input Callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

class Window {
public:
	/**
	 * Sets member title variable.
	 * 
	 * \param title
	 */
	Window(const char* title);

	/**
	 * Creates fullscreen window on primary monitor.
	 * 
	 */
	void init();

	/**
	 * Display window if hidden.
	 * 
	 */
	void show();

	/**
	 * Hide window if displayed.
	 * 
	 */
	void hide();

	/**
	 * Returns the inverse of glfwWindowShouldClose() withought having to 
	 * pass the GLFWwindow handle.
	 * 
	 * \return 
	 */
	bool isOpen();
	
	/**
	 * Swaps renderable buffers and polls window for input events.
	 * 
	 */
	void update();

	/**
	 * Frees all GLFW allocations made.
	 * 
	 */
	void terminate();
	
	/**
	 * Return member GLFWwindow handle.
	 * 
	 * \return 
	 */
	GLFWwindow* getWindow();

	/**
	 * Return member GLFWmonitor handle.
	 * 
	 * \return 
	 */
	GLFWmonitor* getMonitor();

	/**
	 * Return member const GLFWvidmode.
	 * 
	 * \return 
	 */
	const GLFWvidmode* getVidMode();

private:
	// Window Title, Used For Win 
	const char* title;

	// GLFW Members
	GLFWmonitor* monitor;
	const GLFWvidmode* mode;
	GLFWwindow* window;

	// GLFW Member Create Functions
	void createMonitor();
	void createMode();
	void createWindow();
	
	
};

#endif // WINDOW_H

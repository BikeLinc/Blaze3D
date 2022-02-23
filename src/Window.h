/******************************************************************************
 *
 * @file	Window.h
 *
 * @author	Lincoln Scheer
 * @since	02/03/2022
 *
 * @breif	GLWindow is a Blaze3D utility that provides a high-level
 *		interface for creating and manipulating a cross platform window
 *		that holds an opengl context.
 *
 *****************************************************************************/

#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <GL/glew.h>
#define GLEW_STATIC
#include <GLFW/glfw3.h>
#include <iostream>

  // Input Callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

class GLWindow {
public:
	/**
	 * Sets member title variable.
	 *
	 * \param title
	 */
	GLWindow(const char* title);

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
	 * Checks if input callbacks need to be called.
	 * 
	 */
	void processInput();

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
	// GLWindow Title, Used For Win 
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

#endif // GLWINDOW_H
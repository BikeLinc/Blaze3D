/******************************************************************************
 *
 * @file	Window.cpp
 *
 * @author	Lincoln Scheer
 * @since	02/03/2022
 *
 * @breif	GLWindow is a Blaze3D utility that provides a high-level
 *		interface for creating and manipulating a cross platform window
 *		that holds an opengl context.
 *
 *****************************************************************************/

#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
        // Mouse Callback
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
        // Scroll Callback
}

GLWindow::GLWindow(const char* title) {
        this->title = title;
        this->monitor = nullptr;
        this->mode = nullptr;
        this->window = nullptr;
}

void GLWindow::init() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        createMonitor();
        createMode();
        createWindow();
        if (GLEW_OK != glewInit()) {
                glfwTerminate();
        }
}

void GLWindow::show() {
        glfwShowWindow(window);
}

bool GLWindow::isOpen() {
        return !glfwWindowShouldClose(window);
}

void GLWindow::hide() {
        glfwHideWindow(window);
}

void GLWindow::processInput() {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, true);
        }
}

void GLWindow::update() {
        glfwSwapBuffers(window);
        glfwPollEvents();
}

void GLWindow::terminate() {
        glfwTerminate();
}

GLFWwindow* GLWindow::getWindow() {
        return this->window;
}

GLFWmonitor* GLWindow::getMonitor() {
        return this->monitor;
}

const GLFWvidmode* GLWindow::getVidMode() {
        return this->mode;
}

void GLWindow::createMonitor() {
        monitor = glfwGetPrimaryMonitor();
}

void GLWindow::createMode() {
        mode = glfwGetVideoMode(monitor);
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
}

void GLWindow::createWindow() {
        window = glfwCreateWindow(mode->width, mode->height, title, monitor, NULL);
        if (window == NULL)
        {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        glfwSetCursorPosCallback(window, mouse_callback);
        glfwSetScrollCallback(window, scroll_callback);
        glViewport(0, (mode->height - mode->width) / 2, mode->width, mode->width);
        // tell GLFW to capture our mouse
        //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

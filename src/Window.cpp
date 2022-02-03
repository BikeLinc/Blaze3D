/******************************************************************************
 *
 * @file	Window.cpp
 *
 * @author	Lincoln Scheer
 * @since	02/03/2022
 *
 * @breif	Window is a Blaze3D utility that provides a high-level
 *		interface for creating and manipulating a cross platform window
 *		that holds an opengl context.
 *
 *****************************************************************************/

#include "Window.h"

Window::Window(const char* title) {
        this->title     = title;
        this->monitor   = nullptr;
        this->mode      = nullptr;
        this->window    = nullptr;
}

void Window::init() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        createMonitor();
        createMode();
        createWindow();
}

void Window::show() {
        glfwShowWindow(window);
}

bool Window::isOpen() {
        return !glfwWindowShouldClose(window);
}

void Window::hide() {
        glfwHideWindow(window);
}

void Window::update() {
        glfwSwapBuffers(window);
        glfwPollEvents();
}

void Window::terminate() {
        glfwTerminate();
}

GLFWwindow* Window::getWindow() {
        return this->window;
}

GLFWmonitor* Window::getMonitor() {
        return this->monitor;
}

const GLFWvidmode* Window::getVidMode() {
        return this->mode;
}

void Window::createMonitor() {
        monitor = glfwGetPrimaryMonitor();
}

void Window::createMode() {
        mode = glfwGetVideoMode(monitor);
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
}

void Window::createWindow() {
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
        // tell GLFW to capture our mouse
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
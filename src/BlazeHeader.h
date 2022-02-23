/******************************************************************************
 *
 * @file	BlazeHeader.h
 *
 * @author	Lincoln Scheer
 * @since	02/21/2022
 *
 * @breif	BlazeHeader is a static header-only collection of Blaze's 
 *		includes.
 *
 *****************************************************************************/

#ifndef BLAZE_HEADER_H
#define BLAZE_HEADER_H

// Standard Library
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

// OpenGL
#include <GL/glew.h>
#define GLEW_STATIC

// OpenGL Math Library
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

// Engine
#include "Window.h"

// Utilities
#include "Shader.h"
#include "TextureLoader.h"

// Scene
#include "Scene.h"

#endif
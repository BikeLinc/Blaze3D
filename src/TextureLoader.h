/******************************************************************************
 *
 * @file	TextureLoader.h
 *
 * @author	Lincoln Scheer
 * @since	02/01/2022
 *
 * @breif	TextureLoader is a Blaze3D utility that provides easy interface for
 *              loading, storing and retrieving image data. This class uses the
 *              SOIL2 header-only image library to load images.
 *
 *****************************************************************************/

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include "SOIL2/SOIL2.h"

class TextureLoader {
public:
        /**
         * Constructor loads image from specified path on class instantiation.
         *
         * \param path
         */
        TextureLoader(const char* path) {
                load(path);
        }

        /**
         * Return member texture variable.
         *
         * \return
         */
        unsigned int getTexture() {
                return texture;
        }


private:
        unsigned int texture;

        /**
         * Loads image from specified path into member texture variable.
         *
         * \param path
         * \return
         */
        void load(const char* path) {
                int width, height;

                glGenTextures(1, &this->texture);
                glBindTexture(GL_TEXTURE_2D, this->texture);

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

                unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGBA);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
                glGenerateMipmap(GL_TEXTURE_2D);
                SOIL_free_image_data(image);
                glBindTexture(GL_TEXTURE_2D, 0);
        }
};

#endif /* TEXTURE_H */
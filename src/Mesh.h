#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>

struct MeshObject {
	unsigned int cubeVAO, VBO, lightCubeVAO;

	MeshObject() {

                float vertices[] = {
                      0,	0,	0,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      1,	1,	0,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      0,	1,	1,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      1,	1,	0,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      0,	1,	1,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      1,	2,	1,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      /* ---- */
                      0,	1,	1,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      1,	2,	1,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      0,	2,	2,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      1,	2,	1,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      0,	2,	2,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      1,	3,	2,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      /* ---- */
                      0,	2,	2,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      1,	3,	2,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      0,	3,	3,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      1,	3,	2,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      0,	3,	3,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      1,	4,	3,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      /* ---- */
                      1,	1,	0,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      2,	2,	0,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      1,	2,	1,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      2,	2,	0,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      1,	2,	1,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      2,	3,	1,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      /* ---- */
                      1,	2,	1,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      2,	3,	1,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      1,	3,	2,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      2,	3,	1,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      1,	3,	2,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      2,	4,	2,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      /* ---- */
                      1,	3,	2,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      2,	4,	2,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      1,	4,	3,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      2,	4,	2,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      1,	4,	3,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      2,	5,	3,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      /* ---- */
                      2,	2,	0,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      3,	3,	0,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      2,	3,	1,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      3,	3,	0,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      2,	3,	1,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      3,	4,	1,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      /* ---- */
                      2,	3,	1,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      3,	4,	1,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      2,	4,	2,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      3,	4,	1,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      2,	4,	2,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      3,	5,	2,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      /* ---- */
                      2,	4,	2,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      3,	5,	2,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      2,	5,	3,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      3,	5,	2,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,
                      2,	5,	3,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,
                      3,	6,	3,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f
                        // positions          // normals           // texture coords
                        /*
                        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
                         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
                         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
                         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
                        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
                        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
                        
                        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
                         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
                         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
                         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
                        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
                        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
                        
                        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
                        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
                        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
                        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
                        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
                        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

                         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
                         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
                         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
                         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
                         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
                         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
                         
                        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
                         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
                         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
                         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
                        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
                        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
                        */
                       /*
                        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
                         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
                         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
                         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
                        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
                        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
                      */              
                };

                glGenVertexArrays(1, &this->cubeVAO);
                glGenBuffers(1, &this->VBO);

                glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                glBindVertexArray(this->cubeVAO);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
                glEnableVertexAttribArray(2);

                glGenVertexArrays(1, &this->lightCubeVAO);
                glBindVertexArray(this->lightCubeVAO);

                glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
	}
};

#endif /* MESH_H */

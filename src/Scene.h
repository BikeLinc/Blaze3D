/******************************************************************************
 *
 * @file	Scene.h
 *
 * @author	Lincoln Scheer
 * @since	02/23/2022
 *
 * @breif	Scene is the class that Blaze uses to describe where and how 
 *		to render an object.
 *
 *****************************************************************************/

#ifndef SCENE_H
#define SCENE_H

#include "BlazeHeader.h"

struct Transform {
	glm::vec3 position, rotation, scale;
	Transform(glm::vec3 position = glm::vec3(0), glm::vec3 rotation = glm::vec3(0), glm::vec3 scale = glm::vec3(1)) {
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
	}
};

struct Mesh {
	unsigned int VBO, VAO, EBO;
	Mesh(glm::vec2 size) {
		float width2 = size.x / 2, height2 = size.y / 2;
		float vertices[] = {
			// positions          // texture coords
			 width2,  height2, 0.0f,   size.x, size.y, // top right
			 width2, -height2, 0.0f,   size.x, 0.0f, // bottom right
			-width2, -height2, 0.0f,   0.0f, 0.0f, // bottom left
			-width2,  height2, 0.0f,   0.0f, size.y  // top left 
		};
		unsigned int indices[] = {
		    0, 1, 3, // first triangle
		    1, 2, 3  // second triangle
		};
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// texture coord attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}
};

struct Model {
	Mesh* mesh;
	unsigned int texMap1 = 0, texMap2 = 0;
	Shader* shader;
	Transform transform;
	Model(glm::vec2 size, const char* texPath2) {
		mesh = new Mesh(size);
		/// TexPath1 is const null because the shader only works with one texture currently.
		texMap1 = TextureLoader("").getTexture();
		texMap2 = TextureLoader(texPath2).getTexture();
		shader = new Shader("../res/shaders/vert.glsl", "../res/shaders/frag.glsl");
		shader->use();
		shader->setInt("texture1", texMap1);
		shader->setInt("texture2", texMap2);
	}

	void draw(Transform transformation) {
		glActiveTexture(GL_TEXTURE0 + texMap1);
		glBindTexture(GL_TEXTURE_2D, texMap1);
		glActiveTexture(GL_TEXTURE0 + texMap2);
		glBindTexture(GL_TEXTURE_2D, texMap2);

		// create transformations
		glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		transform = glm::translate(transform, transformation.position);
		transform = glm::rotate(transform, transformation.rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
		transform = glm::rotate(transform, transformation.rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
		transform = glm::rotate(transform, transformation.rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
		transform = glm::scale(transform, transformation.scale);

		// get matrix's uniform location and set matrix
		shader->use();
		unsigned int transformLoc = glGetUniformLocation(shader->ID, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

		// render container
		glBindVertexArray(mesh->VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void destroy() {
		glDeleteVertexArrays(1, &mesh->VAO);
		glDeleteBuffers(1, &mesh->VBO);
		glDeleteBuffers(1, &mesh->EBO);
	}
};

struct IModel {
	Model* model = nullptr;
	Transform transform;
	IModel(Model* model, Transform transform) {
		this->model = model;
		this->transform = transform;
	}

	void draw() {
		model->draw(transform);
	}
};

struct Scene {
	std::vector<IModel> instances;
	glm::vec4 backgroundColor;

	Scene(glm::vec4 backgroundColor = glm::vec4(1)) {
		this->backgroundColor = backgroundColor;
	}

	void draw() {
		glClearColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, backgroundColor.w);
		glClear(GL_COLOR_BUFFER_BIT);
		for (int i = 0; i < instances.size(); i++) {
			instances.at(i).draw();
		}
	}

	void destroy() {
		for (int i = 0; i < instances.size(); i++) {
			instances.at(i).model->destroy();
		}
	}
	 
	
};

#endif

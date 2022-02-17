#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <fstream>
#include <cmath>
#include "glm/glm.hpp"
#include <vector>
class Terrain {
public:
	Terrain() {
	}

	float* generateHeightMap(int size) {
		float* heights = new float[size * size];
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				*(heights + x * size + y) = x + y;
			}
		}

		std::ofstream fileStream;
		fileStream.open("EngineLog.TXT");

		
		

		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				fileStream << "(" << x << ", " << *(heights + x * size + y) << ", " << y << ")" << "\t";
			}
			fileStream << "\n\n";
		}

		// Triangulate
		int triangleCount = (size-1);
		std::vector<glm::vec3> vertices;
		int tri = 0;
		for (int x = 0; x < triangleCount; x++) {
			for (int y = 0; y < triangleCount; y++) {
				vertices.push_back(glm::vec3(x, *(heights + x * size + y), y));
				vertices.push_back(glm::vec3(x+1, *(heights + (x+1) * size + y), y));
				vertices.push_back(glm::vec3(x, *(heights + x * size + (y+1)), y+1));
				vertices.push_back(glm::vec3(x+1, *(heights + (x+1) * size + y), y));
				vertices.push_back(glm::vec3(x, *(heights + x * size + (y+1)), y+1));
				vertices.push_back(glm::vec3(x+1, *(heights + (x+1) * size + (y+1)), y+1));
				fileStream << "TriangleA " << tri << ": (" << 
				x << ", " << y << ")  (" <<
				x+1 << ", " << y << ")  (" <<
				x << ", " << y+1 << ") \n";

				fileStream << "TriangleB " << tri << ": (" << 
				x+1 << ", " << y << ")  (" <<
				x << ", " << y+1 << ")  (" <<
				x+1 << ", " << y+1 << ") \n";
				tri++;
				/*
				-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
                         	0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
                         	0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
                         	0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
                        	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
                        	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
				*/
			}
		}

		fileStream << "=== === === START GENERATED TERRAIN DATA === === ===\n";

		int index = 0;
		int vertCount = 0;
		int quadCount = 0;
		for(glm::vec3 point : vertices) {
			
			fileStream << point.x << ",\t" << point.y << ",\t" << point.z << ",\t0.0f,\t1.0f,\t0.0f,\t";
			if(index == 1+(quadCount*6) || index == 2+(quadCount*6) || index == 3+(quadCount*6)) {
				fileStream << "1.0f,\t0.0f,\n";
			} else {
				fileStream << "0.0f,\t1.0f,\n";
			}
			index++;
			if(vertCount != 5) {
				vertCount++;
			} else {
				vertCount = 0;
				quadCount++;
				fileStream << "/* ---- */\n";
			}
			
		}

		fileStream << "=== === === END GENERATED TERRAIN DATA === === ===\n";

		fileStream.close();
		return heights;
	}
};

#endif /* TERRAIN_H */

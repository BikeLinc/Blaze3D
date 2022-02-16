#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <fstream>
#include <cmath>

class Terrain {
public:
	Terrain() {
	}

	float* generateHeightMap(int size) {
		float* heights = new float[size * size];
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				*(heights + x * size + y) = x*y;
			}
		}

		std::ofstream fileStream;
		fileStream.open("EngineLog.TXT");
		

		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				//fileStream << *(heights + x * size + y) << "\t";
				fileStream << "(" << x << "," << y << ")" << "\t";
			}
			fileStream << "\n\n";
		}
		fileStream.close();
		return heights;
	}
};

#endif /* TERRAIN_H */

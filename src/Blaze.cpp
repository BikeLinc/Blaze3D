#include "BlazeHeader.h"

int main() {
	GLWindow window("Blaze2D");
	window.init();

	Scene scene(glm::vec4(0.25, 0.25, 0.35, 1.0));

	Model rectangle(glm::vec2(0.25), "../res/images/abstract_diff.jpg");

	IModel rectangle_instance(&rectangle, Transform());

	scene.instances.push_back(rectangle_instance);

	while (window.isOpen()) {

		window.processInput();

		scene.draw();

		window.update();
	}

	scene.destroy();
	
	window.terminate();

	return 0;
}

#include "Blaze.h"
// TODO: Move to Window.h
void processInput(GLFWwindow* window);
 
// TDOD: Get window size directly from window object
const unsigned int WINDOW_DEFAULT_WIDTH = 1920;
const unsigned int WINDOW_DEFAULT_HEIGHT = 1080;

// TODO: Make Camera a pointer that engine has ref to
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = WINDOW_DEFAULT_WIDTH / 2.0f;
float lastY = WINDOW_DEFAULT_HEIGHT / 2.0f;
bool firstMouse = true;

// === FRAME TIMING ===
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

void renderer_init() {
        if (GLEW_OK != glewInit()) {
                std::cout << "Failed to initialize GLAD" << std::endl;
        }

        glEnable(GL_DEPTH_TEST);
}

int main() {

        Window window("BLAZE WINDOW");
        window.init();

        // Renderer Initialization
        // --------------------------------------------------------------------
        renderer_init();

        /// Scene ///
        
        // Shader Loading
        // --------------------------------------------------------------------
        Shader lightingShader("res/shaders/scene_vert.glsl",
                "res/shaders/scene_frag.glsl");
        Shader lightCubeShader("res/shaders/light_vert.glsl",
                "res/shaders/light_frag.glsl");

        // Mesh Loading
        // --------------------------------------------------------------------
        MeshObject* cube = new MeshObject();


        // Texute Loading
        // --------------------------------------------------------------------
        const char* text = "res/images/grass.jpg";
        const char* spec = "res/images/grass_metalic.jpg";
        TextureLoader diffuseMap(text);
        TextureLoader specularMap(spec);

        // Mesh Position
        // --------------------------------------------------------------------
        int xSize = 8;
        int ySize = 1;
        int zSize = 8;
        float blockScale = 1.0f;

        std::vector<glm::vec3> cubePositions;
        int terrainSize = 4;
        Terrain terrain;
        float* terrainHeights = terrain.generateHeightMap(terrainSize);

        cubePositions.push_back(glm::vec3(0,0,0));

        // Point Light Position
        // --------------------------------------------------------------------
        glm::vec3 pointLightPositions[] = {
                glm::vec3(0.7f,  0.2f,  2.0f),
                glm::vec3(2.3f, -3.3f, -4.0f),
                glm::vec3(-4.0f,  2.0f, -12.0f),
                glm::vec3(0.0f,  0.0f, -3.0f)
        };

        // shader configuration
        // --------------------
        lightingShader.use();
        lightingShader.setInt("material.diffuse", 0);
        lightingShader.setInt("material.specular", 1);

        /// Game Loop

        window.show();

        //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

        // render loop
        // -----------
        while (window.isOpen())
        {
                // per-frame time logic
                // --------------------
                float currentFrame = static_cast<float>(glfwGetTime());
                deltaTime = currentFrame - lastFrame;
                lastFrame = currentFrame;

                // input
                // -----
                processInput(window.getWindow());

                // render
                // ------
                glClearColor(0.815, 0.945, 0.933, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                // be sure to activate shader when setting uniforms/drawing objects
                lightingShader.use();
                lightingShader.setVec3("viewPos", camera.Position);
                lightingShader.setFloat("material.shininess", 32.0f);

                // directional light
                lightingShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
                lightingShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
                lightingShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
                lightingShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
                // point light 1
                lightingShader.setVec3("pointLights[0].position", pointLightPositions[0]);
                lightingShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
                lightingShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
                lightingShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
                lightingShader.setFloat("pointLights[0].constant", 1.0f);
                lightingShader.setFloat("pointLights[0].linear", 0.09f);
                lightingShader.setFloat("pointLights[0].quadratic", 0.032f);
                // point light 2
                lightingShader.setVec3("pointLights[1].position", pointLightPositions[1]);
                lightingShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
                lightingShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
                lightingShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
                lightingShader.setFloat("pointLights[1].constant", 1.0f);
                lightingShader.setFloat("pointLights[1].linear", 0.09f);
                lightingShader.setFloat("pointLights[1].quadratic", 0.032f);
                // point light 3
                lightingShader.setVec3("pointLights[2].position", pointLightPositions[2]);
                lightingShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
                lightingShader.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
                lightingShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
                lightingShader.setFloat("pointLights[2].constant", 1.0f);
                lightingShader.setFloat("pointLights[2].linear", 0.09f);
                lightingShader.setFloat("pointLights[2].quadratic", 0.032f);
                // point light 4
                lightingShader.setVec3("pointLights[3].position", pointLightPositions[3]);
                lightingShader.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
                lightingShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
                lightingShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
                lightingShader.setFloat("pointLights[3].constant", 1.0f);
                lightingShader.setFloat("pointLights[3].linear", 0.09f);
                lightingShader.setFloat("pointLights[3].quadratic", 0.032f);
                // spotLight
                lightingShader.setVec3("spotLight.position", camera.Position);
                lightingShader.setVec3("spotLight.direction", camera.Front);
                lightingShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
                lightingShader.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
                lightingShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
                lightingShader.setFloat("spotLight.constant", 1.0f);
                lightingShader.setFloat("spotLight.linear", 0.09f);
                lightingShader.setFloat("spotLight.quadratic", 0.032f);
                lightingShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
                lightingShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

                // view/projection transformations
                glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WINDOW_DEFAULT_WIDTH / (float)WINDOW_DEFAULT_HEIGHT, 0.1f, 100.0f);
                glm::mat4 view = camera.GetViewMatrix();
                lightingShader.setMat4("projection", projection);
                lightingShader.setMat4("view", view);

                // world transformation
                glm::mat4 model = glm::mat4(1.0f);
                lightingShader.setMat4("model", model);

                // bind diffuse map
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, diffuseMap.getTexture());
                // bind specular map
                glActiveTexture(GL_TEXTURE1);
                glBindTexture(GL_TEXTURE_2D, specularMap.getTexture());

                // render containers
                glBindVertexArray(cube->cubeVAO);
                glm::vec3* cubePosList = cubePositions.data();
                for (unsigned int i = 0; i < sizeof(cubePosList); i++)
                {
                        // calculate the model matrix for each object and pass it to shader before drawing
                        glm::mat4 model = glm::mat4(1.0f);
                        model = glm::translate(model, cubePosList[i]);
                        model = glm::scale(model, glm::vec3(blockScale));
                        lightingShader.setMat4("model", model);
                        glDrawArrays(GL_TRIANGLES, 0, 36);
                }

                // also draw the lamp object(s)
                lightCubeShader.use();
                lightCubeShader.setMat4("projection", projection);
                lightCubeShader.setMat4("view", view);

                // we now draw as many light bulbs as we have point lights.
                glBindVertexArray(cube->lightCubeVAO);
                for (unsigned int i = 0; i < 4; i++)
                {
                        model = glm::mat4(1.0f);
                        model = glm::translate(model, pointLightPositions[i]);
                        model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
                        lightCubeShader.setMat4("model", model);
                        glDrawArrays(GL_TRIANGLES, 0, 36);
                }

                window.update();
        }

        // optional: de-allocate all resources once they've outlived their purpose:
        // ------------------------------------------------------------------------
        glDeleteVertexArrays(1, &cube->cubeVAO);
        glDeleteVertexArrays(1, &cube->lightCubeVAO);
        glDeleteBuffers(1, &cube->VBO);

        // glfw: terminate, clearing all previously allocated GLFW resources.
        // ------------------------------------------------------------------
        window.terminate();
        return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
                camera.ProcessKeyboard(FORWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
                camera.ProcessKeyboard(BACKWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
                camera.ProcessKeyboard(LEFT, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
                camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
        // make sure the viewport matches the new window dimensions; note that width and 
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
        float xpos = static_cast<float>(xposIn);
        float ypos = static_cast<float>(yposIn);

        if (firstMouse)
        {
                lastX = xpos;
                lastY = ypos;
                firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

        lastX = xpos;
        lastY = ypos;

        camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
        camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
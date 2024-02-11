#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include<fstream>
#include<sstream>
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"

const unsigned int width = 800;
const unsigned int height = 800;

int main() {
    // Initialize GLFW
    glfwInit();

    // Tell GLFW what version of OpenGL we are using
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFWwindow object
    GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL File Import", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, width, height);

    Shader shaderProgram("plainvertex.vert", "plainfragment.frag");

    // File reading
    std::ifstream file("en_funksjon_av_to_variable_data.txt");
    std::string line;
    std::vector<GLfloat> vertices;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        GLfloat x, y, z;
        char delim;
        ss >> x >> delim >> y >> delim >> z;
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(z); // Z-coordinate is 0 for 2D

        
    }
    file.close();

    //sjekk hvilke tall som blir lest inn fra filen

    for (size_t i = 0; i < vertices.size(); i += 3) {
        std::cout << "Punkt " << (i / 3) + 1 << ": " << vertices[i] << ", " << vertices[i + 1] << std::endl;
    }


    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(&vertices[0], vertices.size() * sizeof(GLfloat));
    VAO1.LinkVBO(VBO1, 0);
    VAO1.Unbind();
    VBO1.Unbind();

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shaderProgram.Activate();
        VAO1.Bind();
        // Draw GL_LINE_STRIP
        //glDrawArrays(GL_LINE_STRIP, 0, vertices.size() / 3); // Now each vertex has 3 components (x, y, z=0)
        glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    shaderProgram.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "feather/core.h"
#include "opengl/shader.h"
#include "feather/files.h"
#include "feather/log.h"

namespace ft {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    unsigned int VBO, VAO;
    Shader shader;

    int initialiseForTheTriangle() {
        int success = shader.init(
            getFileStr("../featherengine/resources/glsl/default.vert").c_str(), 
            getFileStr("../featherengine/resources/glsl/default.frag").c_str()
        );
        FT_CORE_ASSERT(success == 0, "Failed to initialize shaders");

        glGenVertexArrays(1, &VAO); 
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
        glEnableVertexAttribArray(0);  

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        return 0;
    }

    void renderTriangle() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        glBindVertexArray(VAO); 

        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}
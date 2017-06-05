#include <engine/engine.hh>

#include <iostream>

#include <graphics/shader.hh>

namespace ky
{
  void Engine::start(Game& game)
  {
    this->game_ = std::shared_ptr<Game>(&game);

    this->display_ = std::make_unique<Display>("TEST", 800, 600);
    this->display_->initialize();

    this->gameloop();
  }

  void Engine::close()
  {
    std::cout << "ENGINE IS CLOSING" << std::endl;
  }


  void Engine::gameloop()
  {
    float points[] =
    {
      0.0f, 0.0f, 0.0f,
      100.0f, 0.0f, 0.0f,
      100.0f, 100.0f, 0.0f,
      0.0f, 0.0f, 0.0f,
      100.0f, 100.0f, 0.0f,
      0.0f, 100.0f, 0.0f,

      200.0f, 200.0f, 0.0f,
      300.0f, 200.0f, 0.0f,
      300.0f, 300.0f, 0.0f,
      200.0f, 200.0f, 0.0f,
      300.0f, 300.0f, 0.0f,
      200.0f, 300.0f, 0.0f
    };

    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(float), points, GL_STATIC_DRAW);

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    const char* vertex_shader =
      "#version 400\n"
      "layout(location = 0) in vec3 vertex_position;"
      "uniform mat4 view, proj, model;"
      "void main() {"
      "gl_Position = proj * view * model * vec4(vertex_position, 1.0);"
      "}";

    const char* fragment_shader =
      "#version 400\n"
      "out vec4 frag_colour;"
      "void main() {"
      "  frag_colour = vec4(1, 1, 1, 1.0);"
      "}";

    int width = display_->getWidth();
    int height = display_->getHeight();
    camera_ = std::make_unique<Camera>(0, width, 0, height, Vec2(0.0f, 0.0f));

    Shader shader = Shader(vertex_shader, fragment_shader);

    GLint view_mat_location = glGetUniformLocation(shader.getProgram(), "view");
    GLint proj_mat_location = glGetUniformLocation(shader.getProgram(), "proj");
    GLint model_mat_location = glGetUniformLocation(shader.getProgram(), "model");

    glUseProgram(shader.getProgram());
    glUniformMatrix4fv(view_mat_location, 1, GL_FALSE,
        camera_->getView().getValues().data());
    glUniformMatrix4fv(proj_mat_location, 1, GL_FALSE,
        camera_->getProjection().getValues().data());
    glUniformMatrix4fv(model_mat_location, 1, GL_FALSE,
        Mat4::identity().rotateOnZ(0).getValues().data());
    while (!display_->shouldClose())
    {
      display_->clearScreen();
      glUseProgram(shader.getProgram());
      glBindVertexArray(vao);
      glDrawArrays(GL_TRIANGLES, 0, 12);

      glfwPollEvents();
      if (glfwGetKey(display_->getWindow(), GLFW_KEY_A))
        camera_->move(-20.0f, 0.0f);
      if (glfwGetKey(display_->getWindow(), GLFW_KEY_D))
        camera_->move(20.0f, 0.0f);
      if (glfwGetKey(display_->getWindow(), GLFW_KEY_W))
        camera_->move(0.0f, -20.0f);
      if (glfwGetKey(display_->getWindow(), GLFW_KEY_S))
        camera_->move(0.0f, 20.0f);
      if (glfwGetKey(display_->getWindow(), GLFW_KEY_Q))
        camera_->rotate(-20.0f);
      if (glfwGetKey(display_->getWindow(), GLFW_KEY_E))
        camera_->rotate(20.0f);
    glUniformMatrix4fv( view_mat_location, 1, GL_FALSE,
        camera_->getView().getValues().data());
    glUniformMatrix4fv( proj_mat_location, 1, GL_FALSE,
        camera_->getProjection().getValues().data());
      display_->postRender();
    }

    display_->terminate();
  }

}

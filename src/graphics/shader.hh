#pragma once

#include <string>

#include <OpenGL/gl.h>

namespace ky
{
  class Shader
  {
    public:
      Shader(const std::string& vert_content, const std::string& frag_content);

      inline GLuint getProgram() const { return program_; }
    private:
      Shader();
      GLuint vertex_shader_;
      GLuint fragment_shader_;
      // LEAVE PLACE FOR GEOMETRY SHADER
      GLuint program_;
  };
}

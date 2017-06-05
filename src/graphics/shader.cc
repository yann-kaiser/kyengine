#include <graphics/shader.hh>

#include <iostream>
#include <vector>

namespace ky
{
  Shader::Shader(const std::string& vert_content,
      const std::string& frag_content)
  {
    const char* vert = vert_content.c_str();
    const char* frag = frag_content.c_str();
  
    std::cout << vert << std::endl;
    std::cout << frag << std::endl;

    vertex_shader_ = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader_, 1, &vert, NULL);
    glCompileShader(vertex_shader_);

    // CHECK ERRORS !
    int params = -1;
    glGetShaderiv(vertex_shader_, GL_COMPILE_STATUS, &params);
    if ( GL_TRUE != params ) {
      std::cout << "ERROR: GL shader index " << vertex_shader_ <<
        "did not compile\n" << std::endl;

      GLint maxLength = 0;
      glGetShaderiv(vertex_shader_, GL_INFO_LOG_LENGTH, &maxLength);

      // The maxLength includes the NULL character
      std::vector<GLchar> errorLog(maxLength);
      glGetShaderInfoLog(vertex_shader_, maxLength, &maxLength, &errorLog[0]);
      std::cout << errorLog.data() << std::endl;
    }

    fragment_shader_ = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader_, 1, &frag, NULL);
    glCompileShader(fragment_shader_);
    // CHECK ERRORS !
    params = -1;
    glGetShaderiv(fragment_shader_, GL_COMPILE_STATUS, &params);
    if ( GL_TRUE != params ) {
      std::cout << "ERROR: GL shader index " << fragment_shader_ <<
        "did not compile\n" << std::endl;
    }

    program_ = glCreateProgram();

    glAttachShader(program_, fragment_shader_);
    glAttachShader(program_, vertex_shader_);
    glLinkProgram(program_);
  }
}

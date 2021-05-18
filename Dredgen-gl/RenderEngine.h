#pragma once
// standard libs
#include <memory>
#include <unordered_map>
// 3rd libs
#include "Camera.h"
#include "Light.h"
#include "Shader.h"
#include <GLFW/glfw3.h>
#include <cstdint>
#include <glm/glm.hpp>
// headers
#include "Aopass.h"
#include "Deferrdpass.h"
#include "Framebuffer.h"
#include "Model.h"
#include "Postprocesspass.h"
#include "Shadowpass.h"
#include "Skybox.h"
#include "Uniformbuffer.h"
#include "utils.h"
class RenderEngine {

public:
  RenderEngine(uint32_t _width, uint32_t _height);
  ~RenderEngine();
  void Update();
  void Render();
  void Destroy();
  std::shared_ptr<Camera> GetCam() { return main_cam; }
  uint32_t GetTexture();
  void AddModel(std::string name, std::string path);
  void GetSceneStat();

private:
  void Initglad();
  void Init();
  // void InitFBO(uint32_t& fbo, uint32_t& ebo);
private:
  uint32_t width{}, height{};

  std::shared_ptr<Camera> main_cam{};
  std::shared_ptr<Skybox> skybox{};
  // std::unordered_map<std::string,std::shared_ptr<Shader>> shaders{};
  std::unordered_map<std::string, std::shared_ptr<Model>> scene;
  std::vector<std::shared_ptr<Light>> light;

  std::shared_ptr<UboLight> ubolight{};

  std::shared_ptr<Framebuffer> base_fbo;
  std::shared_ptr<Shadowpass> shadowpass;
  std::shared_ptr<PostProcesspass> postprocess_pass;
  std::shared_ptr<Deferrdpass> deferred_pass;
  std::shared_ptr<Aopass> ao_pass;
  std::shared_ptr<Quad> quad;
};

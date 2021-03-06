#ifndef RAYTRACER_SDFLOADER_HPP
#define RAYTRACER_SDFLOADER_HPP


#include <string>
#include <vector>
#include <glm-0.9.5.3/glm/vec3.hpp>
#include <iostream>
#include <fstream>
#include <sstream> // string stream -> easy parsing mechanics
#include <string>
#include <utility>
#include <map>
#include "../shapes/composite.hpp"
#include "../shapes/sphere.hpp"
#include "../renderer/scene.hpp"
#include "../shapes/triangle.hpp"
#include "../shapes/cone.hpp"
#include "../shapes/triangle.hpp"
#include "../shapes/cylinder.hpp"

class SdfLoader {
public:
    SdfLoader (std::string const& filepath);
    void load_file();
    std::shared_ptr<Scene> get_scene();

private:
    std::shared_ptr<Scene> scene_;
    std::string filepath_;
};


#endif //RAYTRACER_SDFLOADER_HPP

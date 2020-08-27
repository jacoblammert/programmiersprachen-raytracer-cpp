#ifndef RAYTRACER_LIGHT_HPP
#define RAYTRACER_LIGHT_HPP


#include <glm-0.9.5.3/glm/vec3.hpp>

struct Light {

    /**
     *
     * @param position as vec 3
     * @param color as vec 3 (red, gren, blue)
     * @param brightness as float
     * @param hardness as float => 1 = hard shadows, 0 = really soft shadows
     */
    Light(glm::vec3 const& position, glm::vec3 const& color, glm::vec3 brightness, float hardness = 1):
        position_{position},
        color_ {color},
        brightness_ {brightness},
        hardness_ {hardness}
    {}

    glm::vec3 position_;
    glm::vec3 color_;
    //float brightness_;
    glm::vec3 brightness_;
    float hardness_;

};


#endif //RAYTRACER_LIGHT_HPP

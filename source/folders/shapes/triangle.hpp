#ifndef RAYTRACER_TRIANGLE_HPP
#define RAYTRACER_TRIANGLE_HPP

#include <cmath>
#include <iostream>
#include "shape.hpp"

class Triangle : public Shape {
    
public:
    Triangle (std::string const& name, const glm::vec3 &a, const glm::vec3 &b, const glm::vec3 &c);

    bool get_intersect_vec(Ray const& ray, glm::vec3 &hit_point, glm::vec3 &hit_normal, float &distance) const override;

    glm::vec3 get_normal(glm::vec3 const& pos) const override;

    glm::vec3 get_min() const override;

    glm::vec3 get_max() const override;

    glm::vec3 get_median() const override;

    std::shared_ptr<Material> get_material() override;

    void set_material (std::shared_ptr<Material> const& material) override;
    
    void translate(glm::vec3 const& position) override;

    std::string get_information()const override;

    void set_rotation_axis(const glm::vec3& axis) override;
private:
    glm::vec3 b_;
    glm::vec3 c_;
};


#endif //RAYTRACER_TRIANGLE_HPP

#include "plane.hpp"

/**
 * generates a plane with a given position and normal vector
 * @param position for the new plane
 * @param normal of the pane (will be normalized automatically)
 */
Plane::Plane(std::string const& name, glm::vec3 const &position, glm::vec3 const &normal) {
    axis_ = glm::normalize(normal);
    shape_type_ = PLANE;
    name_ = name;
    position_ = position;
}

/**
 * returns true, if this plane has been intersected in front of the ray, no intersections with negative scalar for ray direction allowed
 * @param ray to be tested against the plane
 * @param HitPoint point of the ray plane intersection
 * @param HitNormal normal of the plane
 * @param distance as float (scalar for the normalized direction of the ray)
 * @return true, if intersected in front of the ray, false otherwise
 */
bool Plane::get_intersect_vec(Ray const &ray, glm::vec3 &hit_point, glm::vec3 &hit_normal, float &distance) const {
    float t = glm::dot(position_ - ray.position, axis_) / glm::dot(ray.direction, axis_);

    if (0 <= t && t < distance) {
        distance = t;
        hit_point = ray.position + ray.direction * t;
        hit_normal = get_normal(ray.position);
        return true;
    }
    return false;
}

/**
 * @param pos of the camera very important in order to get correct shadows from both sides of the plane
 * @return normal of the plane always "pointing" towards the camera
 */
glm::vec3 Plane::get_normal(glm::vec3 const &pos) const {
    return axis_;
}

/**
 * @return minimum of the plane (useless, because we will leave planes in the first layer of our hierarchy anyways)
 */
glm::vec3 Plane::get_min() const {
    return {-INFINITY, -INFINITY, -INFINITY}; // should give back a box of the desired size of the plane
}

/**
 * @return maximum of the plane (useless, because we will leave planes in the first layer of our hierarchy anyways)
 */
glm::vec3 Plane::get_max() const {
    return {INFINITY, INFINITY,
            INFINITY}; // should give back a box of the desired size of the plane (cutting doesn't work)
}

/**
 * where is the median of an infinite plane? -> position is our best guess
 * @return position of the plane
 */
glm::vec3 Plane::get_median() const {
    return position_;
}

/**
* @return material of the plane
*/
std::shared_ptr<Material> Plane::get_material() {
    return material_;
}

/**
* @param material is given to plane
*/
void Plane::set_material(std::shared_ptr<Material> const& material) {
    this->material_ = material;
}

/**
 * Changes the position of the Sphere with a given glm::vec3
 * @param position
 */
void Plane::translate(glm::vec3 const& position) {
    position_ += position;
}

/**
*Gives information of the plane
* @returns string with name and data
*/
std::string Plane::get_information() const {
    std::string information = name_ + " " + std::to_string(position_[0]) + " " + std::to_string(position_[1]) + " " + std::to_string(position_[2]) + " "
            + std::to_string(axis_[0]) + " " + std::to_string(axis_[1]) + " " + std::to_string(axis_[2]) + " "
            + material_->name;
    return information;
}

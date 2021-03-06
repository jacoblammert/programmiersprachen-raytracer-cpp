#include "skybox.hpp"

Skybox::Skybox() {

    top_.load("../../source/folders/skybox/posy.ppm");
    bottom_.load("../../source/folders/skybox/negy.ppm");
    left_.load("../../source/folders/skybox/negx.ppm");
    right_.load("../../source/folders/skybox/posx.ppm");
    front_.load("../../source/folders/skybox/negz.ppm");
    back_.load("../../source/folders/skybox/posz.ppm");
}

/**
 * Should return the color of the Skybox, does not work, because the files are not imported correctly
 * @param direction as vec3 of the ray
 * @return Color
 */
glm::vec3 Skybox::get_color(glm::vec3 direction) const {
    float x = 0, y = 0;


    Box box{{-1,-1,-1},{1,1,1}};
    glm::vec3 hit_normal;

    box.get_intersect_vec(direction,hit_normal);

    glm::vec3 color;


    if (hit_normal[0] == 1) { // left
        x = (1 + direction[2]) * 0.5f;
        y = (1 - direction[1]) * 0.5f;
        color = get_pixel_interpolated(x, y,left_);


    } else if (hit_normal[0] == -1) { // right

        x = (1 - direction[2]) * 0.5f;
        y = (1 - direction[1]) * 0.5f;
        color = get_pixel_interpolated(x, y,right_);


    } else if (hit_normal[2] == 1) { // back

        x = (1 - direction[0]) * 0.5f;
        y = (1 - direction[1]) * 0.5f;
        color = get_pixel_interpolated(x, y,back_);

    } else if (hit_normal[2] == -1) { // front

        x = (1 + direction[0]) * 0.5f;
        y = (1 - direction[1]) * 0.5f;
        color = get_pixel_interpolated(x, y,front_);

    } else if (hit_normal[1] == 1) { // Top

        x = (1 - direction[0]) * 0.5f;
        y = (1 + direction[2]) * 0.5f;
        color = get_pixel_interpolated(x, y,top_);

    } else { // Bottom

        x = (1 - direction[0]) * 0.5f;
        y = (1 - direction[2]) * 0.5f;
        color = get_pixel_interpolated(x, y,bottom_);
    }
    return color;
}


/**
 * Interpolates the Color at a given point
 * @param x position
 * @param y position
 * @param renderer Image (top, bottom, left, right, front or back)
 * @return color
 */
glm::vec3 Skybox::get_pixel_interpolated(float x, float y,Ppm const & image) const{

    if (0 <= x && 0 <= y) {
        x = x * (float) image.width;
        y = y * (float) image.height;


        x = ((int) floor(x)) % (int) image.width;
        y = ((int) floor(y)) % (int) image.height;


        int xMax = (x+1) < image.width ? x + 1 : x;
        int yMax = (y+1) < image.height ? y + 1 : y;

        glm::vec3 middle = image.get_pixel({x,y});
        glm::vec3 right = image.get_pixel({xMax,y});
        glm::vec3 bottom = image.get_pixel({x,yMax});
        glm::vec3 bottomright = image.get_pixel({xMax,yMax});


        return interpolate(interpolate(interpolate(middle,right,x-floor(x)),interpolate(bottom,bottomright,x-floor(x)),y-floor(y)),
                           interpolate(interpolate(middle,bottom,y-floor(y)),interpolate(right,bottomright,y-floor(y)),x-floor(x)),0.5f);
    } else {
        return {0,0,0};
    }
}

/**
 * Interpolates two vec3 by a given amount
 * @param A vec3 No.1
 * @param B vec3 No.2
 * @param value of Interpolation
 * @return linearly interpolated vec3
 */
glm::vec3 Skybox::interpolate(const glm::vec3& A,const glm::vec3&  B, float value) const{
    return (B-A) * value + A;
}

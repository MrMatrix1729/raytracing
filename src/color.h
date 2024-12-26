#include "vec3.h"
#include "interval.h"


#ifndef COLOR_H
#define COLOR_H

using color = vec3;

const double COLOR_SCALE = 256;

inline void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0,1] component values to the byte range [0,255].
    static const interval intensity(0.000, 0.999);
    int rbyte = int(COLOR_SCALE * intensity.clamp(r));      // Clamp is used to make sure the color doesn't go outside the interval
    int gbyte = int(COLOR_SCALE * intensity.clamp(g));      // This is necessary as we add colors from surronding pixels for antialiasing
    int bbyte = int(COLOR_SCALE * intensity.clamp(b));      // So while adding it can overflow, so we clamp


    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif
#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class sphere : public hittable {
  public:
    sphere(const point3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        vec3 oc = center - r.origin();

        // For quadratic formula of ray P = Q + td on a sphere with center C in equation of sphere 
        // (C - P).(C - P) = r^2
        // Quadratic Equation => 
        // # Math: t^2 \mathbf{d} \cdot \mathbf{d} - 2t \mathbf{d} \cdot (\mathbf{C} - \mathbf{Q}) + (\mathbf{C} - \mathbf{Q}) \cdot (\mathbf{C} - \mathbf{Q}) - r^2 = 0
        double a = dot(r.direction(), r.direction());
        double h = dot(r.direction(), oc);    // # Math: h = \frac{b}{-2} = \mathbf{d} \cdot (\mathbf{C} - \mathbf{Q})
        double c = dot(oc, oc) - radius*radius;
        double discriminant = h*h - a*c;

        if (discriminant < 0)
            return false;

        double sqrt_of_discriminant = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        double root = (h - sqrt_of_discriminant) / a;
        if (!ray_t.surrounds(root)) {  // condition is root <= ray_tmin || ray_tmax <= root
            root = (h + sqrt_of_discriminant) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    }

  private:
    point3 center;
    double radius;
};

#endif
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <vector>


class hittable_list : public hittable {
    public:
        // A vector of pointer to hittable objects that is also kept track using shared_ptr
        std::vector<shared_ptr<hittable>> objects;

        hittable_list() : objects() {}
        hittable_list(shared_ptr<hittable> object) : objects{object} {}

        void clear() { objects.clear(); }

        void add(shared_ptr<hittable> object) {
            objects.emplace_back(std::move(object));
        }

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            hit_record temp_rec;
            bool hit_anything = false;
            double closest_so_far = ray_t.max;

            for (const auto& object : objects) {
                if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                    hit_anything = true;
                    closest_so_far = temp_rec.t;
                    rec = temp_rec;
                }
            }

            return hit_anything;
        }
};

#endif
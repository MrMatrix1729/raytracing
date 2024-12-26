#ifndef VEC3_H
#define VEC3_H

class vec3 {
    public:
        double e[3];

        // Default defining to (0,0,0)
        vec3() : e{0, 0, 0} {}
        // Parameterized constructor to initialize vector with given values
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        // for '-vec'
        vec3 operator-() const {
            return vec3(-e[0], -e[1], -e[2]);
        }

        // for 'vec[i]'
        double operator[](int i) const {
            if (i < 0 || i >= 3) {
                throw std::out_of_range("Index out of range");
            }
            return e[i];
        }

        // for 'vec[i]'
        double& operator[](int i) {
            if (i < 0 || i >= 3) {
                throw std::out_of_range("Index out of range");
            }
            return e[i];
        }

        // for vec1 += vec2
        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        // for vec1 *= vec2
        vec3& operator*=(const vec3& v) {
            e[0] *= v.e[0];
            e[1] *= v.e[1];
            e[2] *= v.e[2];
            return *this;
        }

        // for vec *= double
        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // for vec /= double
        vec3& operator/=(double t) {
            if (t == 0) {
                throw std::invalid_argument("Division by zero");
            }
            return *this *= 1/t;
        }

        // for absolute dist from origin
        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        // Generate a random vec3
        static vec3 random() {
            return vec3(random_double(), random_double(), random_double());
        }

        // Generating a random vec3 in [min, max)
        static vec3 random(double min, double max) {
            return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
        }

};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;

// for vec3 = vec1 + vec2
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// for vec3 = vec1 - vec2
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// for vec3 = vec1 * vec2
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// for vec2 = double * vec1
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

// for vec2 = vec1 * double
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

// for vec2 = vec1 / double
inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

// for vec3 = vec1 . vec2
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

// for vec2 = vec1 x vec2
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}


inline vec3 unit_vector(const vec3& v) {
    double len = v.length();
    if (len == 0) {
        throw std::runtime_error("Cannot compute unit vector of a zero-length vector");
    }
    return v / len;
}

// for printing
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
} 

#endif // VEC3_H

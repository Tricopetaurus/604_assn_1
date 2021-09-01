#include <iostream>

using namespace std;

enum class TriangleType {
    EQUILATERAL,
    ISOSCELES,
    SCALENE,
    UNKNOWN
};
class Triangle {
    private:
        TriangleType type;
    public:
        static const int NUM_SIDES = 3;
        void set_matching_sides(int sides) {
            if (sides == 0 || sides == 1)
                this->type = TriangleType::SCALENE;
            else if (sides == 2)
                this->type = TriangleType::ISOSCELES;
            else if (sides == 3)
                this->type = TriangleType::EQUILATERAL;
            else
                this->type = TriangleType::UNKNOWN;
        }
        string to_string() {
            switch(this->type){
                case TriangleType::EQUILATERAL:
                    return "equilateral";
                case TriangleType::ISOSCELES:
                    return "isosceles";
                case TriangleType::SCALENE:
                    return "scalene";
                case TriangleType::UNKNOWN:
                default:
                    return "unknown";
            }
        }
        TriangleType get_type() {
            return this->type;
        }
};

int main() {
    Triangle t = Triangle();
    int sides[Triangle::NUM_SIDES] = {0,};

    for(int i=0; i<Triangle::NUM_SIDES; i++) {
        cout << "Enter length of side " << i+1 << endl;
        cout << ">> ";
        cin >> sides[i];
    }

    // TODO: Perform error condition checking. Negatives, floats, non-ints.

    // Iterate over all sides, check the number of occurences for each.
    int num_matching=0;
    for(int i=0; i<Triangle::NUM_SIDES; i++) {
        int match = 0;
        for(int j=0; j<Triangle::NUM_SIDES; j++) {
            if (sides[i] == sides[j])
                match += 1;
        }
        if (match > num_matching)
            num_matching = match;
    }

    t.set_matching_sides(num_matching);
    cout << "You have input a(n) " << t.to_string() << " triangle" << endl;

    return 0;
}
#include <iostream>
#include <fstream>
namespace Skele_lib {
	namespace Shapes {
        struct Shape {
            virtual  double perimeter() = 0;
            virtual  double area() = 0;
        };
        struct Rect : public Shape {
            double w, h;
            Rect(double _w, double _h) {
                this->w = _w;
                this->h = _h; 
            }
            Rect(double _w) {
                this->w = _w;
                this->h = _w; 
            }
            double perimeter() override {
                return 2 * this->h + 2 * this->w;
            }
            double area() override {
                return this->h * this->w;
            }
        };
        void pythapythagoreanTriples(int opnum){
            /**prints all of the Pythapythagorean Triples in z <= opnum to the file pythapythagoreanTriples.cvs*/
            std::ofstream PyFi;
            PyFi.open("pythapythagoreanTriples.cvs");
            for (int z = 1; z < opnum; z++) {
                bool found = false;
                for (int x = 1; x < opnum; x++) {
                    for (int y = 1; y < opnum; y++) {
                        if (pow(x, 2) + pow(y, 2) == pow(z, 2) && !found) {
                            PyFi << x << "," << y << "," << z << ", (found in " << x * y << " operations)\n";
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
	}
}
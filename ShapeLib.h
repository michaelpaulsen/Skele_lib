#include <iostream>
#include <fstream>
namespace Skele_lib {
	namespace Shapes {
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
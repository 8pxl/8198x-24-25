#include "keejLib/lib.h"
#include "../robot.hpp"

using namespace robot;
using namespace exit;

void test() {
    chass.measureOffsets(5);
}
keejLib::Autons autons = {{test}, {"test"}};
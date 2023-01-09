//
//  impl2.cpp
//  TestStaticLib
//
//  Created by Zhanlue Yang on 2023/1/6.
//

#include "deps/impl2.hpp"

int compute_result2(double z) {
    return static_cast<int>(z);
}

int dummy_function(int x) {
    return x + 100;
}

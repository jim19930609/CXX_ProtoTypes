//
//  impl.cpp
//  TestStaticLib
//
//  Created by Zhanlue Yang on 2023/1/6.
//

#include "deps/impl.hpp"
#include "deps/impl2.hpp"
#include "deps/dummy_impl.hpp"

int compute_result(float x) {
    double z = static_cast<double>(x);
    return compute_result2(z);
}

int compute_result_dummy(float x) {
    return static_cast<int>(x);
}

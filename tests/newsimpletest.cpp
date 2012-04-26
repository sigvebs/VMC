/* 
 * File:   newsimpletest.cpp
 * Author: sigve
 *
 * Created on 26.apr.2012, 13:10:25
 */

#include <stdlib.h>
#include <iostream>
#include "QD/QD_Orbital.h"

/*
 * Simple C++ Test Suite
 */

void testEvaluate() {
    rowvec p0(1,2);
    p0(0) = 1;
    p0(1) = 2;
    int p1 = 0;
    int p2 = 0;
    QD_Orbital qD_Orbital(2,1,1);
    double result = qD_Orbital.evaluate(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testEvaluate (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testEvaluate (newsimpletest)" << std::endl;
    testEvaluate();
    std::cout << "%TEST_FINISHED% time=0 testEvaluate (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}


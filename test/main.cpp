#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <aerodynamics.h>


/**
 * Doctest implementation tests.
 * aerodynamics.h
 */

TEST_CASE("Dynamic Viscosity Calculation Test") {
    CHECK(uavcalc::aerodynamics::dynamicViscosity(288.15) == 1.802e-5);
}

TEST_CASE("Kinematic Viscosity Calculation Test") {
    CHECK(uavcalc::aerodynamics::kinematicViscosity(288.15, 0) == 1.4673469387755102e-5);
}

TEST_CASE("Reynolds Number Calculation Test") {
    CHECK(uavcalc::aerodynamics::reynoldsNumber(1.4673469387755102e-5, 0, 0, 0) == 0);
}

/**
 * Tests are must be very reliable.
 * Docs must contain the sources of the test data.
 */
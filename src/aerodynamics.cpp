/**
 * Copyright (c) 2025 Tuygun Unmanned Systems
 * This file is part of the UAVCalc project and is licensed under the terms of the MIT license.
 * author: Hüseyin Karakaya
 * email: karakayahuseyin023@gmail.com
 * date: 2025-03-15
 */

#include <aerodynamics.h>

namespace uavcalc::aerodynamics
{
    double waterVapourPressure(double &temperature) 
    {
        temperature -= 273.15; // Convert from Kelvin to Celsius

        double p = (c0 + temperature * 
                (c1 + temperature * 
                (c2 + temperature * 
                (c3 + temperature * 
                (c4 + temperature * 
                (c5 + temperature * 
                (c6 + temperature * 
                (c7 + temperature * 
                (c8 + temperature * 
                (c9))))))))));
                
        return Eso / pow(p, 8);
    }

    double absoluteAirPressure(const double &temperature, 
                               const double &altitude)
    {
        return STANDARD_AIR_PRESSURE * exp(-1 * (GRAVITATIONAL_ACCELERATION * altitude) / 
            (UNIVERSAL_GAS_CONST * (temperature)));
    }

    double dryAirDensity(const double &temperature)
    {
        return (STANDARD_AIR_PRESSURE) / ((UNIVERSAL_GAS_CONST / DRYAIR_MOLAR_MASS) * STANDARD_AIR_TEMPERATURE);
    }

    double dryAirDensity(const double &temperature,
                         const double &altitude)
    {
        return ((STANDARD_AIR_PRESSURE * DRYAIR_MOLAR_MASS) / (UNIVERSAL_GAS_CONST * STANDARD_AIR_TEMPERATURE)) * 
            pow(((1 - ((LAPSE_RATE * altitude) / STANDARD_AIR_TEMPERATURE))), 
            ((GRAVITATIONAL_ACCELERATION * DRYAIR_MOLAR_MASS) / (UNIVERSAL_GAS_CONST * LAPSE_RATE) - 1));
    }

    double humidAirDensity(double &temperature, 
                           const double &altitude) 
    {
        return (absoluteAirPressure(temperature, altitude) / (DRYAIR_GAS_CONST * temperature)) +
            (waterVapourPressure(temperature) / (WATERVAPOUR_GAS_CONST * temperature));
    }

    double dynamicViscosity(const double &temperature) 
    {
        return STANDARD_DYNAMIC_VISCOSITY * ((0.555 * STANDARD_AIR_TEMPERATURE + SUTHERLAND_CONST) / 
                (0.555 * temperature + SUTHERLAND_CONST)) * pow((temperature / STANDARD_AIR_TEMPERATURE), 1.5);
    }

    double kinematicViscosity(const double &temperature,
                              const double &altitude)
    {
        return dynamicViscosity(temperature) / dryAirDensity(temperature, altitude);
    }

    double reynoldsNumber(const double &kinematicViscosity, 
                          const double &humidity, 
                          const double &flowSpeed, 
                          const double &characteristicLength)
    {
        return flowSpeed * characteristicLength / kinematicViscosity;
    }

    // Implement the second overload of Reynolds number calculation
    double reynoldsNumber(const double &dynamicViscosity,
                          const double &humidity, 
                          const double &fluidDensity, 
                          const double &flowSpeed, 
                          const double &characteristicLength)
    {
        return (fluidDensity * flowSpeed * characteristicLength) / dynamicViscosity;
    }
    
} // namespace uavcalc::aerodynamics

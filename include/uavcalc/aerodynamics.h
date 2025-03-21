/**
 * Copyright (c) 2025 Tuygun Unmanned Systems
 * This file is part of the UAVCalc project and is licensed under the terms of the MIT license.
 * 
 * author: Hüseyin Karakaya
 * email: karakayahuseyin023@gmail.com
 * date: 2025-03-15
 */

#pragma once

#ifndef AERODYNAMICS_H
#define AERODYNAMICS_H

#include <cmath>

namespace uavcalc::aerodynamics
{
    // Fundamental physical constants
    const double UNIVERSAL_GAS_CONST = 8.3143;                   
    const double GRAVITATIONAL_ACCELERATION = 9.81;              

    // Standard atmospheric conditions at sea level
    const double STANDARD_AIR_TEMPERATURE = 288.15;              
    const double STANDARD_AIR_DENSITY = 1.225;                   
    const double STANDARD_AIR_PRESSURE = 101325;                 

    // Air properties
    const double AIR_THERMAL_EXPANSION_COEFFICIENT = 0.003661;   

    // Viscosity-related constants
    const double STANDARD_DYNAMIC_VISCOSITY = 1.802e-5;          
    const double SUTHERLAND_CONST = 119.8;                       

    // Gas component properties
    const double DRYAIR_MOLAR_MASS = 0.0289652;                  
    const double BOLTZMANN_CONST = 1.380649e-23;                 
    const double LAPSE_RATE = 0.0065;                            

    // Water vapor properties
    const double WATERVAPOUR_MOLAR_MASS = 0.018016;              
    const double DRYAIR_GAS_CONST = 287.058;                     
    const double WATERVAPOUR_GAS_CONST = 461.495;                

    // Herman Wobus equation coefficients for water vapor pressure
    const double Eso = 6.1078;                                   
    const double c0 = 0.99999683;
    const double c1 = -0.90826951e-2;
    const double c2 = 0.78736169e-4;
    const double c3 = -0.61117958e-6;
    const double c4 = 0.43884187e-8;
    const double c5 = -0.29883885e-10;
    const double c6 = 0.21874425e-12;
    const double c7 = -0.17892321e-14;
    const double c8 = 0.11112018e-16;
    const double c9 = -0.30994571e-19;
    
    /**
     * Calculates the water vapor pressure at a given temperature using the Herman Wobus equation.
     *
     * @param temperature The temperature in Kelvin.
     *
     * @return The water vapor pressure in Pascals.
     */

    double waterVapourPressure(const double &temperature);

    /**
     * Calculates the absolute air pressure at a given altitude and temperature using the barometric formula.
     *
     * @param temperature The temperature in Kelvin.
     * @param altitude The altitude in meters.
     *
     * @return The absolute air pressure in Pascals.
     */

    double absoluteAirPressure(const double &temperature,
                               const double &altitude);

    /**
     * Calculates the dry air density at a given temperature.
     *
     * @param temperature The temperature in Kelvin.
     *
     * @return The dry air density in kilograms per cubic meter.
     */

    double dryAirDensity(const double &temperature);

    /**
     * Calculates the air density at a given location given the temperature and altitude.
     *
     * @param temperature The temperature in Kelvin.
     * @param altitude The altitude in meters.
     *
     * @return The air density in kilograms per cubic meter.
     */

    double dryAirDensity(const double &temperature,
                         const double &altitude);

    /**
     * Calculates the density of humid air at a given temperature and altitude.
     *
     * @param temperature The temperature in Kelvin.
     * @param altitude The altitude in meters.
     *
     * @return The density of humid air in kilograms per cubic meter.
     */

    double humidAirDensity(const double &temperature,
                           const double &altitude);

    /**
     * Calculates the dynamic viscosity of air at a given temperature.
     *
     * @param temperature The temperature in Kelvin.
     *
     * @return The dynamic viscosity in Pascal-seconds.
     */

    double dynamicViscosity(const double &temperature);

    /**
     * Calculates the kinematic viscosity of air at a given temperature and altitude.
     *
     * @param temperature The temperature in Kelvin.
     * @param altitude The altitude in meters.
     *
     * @return The kinematic viscosity in square meters per second.
     */

    double kinematicViscosity(const double &temperature,
                              const double &altitude);

    /**
     * Calculates the Reynolds number using kinematic viscosity.
     *
     * @param kinematicViscosity The kinematic viscosity of the fluid.
     * @param humidity The humidity ratio.
     * @param flowSpeed The flow speed in meters per second.
     * @param characteristicLength The characteristic length of the body exposed to flow in meters.
     * @param kinematicViscosity The kinematic viscosity of the fluid.
     *
     * @return The Reynolds number.
     */

    double reynoldsNumber(const double &kinematicViscosity,
                          const double &humidity, 
                          const double &flowSpeed, 
                          const double &characteristicLength);

    /**
     * Calculates the Reynolds number using dynamic viscosity.
     *
     * @param dynamicViscosity The dynamic viscosity of the fluid.
     * @param humidity The humidity ratio.
     * @param fluidDensity The density of the fluid in kilograms per cubic meter.
     * @param flowSpeed The flow speed in meters per second.
     * @param characteristicLength The characteristic length in meters.
     * @param dynamicViscosity The dynamic viscosity of the fluid.
     *
     * @return The Reynolds number.
     */

    double reynoldsNumber(const double &dynamicViscosity,
                          const double &humidity, 
                          const double &fluidDensity, 
                          const double &flowSpeed,
                          const double &characteristicLength);

} // namespace uavcalc::aerodynamics

#endif // AERODYNAMICS_H

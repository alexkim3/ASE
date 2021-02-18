#include "Spring.h"

/// @brief multiple spring-mass system
/// Modified from :-
/// Khan Academy. 2021. Simulation | Pixar in a Box | Computing |
/// Khan Academy. [online] Available at:
/// <https://www.khanacademy.org/computing/pixar/simulation/>
/// [Accessed 1 February 2021].
void Spring::simulate()
{
    // Mass 1 Spring Force
    float mass1SpringForceY = -k*(mass1PositionY - anchorY);
    float mass1SpringForceX = -k*(mass1PositionX - anchorX);

    // Mass 2 Spring Force
    float mass2SpringForceY = -k*(mass2PositionY - mass1PositionY);
    float mass2SpringForceX = -k*(mass2PositionX - mass1PositionX);

    // Mass 1 daming
    float mass1DampingForceY = damping * mass1VelocityY;
    float mass1DampingForceX = damping * mass1VelocityX;

    // Mass 2 daming
    float mass2DampingForceY = damping * mass2VelocityY;
    float mass2DampingForceX = damping * mass2VelocityX;

    // Mass 1 net force
    float mass1ForceY = mass1SpringForceY + mass * gravity - mass1DampingForceY - mass2SpringForceY + mass2DampingForceY;

    float mass1ForceX = mass1SpringForceX - mass1DampingForceX - mass2SpringForceX + mass2DampingForceX;

    // Mass 2 net force
    float mass2ForceY = mass2SpringForceY + mass * gravity - mass2DampingForceY;
    float mass2ForceX = mass2SpringForceX - mass2DampingForceX;

    // Mass 1 acceleration
    float mass1AccelerationY = mass1ForceY/mass;
    float mass1AccelerationX = mass1ForceX/mass;

    // Mass 2 acceleration
    float mass2AccelerationY = mass2ForceY/mass;
    float mass2AccelerationX = mass2ForceX/mass;

    // Mass 1 velocity
    mass1VelocityY = mass1VelocityY + mass1AccelerationY * timeStep;
    mass1VelocityX = mass1VelocityX + mass1AccelerationX * timeStep;

    // Mass 2 velocity
    mass2VelocityY = mass2VelocityY + mass2AccelerationY * timeStep;
    mass2VelocityX = mass2VelocityX + mass2AccelerationX * timeStep;

    // Mass 1 position
    mass1PositionY = mass1PositionY + mass1VelocityY * timeStep;
    mass1PositionX = mass1PositionX + mass1VelocityX * timeStep;

    // Mass 2 position
    mass2PositionY = mass2PositionY + mass2VelocityY * timeStep;
    mass2PositionX = mass2PositionX + mass2VelocityX * timeStep;
    point2[1] = mass1PositionY;
    point2[0] = mass1PositionX;
    point3[1] = mass2PositionY;
    point3[0] = mass2PositionX;

}

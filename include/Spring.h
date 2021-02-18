#include "ngl/Vec3.h"

struct Spring
{
  ngl::Vec3 point1 = {0.f, 0.f, 0.f};
  ngl::Vec3 point2 = {30.f, 0.f, 0.f};
  ngl::Vec3 point3 = {-30.f, 0.f, 0.f};

  // INITIAL SETTINGS
  float gravity = -5;
  float mass = 10;

  // Mass 1
  float mass1PositionY = point2[1];
  float mass1PositionX = point2[0];
  float mass1VelocityY = 0;
  float mass1VelocityX = 0;

  // Mass 2
  float mass2PositionY = point3[1];
  float mass2PositionX = point3[0];
  float mass2VelocityY = 0;
  float mass2VelocityX = 0;


  double timeStep = 0.28;
  float anchorX = 0;
  float anchorY = 0;
  float k = 2;
  float damping = 4;
  void simulate();
};

#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce;
    Vector2 centerMass;
    int total = 0;

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood
    for (int i = 0; i < neighborhood.size(); i++)
    {
        float dist = boid->getVelocity().getDistance(boid->getPosition(), neighborhood[i]->getPosition());
        if (dist < boid->getDetectionRadius())
        {
            centerMass += neighborhood[i]->getPosition();
            total++;
        }
    }
    if(total != 0) 
        centerMass /= total;
   
    cohesionForce = centerMass - boid->getPosition();

    return Vector2::normalized(cohesionForce);
}
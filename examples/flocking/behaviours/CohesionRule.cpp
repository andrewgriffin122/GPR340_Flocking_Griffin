#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce;

    Vector2 centerMass;
    float dist;

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood
    for (int i = 0; i < neighborhood.size(); i++)
    {
       //something something detection radius
        dist = boid->getPosition().getDistance(boid->getPosition(), neighborhood[i]->getPosition());

        if (dist <= boid->getDetectionRadius())
        {
            centerMass += neighborhood[i]->getPosition();
        }
    }
    centerMass / neighborhood.size();
    //this aint it bud
    cohesionForce = centerMass - boid->getPosition();

    return cohesionForce;
}
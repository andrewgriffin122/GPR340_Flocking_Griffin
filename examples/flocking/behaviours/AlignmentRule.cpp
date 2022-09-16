#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2 AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 averageVelocity = Vector2::zero();
    int total = 0;

    // todo: add your code here to align each boid in a neighborhood
    // hint: iterate over the neighborhood
    for (int i = 0; i < neighborhood.size(); i++)
    {
        //Check if other boid's are in dectection radius
        float dist = boid->getVelocity().getDistance(boid->getPosition(), neighborhood[i]->getPosition());
        if (dist < boid->getDetectionRadius())
        {
            averageVelocity += neighborhood[i]->getVelocity();
            total++;
        }
    }
    if(total != 0)
        averageVelocity /= total;

    return Vector2::normalized(averageVelocity);
}
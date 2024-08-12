#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

class MovementSystem
{
    public:
        MovementSystem()
        {
            // TODO:
            // RequireComponent<TransformComponent>();
            // RequireComponent<VelocityComponent>();
        }
        void Update()
        {
            // for (auto entity : GetEntities())
            // {
            //     auto& transform = entity.GetComponent<TransformComponent>();
            //     auto& velocity = entity.GetComponent<VelocityComponent>();
            //     transform.position += velocity.velocity * Time::deltaTime;
            // }
        }
};
#endif
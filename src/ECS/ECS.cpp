#include "ECS.h"


int Entity::GetId() const 
{
    return id;
};

void ECS_System::AddEntityToSystem(Entity entity)
{
    entities.push_back(entity);
}

void ECS_System::RemoveEntityFromSystem(Entity entity)
{
    entities.erase(std::remove_if(entities.begin(), entities.end(), [&entity](Entity other)
        {
        return entity.GetId() == other.GetId();
        }
    ), entities.end());
}

std::vector<Entity> ECS_System::GetSystemEntities() const
{
    return entities;
}

const Signature& ECS_System::GetComponentSignature() const
{
    return componentSignature;
}

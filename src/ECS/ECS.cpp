#include "ECS.h"


int Entity::GetId() const 
{
    return id;
};

void System::AddEntityToSystem(Entity entity)
{
    entities.push_back(entity);
}

void System::RemoveEntityFromSystem(Entity entity)
{
    entities.erase(std::remove_if(entities.begin(), entities.end(), [&entity](Entity other){
        return entity.GetId() == other.GetId();
    }), entities.end());

    for (Entity e : entities)
    {
        if (entity.GetId() == e.GetId())
        {
            entities.erase(entity);
            break;
        }
    }
}

std::vector<Entity> System::GetSystemEntities() const
{
    return entities;
}

const Signature& System::GetComponentSignature() const
{
    return componentSignature;
}

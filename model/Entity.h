class Position
{
public:
  float x;
  float y;

  Position();

  Position(float x, float y);
};

class Entity
{
public:
  Position position;
  virtual void update(float deltaTime) = 0; // Update the entity's state
  virtual void interact(Entity &other) = 0; // Handle interactions

  Entity(Position initPosition);
};
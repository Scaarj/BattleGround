#include "wall.h"

Wall::Wall(b2World &world, float x, float y, float width, float height)
    : BasicUnit(QString("wall"), world, x + width / 2, y + height / 2),
      _width(width),
      _height(height) {
  b2PolygonShape *boxShape = new b2PolygonShape;
  _bodyDef.type = b2_staticBody;
  _body = world.CreateBody(&_bodyDef);
  boxShape->SetAsBox(_width / 2, _height / 2);
  _body->CreateFixture(boxShape, 0.f);
}

float Wall::width() const { return _width; }

float Wall::height() const { return _height; }

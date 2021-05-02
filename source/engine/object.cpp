#include "object.h"

using namespace engine;

Object::Object(ObjectSize::SizeType size)
    : _hitBox(ObjectSize::getHitbox(size)) {}

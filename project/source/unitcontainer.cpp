#include "unitcontainer.h"

#include <QDebug>

UnitContainer::UnitContainer(QObject *object) : QObject(object) {}

void UnitContainer::collect(BasicUnit *unit) {
  if (!unit) {
    return;
  }

  emit createObject(_unitIndex, unit->type(), unit->x(), unit->y(),
                    unit->width(), unit->height());
  _objects[_unitIndex] = std::shared_ptr<BasicUnit>(unit);
  _unitIndex++;
}

const std::map<int, std::shared_ptr<BasicUnit> > &UnitContainer::objects()
    const {
  return _objects;
}

void UnitContainer::update() {
  if (_objects.empty()) {
    return;
  }

  for (auto &it : _objects) {
    int index = it.first;
    auto unit = it.second;
    if (unit->bodyType() != b2_staticBody) {
      emit moveObjectTo(index, unit->type(), unit->x(), unit->y(),
                        unit->angle());
    }
  }
}

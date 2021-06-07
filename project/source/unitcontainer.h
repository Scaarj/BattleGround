#pragma once

#include <QObject>
#include <map>
#include <memory>

#include "basicunit.h"

class UnitContainer : public QObject {
  Q_OBJECT
 public:
  UnitContainer(QObject* object);

  void collect(BasicUnit* unit);
  const std::map<int, std::shared_ptr<BasicUnit>>& objects() const;

  void update();

 signals:

  void createObject(int id, const QString& type, float x, float y, float width,
                    float height);

  void moveObjectTo(int id, const QString& type, float x, float y, float angle);

 private:
  int _unitIndex;
  std::map<int, std::shared_ptr<BasicUnit>> _objects;
};

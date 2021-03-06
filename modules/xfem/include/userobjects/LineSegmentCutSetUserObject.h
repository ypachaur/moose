//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef LINESEGMENTCUTSETUSEROBJECT_H
#define LINESEGMENTCUTSETUSEROBJECT_H

#include "GeometricCut2DUserObject.h"

// Forward declarations
class LineSegmentCutSetUserObject;

template <>
InputParameters validParams<LineSegmentCutSetUserObject>();

class LineSegmentCutSetUserObject : public GeometricCut2DUserObject
{
public:
  LineSegmentCutSetUserObject(const InputParameters & parameters);

  virtual const std::vector<Point>
  getCrackFrontPoints(unsigned int num_crack_front_points) const override;

protected:
  std::vector<Real> _cut_data;
};

#endif // LINESEGMENTCUTSETUSEROBJECT_H

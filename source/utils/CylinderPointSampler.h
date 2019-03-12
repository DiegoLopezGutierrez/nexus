// ----------------------------------------------------------------------------
///  \file   CylinderPointSampler.h
///  \brief  Generator of random points in a cylinder.
///
///  \author   Javier Mu�oz Vidal <jmunoz@ific.uv.es>
///  \date     2 November 2009
///  \version  $Id$
///
///  Copyright (c) 2009-2013 NEXT Collaboration. All rights reserved.
// ----------------------------------------------------------------------------

#ifndef CYLINDER_POINT_SAMPLER_H
#define CYLINDER_POINT_SAMPLER_H

#include <G4ThreeVector.hh>
#include <G4RotationMatrix.hh>


namespace nexus {
  
  /// Generator of random positions in a cylinder

  class CylinderPointSampler
  {
  public:
    /// Constructor
    CylinderPointSampler(G4double inner_rad, G4double inner_length,
			    G4double body_thickness, G4double endcaps_thickness,
			    G4ThreeVector origin=G4ThreeVector(0,0,0),
			    G4RotationMatrix* rotation=0);
    /// Destructor
    ~CylinderPointSampler();

    /// Returns vertex within region <region> of the chamber
    G4ThreeVector GenerateVertex(const G4String& region);

    /// Returns the global (without rotation and translation)
    /// vertex. Useful for volume checks.
    void GetGlobalPosition(G4ThreeVector& vertex,
			   G4double global_origin);

  private:
    G4double GetRadius(G4double inner, G4double outer);
    G4double GetPhi();
    G4double GetLength(G4double origin, G4double max_length);
    G4ThreeVector RotateAndTranslate(G4ThreeVector position);

  private:
    /// Default constructor is hidden
    CylinderPointSampler();

  private:
    G4double _inner_length, _inner_radius;        ///< Internal dimensions
    G4double _body_thickness, _endcaps_thickness; ///< Thicknesses
    G4double _outer_radius;                       ///< External radius

    G4double _perc_body_surf, _perc_body_vol; ///< Cylinder body percentages

    G4ThreeVector _origin; ///< Origin of coordinates
    G4RotationMatrix* _rotation; ///< Rotation of the cylinder (if any)

  };
  
} // namespace nexus

#endif

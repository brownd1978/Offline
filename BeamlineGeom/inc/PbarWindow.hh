#ifndef BeamlineGeom_PbarWindow_hh
#define BeamlineGeom_PbarWindow_hh

//
// Class to represent the collimators. Position is relative to
// the corresponding TS straight section
//
#include "CLHEP/Vector/ThreeVector.h"
#include <vector>

namespace mu2e {

  class PbarWindow {

  friend class BeamlineMaker;

  public:

    PbarWindow() : _rOut(0.), _halfZ(0.) { }

    // use compiler-generated copy c'tor, copy assignment, and d'tor

    std::string shape() const { return _shape; }
    double halfLength() const { return _halfZ; }
    CLHEP::Hep3Vector const& getLocal() const { return _origin; }
    std::string material() const { return _material; }
    int         version()  const { return _version; }

    // The following are primarily for version 1 and 2
    double rOut()   const  { return _rOut; }
    double getY0()  const  { return _y0 ; };
    double getY1()  const  { return _y1 ; };
    double getDZ0() const  { return _dz0; };
    double getDZ1() const  { return _dz1; };
    double getWedgeZOffset() const { return _wedgeZOffset; }

    void set(double halfZ, CLHEP::Hep3Vector origin) {
      _halfZ  = halfZ;
      _origin = origin; 
    }

    // The following are for version 3, which has the "wedge" built from
    // strips of Be.
    double    diskRadius()        const  { return _diskRadius;}
    int       nStrips()           const  { return _nStrips;}
    double    width()             const  { return _width;}
    double    stripThickness()    const  { return _stripThickness;}
    std::vector<double> heights() const  { return _stripHeights;}

  private:

    std::string _shape;
    std::string _material;

    double _rOut;
    double _halfZ;
    CLHEP::Hep3Vector _origin;

    int    _version;

    double _y0 ;
    double _y1 ;
    double _dz0;
    double _dz1;
    double _wedgeZOffset;

    double _diskRadius;
    int    _nStrips;
    double _width;
    double _stripThickness;
    std::vector<double> _stripHeights;


};

}
#endif /* BeamlineGeom_PbarWindow_hh */

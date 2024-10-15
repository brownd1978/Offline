#ifndef TrackerGeom_StrawProperties_hh
#define TrackerGeom_StrawProperties_hh
namespace mu2e {
  struct StrawProperties {
    double _strawInnerRadius= 0;
    double _strawOuterRadius= 0;
    double _strawWallThickness= 0;
    double _outerMetalThickness= 0;
    double _innerMetal1Thickness= 0;
    double _innerMetal2Thickness= 0;
    double _wireRadius= 0;
    double _wirePlateThickness= 0;
    double strawInnerRadius() const{ return _strawInnerRadius; }
    double strawOuterRadius() const{ return _strawOuterRadius; }
    double strawWallThickness() const{ return _strawWallThickness; }
    double outerMetalThickness() const{ return _outerMetalThickness; }
    double innerMetal1Thickness() const{ return _innerMetal1Thickness; }
    double innerMetal2Thickness() const{ return _innerMetal2Thickness; }
    double wireRadius()           const { return _wireRadius; }
    double wirePlateThickness()   const { return _wirePlateThickness; }

  };
}
#endif

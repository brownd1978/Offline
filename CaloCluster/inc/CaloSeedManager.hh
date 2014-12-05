//
// Original author B.Echenard
//

#ifndef CaloCluster_CaloSeedManager_HH_
#define CaloCluster_CaloSeedManager_HH_


// Mu2e includes
#include "RecoDataProducts/inc/CaloCrystalHit.hh"


// C++ includes
#include <unordered_map>
#include <map>


namespace mu2e {





    class CaloSeedManager{


	 public:


             enum SeedType{Energy,Time};

             typedef std::list<CaloCrystalHit const*> CaloCrystalList;
             typedef std::vector<CaloCrystalHit const*> CaloCrystalVec;


  	     CaloSeedManager(int size, SeedType seedMode =  SeedType::Energy ) : _seedMap(size), _seedMode(seedMode) {}; 
             ~CaloSeedManager(){};


	     void add(CaloCrystalHit const&);
             
	     CaloCrystalHit const* seed();
             
	     void checkSeedbyList(CaloCrystalList const& crystalsInCluster, std::vector<CaloCrystalVec> const& idHitMap);
             void checkSeedbyId(int iId, CaloCrystalVec const& hits);
      
             void dumpSeed();
	
	
	     
	 private:
 	     
	     std::vector<CaloCrystalHit const*> _seedMap;
	     SeedType _seedMode;

  
    };


} // end namespace mu2e

#endif
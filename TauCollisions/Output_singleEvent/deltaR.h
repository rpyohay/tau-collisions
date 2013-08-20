#ifndef PhysicsTools_Utilities_deltaR_h
#define PhysicsTools_Utilities_deltaR_h
/* functions to compute deltaR
 *
 * Ported from original code in RecoJets 
 * Fedor Ratnikov, FNAL
 */
#include "deltaPhi.h"
#include <cmath>

namespace reco {
 
  inline double deltaR2(double eta1, double phi1, double eta2, double phi2) {
    double deta = eta1 - eta2;
    double dphi = deltaPhi(phi1, phi2);
    return deta*deta + dphi*dphi;
  }
  
  inline double deltaR(double eta1, double phi1, double eta2, double phi2) {
    return sqrt(deltaR2 (eta1, phi1, eta2, phi2));
  }
  
  template<typename T1, typename T2>
  double deltaR2(const T1 & t1, const T2 & t2) {
    return deltaR2(t1.eta(), t1.phi(), t2.eta(), t2.phi());
  } 
  
  template<typename T1, typename T2>
  double deltaR(const T1 & t1, const T2 & t2) {
    return deltaR(t1.eta(), t1.phi(), t2.eta(), t2.phi());
  } 

}

template<typename T1, typename T2 = T1>
struct DeltaR {
  double operator()( const T1 & t1, const T2 & t2 ) const {
    return reco::deltaR(t1, t2);
  }
};
#endif

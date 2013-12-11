/* ----------------------------------------------------------------------
   SPARTA - Stochastic PArallel Rarefied-gas Time-accurate Analyzer
   http://sparta.sandia.gov
   Steve Plimpton, sjplimp@sandia.gov, Michael Gallis, magalli@sandia.gov
   Sandia National Laboratories

   Copyright (2012) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level SPARTA directory.
------------------------------------------------------------------------- */

#ifdef FIX_CLASS

FixStyle(balance,FixBalance)

#else

#ifndef SPARTA_FIX_BALANCE_H
#define SPARTA_FIX_BALANCE_H

#include "stdio.h"
#include "fix.h"

namespace SPARTA_NS {

class FixBalance : public Fix {
 public:
  FixBalance(class SPARTA *, int, char **);
  ~FixBalance();
  int setmask();
  void init();
  void end_of_step();
  double compute_scalar();
  double compute_vector(int);
  double memory_usage();

 private:
  int me,nprocs;
  double thresh;
  int bstyle,rcbwt;

  double imbnow;                // current imbalance factor
  double imbprev;               // imbalance factor before last rebalancing
  double imbfinal;              // imbalance factor after last rebalancing
  int maxperproc;               // max atoms on any processor

  class RanPark *random;
  class RCB *rcb;

  double imbalance_nlocal(int &);
};

}

#endif
#endif
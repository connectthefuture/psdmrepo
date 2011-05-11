//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Test root main functionality which is going to be used in RootHist packadge
//
// Author List:
//      Mikhail Dubrovin
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------

#include <string>
#include <iostream>
//#include <sstream>

//#include <stdio.h> // for C style printf

//----------------------
// Base Class Headers --
//----------------------

#include "RootHist/RootHManager.h"
#include "PSHist/HManager.h"
#include "PSHist/Axis.h"
#include "PSHist/H1.h"
#include "PSHist/H2.h"
#include "PSHist/Tuple.h"
#include "PSHist/Column.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

#include "root/TRandom.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

using std::cout;
using std::endl;

//using namespace PSTime;

int main ()
{
  cout << "Stars ex_PSHist_1 : main()" << endl; 

  double edges[]={0, 0.05, 0.1, 0.2, 0.25, 0.3, 0.5, 0.55, 0.7, 0.9, 1};

  cout << "sizeof(edges) =" << sizeof(edges) << endl;     


  // Axis
  PSHist::Axis axis1(60,0,1);
  PSHist::Axis axis2(40,0,1);
  PSHist::Axis axis3(10,edges);
  PSHist::Axis axis4(100,0,1);

  PSHist::HManager *hMan = new RootHist::RootHManager("pshist-test.root", "RECREATE");


  // H1 - 1d histograms
  PSHist::H1 *pH1_1 = hMan->hist1i( "H1_N0001", "My his1d 1 title^{#alpha}", 100, 0., 1.);
  PSHist::H1 *pH1_2 = hMan->hist1f( "H1_N0002", "My his1d 2 title^{#beta}",  axis4 );
  PSHist::H1 *pH1_3 = hMan->hist1d( "H1_N0003", "My his1d 3 title^{#gamma}", 100, 0., 1.01);
  PSHist::H1 *pH1_4 = hMan->hist1d( "H1_N0004", "My his1d 4 title^{#delta}", 10, edges);


  // H2 - 2d histograms
  PSHist::H2 *pH2_1 = hMan->hist2i( "H2_N0001", "My his2d 1 title^{#theta}",  axis1, axis2 ); 
  PSHist::H2 *pH2_2 = hMan->hist2f( "H2_N0002", "My his2d 2 title^{#phi}",    axis1, axis3 ); 
  PSHist::H2 *pH2_3 = hMan->hist2d( "H2_N0003", "My his2d 3 title^{#eta}",    axis2, axis2 ); 
  PSHist::H2 *pH2_4 = hMan->hist2d( "H2_N0004", "My his2d 4 title^{#lambda}", axis3, axis2 ); 


  // Profile - 1d profile histograms
  PSHist::Profile *pP1_1 = hMan->prof1( "P1_N0001", "My profile 1 title^{#psi}",     60, 0, 1,  0, 1 ); 
  PSHist::Profile *pP1_2 = hMan->prof1( "P1_N0002", "My profile 2 title^{#iota}",    axis2,     0, 1 ); 
  PSHist::Profile *pP1_3 = hMan->prof1( "P1_N0003", "My profile 3 title^{#kappa}",   10, edges, 0, 1 ); 
  PSHist::Profile *pP1_4 = hMan->prof1( "P1_N0004", "My profile 4 title^{#lambda}",  axis3,     0, 1 ); 


  // Tuple
  PSHist::Tuple *pTuple_1 = hMan->tuple( "TUPLE_N1", "My tuple title^{#alpha}" ); 

  // Column (parameter(s)) for the tuple
  // The ROOT-style constructor
  double val;
  PSHist::Column *pColumn_1 = pTuple_1->column( "C_N0001", &val, "EBEAM/D" );

  float freq;
  PSHist::Column *pColumn_2 = pTuple_1->column( "C_N0002", &freq, "Freq/F" );



  cout << "Fill histograms" << endl;
	for (int i=0; i<10000; i++)
	  {
            pH1_1 -> fill( gRandom->Rndm(1)        ); // Uniform distribution on [0,1]
            pH1_2 -> fill( gRandom->Gaus(0.5, 0.1) ); // Gaussian for mu and sigma
            pH1_3 -> fill( double(0.0001*i), double(i) );
            pH1_4 -> fill( gRandom->Rndm(1)        );

            pH2_1 -> fill( gRandom->Gaus(0.5, 0.1), gRandom->Rndm(1) );
            pH2_2 -> fill( gRandom->Gaus(0.5, 0.1), gRandom->Rndm(1) );
            pH2_3 -> fill( gRandom->Gaus(0.4, 0.1), gRandom->Gaus(0.6, 0.2) );
            pH2_4 -> fill( gRandom->Gaus(0.3, 0.2), gRandom->Gaus(0.7, 0.1) );

            pP1_1 -> fill( gRandom->Gaus(0.5, 0.1), gRandom->Rndm(1) );
            pP1_2 -> fill( gRandom->Gaus(0.5, 0.1), gRandom->Rndm(1) );
            pP1_3 -> fill( gRandom->Gaus(0.4, 0.1), gRandom->Gaus(0.6, 0.2) );
            pP1_4 -> fill( gRandom->Gaus(0.3, 0.2), gRandom->Gaus(0.7, 0.1) );

	    val  = gRandom->Gaus(2.5, 0.1);
	    freq = gRandom->Gaus(1.5, 0.1);
            pTuple_1 -> fill();
	  }

  hMan -> write();

  delete hMan;  // close file

}


/*

int garbage()
{

  TFile *pfile = new TFile("file.root", "RECREATE", "Created for you by RootManager" );
  cout << "Open Root file with name : " << pfile ->GetName() << endl;


  cout << "Create histogram" << endl;
  TH1D *pHis1 = new TH1D("pHis1","My comment to TH1D", 100, 0.5, 100+0.5);


  cout << "Reset and fill histogram" << endl;
        pHis1 -> Reset();
	for (int i=0 ;i<10000;i++)
	  {
            double random = 100 * gRandom->Rndm(1);

	    //pHis1 -> Fill( double(i), 0.1*i );
	    pHis1 -> Fill( random );

	  }


  cout << "Write histogram in file" << endl;
        pHis1 -> Write();


// Define some simple structures
   typedef struct {float x,y,z;} POINT;

   static POINT point;


  cout << "Create tree" << endl;
//TTree *t3 = (TTree*)->Get("t3"); // if tuple existed
  TTree *ptree = new TTree("ptree", "My comment to TTree");


  cout << "Create  a couple of branches" << endl;
  float new_v;
  TBranch *pbranch = ptree->Branch("new_v", &new_v, "new_v/F");

                     ptree->Branch("point",&point,"x:y:z");


  cout << "Fill branch" << endl;
  for (int i = 0; i < 10000; i++){

      new_v   = gRandom->Gaus(0, 1);

      point.x = gRandom->Gaus(1, 1); 
      point.y = gRandom->Gaus(2, 1); 
      point.z = gRandom->Gaus(3, 1); 

      ptree->Fill();
      //pbranch->Fill();
  }


  cout << "Write tree in file" << endl;
  ptree -> Write();

  
  cout << "Close file" << endl;
  pfile -> Close();


  //cout << "Delete all objects" << endl;
  //delete pHis1;
  //delete ptree;

  return 0;

}


*/

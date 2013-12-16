//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: Mu2eVisCommands.hh,v 1.1 2013/12/16 21:58:24 genser Exp $
// $Author: genser $
// $Date: 2013/12/16 21:58:24 $
//
// Original author KLG
//
// Modeled after G4VisCommandSceneHandler...
//
#ifndef G4VISCOMMANDSSCENEHANDLER_HH
#define G4VISCOMMANDSSCENEHANDLER_HH

#include "G4VVisCommand.hh"

class G4UIcommand;
;

class Mu2eVisCommandSceneHandlerDrawEvent: public G4VVisCommand {
public:
  // Uses compiler defaults for copy constructor and assignment operator
  Mu2eVisCommandSceneHandlerDrawEvent();
  ~Mu2eVisCommandSceneHandlerDrawEvent();
  G4String GetCurrentValue(G4UIcommand* command);
  void SetNewValue(G4UIcommand* command, G4String newValue);
private:
  G4UIcommand* fpCommand;
};

#endif

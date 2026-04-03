/*
    This file is part of nutr.

    nutr is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    nutr is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with nutr.  If not, see <https://www.gnu.org/licenses/>.

        Copyright (C) 2020-2022 Udo Friman-Gayer and Oliver Papst
*/

#include <memory>
#include <vector>

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "DetectorConstruction.hh"

#include "BeamPipe.hh"
#include "CeBr3_2x2.hh"
#include "CollimatorRoom.hh"
#include "Filters.hh"
#include "GammaVault.hh"
#include "HPGe_Clover.hh"
#include "HPGe_Coaxial.hh"
#include "HPGe_Collection.hh"
#include "LeadShieldingUTR_70Ge_Kowalewski_LE.hh"
#include "MOLLY.hh"
#include "Mechanical.hh"
#include "ZeroDegreeMechanical.hh"

// Note: The order of the filters in the filter configuration is important,
// since the first filter in the list is the one that is closest to the
// detector. The second filter is the one that is closer to the target. This is
// important, because the Cu filter was placed behind the Pb filter to stop the
// Pb x-rays.

vector<Detector *> detectors = {
    new HPGe_Clover(
        "C1", HPGe_Clover_Collection::HPGe_Clover_4x50x80SEG2, 90. * deg,
        0. * deg, 8.00 * inch,
        {{{"G4_Cu", cu_clover_thin}, {"G4_Pb", pb_clover_thick}}, true}, {},
        0. * pi), // SN34
    new HPGe_Clover(
        "C3", HPGe_Clover_Collection::HPGe_Clover_4x50x80NS, 90. * deg,
        90. * deg, 8.00 * inch,
        {{{"G4_Cu", cu_clover_thin}, {"G4_Pb", pb_clover_thick}}, false}, {},
        0. * pi), // SN02
    new HPGe_Clover(
        "C5", HPGe_Clover_Collection::HPGe_Clover_4x50x80NS, 90. * deg,
        180. * deg, 8.00 * inch,
        {{{"G4_Cu", cu_clover_thin}, {"G4_Pb", pb_clover_thick}}, true}, {},
        0. * pi), // SN03
    new HPGe_Clover(
        "C7", HPGe_Clover_Collection::HPGe_Clover_CloverShare, 90. * deg,
        270. * deg, 8.00 * inch,
        {{{"G4_Cu", cu_clover_thin}, {"G4_Pb", pb_clover_thick}}, true}, {},
        0. * pi), // SN19
    new HPGe_Clover(
        "B1", HPGe_Clover_Collection::HPGe_Clover_4x50x80SEG2, 135. * deg,
        0. * deg, 8.00 * inch,
        {{{"G4_Cu", cu_clover_thin}, {"G4_Pb", pb_clover_thick}}, true}, {},
        0. * pi), // SN30
    new HPGe_Clover(
        "B2", HPGe_Clover_Collection::HPGe_Clover_4x50x80SEG2, 125.26 * deg,
        45. * deg, 8.00 * inch,
        {{{"G4_Cu", cu_clover_thin}, {"G4_Pb", pb_clover_thick}}, false}, {},
        0. * pi), // SN33
    new HPGe_Clover(
        "B3", HPGe_Clover_Collection::HPGe_Clover_CloverShare, 135. * deg,
        90. * deg, 8.00 * inch,
        {{{"G4_Cu", cu_clover_thin}, {"G4_Pb", pb_clover_thick}}, true}, {},
        0. * pi), // SN35
    new HPGe_Clover(
        "B4", HPGe_Clover_Collection::HPGe_Clover_4x50x80SEG2, 125.26 * deg,
        135. * deg, 8.00 * inch,
        {{{"G4_Cu", cu_clover_thin}, {"G4_Pb", pb_clover_thick}}, false}, {},
        30. * deg), // SN32
    new HPGe_Clover(
        "B5", HPGe_Clover_Collection::HPGe_Clover_CloverShare, 135. * deg,
        180. * deg, 8.00 * inch,
        {{{"G4_Cu", cu_clover_thin}, {"G4_Pb", pb_clover_thick}}, true}, {},
        0. * pi), // SN10

    new CeBr3_2x2("B", 90. * deg, 27.5 * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, true}),
    new CeBr3_2x2("C", 90. * deg, 45. * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, true}),
    new CeBr3_2x2("D", 90. * deg, 62.5 * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, true}),
    new CeBr3_2x2("F", 90. * deg, 117.5 * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, false}),
    new CeBr3_2x2("G", 90. * deg, 135. * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, false}),
    new CeBr3_2x2("H", 90. * deg, 152.5 * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, false}),
    new CeBr3_2x2("K", 90. * deg, 225. * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, true}),
    new CeBr3_2x2("O", 90. * deg, 315. * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, true}),
    new CeBr3_2x2("BJ", 135. * deg, 19. / 28. * 360. * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, true}),
    new CeBr3_2x2("BK", 135. * deg, 21. / 28. * 360. * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, false}),
    new CeBr3_2x2("BL", 135. * deg, 23. / 28. * 360. * deg, 8.00 * inch,
                  {{{"G4_Cu", cu_cebr_thick}, {"G4_Pb", pb_cebr_thin}}, true}),

    new HPGe_Coaxial("ZDEG", HPGe_Coaxial_Collection::HPGe_120_TUNL_40383,
                     HPGe_Coaxial_Dewar_Properties(), 0. * deg, 0. * deg,
                     ZeroDegreeMechanical::zero_degree_to_target),
    new MOLLY(0. * deg, 0. * deg, 11. * m)};

G4VPhysicalVolume *DetectorConstruction::Construct() {

  ConstructBoxWorld(2. * m, 2. * m, 12.0 * m);

  CollimatorRoom(world_logical).Construct({});
  BeamPipe(world_logical).Construct({});
  LeadShieldingUTR(world_logical).Construct({});
  Mechanical(world_logical).Construct({});
  ZeroDegreeMechanical(world_logical)
      .Construct(G4ThreeVector(zero_degree_x, zero_degree_y, 0.));
  GammaVault(world_logical).Construct({});

  for (size_t n_detector = 0; n_detector < detectors.size() - 2; ++n_detector) {
    detectors[n_detector]->Construct(world_logical, {});
    RegisterSensitiveLogicalVolumes(
        detectors[n_detector]->get_sensitive_logical_volumes());
  }
  detectors[detectors.size() - 2]->Construct(
      world_logical, G4ThreeVector(zero_degree_x, zero_degree_y, 0.));
  RegisterSensitiveLogicalVolumes(
      detectors[detectors.size() - 2]->get_sensitive_logical_volumes());
  detectors[detectors.size() - 1]->Construct(world_logical,
                                             G4ThreeVector(molly_x, 0., 0.));
  RegisterSensitiveLogicalVolumes(
      detectors[detectors.size() - 1]->get_sensitive_logical_volumes());

  return world_phys;
}

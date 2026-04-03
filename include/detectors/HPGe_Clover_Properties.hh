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

/**
 * This file contains code from the "utr" Geant4 simulation project.
 *
 * U. Friman-Gayer, J. Kleemann, and O. Papst, GEANT4 simulation of the Upstream
 * Target ROOM (UTR) at the HIγS facility (v2019.09), Zenodo (2019)
 * https://doi.org/10.5281/zenodo.3430154
 */

// Struct that contains the properties of a specific
// clover-type High-purity Germanium (HPGe) detector

#pragma once

#include <string_view>

using std::string_view;

struct HPGe_Clover_Properties {
  // Struct that contains the dimensions of a clover detector
  //
  // 'Front' = towards the target
  // 'Back' = away from the target

  // Detector crystals
  // These crystals are cylinders that have been squared off (See EURYSIS CLOVER
  // 4x50x80 SEG.2 Drawing sheet). There is also a hole in the crystal for the
  // anode

  // Radius of the detector crystals if they were still round
  double crystal_radius;

  // Length of the detector crystal
  double crystal_length;

  // Rounding radius of the crystal face
  double crystal_face_radius;

  // The contact layers on the surface of the crystal are neglected at the
  // moment, since they usually have a thickness of less than a millimeter and
  // are made of very light materials

  // The four crystals do not touch each other, but there
  // is some gap in between
  double crystal_gap;

  // Vacuum-filled gap between the end cap and the detector crystals at the
  // front
  double end_cap_to_crystal_gap_front;

  // Length of the evacuated area inside the end cap
  double vacuum_length;

  // Length of the anode hole from the back of each crystal.
  double anode_length;

  // Radius of the anode hole.
  double anode_radius;

  // End cap
  // Case with quadratic base area and smoothed edges which covers the whole
  // mount cup. It consists of the front part that contains the detector
  // crystals and a back part that contains the electronics. The back part is
  // modelled as an skeleton, since the inner composition is unknown.

  // Side length of the front end cap with a quadratic (see next variable) base
  // area
  double end_cap_front_side_length;

  // Rounding radius of the edges
  double end_cap_front_rounding_radius;

  // Length of the end cap around the crystal.
  double end_cap_front_length;

  // Thickness of the end cap at the front (But not at the part that faces the
  // target. This 'window thickness' (see below) may be thinner.)
  double end_cap_front_thickness;

  // Thickness of the window which faces the target
  double end_cap_window_thickness;

  // Connection between end cap and dewar
  // The following parts are implemented mainly for aesthetic reasons and
  // they are rough estimates for the actual structure of the end cap at
  // the back, the dewar and the connecting piece.

  // Side length of the back end cap with a
  // quadratic (see next variable) base area
  double end_cap_back_side_length;

  // Rounding radius of the edges
  double end_cap_back_rounding_radius;

  // Length of the end cap around the electronics.
  double end_cap_back_length;

  // Thickness of the end cap
  double end_cap_back_thickness;

  string_view end_cap_material;

  // Connection between dewar and mount cup / end cap
  // Contains the cold finger and electronics, but the latter are not
  // implemented here. Assumed to consist of solid aluminium.

  // Length of the connecting piece
  double connection_length;

  // Radius of the connecting piece
  double connection_radius;

  string_view connection_material;

  // Dewar
  // A cylindric tube with top and bottom

  // Dewar length, including top and bottom
  double dewar_length;

  // Outer radius, can be measured most easily
  double dewar_outer_radius;

  // Dewar wall thickness. Assumed to be the same for top, bottom and side
  double dewar_wall_thickness;

  string_view dewar_material;
};

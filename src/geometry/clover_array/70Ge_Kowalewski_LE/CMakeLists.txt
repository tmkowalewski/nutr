#    This file is part of nutr.
#
#    nutr is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    nutr is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with nutr.  If not, see <https://www.gnu.org/licenses/>.
#
#    Copyright (C) 2020-2022 Udo Friman-Gayer and Oliver Papst

add_library(detectorConstruction_70Ge_Kowalewski_LE DetectorConstruction.cc)
target_include_directories(detectorConstruction_70Ge_Kowalewski_LE PUBLIC ${PROJECT_SOURCE_DIR}/include/detectors ${PROJECT_SOURCE_DIR}/include/geometry ${PROJECT_SOURCE_DIR}/include/geometry/clover_array/70Ge_Kowalewski_LE ${PROJECT_SOURCE_DIR}/include/geometry/clover_array/array ${PROJECT_SOURCE_DIR}/include/sensitive_detector/${SENSITIVE_DETECTOR_DIR})
target_link_libraries(detectorConstruction_70Ge_Kowalewski_LE beamPipe cebr3_2x2 collimatorRoom gamma_vault mechanical nDetectorConstruction hpgeCoaxial hpgeClover labr3ce_3x3 leadShieldingUTR_70Ge_Kowalewski_LE molly SensitiveDetector zero_degree_mechanical)

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/70Ge_Kowalewski_LE)
add_executable(gps_70Ge_Kowalewski_LE ${PROJECT_SOURCE_DIR}/src/fundamentals/nutr.cc)
set_target_properties(gps_70Ge_Kowalewski_LE PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/70Ge_Kowalewski_LE)
target_include_directories(gps_70Ge_Kowalewski_LE PUBLIC ${PROJECT_SOURCE_DIR}/include/fundamentals ${PROJECT_SOURCE_DIR}/include/geometry ${PROJECT_SOURCE_DIR}/include/physics)
target_link_libraries(gps_70Ge_Kowalewski_LE actionInitialization ${Boost_LIBRARIES} detectorConstruction_70Ge_Kowalewski_LE physics ${Geant4_LIBRARIES})

add_executable(angcorr_70Ge_Kowalewski_LE ${PROJECT_SOURCE_DIR}/src/fundamentals/nutr.cc)
set_target_properties(angcorr_70Ge_Kowalewski_LE PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/70Ge_Kowalewski_LE)
target_include_directories(angcorr_70Ge_Kowalewski_LE PUBLIC ${PROJECT_SOURCE_DIR}/include/fundamentals ${PROJECT_SOURCE_DIR}/include/geometry ${PROJECT_SOURCE_DIR}/include/physics)
target_link_libraries(angcorr_70Ge_Kowalewski_LE actionInitialization ${Boost_LIBRARIES} detectorConstruction_70Ge_Kowalewski_LE physics ${Geant4_LIBRARIES})

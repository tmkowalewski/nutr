#!/bin/bash
# Script to run Geant4 efficiency simulations for the creation of efficiency curves for NRF data analysis

# Define paths and parameters
TREE_DIR="/home/tylermk/TUNL/Data/NRF/70Ge/efficiency_calibration/trees"
NUTR_BUILD_DIR="/home/tylermk/TUNL/Toolkits/nutr/nutr-build"
GEANT4_EXECUTABLE="${NUTR_BUILD_DIR}/70Ge_Kowalewski_LE/gps_70Ge_Kowalewski_LE"

# Check for required arguments
if [[ $# -ne 3 ]]; then
    echo "Usage: $0 <energy_min> <energy_max> <energy_spacing>"
    exit 1
fi

ENERGY_MIN=$1
ENERGY_MAX=$2
ENERGY_SPACING=$3

# Loop through energy range and run simulations
for (( ENERGY=ENERGY_MIN; ENERGY<=ENERGY_MAX; ENERGY+=ENERGY_SPACING )); do
    echo "Running simulation for energy: ${ENERGY} keV"
    OUTPUT_FILE="${TREE_DIR}/gamma.${ENERGY}.root"


    # Create a temporary macro file with the current energy
    MACRO_FILE=$(mktemp)
    sed "s/ENERGY/${ENERGY}/" ${NUTR_BUILD_DIR}/scripts/examples/efficiency.mac > "$MACRO_FILE"

    $GEANT4_EXECUTABLE --macro $MACRO_FILE --output $OUTPUT_FILE

    # Clean up temporary macro file
    rm "$MACRO_FILE"

    echo "Simulation for energy ${ENERGY} keV completed. Output saved to ${OUTPUT_FILE}"
done

echo "All simulations completed."

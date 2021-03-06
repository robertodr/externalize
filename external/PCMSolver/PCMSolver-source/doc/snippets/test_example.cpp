/* pcmsolver_copyright_start */
/*
 *     PCMSolver, an API for the Polarizable Continuum Model
 *     Copyright (C) 2013-2015 Roberto Di Remigio, Luca Frediani and contributors
 *     
 *     This file is part of PCMSolver.
 *     
 *     PCMSolver is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *     
 *     PCMSolver is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 *     
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with PCMSolver.  If not, see <http://www.gnu.org/licenses/>.
 *     
 *     For information on the complete list of contributors to the
 *     PCMSolver API, see: <http://pcmsolver.github.io/pcmsolver-doc>
 */
/* pcmsolver_copyright_end */

#include "catch.hpp"

#include <vector>
#include <cmath>

#include "Config.hpp"

#include <Eigen/Core>

#include "GePolCavity.hpp"
#include "TestingMolecules.hpp"

TEST_CASE("GePol cavity for a single sphere", "[gepol][gepol_point]")
{
    double area = 0.4;
    Molecule point = dummy<0>();
    GePolCavity cavity = GePolCavity(point, area, 0.0, 100.0);
    cavity.saveCavity("point.npz");

    /*! \class GePolCavity
     *  \test \b GePolCavityTest_size tests GePol cavity size for a point charge
     */
    SECTION("Test size")
    {
        int size = 32;
        size_t actualSize = cavity.size();
        REQUIRE(size == actualSize);
    }

    /*! \class GePolCavity
     *  \test \b GePolCavityTest_area tests GePol cavity surface area for a point charge
     */
    SECTION("Test surface area")
    {
        double area = 4.0 * M_PI * pow(1.0, 2);
        double actualArea = cavity.elementArea().sum();
        REQUIRE(area == Approx(actualArea));
    }

    /*! \class GePolCavity
     *  \test \b GePolCavityTest_volume tests GePol cavity volume for a point charge
     */
    SECTION("Test volume")
    {
        double volume = 4.0 * M_PI * pow(1.0, 3) / 3.0;
        Eigen::Matrix3Xd elementCenter = cavity.elementCenter();
        Eigen::Matrix3Xd elementNormal = cavity.elementNormal();
        double actualVolume = 0;
        for ( size_t i = 0; i < cavity.size(); ++i ) {
            actualVolume += cavity.elementArea(i) * elementCenter.col(i).dot(elementNormal.col(
                        i));
        }
        actualVolume /= 3;
        REQUIRE(volume == Approx(actualVolume));
    }
}

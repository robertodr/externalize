/* pcmsolver_copyright_start */
/*
 *     PCMSolver, an API for the Polarizable Continuum Model
 *     Copyright (C) 2013-2016 Roberto Di Remigio, Luca Frediani and contributors
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
 *     PCMSolver API, see: <http://pcmsolver.readthedocs.io/>
 */
/* pcmsolver_copyright_end */

#ifndef QUADRATURERULES_HPP
#define QUADRATURERULES_HPP

#include <vector>

#include "Config.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/map.hpp>

template <typename PointsPolicy>
struct QuadratureRule {
    int nPoints() { return PointsPolicy::nPoints(); }
    double abscissa(int i) { return PointsPolicy::gaussAbscissa(i); }
    double weight(int i) { return PointsPolicy::gaussWeight(i); }
};

struct gauss16 {
    int nPoints() { return 16; }
    /*! Abscissae for 16-point Gaussian quadrature rule */
    static double gaussAbscissa(int i) {
        static std::vector<double> x16(8);

        x16[0] = 0.9894009349916499325961542;
        x16[1] = 0.9445750230732325760779884;
        x16[2] = 0.8656312023878317438804679;
        x16[3] = 0.7554044083550030338951012;
        x16[4] = 0.6178762444026437484466718;
        x16[5] = 0.4580167776572273863424194;
        x16[6] = 0.2816035507792589132304605;
        x16[7] = 0.0950125098376374401853193;

        return x16[i];
    }
    /*! Weights for 16-point Gaussian quadrature rule */
    static double gaussWeight(int i) {
        static std::vector<double> w16(8);

        w16[0] = 0.0271524594117540948517806;
        w16[1] = 0.0622535239386478928628438;
        w16[2] = 0.0951585116824927848099251;
        w16[3] = 0.1246289712555338720524763;
        w16[4] = 0.1495959888165767320815017;
        w16[5] = 0.1691565193950025381893121;
        w16[6] = 0.1826034150449235888667637;
        w16[7] = 0.1894506104550684962853967;

        return w16[i];
    }
};

struct gauss32 {
    int nPoints() { return 32; }
    /*! Abscissae for 32-point Gaussian quadrature rule */
    static double gaussAbscissa(int i) {
        static std::vector<double> x32(16);

        x32[0]  = 0.9972638618494815635449811;
        x32[1]  = 0.9856115115452683354001750;
        x32[2]  = 0.9647622555875064307738119;
        x32[3]  = 0.9349060759377396891709191;
        x32[4]  = 0.8963211557660521239653072;
        x32[5]  = 0.8493676137325699701336930;
        x32[6]  = 0.7944837959679424069630973;
        x32[7]  = 0.7321821187402896803874267;
        x32[8]  = 0.6630442669302152009751152;
        x32[9]  = 0.5877157572407623290407455;
        x32[10] = 0.5068999089322293900237475;
        x32[11] = 0.4213512761306353453641194;
        x32[12] = 0.3318686022821276497799168;
        x32[13] = 0.2392873622521370745446032;
        x32[14] = 0.1444719615827964934851864;
        x32[15] = 0.0483076656877383162348126;

        return x32[i];
    }

    /*! Weights for 32-point Gaussian quadrature rule */
    static double gaussWeight(int i) {
        static std::vector<double> w32(16);

        w32[0]  = 0.0070186100094700966004071;
        w32[1]  = 0.0162743947309056706051706;
        w32[2]  = 0.0253920653092620594557526;
        w32[3]  = 0.0342738629130214331026877;
        w32[4]  = 0.0428358980222266806568786;
        w32[5]  = 0.0509980592623761761961632;
        w32[6]  = 0.0586840934785355471452836;
        w32[7]  = 0.0658222227763618468376501;
        w32[8]  = 0.0723457941088485062253994;
        w32[9]  = 0.0781938957870703064717409;
        w32[10] = 0.0833119242269467552221991;
        w32[11] = 0.0876520930044038111427715;
        w32[12] = 0.0911738786957638847128686;
        w32[13] = 0.0938443990808045656391802;
        w32[14] = 0.0956387200792748594190820;
        w32[15] = 0.0965400885147278005667648;

        return w32[i];
    }
};


struct gauss64 {
    int nPoints() { return 64; }
    /*! Abscissae for 64-point Gaussian quadrature rule */
    static double gaussAbscissa(int i) {
        static std::vector<double> x64(32);

        x64[0]  = 0.9993050417357721394569056;
        x64[1]  = 0.9963401167719552793469245;
        x64[2]  = 0.9910133714767443207393824;
        x64[3]  = 0.9833362538846259569312993;
        x64[4]  = 0.9733268277899109637418535;
        x64[5]  = 0.9610087996520537189186141;
        x64[6]  = 0.9464113748584028160624815;
        x64[7]  = 0.9295691721319395758214902;
        x64[8]  = 0.9105221370785028057563807;
        x64[9]  = 0.8893154459951141058534040;
        x64[10] = 0.8659993981540928197607834;
        x64[11] = 0.8406292962525803627516915;
        x64[12] = 0.8132653151227975597419233;
        x64[13] = 0.7839723589433414076102205;
        x64[14] = 0.7528199072605318966118638;
        x64[15] = 0.7198818501716108268489402;
        x64[16] = 0.6852363130542332425635584;
        x64[17] = 0.6489654712546573398577612;
        x64[18] = 0.6111553551723932502488530;
        x64[19] = 0.5718956462026340342838781;
        x64[20] = 0.5312794640198945456580139;
        x64[21] = 0.4894031457070529574785263;
        x64[22] = 0.4463660172534640879849477;
        x64[23] = 0.4022701579639916036957668;
        x64[24] = 0.3572201583376681159504426;
        x64[25] = 0.3113228719902109561575127;
        x64[26] = 0.2646871622087674163739642;
        x64[27] = 0.2174236437400070841496487;
        x64[28] = 0.1696444204239928180373136;
        x64[29] = 0.1214628192961205544703765;
        x64[30] = 0.0729931217877990394495429;
        x64[31] = 0.0243502926634244325089558;

        return x64[i];
    }

    /*! Weights for 64-point Gaussian quadrature rule */
    static double gaussWeight(int i) {
        static std::vector<double> w64(32);

        w64[0]  = 0.0017832807216964329472961;
        w64[1]  = 0.0041470332605624676352875;
        w64[2]  = 0.0065044579689783628561174;
        w64[3]  = 0.0088467598263639477230309;
        w64[4]  = 0.0111681394601311288185905;
        w64[5]  = 0.0134630478967186425980608;
        w64[6]  = 0.0157260304760247193219660;
        w64[7]  = 0.0179517157756973430850453;
        w64[8]  = 0.0201348231535302093723403;
        w64[9]  = 0.0222701738083832541592983;
        w64[10] = 0.0243527025687108733381776;
        w64[11] = 0.0263774697150546586716918;
        w64[12] = 0.0283396726142594832275113;
        w64[13] = 0.0302346570724024788679741;
        w64[14] = 0.0320579283548515535854675;
        w64[15] = 0.0338051618371416093915655;
        w64[16] = 0.0354722132568823838106931;
        w64[17] = 0.0370551285402400460404151;
        w64[18] = 0.0385501531786156291289625;
        w64[19] = 0.0399537411327203413866569;
        w64[20] = 0.0412625632426235286101563;
        w64[21] = 0.0424735151236535890073398;
        w64[22] = 0.0435837245293234533768279;
        w64[23] = 0.0445905581637565630601347;
        w64[24] = 0.0454916279274181444797710;
        w64[25] = 0.0462847965813144172959532;
        w64[26] = 0.0469681828162100173253263;
        w64[27] = 0.0475401657148303086622822;
        w64[28] = 0.0479993885964583077281262;
        w64[29] = 0.0483447622348029571697695;
        w64[30] = 0.0485754674415034269347991;
        w64[31] = 0.0486909570091397203833654;

        return w64[i];
    }
};

namespace mpl = boost::mpl;

typedef mpl::map< mpl::pair<mpl::int_<16>, gauss16>,
        mpl::pair<mpl::int_<32>, gauss32>,
        mpl::pair<mpl::int_<64>, gauss64> > rules_map;

#endif // QUADRATURERULES_HPP

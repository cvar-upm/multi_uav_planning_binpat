/*!******************************************************************************
 * \authors   David Eugenio <david.eugenioq@alumnos.upm.es>
 * \copyright Copyright (c) 2022 Universidad Politecnica de Madrid
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

#include "plan.hpp"

#include <iostream>

int main() {
    // Regionset

    std::vector vertices_0
        { gmt::point<2u>(0.f, 0.f)
        , gmt::point<2u>(10.f, 0.f)
        , gmt::point<2u>(10.f, 15.f)
        , gmt::point<2u>(0.f, 15.f)
        };

    auto polygon_0 = gmt::make_polygon(gmt::make_chain(seq::make_range_sequence(vertices_0)));

    pln::region region_0 = pln::make_region(polygon_0, gmt::point<2u>(1.5f, 0.f));



    std::vector vertices_1
        { gmt::point<2u>(15.f, 0.f)
        , gmt::point<2u>(30.f, 0.f)
        , gmt::point<2u>(30.f, 10.f)
        , gmt::point<2u>(15.f, 10.f)
        };

    auto polygon_1 = gmt::make_polygon(gmt::make_chain(seq::make_range_sequence(vertices_1)));

    pln::region region_1 = pln::make_region(polygon_1, gmt::point<2u>(3.f, 0.f));



    std::vector region_vector{ region_0, region_1 };

    auto regionset = seq::make_range_sequence(region_vector);



    // Homeset

    std::vector home_vector
        { gmt::point<3u>(-1.f, 0.f, .0f)
        , gmt::point<3u>(-1.f, 3.f, .0f)
        };

    auto homeset = seq::make_range_sequence(home_vector);



    // Parameters

    gmt::distance separation = 1.f;
    gmt::distance base = 4.f;
    gmt::distance increment = 0.5f;
    gmt::distance inspection = 3.f;

    pln::parameters parameters(separation, base, increment, inspection);



    auto plan = pln::generate_plan(regionset, homeset, parameters);



    std::cout << plan << std::endl;

    return 0;
}

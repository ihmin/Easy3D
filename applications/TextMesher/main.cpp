/**
 * Copyright (C) 2015 by Liangliang Nan (liangliang.nan@gmail.com)
 * https://3d.bk.tudelft.nl/liangliang/
 *
 * This file is part of Easy3D. If it is useful in your research/work,
 * I would be grateful if you show your appreciation by citing it:
 * ------------------------------------------------------------------
 *      Liangliang Nan.
 *      Easy3D: a lightweight, easy-to-use, and efficient C++
 *      library for processing and rendering 3D data. 2018.
 * ------------------------------------------------------------------
 * Easy3D is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 3
 * as published by the Free Software Foundation.
 *
 * Easy3D is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#include <easy3d/core/surface_mesh.h>
#include <easy3d/fileio/resources.h>
#include <easy3d/viewer/viewer.h>
#include <easy3d/viewer/camera.h>
#include <easy3d/util/logging.h>

#include "text_mesher.h"


using namespace easy3d;

int main(int argc, char** argv) {
    // Initialize logging.
    logging::initialize();

    // Create an Easy3D viewer.
    Viewer viewer("TextMesher - Easy3D");

    // Create an instance of mesher by specifying a font file.
    const std::string font_file = resource::directory() + "/fonts/Earth-Normal.ttf";
    TextMesher mesher(font_file, 48);   // font size is 48

    // Generate a surface mesh for "Easy3D".
    SurfaceMesh* mesh = mesher.generate_mesh("Easy3D", 0, 0);
    if (mesh)
        viewer.add_model(mesh); // Add the mesh to the viewer.

    // Generate another mesh for "Makes 3D Easy!".
    mesh = mesher.generate_mesh("Makes 3D Easy!", 0, -60);
    if (mesh)
        viewer.add_model(mesh); // Add the mesh to the viewer.

    // We always want to look the front of the meshed text.
    viewer.camera()->setViewDirection(vec3(0, 0, -1));
    viewer.camera()->setUpVector(vec3(0, 1, 0));

    // Go...
    return viewer.run();
}
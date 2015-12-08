/*
 * this is part of the bayesian object tracking (bot),
 * (https://github.com/bayesian-object-tracking)
 *
 * copyright (c) 2015 max planck society,
 * 				 autonomous motion department,
 * 			     institute for intelligent systems
 *
 * this source code form is subject to the terms of the gnu general public
 * license license (gnu gpl). a copy of the license can be found in the license
 * file distributed with this source code.
 */

#pragma once

#include <dbot/util/object_file_reader.hpp>
#include <dbot/util/object_model_loader.hpp>
#include <dbot/util/object_resource_identifier.hpp>

namespace dbot
{
class SimpleWavefrontObjectModelLoader : public ObjectModelLoader
{
public:
    SimpleWavefrontObjectModelLoader(const ObjectResourceIdentifier& ori)
        : ori_(ori)
    {
    }

    void load(
        std::vector<std::vector<Eigen::Vector3d>>& vertices,
        std::vector<std::vector<std::vector<int>>>& triangle_indices) const
    {
        vertices.resize(ori_.count_meshes());
        triangle_indices.resize(ori_.count_meshes());

        for (size_t i = 0; i < ori_.count_meshes(); i++)
        {
            ObjectFileReader file_reader;
            file_reader.set_filename(ori_.mesh_path(i));
            file_reader.Read();

            vertices[i] = *file_reader.get_vertices();
            triangle_indices[i] = *file_reader.get_indices();
        }
    }

private:
    ObjectResourceIdentifier ori_;
};
}
